using ClientTrivia.Properties;

namespace ClientTrivia
{
    partial class CustomForm
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
            this.BackGroundAnimation = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.BackGroundAnimation)).BeginInit();
            this.SuspendLayout();
            // 
            // BackGroundAnimation
            // 
            this.BackGroundAnimation.Dock = System.Windows.Forms.DockStyle.Fill;
            this.BackGroundAnimation.Image = global::ClientTrivia.Properties.Resources.LogInSignUpbackground;
            this.BackGroundAnimation.Location = new System.Drawing.Point(0, 0);
            this.BackGroundAnimation.Name = "BackGroundAnimation";
            this.BackGroundAnimation.Size = new System.Drawing.Size(784, 461);
            this.BackGroundAnimation.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.BackGroundAnimation.TabIndex = 0;
            this.BackGroundAnimation.TabStop = false;
            this.BackGroundAnimation.SendToBack();
            // 
            // CustomForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(784, 461);
            this.Controls.Add(this.BackGroundAnimation);
            this.Name = "CustomForm";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.BackGroundAnimation)).EndInit();
            this.ResumeLayout(false);
        }

        #endregion

        private System.Windows.Forms.PictureBox BackGroundAnimation;
    }
}