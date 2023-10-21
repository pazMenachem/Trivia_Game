namespace ClientTrivia
{
    partial class RoomMenu
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
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle1 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle2 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle3 = new System.Windows.Forms.DataGridViewCellStyle();
            this.RoomListTitle = new System.Windows.Forms.Label();
            this.CreateRoomButton = new System.Windows.Forms.Button();
            this.enter = new System.Windows.Forms.Button();
            this.backMenu = new System.Windows.Forms.Button();
            this.RoomList = new System.Windows.Forms.DataGridView();
            this.RoomName = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Questions = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Time = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Players = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Creator = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.RefreshButton = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.RoomList)).BeginInit();
            this.SuspendLayout();
            // 
            // RoomListTitle
            // 
            this.RoomListTitle.AutoSize = true;
            this.RoomListTitle.BackColor = System.Drawing.Color.Transparent;
            this.RoomListTitle.Font = new System.Drawing.Font("Microsoft Sans Serif", 31.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.RoomListTitle.Location = new System.Drawing.Point(319, 90);
            this.RoomListTitle.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.RoomListTitle.Name = "RoomListTitle";
            this.RoomListTitle.Size = new System.Drawing.Size(272, 61);
            this.RoomListTitle.TabIndex = 1;
            this.RoomListTitle.Text = "Room List";
            this.RoomListTitle.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // CreateRoomButton
            // 
            this.CreateRoomButton.BackColor = System.Drawing.SystemColors.Control;
            this.CreateRoomButton.Location = new System.Drawing.Point(149, 416);
            this.CreateRoomButton.Margin = new System.Windows.Forms.Padding(4);
            this.CreateRoomButton.Name = "CreateRoomButton";
            this.CreateRoomButton.Size = new System.Drawing.Size(177, 28);
            this.CreateRoomButton.TabIndex = 2;
            this.CreateRoomButton.Text = "Create Room";
            this.CreateRoomButton.UseVisualStyleBackColor = false;
            this.CreateRoomButton.Click += new System.EventHandler(this.CreateRoomButton_Click);
            // 
            // enter
            // 
            this.enter.Location = new System.Drawing.Point(652, 416);
            this.enter.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.enter.Name = "enter";
            this.enter.Size = new System.Drawing.Size(177, 28);
            this.enter.TabIndex = 4;
            this.enter.Text = "Enter Room";
            this.enter.UseVisualStyleBackColor = true;
            this.enter.Click += new System.EventHandler(this.enter_Click);
            // 
            // backMenu
            // 
            this.backMenu.Location = new System.Drawing.Point(800, 482);
            this.backMenu.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.backMenu.Name = "backMenu";
            this.backMenu.Size = new System.Drawing.Size(117, 42);
            this.backMenu.TabIndex = 5;
            this.backMenu.Text = "Back to Menu";
            this.backMenu.UseVisualStyleBackColor = true;
            this.backMenu.Click += new System.EventHandler(this.backMenu_Click);
            // 
            // RoomList
            // 
            this.RoomList.AllowUserToAddRows = false;
            this.RoomList.AllowUserToDeleteRows = false;
            this.RoomList.AllowUserToResizeColumns = false;
            this.RoomList.AllowUserToResizeRows = false;
            dataGridViewCellStyle1.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;
            dataGridViewCellStyle1.BackColor = System.Drawing.Color.DarkSeaGreen;
            this.RoomList.AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
            this.RoomList.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.RoomList.BackgroundColor = System.Drawing.Color.DarkSeaGreen;
            this.RoomList.ClipboardCopyMode = System.Windows.Forms.DataGridViewClipboardCopyMode.EnableAlwaysIncludeHeaderText;
            this.RoomList.ColumnHeadersBorderStyle = System.Windows.Forms.DataGridViewHeaderBorderStyle.None;
            dataGridViewCellStyle2.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;
            dataGridViewCellStyle2.BackColor = System.Drawing.Color.DarkSeaGreen;
            dataGridViewCellStyle2.ForeColor = System.Drawing.SystemColors.WindowText;
            dataGridViewCellStyle2.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle2.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle2.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.RoomList.ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
            this.RoomList.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.RoomList.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.RoomName,
            this.Questions,
            this.Time,
            this.Players,
            this.Creator});
            this.RoomList.EnableHeadersVisualStyles = false;
            this.RoomList.GridColor = System.Drawing.Color.DarkSeaGreen;
            this.RoomList.Location = new System.Drawing.Point(101, 167);
            this.RoomList.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.RoomList.MultiSelect = false;
            this.RoomList.Name = "RoomList";
            this.RoomList.ReadOnly = true;
            this.RoomList.RowHeadersVisible = false;
            this.RoomList.RowHeadersWidth = 51;
            this.RoomList.RowTemplate.DefaultCellStyle.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;
            this.RoomList.RowTemplate.DefaultCellStyle.BackColor = System.Drawing.Color.DarkSeaGreen;
            this.RoomList.RowTemplate.Height = 24;
            this.RoomList.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.RoomList.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.RoomList.Size = new System.Drawing.Size(797, 220);
            this.RoomList.TabIndex = 7;
            // 
            // RoomName
            // 
            this.RoomName.HeaderText = "Room Name";
            this.RoomName.MinimumWidth = 6;
            this.RoomName.Name = "RoomName";
            this.RoomName.ReadOnly = true;
            // 
            // Questions
            // 
            this.Questions.HeaderText = "Questions";
            this.Questions.MinimumWidth = 6;
            this.Questions.Name = "Questions";
            this.Questions.ReadOnly = true;
            // 
            // Time
            // 
            dataGridViewCellStyle3.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.Time.DefaultCellStyle = dataGridViewCellStyle3;
            this.Time.HeaderText = "Seconds Per Question";
            this.Time.MinimumWidth = 6;
            this.Time.Name = "Time";
            this.Time.ReadOnly = true;
            // 
            // Players
            // 
            this.Players.HeaderText = "Players";
            this.Players.MinimumWidth = 6;
            this.Players.Name = "Players";
            this.Players.ReadOnly = true;
            // 
            // Creator
            // 
            this.Creator.HeaderText = "Room Creator";
            this.Creator.MinimumWidth = 6;
            this.Creator.Name = "Creator";
            this.Creator.ReadOnly = true;
            // 
            // RefreshButton
            // 
            this.RefreshButton.BackColor = System.Drawing.SystemColors.Control;
            this.RefreshButton.Location = new System.Drawing.Point(398, 416);
            this.RefreshButton.Margin = new System.Windows.Forms.Padding(4);
            this.RefreshButton.Name = "RefreshButton";
            this.RefreshButton.Size = new System.Drawing.Size(177, 28);
            this.RefreshButton.TabIndex = 8;
            this.RefreshButton.Text = "Refresh Room Menu";
            this.RefreshButton.UseVisualStyleBackColor = false;
            this.RefreshButton.Click += new System.EventHandler(this.RefreshRoomButton_Click);
            // 
            // RoomMenu
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Control;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.ClientSize = new System.Drawing.Size(1141, 554);
            this.Controls.Add(this.RefreshButton);
            this.Controls.Add(this.RoomList);
            this.Controls.Add(this.backMenu);
            this.Controls.Add(this.enter);
            this.Controls.Add(this.CreateRoomButton);
            this.Controls.Add(this.RoomListTitle);
            this.Cursor = System.Windows.Forms.Cursors.Arrow;
            this.Margin = new System.Windows.Forms.Padding(5);
            this.Name = "RoomMenu";
            this.Text = "JoinRoom";
            this.Controls.SetChildIndex(this.RoomListTitle, 0);
            this.Controls.SetChildIndex(this.CreateRoomButton, 0);
            this.Controls.SetChildIndex(this.enter, 0);
            this.Controls.SetChildIndex(this.backMenu, 0);
            this.Controls.SetChildIndex(this.RoomList, 0);
            this.Controls.SetChildIndex(this.RefreshButton, 0);
            ((System.ComponentModel.ISupportInitialize)(this.RoomList)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label RoomListTitle;
        private System.Windows.Forms.Button CreateRoomButton;
        private System.Windows.Forms.Button enter;
        private System.Windows.Forms.Button backMenu;
        private System.Windows.Forms.DataGridView RoomList;
        private System.Windows.Forms.DataGridViewTextBoxColumn RoomName;
        private System.Windows.Forms.DataGridViewTextBoxColumn Questions;
        private System.Windows.Forms.DataGridViewTextBoxColumn Time;
        private System.Windows.Forms.DataGridViewTextBoxColumn Players;
        private System.Windows.Forms.DataGridViewTextBoxColumn Creator;
        private System.Windows.Forms.Button RefreshButton;
    }
}