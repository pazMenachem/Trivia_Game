#include "SqliteDataBase.h"

IDataBase* IDataBase::_instance = nullptr;

bool SqliteDataBase::open()
{
    ifstream db(DB_NAME);
    if (!db.good())
        cerr << "Failed to Read DataBase, Created new one." << endl;
    db.close();

    int res = sqlite3_open(DB_NAME, &_dbPtr);
    if (res == SQLITE_OK) // DB opened
    {
        createTables();
        cout << "SQLite DataBase opened." << endl;
        return true;
    }
    else // Failed to open DB
    {
        cerr << "Failed to open DataBase." << endl;
        return false;
    }
}

bool SqliteDataBase::close()
{
    if (_dbPtr) {
        sqlite3_close(_dbPtr);
        _dbPtr = nullptr;
        cout << "DataBase Closed" << endl;
        return true;
    }
    cerr << "DataBase Already closed" << endl;
    return false;
}

bool SqliteDataBase::doesUserExist(const string& userName)
{
    const char* query = "SELECT * FROM Users WHERE USERNAME = ?";
    sqlite3_stmt* statement;

    if (sqlite3_prepare_v2(_dbPtr, query, -1, &statement, nullptr) != SQLITE_OK) {
        cerr << "Failed to prepare query: " << sqlite3_errmsg(_dbPtr) << endl;
        return false;
    }
    sqlite3_bind_text(statement, 1, userName.c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(statement) == SQLITE_ROW) {
        sqlite3_finalize(statement);
        return true;  // User exists
    }

    sqlite3_finalize(statement);
    checkForErrorMessage();
    return false;  // User does not exist
}

bool SqliteDataBase::doesPasswordMatch(const string& userName, const string& password)
{
    const char* query = "SELECT * FROM Users WHERE USERNAME = ? AND PASSWORD = ?";
    sqlite3_stmt* statement;

    if (sqlite3_prepare_v2(_dbPtr, query, -1, &statement, nullptr) != SQLITE_OK) {
        cerr << "Failed to prepare query: " << sqlite3_errmsg(_dbPtr) << endl;
        return false;
    }
    sqlite3_bind_text(statement, 1, userName.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(statement, 2, password.c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(statement) == SQLITE_ROW) {
        sqlite3_finalize(statement);
        return true;  // Password match
    }

    sqlite3_finalize(statement);
    checkForErrorMessage();
    return false;  // Password does not match
}

bool SqliteDataBase::addNewUser(const string& userName, const string& pass, const string& email)
{
    const char* query = "INSERT INTO USERS VALUES (?, ?, ?);";
    sqlite3_stmt* statment;

    if(sqlite3_prepare_v2(_dbPtr, query, -1, &statment, nullptr) != SQLITE_OK){
        cerr << "Failed to prepare query: " << sqlite3_errmsg(_dbPtr) << endl;
        return 0;
    }

    sqlite3_bind_text(statment, 1, userName.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(statment, 2, pass.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(statment, 3, email.c_str(), -1, SQLITE_STATIC);
    
    if (sqlite3_step(statment) == SQLITE_DONE) {
        sqlite3_finalize(statment);
        addUserToStatisticsTable(userName);
        return 1;
    }
    checkForErrorMessage();
    sqlite3_finalize(statment);
    return 0;
}

vector<Question> SqliteDataBase::getQuestions(int numOfQuestions) const
{
    if (numOfQuestions > _questions.size())
        numOfQuestions = int(_questions.size());

    vector<Question> res;
    set<int> usedIndex;
    random_device rd;
    default_random_engine rng(rd());
    int randomIndex;
    do {
        randomIndex = rng() % _questions.size();

        if (usedIndex.find(randomIndex) == usedIndex.end())
        {
            numOfQuestions--;
            usedIndex.insert(randomIndex);
            res.push_back(_questions[randomIndex]);
        }
        else
            continue;
    } while (numOfQuestions);

    return res;
}

void SqliteDataBase::deleteInstance()
{
    _instance->close();
    delete _instance;
}

IDataBase* SqliteDataBase::getInstance()
{
    if (!_instance) {
        _instance = new SqliteDataBase();
        _instance->open();
    }
    return _instance;
}

bool SqliteDataBase::runQuery(const char* query)
{
    char* errmsg = nullptr;
    int res = sqlite3_exec(_dbPtr, query, nullptr, nullptr, &errmsg);
    if (res != SQLITE_OK)
    {
        cerr << errmsg << endl;
        delete errmsg;
        return false;
    }
    delete errmsg;
    return true;
}

bool SqliteDataBase::addQuestionsToDB()
{
    const char* query = "INSERT INTO Questions"\
                        "(QUESTION, ANSWER1, ANSWER2, ANSWER3, ANSWER4, CORRECTANSWER)"\
                        "VALUES(?, ?, ?, ?, ?, ?);";
    sqlite3_stmt* statment;

    if (sqlite3_prepare_v2(_dbPtr, query, -1, &statment, nullptr) != SQLITE_OK) {
        cerr << "Failed to prepare query: " << sqlite3_errmsg(_dbPtr) << endl;
        return false;
    }

    for (int i = 0; i < _questions.size(); i++)
    {
        sqlite3_bind_text(statment, 1, _questions[i]._question.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(statment, 2, _questions[i]._answers[0].c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(statment, 3, _questions[i]._answers[1].c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(statment, 4, _questions[i]._answers[2].c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(statment, 5, _questions[i]._answers[3].c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(statment, 6, _questions[i]._correctAnswer);

        if (sqlite3_step(statment) != SQLITE_DONE) {
            continue; // Repeated question.
            //checkForErrorMessage();
            //return false;
        }
        sqlite3_reset(statment);
    }

    sqlite3_finalize(statment);
    return true;
}

bool SqliteDataBase::readQuestionsFromFile()
{
    ifstream questionsFile(QUESTION_FILE_NAME);
    if (!questionsFile.good()) {
        cerr << "Failed to open questions file." << endl;
        return false;
    }
    
    string line;
    short index = false;
    Question question;
    string correctAnswer;

    try {
        while (getline(questionsFile, line)) {
            stringstream ss(line);

            // Read question
            getline(ss, question._question, ',');

            // Read answers
            for (int i = 0; i < AMOUNT_OF_ANSWERS; i++)
                getline(ss, question._answers[i], ',');

            // Read correct answer
            getline(ss, correctAnswer, ',');
            question._correctAnswer = stoi(correctAnswer);

            index = 0;
            _questions.push_back(question);
        }
    }
    catch (const exception& e) {
        cerr << e.what();
        return false;
    }

    questionsFile.close();
    return true;
}

void SqliteDataBase::addTestInfo(int amount)
{
    string username;
    string password;
    string email;

    for (int i = 0; i < amount; ++i) {
        username = "user" + to_string(i);
        password = "password" + to_string(i);
        email = "user" + to_string(i) + "@example.com";
        if (!addNewUser(username, password, email)) {
            cout << "Test Rows already in DB" << endl;
            return;
        }
    }
}

bool SqliteDataBase::checkForErrorMessage() const
{
    const char* errorMsg = sqlite3_errmsg(_dbPtr);
    if (errorMsg != "not an error")
    {
        cout << "SQLite Error: " << errorMsg << endl;
        return true;
    }
    return false;
}

void SqliteDataBase::addUserToStatisticsTable(const string userName) const
{
    const char* query = "INSERT INTO STATISTICS VALUES (?, 0, 0, 0, 0, 0)";
    sqlite3_stmt* statment;

    if (sqlite3_prepare_v2(_dbPtr, query, -1, &statment, NULL) == SQLITE_OK) {
        sqlite3_bind_text(statment, 1, userName.c_str(), -1, SQLITE_STATIC);

        if (sqlite3_step(statment) != SQLITE_DONE)
            checkForErrorMessage();
    }
    sqlite3_finalize(statment);
}

float SqliteDataBase::getPlayerAverageAnswerTime(const string& userName) const
{
    int totalTime = 0;
    int amountOfAnswers = 1;
    const char* queryTotalTime = "SELECT TOTALTIME FROM Statistics WHERE USERNAME = ?";
    const char* queryQuestions = "SELECT ANSWERS FROM Statistics WHERE USERNAME = ?";
    sqlite3_stmt* statement;

    if (sqlite3_prepare_v2(_dbPtr, queryTotalTime, -1, &statement, NULL) == SQLITE_OK)
    {
        sqlite3_bind_text(statement, 1, userName.c_str(), -1, SQLITE_STATIC);
        if (sqlite3_step(statement) == SQLITE_ROW)
            totalTime = static_cast<int>(sqlite3_column_int(statement, 0));
        checkForErrorMessage();
    }

    if (sqlite3_prepare_v2(_dbPtr, queryQuestions, -1, &statement, nullptr) == SQLITE_OK)
    {
        sqlite3_bind_text(statement, 1, userName.c_str(), -1, SQLITE_STATIC);
        if (sqlite3_step(statement) == SQLITE_ROW)
            amountOfAnswers = static_cast<int>(sqlite3_column_int(statement, 0));
        checkForErrorMessage();
    }

    sqlite3_finalize(statement);
    if (!amountOfAnswers) // divide by zero
        return 0;
    return float(totalTime/amountOfAnswers);
}

int SqliteDataBase::getNumOfCorrectAnswers(const string& userName) const
{
    sqlite3_stmt* statement;
    const char* query = "SELECT CORRECTANSWERS FROM Statistics WHERE USERNAME = ?";
    int numOfCorrectAnswers = 0;

    if (sqlite3_prepare_v2(_dbPtr, query, -1, &statement, NULL) == SQLITE_OK)
    {
        sqlite3_bind_text(statement, 1, userName.c_str(), -1, SQLITE_STATIC);
        if (sqlite3_step(statement) == SQLITE_ROW)
            numOfCorrectAnswers = sqlite3_column_int(statement, 0);

        sqlite3_finalize(statement);
    }
    checkForErrorMessage();
    return numOfCorrectAnswers;
}

int SqliteDataBase::getNumOfTotalAnswers(const string& userName) const
{
    sqlite3_stmt* statement;
    const char* query = "SELECT ANSWERS FROM Statistics WHERE USERNAME = ?";
    int numOfAnswers = 0;

    if (sqlite3_prepare_v2(_dbPtr, query, -1, &statement, NULL) == SQLITE_OK)
    {
        sqlite3_bind_text(statement, 1, userName.c_str(), -1, SQLITE_STATIC);
        if (sqlite3_step(statement) == SQLITE_ROW)
            numOfAnswers = sqlite3_column_int(statement, 0);

        sqlite3_finalize(statement);
    }
    checkForErrorMessage();
    return numOfAnswers;
}

int SqliteDataBase::getNumOfPlayerGames(const string& userName) const
{
    sqlite3_stmt* statement;
    const char* query = "SELECT GAMES FROM Statistics WHERE USERNAME = ?";
    int numOfGames = 0;

    if (sqlite3_prepare_v2(_dbPtr, query, -1, &statement, NULL) == SQLITE_OK)
    {
        sqlite3_bind_text(statement, 1, userName.c_str(), -1, SQLITE_STATIC);
        if (sqlite3_step(statement) == SQLITE_ROW)
            numOfGames = sqlite3_column_int(statement, 0);

        sqlite3_finalize(statement);
    }
    checkForErrorMessage();
    return numOfGames;
}

int SqliteDataBase::getPlayerScore(const string& userName) const
{
    sqlite3_stmt* statement;
    const char* query = "SELECT POINTS FROM Statistics WHERE USERNAME = ?";
    int points = -1;

    if (sqlite3_prepare_v2(_dbPtr, query, -1, &statement, NULL) == SQLITE_OK)
    {
        sqlite3_bind_text(statement, 1, userName.c_str(), -1, SQLITE_STATIC);
        if (sqlite3_step(statement) == SQLITE_ROW)
            points = sqlite3_column_int(statement, 0);

        sqlite3_finalize(statement);
    }
    checkForErrorMessage();
    return points;
}

// return top 5 highest players by points
vector<pair<string, int>> SqliteDataBase::getHighScores() const
{
    vector<pair<string, int>> highScores;
    sqlite3_stmt* stmt;

    // Prepare the SQL statement
    const char* sql = "SELECT USERNAME, POINTS " \
                      "FROM Statistics " \
                      "ORDER BY POINTS DESC LIMIT 5";

    if (sqlite3_prepare_v2(_dbPtr, sql, -1, &stmt, NULL) == SQLITE_OK) 
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            // Read the values from the result row
            const char* username = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
            int points = sqlite3_column_int(stmt, 1);

            // Add the result to the highScores vector
            highScores.push_back(make_pair(username, points));
        }

    // Finalize the statement
    sqlite3_finalize(stmt);
    checkForErrorMessage();
    return highScores;
}

bool SqliteDataBase::updateUserStatistics(const GameData& gameData, const string& userName) const
{
    const char* query = "UPDATE statistics                    \
                         SET GAMES = GAMES + 1,               \
                         POINTS = POINTS + ?,                 \
                         CORRECTANSWERS = CORRECTANSWERS + ?, \
                         TOTALTIME = TOTALTIME + ?,           \
                         ANSWERS = ANSWERS + ?                \
                         WHERE USERNAME = ?";
    sqlite3_stmt* statement;

    if (sqlite3_prepare_v2(_dbPtr, query, -1, &statement, nullptr) != SQLITE_OK) {
        cerr << "Failed to prepare query: " << sqlite3_errmsg(_dbPtr) << endl;
        return false;
    }

    sqlite3_bind_int(statement, 1, gameData._playersPoints.at(userName));
    sqlite3_bind_int(statement, 2, gameData._correctAnswers.at(userName));
    sqlite3_bind_int(statement, 3, gameData._totalTime.at(userName));
    sqlite3_bind_int(statement, 4, gameData._amountOfQuestions.at(userName));
    sqlite3_bind_text(statement, 5, userName.c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(statement) == SQLITE_DONE)
    {
        sqlite3_finalize(statement);
        return true;
    }
            
    checkForErrorMessage();
    sqlite3_finalize(statement);
    return false;
}

void SqliteDataBase::createTables()
{
    try {
        createUserTable();
        createQuestionTable();
        createStatisticsTable();
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
        cerr << "Failed to create Tables." << endl;
    }

    #ifdef _DEV_
        addTestInfo(AMOUNT_OF_ROWS_TO_TEST);
    #endif

    if (!readQuestionsFromFile())
        cerr << __FUNCTION__ " Failed to read questions from file" << endl;
    if (!addQuestionsToDB())
        cerr << __FUNCTION__ " Failed to add questions" << endl;
}

bool SqliteDataBase::createStatisticsTable()
{
    const char* query =
        "CREATE TABLE Statistics("\
        "USERNAME TEXT NOT NULL,"\
        "ANSWERS INTEGER,"\
        "CORRECTANSWERS INTEGER,"\
        "GAMES INTEGER,"\
        "TOTALTIME INTEGER,"\
        "POINTS INTEGER,"\
        "FOREIGN KEY (USERNAME) REFERENCES Users(USERNAME) ON DELETE CASCADE"\
        ");";

    if (runQuery(query)) {
        cout << "Statistics Table created" << endl;
        return 1;
    }
    else // Already created, msg printed in runQuery
        return 0;
}

bool SqliteDataBase::createUserTable()
{
    const char* query =
        "CREATE TABLE Users("\
        "USERNAME TEXT PRIMARY KEY NOT NULL,"\
        "PASSWORD TEXT NOT NULL,"\
        "EMAIL TEXT NOT NULL"\
        ");";

        if (runQuery(query)) {
            cout << "User Table created" << endl;
            return 1;
        }
        else // Already created, msg printed in runQuery
            return 0;
}

bool SqliteDataBase::createQuestionTable()
{
    const char* query =
        "CREATE TABLE Questions("\
        "QUESTION TEXT PRIMARY KEY NOT NULL,"\
        "ANSWER1 TEXT NOT NULL,"\
        "ANSWER2 TEXT NOT NULL,"\
        "ANSWER3 TEXT NOT NULL,"\
        "ANSWER4 TEXT NOT NULL,"\
        "CORRECTANSWER INTEGER NOT NULL CHECK (CORRECTANSWER >= 1 AND CORRECTANSWER <= 4)"
        ");";

        if (runQuery(query)) {
            cout << "Question Table created" << endl;
            return 1;
        } 
        else // Already created, msg printed in runQuery
            return 0;
}
