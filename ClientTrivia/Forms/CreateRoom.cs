using ClientTrivia.Forms;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ClientTrivia
{
    public partial class CreateRoom : CustomForm
    {
        private int _time;
        private int _questions;
        private int _maxUsers;

        public CreateRoom()
        {
            InitializeComponent();
            ApplyCustomFont();
        }

        private void BackButton_Click(object sender, EventArgs e)
        {
            Utils.SwapForms<CreateRoom, RoomMenu>(this);
        }

        private async void CreateRoomButton_Click(object sender, EventArgs e)
        {
            if (!Utils.CheckForFields(this.RoomName.Text,
                                      this.TimeQuestion.Text,
                                      this.Questions.Text,
                                      this.MaxUsers.Text))
            {
                Utils.FillAllFieldsAlert();
                return;
            }

            _time      = Int32.Parse(this.TimeQuestion.Text);
            _questions = Int32.Parse(this.Questions.Text);
            _maxUsers  = Int32.Parse(this.MaxUsers.Text);

            var jsonData = new
            {
                roomName = this.RoomName.Text,
                answerTimeOut = _time,
                questionCount = _questions,
                maxUsers = _maxUsers
            };

            dynamic data = await Communicator.GetInstance().SendAndReceiveData((byte)Utils.Codes.CreateRoom,
                                                                         jsonData);
            if (data.code == Utils.Codes.Success)
            {
                GameData roomData = new GameData
                {
                    _TimeQuestion = _time,
                    _AmountOfQuestions = _questions,
                    _MaxUsers = _maxUsers,
                    _RoomName = this.RoomName.Text,
                    _roomId = (int)data.roomId,
                    _owner = true,
                    _creator = Communicator.UserName,
                    _playerNames = new string[4]
                };

                Utils.SwapForms<CreateRoom, WaitingRoom>(this, roomData);
            }
            else
                MessageBox.Show(data.message.ToString());
        }
    }
}
