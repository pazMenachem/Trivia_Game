namespace ClientTrivia
{
    partial class CreateRoom
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
            this.RoomName = new System.Windows.Forms.TextBox();
            this.TimeQuestion = new System.Windows.Forms.TextBox();
            this.MaxUsers = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.CreateRoomButton = new System.Windows.Forms.Button();
            this.label5 = new System.Windows.Forms.Label();
            this.Questions = new System.Windows.Forms.TextBox();
            this.BackButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // RoomName
            // 
            this.RoomName.Location = new System.Drawing.Point(350, 171);
            this.RoomName.Name = "RoomName";
            this.RoomName.Size = new System.Drawing.Size(100, 22);
            this.RoomName.TabIndex = 0;
            // 
            // TimeQuestion
            // 
            this.TimeQuestion.Location = new System.Drawing.Point(350, 215);
            this.TimeQuestion.Name = "TimeQuestion";
            this.TimeQuestion.Size = new System.Drawing.Size(100, 22);
            this.TimeQuestion.TabIndex = 1;
            // 
            // MaxUsers
            // 
            this.MaxUsers.Location = new System.Drawing.Point(350, 258);
            this.MaxUsers.Name = "MaxUsers";
            this.MaxUsers.Size = new System.Drawing.Size(100, 22);
            this.MaxUsers.TabIndex = 2;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.label1.Location = new System.Drawing.Point(156, 171);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(130, 25);
            this.label1.TabIndex = 4;
            this.label1.Text = "Room Name";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.label2.Location = new System.Drawing.Point(116, 212);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(189, 25);
            this.label2.TabIndex = 5;
            this.label2.Text = "Time For Question";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.label3.Location = new System.Drawing.Point(155, 258);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(131, 25);
            this.label3.TabIndex = 6;
            this.label3.Text = "Max Players";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 36F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.label4.Location = new System.Drawing.Point(233, 66);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(311, 55);
            this.label4.TabIndex = 7;
            this.label4.Text = "Create Room";
            // 
            // CreateRoomButton
            // 
            this.CreateRoomButton.Location = new System.Drawing.Point(331, 355);
            this.CreateRoomButton.Name = "CreateRoomButton";
            this.CreateRoomButton.Size = new System.Drawing.Size(131, 23);
            this.CreateRoomButton.TabIndex = 8;
            this.CreateRoomButton.Text = "Create Room";
            this.CreateRoomButton.UseVisualStyleBackColor = true;
            this.CreateRoomButton.Click += new System.EventHandler(this.CreateRoomButton_Click);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.label5.Location = new System.Drawing.Point(101, 301);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(216, 25);
            this.label5.TabIndex = 9;
            this.label5.Text = "Amount Of Questions";
            // 
            // Questions
            // 
            this.Questions.Location = new System.Drawing.Point(350, 301);
            this.Questions.Name = "Questions";
            this.Questions.Size = new System.Drawing.Size(100, 22);
            this.Questions.TabIndex = 10;
            // 
            // BackButton
            // 
            this.BackButton.Location = new System.Drawing.Point(331, 401);
            this.BackButton.Margin = new System.Windows.Forms.Padding(2);
            this.BackButton.Name = "BackButton";
            this.BackButton.Size = new System.Drawing.Size(131, 25);
            this.BackButton.TabIndex = 11;
            this.BackButton.Text = "Back to Room Menu";
            this.BackButton.UseVisualStyleBackColor = true;
            this.BackButton.Click += new System.EventHandler(this.BackButton_Click);
            // 
            // CreateRoom
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.BackButton);
            this.Controls.Add(this.Questions);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.CreateRoomButton);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.MaxUsers);
            this.Controls.Add(this.TimeQuestion);
            this.Controls.Add(this.RoomName);
            this.Name = "CreateRoom";
            this.Text = "CreateRoom";
            this.Controls.SetChildIndex(this.RoomName, 0);
            this.Controls.SetChildIndex(this.TimeQuestion, 0);
            this.Controls.SetChildIndex(this.MaxUsers, 0);
            this.Controls.SetChildIndex(this.label1, 0);
            this.Controls.SetChildIndex(this.label2, 0);
            this.Controls.SetChildIndex(this.label3, 0);
            this.Controls.SetChildIndex(this.label4, 0);
            this.Controls.SetChildIndex(this.CreateRoomButton, 0);
            this.Controls.SetChildIndex(this.label5, 0);
            this.Controls.SetChildIndex(this.Questions, 0);
            this.Controls.SetChildIndex(this.BackButton, 0);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox RoomName;
        private System.Windows.Forms.TextBox TimeQuestion;
        private System.Windows.Forms.TextBox MaxUsers;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button CreateRoomButton;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox Questions;
        private System.Windows.Forms.Button BackButton;
    }
}