namespace ClientTrivia.Forms
{
    partial class GameWindow
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.QuestionLabel = new System.Windows.Forms.Label();
            this.AnswerOneLabel = new System.Windows.Forms.Label();
            this.AnswerThreeLabel = new System.Windows.Forms.Label();
            this.AnswerTwoLabel = new System.Windows.Forms.Label();
            this.AnswerFourLabel = new System.Windows.Forms.Label();
            this.LeaveGameButton = new System.Windows.Forms.Button();
            this.SendAnswerButton = new System.Windows.Forms.Button();
            this.RoomNameLabel = new System.Windows.Forms.Label();
            this.QuestionTimer = new System.Windows.Forms.Timer(this.components);
            this.TimeLeftLabel = new System.Windows.Forms.Label();
            this.TimeLabel = new System.Windows.Forms.Label();
            this.radioButton1 = new System.Windows.Forms.RadioButton();
            this.radioButton2 = new System.Windows.Forms.RadioButton();
            this.radioButton3 = new System.Windows.Forms.RadioButton();
            this.radioButton4 = new System.Windows.Forms.RadioButton();
            this.PlayerPointsLabel1 = new System.Windows.Forms.Label();
            this.PlayerPointsLabel2 = new System.Windows.Forms.Label();
            this.PlayerPointsLabel3 = new System.Windows.Forms.Label();
            this.PlayerPointsLabel4 = new System.Windows.Forms.Label();
            this.PointsLabel = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // QuestionLabel
            // 
            this.QuestionLabel.AutoSize = true;
            this.QuestionLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.QuestionLabel.Location = new System.Drawing.Point(136, 77);
            this.QuestionLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.QuestionLabel.Name = "QuestionLabel";
            this.QuestionLabel.Size = new System.Drawing.Size(142, 36);
            this.QuestionLabel.TabIndex = 0;
            this.QuestionLabel.Text = "Question ";
            // 
            // AnswerOneLabel
            // 
            this.AnswerOneLabel.AutoSize = true;
            this.AnswerOneLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.AnswerOneLabel.Location = new System.Drawing.Point(123, 127);
            this.AnswerOneLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.AnswerOneLabel.Name = "AnswerOneLabel";
            this.AnswerOneLabel.Size = new System.Drawing.Size(145, 29);
            this.AnswerOneLabel.TabIndex = 1;
            this.AnswerOneLabel.Text = "Answer One";
            // 
            // AnswerThreeLabel
            // 
            this.AnswerThreeLabel.AutoSize = true;
            this.AnswerThreeLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.AnswerThreeLabel.Location = new System.Drawing.Point(504, 127);
            this.AnswerThreeLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.AnswerThreeLabel.Name = "AnswerThreeLabel";
            this.AnswerThreeLabel.Size = new System.Drawing.Size(164, 29);
            this.AnswerThreeLabel.TabIndex = 2;
            this.AnswerThreeLabel.Text = "Answer Three";
            // 
            // AnswerTwoLabel
            // 
            this.AnswerTwoLabel.AutoSize = true;
            this.AnswerTwoLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.AnswerTwoLabel.Location = new System.Drawing.Point(131, 254);
            this.AnswerTwoLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.AnswerTwoLabel.Name = "AnswerTwoLabel";
            this.AnswerTwoLabel.Size = new System.Drawing.Size(147, 29);
            this.AnswerTwoLabel.TabIndex = 3;
            this.AnswerTwoLabel.Text = "Answer Two";
            // 
            // AnswerFourLabel
            // 
            this.AnswerFourLabel.AutoSize = true;
            this.AnswerFourLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.AnswerFourLabel.Location = new System.Drawing.Point(519, 254);
            this.AnswerFourLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.AnswerFourLabel.Name = "AnswerFourLabel";
            this.AnswerFourLabel.Size = new System.Drawing.Size(149, 29);
            this.AnswerFourLabel.TabIndex = 4;
            this.AnswerFourLabel.Text = "Answer Four";
            // 
            // LeaveGameButton
            // 
            this.LeaveGameButton.Location = new System.Drawing.Point(901, 463);
            this.LeaveGameButton.Margin = new System.Windows.Forms.Padding(4);
            this.LeaveGameButton.Name = "LeaveGameButton";
            this.LeaveGameButton.Size = new System.Drawing.Size(135, 62);
            this.LeaveGameButton.TabIndex = 5;
            this.LeaveGameButton.Text = "Leave Game";
            this.LeaveGameButton.UseVisualStyleBackColor = true;
            this.LeaveGameButton.Click += new System.EventHandler(this.LeaveGameButton_Click);
            // 
            // SendAnswerButton
            // 
            this.SendAnswerButton.Location = new System.Drawing.Point(611, 370);
            this.SendAnswerButton.Margin = new System.Windows.Forms.Padding(4);
            this.SendAnswerButton.Name = "SendAnswerButton";
            this.SendAnswerButton.Size = new System.Drawing.Size(153, 71);
            this.SendAnswerButton.TabIndex = 6;
            this.SendAnswerButton.Text = "Send Answer";
            this.SendAnswerButton.UseVisualStyleBackColor = true;
            this.SendAnswerButton.Click += new System.EventHandler(this.SendAnswerButton_Click);
            // 
            // RoomNameLabel
            // 
            this.RoomNameLabel.AutoSize = true;
            this.RoomNameLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.RoomNameLabel.Location = new System.Drawing.Point(454, 21);
            this.RoomNameLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.RoomNameLabel.Name = "RoomNameLabel";
            this.RoomNameLabel.Size = new System.Drawing.Size(149, 29);
            this.RoomNameLabel.TabIndex = 7;
            this.RoomNameLabel.Text = "Room Name";
            // 
            // QuestionTimer
            // 
            this.QuestionTimer.Interval = 1000;
            // 
            // TimeLeftLabel
            // 
            this.TimeLeftLabel.AutoSize = true;
            this.TimeLeftLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.TimeLeftLabel.Location = new System.Drawing.Point(393, 360);
            this.TimeLeftLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.TimeLeftLabel.Name = "TimeLeftLabel";
            this.TimeLeftLabel.Size = new System.Drawing.Size(114, 29);
            this.TimeLeftLabel.TabIndex = 8;
            this.TimeLeftLabel.Text = "Time Left";
            // 
            // TimeLabel
            // 
            this.TimeLabel.AutoSize = true;
            this.TimeLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.TimeLabel.Location = new System.Drawing.Point(429, 409);
            this.TimeLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.TimeLabel.Name = "TimeLabel";
            this.TimeLabel.Size = new System.Drawing.Size(30, 32);
            this.TimeLabel.TabIndex = 9;
            this.TimeLabel.Text = "0";
            // 
            // radioButton1
            // 
            this.radioButton1.AutoSize = true;
            this.radioButton1.Location = new System.Drawing.Point(165, 160);
            this.radioButton1.Margin = new System.Windows.Forms.Padding(4);
            this.radioButton1.Name = "radioButton1";
            this.radioButton1.Size = new System.Drawing.Size(103, 20);
            this.radioButton1.TabIndex = 10;
            this.radioButton1.TabStop = true;
            this.radioButton1.Text = "radioButton1";
            this.radioButton1.UseVisualStyleBackColor = true;
            this.radioButton1.CheckedChanged += new System.EventHandler(this.radioButton1_CheckedChanged);
            // 
            // radioButton2
            // 
            this.radioButton2.AutoSize = true;
            this.radioButton2.Location = new System.Drawing.Point(175, 287);
            this.radioButton2.Margin = new System.Windows.Forms.Padding(4);
            this.radioButton2.Name = "radioButton2";
            this.radioButton2.Size = new System.Drawing.Size(103, 20);
            this.radioButton2.TabIndex = 11;
            this.radioButton2.TabStop = true;
            this.radioButton2.Text = "radioButton2";
            this.radioButton2.UseVisualStyleBackColor = true;
            this.radioButton2.CheckedChanged += new System.EventHandler(this.radioButton2_CheckedChanged);
            // 
            // radioButton3
            // 
            this.radioButton3.AutoSize = true;
            this.radioButton3.Location = new System.Drawing.Point(565, 160);
            this.radioButton3.Margin = new System.Windows.Forms.Padding(4);
            this.radioButton3.Name = "radioButton3";
            this.radioButton3.Size = new System.Drawing.Size(103, 20);
            this.radioButton3.TabIndex = 12;
            this.radioButton3.TabStop = true;
            this.radioButton3.Text = "radioButton3";
            this.radioButton3.UseVisualStyleBackColor = true;
            this.radioButton3.CheckedChanged += new System.EventHandler(this.radioButton3_CheckedChanged);
            // 
            // radioButton4
            // 
            this.radioButton4.AutoSize = true;
            this.radioButton4.Location = new System.Drawing.Point(565, 287);
            this.radioButton4.Margin = new System.Windows.Forms.Padding(4);
            this.radioButton4.Name = "radioButton4";
            this.radioButton4.Size = new System.Drawing.Size(103, 20);
            this.radioButton4.TabIndex = 13;
            this.radioButton4.TabStop = true;
            this.radioButton4.Text = "radioButton4";
            this.radioButton4.UseVisualStyleBackColor = true;
            this.radioButton4.CheckedChanged += new System.EventHandler(this.radioButton4_CheckedChanged);
            // 
            // PlayerPointsLabel1
            // 
            this.PlayerPointsLabel1.AutoSize = true;
            this.PlayerPointsLabel1.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.PlayerPointsLabel1.Location = new System.Drawing.Point(15, 358);
            this.PlayerPointsLabel1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.PlayerPointsLabel1.Name = "PlayerPointsLabel1";
            this.PlayerPointsLabel1.Size = new System.Drawing.Size(243, 32);
            this.PlayerPointsLabel1.TabIndex = 15;
            this.PlayerPointsLabel1.Text = "Player One Points";
            this.PlayerPointsLabel1.Visible = false;
            // 
            // PlayerPointsLabel2
            // 
            this.PlayerPointsLabel2.AutoSize = true;
            this.PlayerPointsLabel2.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.PlayerPointsLabel2.Location = new System.Drawing.Point(16, 406);
            this.PlayerPointsLabel2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.PlayerPointsLabel2.Name = "PlayerPointsLabel2";
            this.PlayerPointsLabel2.Size = new System.Drawing.Size(242, 32);
            this.PlayerPointsLabel2.TabIndex = 16;
            this.PlayerPointsLabel2.Text = "Player Two Points";
            this.PlayerPointsLabel2.Visible = false;
            // 
            // PlayerPointsLabel3
            // 
            this.PlayerPointsLabel3.AutoSize = true;
            this.PlayerPointsLabel3.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.PlayerPointsLabel3.Location = new System.Drawing.Point(15, 452);
            this.PlayerPointsLabel3.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.PlayerPointsLabel3.Name = "PlayerPointsLabel3";
            this.PlayerPointsLabel3.Size = new System.Drawing.Size(263, 32);
            this.PlayerPointsLabel3.TabIndex = 17;
            this.PlayerPointsLabel3.Text = "Player Three Points";
            this.PlayerPointsLabel3.Visible = false;
            // 
            // PlayerPointsLabel4
            // 
            this.PlayerPointsLabel4.AutoSize = true;
            this.PlayerPointsLabel4.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.PlayerPointsLabel4.Location = new System.Drawing.Point(11, 503);
            this.PlayerPointsLabel4.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.PlayerPointsLabel4.Name = "PlayerPointsLabel4";
            this.PlayerPointsLabel4.Size = new System.Drawing.Size(247, 32);
            this.PlayerPointsLabel4.TabIndex = 18;
            this.PlayerPointsLabel4.Text = "Player Four Points";
            this.PlayerPointsLabel4.Visible = false;
            // 
            // PointsLabel
            // 
            this.PointsLabel.AutoSize = true;
            this.PointsLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.PointsLabel.Location = new System.Drawing.Point(94, 313);
            this.PointsLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.PointsLabel.Name = "PointsLabel";
            this.PointsLabel.Size = new System.Drawing.Size(80, 29);
            this.PointsLabel.TabIndex = 19;
            this.PointsLabel.Text = "Points";
            // 
            // GameWindow
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1067, 554);
            this.Controls.Add(this.PointsLabel);
            this.Controls.Add(this.PlayerPointsLabel4);
            this.Controls.Add(this.PlayerPointsLabel3);
            this.Controls.Add(this.PlayerPointsLabel2);
            this.Controls.Add(this.PlayerPointsLabel1);
            this.Controls.Add(this.radioButton4);
            this.Controls.Add(this.radioButton3);
            this.Controls.Add(this.radioButton2);
            this.Controls.Add(this.radioButton1);
            this.Controls.Add(this.TimeLabel);
            this.Controls.Add(this.TimeLeftLabel);
            this.Controls.Add(this.RoomNameLabel);
            this.Controls.Add(this.SendAnswerButton);
            this.Controls.Add(this.LeaveGameButton);
            this.Controls.Add(this.AnswerFourLabel);
            this.Controls.Add(this.AnswerTwoLabel);
            this.Controls.Add(this.AnswerThreeLabel);
            this.Controls.Add(this.AnswerOneLabel);
            this.Controls.Add(this.QuestionLabel);
            this.Margin = new System.Windows.Forms.Padding(5);
            this.Name = "GameWindow";
            this.Text = "GameWindow";
            this.Controls.SetChildIndex(this.QuestionLabel, 0);
            this.Controls.SetChildIndex(this.AnswerOneLabel, 0);
            this.Controls.SetChildIndex(this.AnswerThreeLabel, 0);
            this.Controls.SetChildIndex(this.AnswerTwoLabel, 0);
            this.Controls.SetChildIndex(this.AnswerFourLabel, 0);
            this.Controls.SetChildIndex(this.LeaveGameButton, 0);
            this.Controls.SetChildIndex(this.SendAnswerButton, 0);
            this.Controls.SetChildIndex(this.RoomNameLabel, 0);
            this.Controls.SetChildIndex(this.TimeLeftLabel, 0);
            this.Controls.SetChildIndex(this.TimeLabel, 0);
            this.Controls.SetChildIndex(this.radioButton1, 0);
            this.Controls.SetChildIndex(this.radioButton2, 0);
            this.Controls.SetChildIndex(this.radioButton3, 0);
            this.Controls.SetChildIndex(this.radioButton4, 0);
            this.Controls.SetChildIndex(this.PlayerPointsLabel1, 0);
            this.Controls.SetChildIndex(this.PlayerPointsLabel2, 0);
            this.Controls.SetChildIndex(this.PlayerPointsLabel3, 0);
            this.Controls.SetChildIndex(this.PlayerPointsLabel4, 0);
            this.Controls.SetChildIndex(this.PointsLabel, 0);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label QuestionLabel;
        private System.Windows.Forms.Label AnswerOneLabel;
        private System.Windows.Forms.Label AnswerThreeLabel;
        private System.Windows.Forms.Label AnswerTwoLabel;
        private System.Windows.Forms.Label AnswerFourLabel;
        private System.Windows.Forms.Button LeaveGameButton;
        private System.Windows.Forms.Button SendAnswerButton;
        private System.Windows.Forms.Label RoomNameLabel;
        private System.Windows.Forms.Timer QuestionTimer;
        private System.Windows.Forms.Label TimeLeftLabel;
        private System.Windows.Forms.Label TimeLabel;
        private System.Windows.Forms.RadioButton radioButton1;
        private System.Windows.Forms.RadioButton radioButton2;
        private System.Windows.Forms.RadioButton radioButton3;
        private System.Windows.Forms.RadioButton radioButton4;
        private System.Windows.Forms.Label PlayerPointsLabel1;
        private System.Windows.Forms.Label PlayerPointsLabel2;
        private System.Windows.Forms.Label PlayerPointsLabel3;
        private System.Windows.Forms.Label PlayerPointsLabel4;
        private System.Windows.Forms.Label PointsLabel;
    }
}