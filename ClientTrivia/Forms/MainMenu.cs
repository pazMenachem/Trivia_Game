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
    public partial class MainMenu : CustomForm
    {
        Label[] _highScoresLabels = new Label[5]; 
        public MainMenu()
        {
            InitializeComponent();
            WaitingRoomInit();
            ApplyCustomFont();
        }

        private void WaitingRoomInit()
        {
            _highScoresLabels[0] = playerOneHighLabel;
            _highScoresLabels[1] = playerTwoHighLabel;
            _highScoresLabels[2] = playerThreeHighLabel;
            _highScoresLabels[3] = playerFourHighLabel;
            _highScoresLabels[4] = playerFiveHighLabel;
            GetStatistics();
        }

        private async void GetStatistics()
        {
            dynamic jsonRes = await Communicator.GetInstance().SendAndReceiveData((byte)Utils.Codes.GetStatistics);

            ParsePersonalStats(jsonRes);
            ParseHighScore(jsonRes);

        }

        private void ParseHighScore(dynamic jsonRes)
        {
            if (jsonRes.code == Utils.Codes.Success)
            {
                string[] highScores = ((string)jsonRes.highScores).Split(';');
                string[] playerNscore;
                int index = 0;
                foreach (string highScore in highScores)
                {
                    playerNscore = highScore.Split(',');
                    _highScoresLabels[index++].Text = playerNscore[0] + "    " + playerNscore[1];
                };
            }
            else
                MessageBox.Show(jsonRes.message.ToString());
        }

        private void ParsePersonalStats(dynamic jsonRes)
        {
            averageTimeLabel.Text +=    " " + jsonRes.averageTime;
            gamesCountLabel.Text +=     " " + jsonRes.games;
            totalQuestionsLabel.Text += " " + jsonRes.answers;
            pointsLabel.Text +=         " " + jsonRes.points;
            correctAnswersLabel.Text += " " + jsonRes.correctAnswers;
        }

        private async void LogOutButton_Click(object sender, EventArgs e)
        {
            dynamic data = await Communicator.GetInstance().SendAndReceiveData((byte)Utils.Codes.LogOut);

            if (data.code == Utils.Codes.Success)
            {
                Communicator.UserName = null;
                Utils.SwapForms<MainMenu, LogIn>(this);
            }
            else
                MessageBox.Show(data.message.ToString());
        }

        private void RoomMenu_Click(object sender, EventArgs e)
        {
            Utils.SwapForms<MainMenu, RoomMenu>(this);
        }
    }
}
