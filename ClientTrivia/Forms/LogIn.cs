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

namespace ClientTrivia
{
    public partial class LogIn : CustomForm
    {
        public LogIn()
        {
            InitializeComponent();
            ApplyCustomFont();
        }

        private async void LogInButton_Click(object sender, EventArgs e)
        {
            if (!Utils.CheckForFields(this.UserName.Text, this.Password.Text))
            {
                Utils.FillAllFieldsAlert();
                return;
            }

            var jsonData = new
            {
                userName = this.UserName.Text,
                password = this.Password.Text
            };
            dynamic dataRes = await Communicator.GetInstance().SendAndReceiveData((byte)Utils.Codes.LogIn, jsonData);
            
            if (dataRes.code == Utils.Codes.Success)
            {
                Communicator.UserName = jsonData.userName;
                Utils.SwapForms<LogIn, MainMenu>(this);
            }
            else
                MessageBox.Show(dataRes.message.ToString());
        }

        private void ToSignUp_Click(object sender, EventArgs e)
        {
            Utils.SwapForms<LogIn, SignUp>(this);
        }
    }
}
