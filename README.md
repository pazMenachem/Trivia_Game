# Trivia Game

A multiplayer trivia game with a client-server architecture, featuring real-time gameplay, room management, and user authentication.

## Architecture

- **Server**: C++ backend handling game logic, user management, and database operations
- **Client**: C# Windows Forms application providing the user interface
- **Database**: SQLite for persistent data storage

## Features

- User authentication (login/signup)
- Real-time multiplayer gameplay
- Room creation and management
- Custom game settings
- Score tracking and statistics
- Interactive UI with custom styling

## Technical Stack

### Server
- C++
- SQLite
- WebSocket communication
- JSON for data serialization

### Client
- C# (.NET Framework)
- Windows Forms
- Newtonsoft.Json for JSON handling
- Custom networking implementation

## Project Structure

### Server Components
- Game logic handlers
- Room management system
- User authentication
- Database operations
- WebSocket communication

### Client Components
- User interface forms
- Network communication layer
- Data serialization/deserialization
- Game state management

## Setup

1. Clone the repository
```bash
git clone https://github.com/yourusername/Trivia_Game.git
```

2. Build the server (requires Visual Studio with C++ support)
   - Open `ServerTrivia/ServerTrivia.sln`
   - Build the solution

3. Build the client (requires Visual Studio with C# support)
   - Open `ClientTrivia/ClientTrivia.sln`
   - Restore NuGet packages
   - Build the solution

4. Configure the connection
   - Default server address: 127.0.0.1
   - Default port: 8826

## Running the Application

1. Start the server application
2. Launch the client application
3. Create an account or log in
4. Create or join a game room
5. Play!

## Dependencies

### Server
- C++ Standard Library
- SQLite
- JSON parsing library

### Client
- .NET Framework
- Newtonsoft.Json
- System.Memory
- System.Buffers
- System.Numerics.Vectors

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contributing

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## Authors

- [@pazmenachem](https://github.com/pazmenachem) - Paz Menachem
