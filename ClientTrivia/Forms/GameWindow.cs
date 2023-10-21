using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ClientTrivia.Forms
{
    public partial class GameWindow : CustomForm
    {
        private GameData _gameData;
        private CancellationTokenSource _cancellationTokenSource;
        private CancellationToken _cancelToken;
        private int _secondsTimer = 0;
        private int _currentAnswer = 0;
        private Control[] _labels = new Control[4];

        public GameWindow(GameData gameData)
        {
            InitializeComponent();
            GameCustomInit(gameData);
            Communicator.GetInstance().SendData((byte)Utils.Codes.GetGameStats);
        }

        private void GameCustomInit(GameData gameData)
        {
            _gameData = gameData;
            _cancellationTokenSource = new CancellationTokenSource();
            _cancelToken = _cancellationTokenSource.Token;
            RoomNameLabel.Text = _gameData._RoomName;

            QuestionTimer.Interval = 1000;
            QuestionTimer.Tick += Timer;
            //QuestionTimer.Start();

            if (_gameData._owner)
                LeaveGameButton.Text = "Close Game";

            _labels[0] = PlayerPointsLabel1;
            _labels[1] = PlayerPointsLabel2;
            _labels[2] = PlayerPointsLabel3;
            _labels[3] = PlayerPointsLabel4;

            ApplyCustomFont();
            _ = StartListen();
        }

        private void Timer(object sender, EventArgs e)
        {
            _secondsTimer++;
            TimeLabel.Text = (_gameData._TimeQuestion - _secondsTimer).ToString();
            if (_secondsTimer == _gameData._TimeQuestion)
            {
                SendCurrentAnswer();
                Reset();
                System.Windows.Forms.MessageBox.Show("Times Up!");
            }
        }
        private void Reset()
        {
            _currentAnswer = 0;
            _secondsTimer  = 0;
            SendAnswerButton.Enabled = true;
            LeaveGameButton.Enabled = true;
        }
        private void SendCurrentAnswer()
        {
            var data = new
            {
                time   = _secondsTimer,
                answer = _currentAnswer
            };
            Communicator.GetInstance().SendData((byte)Utils.Codes.SubmitAnswer, data);
        }

        private async Task StartListen()
        {
            while (true)
                try
                {
                    dynamic jsonData = await Communicator.GetInstance().ReceiveData(_cancelToken);

                    if (_cancelToken.IsCancellationRequested)
                        return;

                    if (((JObject)jsonData).ContainsKey("broadCast"))
                        HandleBroadCast(jsonData);
                    else
                        HandleSelfRequest(jsonData);
                }
                catch (Exception ex)
                {
                    System.Windows.Forms.MessageBox.Show("oops, something went wrong :\n" + ex.ToString(),
                                                       "Error",
                                                       MessageBoxButtons.OK,
                                                       MessageBoxIcon.Error);
                    Environment.Exit(1);
                }
        }

        public void HandleBroadCast(dynamic jsonData)
        {   
            switch ((Utils.Codes)jsonData.broadCast)
            {
                case Utils.Codes.BCGameClosed:
                    System.Windows.Forms.MessageBox.Show(jsonData.message.ToString());
                    LeaveCloseGame(jsonData);
                    break;
                case Utils.Codes.BCPlayerJoinedLeft:
                    PlayerLeft(jsonData);
                    break;
                default:
                    throw new Exception("UnValid BroadCast Code");
            }
        }

        private void PlayerLeft(dynamic jsonData)
        {
            // Need to Add to chat "Player X left the game", or other possibility for rest of the players to
            // know... not really necessary since it wont affect other players.
            // Player who left will still display his current points.
            // json contains "playerName".
            return;
        }

        public void HandleSelfRequest(dynamic jsonData)
        {
            switch ((Utils.Codes)jsonData.requestCode)
            {
                case Utils.Codes.CloseGame:
                case Utils.Codes.LeaveGame:
                    LeaveCloseGame(jsonData);
                    break;
                case Utils.Codes.SubmitAnswer:
                case Utils.Codes.GetGameStats:
                    UpdateGameStats(jsonData);
                    break;
                default:
                    throw new Exception("UnValid Self Handle Code");
            }
        }

        private void UpdateGameStats(dynamic jsonData)
        {
            UpdateQuestion(jsonData.currentQuestion);
            UpdatePoints(jsonData);
            Reset();

            if (((JObject)jsonData.currentQuestion).ContainsKey("finish"))
                FinishGame();
        }

        private void FinishGame()
        {
            System.Windows.Forms.MessageBox.Show("Game finished!");
            LeaveGameButton_Click(null, null);
        }

        private void UpdatePoints(dynamic jsonData)
        {
            HashSet<string> activePlayers = new HashSet<string>(((string)jsonData.activePlayers).Split(','));
            JObject playerStats = jsonData.playerStats;
            string playerName;

            for (int index = 0; index < _gameData._playerNames.Count(); index ++)
            {
                playerName = _gameData._playerNames[index];
                if (activePlayers.Contains(playerName))
                {
                    _labels[index].Text = playerName + " - " + playerStats[playerName];
                    _labels[index].Visible = true;
                }
            }
            return;
        }

        private void UpdateQuestion(dynamic currentQuestion)
        {
            QuestionLabel.Text    = currentQuestion.question;
            AnswerOneLabel.Text   = currentQuestion.answerOne;
            AnswerTwoLabel.Text   = currentQuestion.answerTwo;
            AnswerThreeLabel.Text = currentQuestion.answerThree;
            AnswerFourLabel.Text  = currentQuestion.answerFour;
        }

        private void LeaveCloseGame(dynamic jsonData)
        {
            if (jsonData.code == Utils.Codes.Success)
            {
                _cancellationTokenSource.Cancel();
                Utils.SwapForms<GameWindow, MainMenu>(this);
                return;
            }
            System.Windows.Forms.MessageBox.Show(jsonData.message.ToString());
        }

        private void LeaveGameButton_Click(object sender, EventArgs e)
        {
            if (_gameData._owner)
                Communicator.GetInstance().SendData((byte)Utils.Codes.CloseGame);
            else
                Communicator.GetInstance().SendData((byte)Utils.Codes.LeaveGame);
        }

        private void SendAnswerButton_Click(object sender, EventArgs e)
        {
            SendCurrentAnswer();
            SendAnswerButton.Enabled = false;
            LeaveGameButton.Enabled = false;
        }
        private void radioButton1_CheckedChanged(object sender, EventArgs e){_currentAnswer = 1;}
        private void radioButton2_CheckedChanged(object sender, EventArgs e){_currentAnswer = 2;}
        private void radioButton3_CheckedChanged(object sender, EventArgs e){_currentAnswer = 3;}
        private void radioButton4_CheckedChanged(object sender, EventArgs e){_currentAnswer = 4;}
    }
}
