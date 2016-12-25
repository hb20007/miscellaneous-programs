/// <file>
/// <author>Hanna Sababa</author>
/// <datecreated>2016-11-07</datecreated>
/// <summary>
/// Countains the part of the class SeferBookstoreSplashScreen with the visual aspects of the form
/// </summary>
/// </file>

namespace SeferBookstore
{
    partial class SeferBookStoreSplashScreen
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
            if (disposing && (this.components != null))
            {
                this.components.Dispose();
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
            this.splashScreenMainLabel = new System.Windows.Forms.Label();
            this.splashFormVersionLabel = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // splashScreenMainLabel
            // 
            this.splashScreenMainLabel.AutoSize = true;
            this.splashScreenMainLabel.BackColor = System.Drawing.Color.Transparent;
            this.splashScreenMainLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.splashScreenMainLabel.ForeColor = System.Drawing.SystemColors.Info;
            this.splashScreenMainLabel.Location = new System.Drawing.Point(4, 12);
            this.splashScreenMainLabel.Name = "splashScreenMainLabel";
            this.splashScreenMainLabel.Size = new System.Drawing.Size(241, 18);
            this.splashScreenMainLabel.TabIndex = 0;
            this.splashScreenMainLabel.Text = "Application name and company";
            // 
            // splashFormVersionLabel
            // 
            this.splashFormVersionLabel.AutoSize = true;
            this.splashFormVersionLabel.BackColor = System.Drawing.Color.Transparent;
            this.splashFormVersionLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.splashFormVersionLabel.ForeColor = System.Drawing.SystemColors.Info;
            this.splashFormVersionLabel.Location = new System.Drawing.Point(262, 35);
            this.splashFormVersionLabel.Name = "splashFormVersionLabel";
            this.splashFormVersionLabel.Size = new System.Drawing.Size(112, 18);
            this.splashFormVersionLabel.TabIndex = 1;
            this.splashFormVersionLabel.Text = "Version number";
            // 
            // SeferBookStoreSplashScreen
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = global::SeferBookstore.Properties.Resources.seferSplashImage;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.ClientSize = new System.Drawing.Size(302, 182);
            this.Controls.Add(this.splashFormVersionLabel);
            this.Controls.Add(this.splashScreenMainLabel);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "SeferBookStoreSplashScreen";
            this.ShowInTaskbar = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "SeferBookStoreSplashScreen";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label splashScreenMainLabel;
        private System.Windows.Forms.Label splashFormVersionLabel;
    }
}