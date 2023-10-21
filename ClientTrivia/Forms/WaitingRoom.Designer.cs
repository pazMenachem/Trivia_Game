namespace ClientTrivia.Forms
{
    partial class WaitingRoom
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
            this.WaitingRoomTitle = new System.Windows.Forms.Label();
            this.ListPlayers = new System.Windows.Forms.ListView();
            this.PlayersLabel = new System.Windows.Forms.Label();
            this.ChatWindow = new System.Windows.Forms.ListView();
            this.label1 = new System.Windows.Forms.Label();
            this.StartGameButton = new System.Windows.Forms.Button();
            this.TextQuestions = new System.Windows.Forms.TextBox();
            this.TextTime = new System.Windows.Forms.TextBox();
            this.TextPlayers = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.TextName = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.GoBackButton = new System.Windows.Forms.Button();
            this.MessageBox = new System.Windows.Forms.TextBox();
            this.MessageButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // WaitingRoomTitle
            // 
            this.WaitingRoomTitle.AutoSize = true;
            this.WaitingRoomTitle.Font = new System.Drawing.Font("Microsoft Sans Serif", 36F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.WaitingRoomTitle.Location = new System.Drawing.Point(288, 58);
            this.WaitingRoomTitle.Name = "WaitingRoomTitle";
            this.WaitingRoomTitle.Size = new System.Drawing.Size(406, 69);
            this.WaitingRoomTitle.TabIndex = 0;
            this.WaitingRoomTitle.Text = "Waiting Room";
            // 
            // ListPlayers
            // 
            this.ListPlayers.HideSelection = false;
            this.ListPlayers.Location = new System.Drawing.Point(93, 138);
            this.ListPlayers.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.ListPlayers.Name = "ListPlayers";
            this.ListPlayers.Size = new System.Drawing.Size(157, 246);
            this.ListPlayers.TabIndex = 1;
            this.ListPlayers.UseCompatibleStateImageBehavior = false;
            // 
            // PlayersLabel
            // 
            this.PlayersLabel.AutoSize = true;
            this.PlayersLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.PlayersLabel.Location = new System.Drawing.Point(71, 92);
            this.PlayersLabel.Name = "PlayersLabel";
            this.PlayersLabel.Size = new System.Drawing.Size(77, 25);
            this.PlayersLabel.TabIndex = 2;
            this.PlayersLabel.Text = "Players";
            // 
            // ChatWindow
            // 
            this.ChatWindow.HideSelection = false;
            this.ChatWindow.Location = new System.Drawing.Point(792, 138);
            this.ChatWindow.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.ChatWindow.Name = "ChatWindow";
            this.ChatWindow.Size = new System.Drawing.Size(167, 246);
            this.ChatWindow.TabIndex = 3;
            this.ChatWindow.UseCompatibleStateImageBehavior = false;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.label1.Location = new System.Drawing.Point(819, 101);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(110, 25);
            this.label1.TabIndex = 4;
            this.label1.Text = "Room Chat";
            // 
            // StartGameButton
            // 
            this.StartGameButton.Location = new System.Drawing.Point(440, 375);
            this.StartGameButton.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.StartGameButton.Name = "StartGameButton";
            this.StartGameButton.Size = new System.Drawing.Size(136, 36);
            this.StartGameButton.TabIndex = 5;
            this.StartGameButton.Text = "Start Game!";
            this.StartGameButton.UseVisualStyleBackColor = true;
            this.StartGameButton.Visible = false;
            this.StartGameButton.Click += new System.EventHandler(this.StartGameButton_Click);
            // 
            // TextQuestions
            // 
            this.TextQuestions.Location = new System.Drawing.Point(565, 238);
            this.TextQuestions.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.TextQuestions.Name = "TextQuestions";
            this.TextQuestions.ReadOnly = true;
            this.TextQuestions.Size = new System.Drawing.Size(39, 22);
            this.TextQuestions.TabIndex = 6;
            // 
            // TextTime
            // 
            this.TextTime.Location = new System.Drawing.Point(565, 293);
            this.TextTime.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.TextTime.Name = "TextTime";
            this.TextTime.ReadOnly = true;
            this.TextTime.Size = new System.Drawing.Size(39, 22);
            this.TextTime.TabIndex = 7;
            // 
            // TextPlayers
            // 
            this.TextPlayers.Location = new System.Drawing.Point(179, 92);
            this.TextPlayers.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.TextPlayers.Name = "TextPlayers";
            this.TextPlayers.ReadOnly = true;
            this.TextPlayers.Size = new System.Drawing.Size(39, 22);
            this.TextPlayers.TabIndex = 8;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.label2.Location = new System.Drawing.Point(296, 238);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(201, 25);
            this.label2.TabIndex = 10;
            this.label2.Text = "Number Of Questions";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.label3.Location = new System.Drawing.Point(296, 295);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(209, 25);
            this.label3.TabIndex = 11;
            this.label3.Text = "Seconds Per Question";
            // 
            // TextName
            // 
            this.TextName.Location = new System.Drawing.Point(533, 178);
            this.TextName.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.TextName.Name = "TextName";
            this.TextName.ReadOnly = true;
            this.TextName.Size = new System.Drawing.Size(93, 22);
            this.TextName.TabIndex = 12;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.label4.Location = new System.Drawing.Point(361, 178);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(120, 25);
            this.label4.TabIndex = 13;
            this.label4.Text = "Room Name";
            // 
            // GoBackButton
            // 
            this.GoBackButton.Location = new System.Drawing.Point(440, 453);
            this.GoBackButton.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.GoBackButton.Name = "GoBackButton";
            this.GoBackButton.Size = new System.Drawing.Size(136, 37);
            this.GoBackButton.TabIndex = 14;
            this.GoBackButton.Text = "Leave Room";
            this.GoBackButton.UseVisualStyleBackColor = true;
            this.GoBackButton.Click += new System.EventHandler(this.GoBackButton_Click);
            // 
            // MessageBox
            // 
            this.MessageBox.Location = new System.Drawing.Point(748, 417);
            this.MessageBox.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.MessageBox.MinimumSize = new System.Drawing.Size(4, 60);
            this.MessageBox.Name = "MessageBox";
            this.MessageBox.Size = new System.Drawing.Size(265, 22);
            this.MessageBox.TabIndex = 15;
            // 
            // MessageButton
            // 
            this.MessageButton.Location = new System.Drawing.Point(808, 513);
            this.MessageButton.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.MessageButton.Name = "MessageButton";
            this.MessageButton.Size = new System.Drawing.Size(131, 28);
            this.MessageButton.TabIndex = 16;
            this.MessageButton.Text = "Send Message";
            this.MessageButton.UseVisualStyleBackColor = true;
            this.MessageButton.Click += new System.EventHandler(this.MessageButton_Click);
            // 
            // WaitingRoom
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1045, 567);
            this.Controls.Add(this.MessageButton);
            this.Controls.Add(this.MessageBox);
            this.Controls.Add(this.GoBackButton);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.TextName);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.TextPlayers);
            this.Controls.Add(this.TextTime);
            this.Controls.Add(this.TextQuestions);
            this.Controls.Add(this.StartGameButton);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.ChatWindow);
            this.Controls.Add(this.PlayersLabel);
            this.Controls.Add(this.ListPlayers);
            this.Controls.Add(this.WaitingRoomTitle);
            this.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.Name = "WaitingRoom";
            this.Text = "WaitingRoom";
            this.Controls.SetChildIndex(this.WaitingRoomTitle, 0);
            this.Controls.SetChildIndex(this.ListPlayers, 0);
            this.Controls.SetChildIndex(this.PlayersLabel, 0);
            this.Controls.SetChildIndex(this.ChatWindow, 0);
            this.Controls.SetChildIndex(this.label1, 0);
            this.Controls.SetChildIndex(this.StartGameButton, 0);
            this.Controls.SetChildIndex(this.TextQuestions, 0);
            this.Controls.SetChildIndex(this.TextTime, 0);
            this.Controls.SetChildIndex(this.TextPlayers, 0);
            this.Controls.SetChildIndex(this.label2, 0);
            this.Controls.SetChildIndex(this.label3, 0);
            this.Controls.SetChildIndex(this.TextName, 0);
            this.Controls.SetChildIndex(this.label4, 0);
            this.Controls.SetChildIndex(this.GoBackButton, 0);
            this.Controls.SetChildIndex(this.MessageBox, 0);
            this.Controls.SetChildIndex(this.MessageButton, 0);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label WaitingRoomTitle;
        private System.Windows.Forms.ListView ListPlayers;
        private System.Windows.Forms.Label PlayersLabel;
        private System.Windows.Forms.ListView ChatWindow;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button StartGameButton;
        private System.Windows.Forms.TextBox TextQuestions;
        private System.Windows.Forms.TextBox TextTime;
        private System.Windows.Forms.TextBox TextPlayers;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox TextName;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button GoBackButton;
        private System.Windows.Forms.TextBox MessageBox;
        private System.Windows.Forms.Button MessageButton;
    }
}