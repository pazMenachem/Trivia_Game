using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Text;
using System.Linq;
using System.Reflection.Emit;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ClientTrivia
{
    public partial class SignUp : CustomForm
    {
        public SignUp()
        {
            InitializeComponent();
            ApplyCustomFont();
        }

        private async void  SignUpButton_Click(object sender, EventArgs e)
        {
            if (!Utils.CheckForFields(this.UserName.Text, this.Password.Text, this.Email.Text))
            {
                Utils.FillAllFieldsAlert();
                return;
            }

            var jsonData = new
            {
                userName = this.UserName.Text,
                password = this.Password.Text,
                email = this.Email.Text
            };
            
            dynamic data = await Communicator.GetInstance().SendAndReceiveData((byte)Utils.Codes.SignUp,
                                                                         jsonData);

            if (data.code == Utils.Codes.Success)
                Utils.SwapForms<SignUp, LogIn>(this);
            else
                MessageBox.Show(data.message.ToString());
        }

        private void LogInLinkButton(object sender, EventArgs e)
        {
            Utils.SwapForms<SignUp, LogIn>(this);
        }
    }
}
