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
    public partial class WaitingRoom : CustomForm
    {
        private GameData _gameData;
        private CancellationTokenSource _cancellationTokenSource;
        private CancellationToken _cancelToken;

        public WaitingRoom(GameData gameData)
        {
            _gameData = gameData;

            InitializeComponent();
            ApplyCustomFont();
            WaitingCustomInit();
            _ = StartListen();
            RequestPlayerList();
        }

        private void WaitingCustomInit()
        {
            _cancellationTokenSource = new CancellationTokenSource();
            _cancelToken = _cancellationTokenSource.Token;

            if (_gameData._owner)
            {
                StartGameButton.Visible = true;
                GoBackButton.Text = "Close Room";
            }

            TextName.Text      = _gameData._RoomName;
            TextQuestions.Text = _gameData._AmountOfQuestions.ToString();
            TextTime.Text      = _gameData._TimeQuestion.ToString();
        }

        private void RequestPlayerList()
        {
            var data = new
            {
                roomId = _gameData._roomId,
            };

            Communicator.GetInstance().SendData((byte)Utils.Codes.GetPlayersInRoom, data);
        }

        private void RefreshPlayerList(dynamic jsonData)
        {
            if (jsonData.code == Utils.Codes.Success)
                ParsePlayerList((string)jsonData.playersInRoom);
            else
            {
                ListPlayers.Items.Add("Error Displaying Players");
                System.Windows.Forms.MessageBox.Show(jsonData.message.ToString());
            }
        }

        private void ParsePlayerList(string rawData)
        {
            ListPlayers.Items.Clear();
            _gameData._playerNames = rawData.Split(',');

            foreach (string name in _gameData._playerNames)
                ListPlayers.Items.Add("- " + name + "\n");

            TextPlayers.Text = _gameData._playerNames.Length + "/" + _gameData._MaxUsers;
        }

        private async Task StartListen()
        {
            while(true)
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

        private void HandleBroadCast(dynamic jsonData)
        {
            switch ((Utils.Codes)jsonData.broadCast)
            {
                case Utils.Codes.BCPlayerJoinedLeft:
                    RequestPlayerList();
                    break;
                case Utils.Codes.BCRoomClosed:
                    System.Windows.Forms.MessageBox.Show(jsonData.message.ToString());
                    LeaveRoom(jsonData);
                    break;
                case Utils.Codes.BCGameStarted:
                    StartGame(jsonData);
                    break;
                case Utils.Codes.BCNewChatMessage:
                    AddChatMessage(jsonData);
                    break;
                default:
                    throw new Exception("UnValid BroadCast Code");
            }
        }

        private void AddChatMessage(dynamic jsonData)
        {
            ChatWindow.Items.Add(jsonData.userName.ToString());
            ChatWindow.Items.Add(jsonData.message.ToString());
        }

        private void HandleSelfRequest(dynamic jsonData)
        {
            switch ((Utils.Codes)jsonData.requestCode)
            {
                case Utils.Codes.StartGame:
                    StartGame(jsonData);
                    break;
                case Utils.Codes.CloseRoom:
                case Utils.Codes.LeaveRoom:
                    LeaveRoom(jsonData);
                    break;
                case Utils.Codes.GetPlayersInRoom:
                    RefreshPlayerList(jsonData);
                    break;
                case Utils.Codes.JoinRoom:
                    JoinRoom(jsonData);
                    break;
                default:
                    throw new Exception("UnValid Self Handle Code");
            }
        }

        private void StartGame(dynamic jsonData)
        {
            if (jsonData.code == Utils.Codes.Success)
                Utils.SwapForms<WaitingRoom, GameWindow>(this, _gameData);
            else
                System.Windows.Forms.MessageBox.Show(jsonData.message.ToString());
        }

        private void GoBackButton_Click(object sender, EventArgs e)
        {
            if (_gameData._owner)
                // Room Admin
                Communicator.GetInstance().SendData((byte)Utils.Codes.CloseRoom);
            else
                // Room Member
                Communicator.GetInstance().SendData((byte)Utils.Codes.LeaveRoom);
        }

        private void LeaveRoom(dynamic jsonData)
        {
            if (jsonData.code == Utils.Codes.Success)
            {
                _cancellationTokenSource.Cancel(); // Ending the listener task
                Utils.SwapForms<WaitingRoom, RoomMenu>(this);
            }
            else
                System.Windows.Forms.MessageBox.Show(jsonData.message.ToString());
        }
        private void JoinRoom(dynamic jsonData)
        {
            if (jsonData.code == Utils.Codes.Success) return;

            System.Windows.Forms.MessageBox.Show(jsonData.message.ToString());
        }

        private void MessageButton_Click(object sender, EventArgs e)
        {
            var data = new
            {
                userName = Communicator.UserName,
                message  = MessageBox.Text,
            };
            Communicator.GetInstance().SendData((byte)Utils.Codes.ChatMessage, data);
            MessageBox.ResetText();
        }

        private void StartGameButton_Click(object sender, EventArgs e)
        {
            Communicator.GetInstance().SendData((byte)Utils.Codes.StartGame);
        }
    }
}
