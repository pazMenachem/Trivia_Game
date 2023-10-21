using ClientTrivia.Forms;
using System;
using System.Windows.Forms;

namespace ClientTrivia
{
    public partial class RoomMenu : CustomForm
    {
        public RoomMenu()
        {
            InitializeComponent();
            ApplyCustomFont();
            RefreshRoomList();
        }

        private async void RefreshRoomList()
        {
            dynamic data = await Communicator.GetInstance().SendAndReceiveData((byte)Utils.Codes.GetRoomsData);

            if (data.code == Utils.Codes.Success)
                ParseRoomString(data.rooms.ToString());
            else
                MessageBox.Show(data.message.ToString());
        }
        private void ParseRoomString(string rooms)
        {
            string[] records = rooms.Split(';');
            string[] fields;
            string currentPlayers;
            string maxPlayers;
            string name;
            string questions;
            string timeQuestion;
            string owner;

            foreach (string record in records)
                if (!string.IsNullOrEmpty(record))
                {
                    fields = record.Split(',');

                    name = fields[0];
                    questions = fields[1];
                    timeQuestion = fields[2];
                    maxPlayers = fields[3];
                    currentPlayers = fields[4];
                    owner = fields[5];

                    RoomList.Rows.Add(name,
                                      questions,
                                      timeQuestion,
                                      currentPlayers + '/' + maxPlayers,
                                      owner);
                }
        }
        private void backMenu_Click(object sender, EventArgs e)
        {
            Utils.SwapForms<RoomMenu, MainMenu>(this);
        }
        private void CreateRoomButton_Click(object sender, EventArgs e)
        {
            Utils.SwapForms<RoomMenu, CreateRoom>(this);
        }
        private async void enter_Click(object sender, EventArgs e)
        {
            if (RoomList.SelectedRows.Count == 0)
            {
                MessageBox.Show("Please select a Game room");
                return;
            }
            string owner = RoomList.SelectedRows[0].Cells[4].Value.ToString();

            var jsonData = new
            {
                ownerName = owner
            };

            dynamic jsonRes = await Communicator.GetInstance().SendAndReceiveData((byte)Utils.Codes.JoinRoom, jsonData);

            if (jsonRes.code == Utils.Codes.Success)
                JoinRoom((int)jsonRes.roomId);
            else
                MessageBox.Show(jsonRes.message.ToString());
        }
        private void JoinRoom(int roomId)
        {
            GameData roomData = new GameData {
                _creator           = RoomList.SelectedRows[0].Cells[4].Value.ToString(),
                _RoomName          = RoomList.SelectedRows[0].Cells[0].Value.ToString(),
                _AmountOfQuestions = Int32.Parse(RoomList.SelectedRows[0].Cells[1].Value.ToString()),
                _TimeQuestion      = Int32.Parse(RoomList.SelectedRows[0].Cells[2].Value.ToString()),
                _MaxUsers          = Int32.Parse(RoomList.SelectedRows[0].Cells[3].Value.ToString().Split('/')[1]),
                _owner             = false,
                _roomId            = roomId,
                _playerNames       = new string[4]
            };
            Utils.SwapForms<RoomMenu, WaitingRoom>(this, roomData);
        }

        private void RefreshRoomButton_Click(object sender, EventArgs e)
        {
            RoomList.Rows.Clear();
            RefreshRoomList();
        }
    }
}
