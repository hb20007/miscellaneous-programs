/// <file>
/// <author>hb20007</author>
/// <datecreated>2016-10-30</datecreated>
/// <summary>
///  Contains the part of the class CountriesSplashScreenForm dealing with displaying the components on the form
/// </summary>
/// </file>

namespace CountriesWindowsForm
{
    partial class CountriesSplashScreenForm
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
            this.splashScreenLabel = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // splashScreenLabel
            // 
            this.splashScreenLabel.AutoSize = true;
            this.splashScreenLabel.BackColor = System.Drawing.Color.Transparent;
            this.splashScreenLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.splashScreenLabel.ForeColor = System.Drawing.SystemColors.InfoText;
            this.splashScreenLabel.Location = new System.Drawing.Point(8, 117);
            this.splashScreenLabel.Name = "splashScreenLabel";
            this.splashScreenLabel.Size = new System.Drawing.Size(270, 24);
            this.splashScreenLabel.TabIndex = 0;
            this.splashScreenLabel.Text = "Countries by hb20007 (v" + CountriesFormAboutBox.AssemblyVersion.Substring(0, 3) + ")"; // I use the substring function because I want to display only the first 2 numbers of the version number
            // 
            // CountriesSplashScreenForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.DarkMagenta;
            this.BackgroundImage = global::CountriesWindowsForm.Properties.Resources.ce1370f5_143a_4098_af09_76638ac9c636;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.ClientSize = new System.Drawing.Size(284, 261);
            this.Controls.Add(this.splashScreenLabel);
            this.DoubleBuffered = true;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "CountriesSplashScreenForm";
            this.ShowInTaskbar = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "CountriesSplashScreenForm";
            this.TransparencyKey = System.Drawing.Color.DarkMagenta;
            this.ResumeLayout(false);
            this.PerformLayout();
        }
        #endregion

        private System.Windows.Forms.Label splashScreenLabel;
    }
}