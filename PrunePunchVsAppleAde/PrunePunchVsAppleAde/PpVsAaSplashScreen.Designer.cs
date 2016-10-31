/// <file>
/// <author>Hanna Sababa</author>
/// <datecreated>2016-10-31</datecreated>
/// <summary>
/// Part of the PpVsAaSpashScreen class with the auto-generated stuff
/// </summary>
/// </file>

namespace PrunePunchVsAppleAde
{
    partial class PpVsAaSplashScreen
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
            this.splashScreenTitleLabel = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // splashScreenTitleLabel
            // 
            this.splashScreenTitleLabel.AutoSize = true;
            this.splashScreenTitleLabel.BackColor = System.Drawing.Color.Transparent;
            this.splashScreenTitleLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.splashScreenTitleLabel.ForeColor = System.Drawing.SystemColors.Control;
            this.splashScreenTitleLabel.Location = new System.Drawing.Point(17, 149);
            this.splashScreenTitleLabel.Name = "splashScreenTitleLabel";
            this.splashScreenTitleLabel.Size = new System.Drawing.Size(243, 20);
            this.splashScreenTitleLabel.TabIndex = 0;
            this.splashScreenTitleLabel.Text = "Prune Punch™ vs Apple Ade™";
            // 
            // PpVsAaSpashScreen
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = global::PrunePunchVsAppleAde.Properties.Resources.db19fe86_7f59_46fc_a13b_1778c591c8a0; // Image used is in the public domain
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.ClientSize = new System.Drawing.Size(275, 178);
            this.Controls.Add(this.splashScreenTitleLabel);
            this.DoubleBuffered = true;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "PpVsAaSpashScreen";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "PpVsAaSpashScreen";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label splashScreenTitleLabel;
    }
}