/// <file>
/// <author>Hanna Sababa</author>
/// <datecreated>2016-10-30</datecreated>
/// <summary>
///  Contains the part of the class PpVsAaMainForm dealing with displaying the components on the form
/// </summary>
/// </file>

namespace PrunePunchVsAppleAde
{
    partial class PpVsAaMainForm
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
            this.components = new System.ComponentModel.Container();
            this.ppVsAaMainFormToolTip = new System.Windows.Forms.ToolTip(this.components);
            this.instructionsLabel = new System.Windows.Forms.Label();
            this.addYourScoresButton = new System.Windows.Forms.Button();
            this.prunePunchTrackBar = new System.Windows.Forms.TrackBar();
            this.appleAdeTrackBar = new System.Windows.Forms.TrackBar();
            this.prunePunchLabel = new System.Windows.Forms.Label();
            this.appleAdeLabel = new System.Windows.Forms.Label();
            this.horizontalDividerLabel = new System.Windows.Forms.Label();
            this.prunePunchRatingLabel = new System.Windows.Forms.Label();
            this.appleAdeRatingLabel = new System.Windows.Forms.Label();
            this.ppVsAaMainFormMenuStrip = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.rToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.addYourScoresToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.summaryToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.aboutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            ((System.ComponentModel.ISupportInitialize)(this.prunePunchTrackBar)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.appleAdeTrackBar)).BeginInit();
            this.ppVsAaMainFormMenuStrip.SuspendLayout();
            this.SuspendLayout();
            // 
            // instructionsLabel
            // 
            this.instructionsLabel.AutoSize = true;
            this.instructionsLabel.Location = new System.Drawing.Point(97, 41);
            this.instructionsLabel.Name = "instructionsLabel";
            this.instructionsLabel.Size = new System.Drawing.Size(271, 15);
            this.instructionsLabel.TabIndex = 0;
            this.instructionsLabel.Text = "Select your rating scores for the two drinks below";
            // 
            // addYourScoresButton
            // 
            this.addYourScoresButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.addYourScoresButton.Location = new System.Drawing.Point(162, 225);
            this.addYourScoresButton.Name = "addYourScoresButton";
            this.addYourScoresButton.Size = new System.Drawing.Size(150, 27);
            this.addYourScoresButton.TabIndex = 6;
            this.addYourScoresButton.Text = "&Add your scores";
            this.addYourScoresButton.UseVisualStyleBackColor = true;
            this.addYourScoresButton.Click += new System.EventHandler(this.addYourScoresButton_Click);
            // 
            // prunePunchTrackBar
            // 
            this.prunePunchTrackBar.Cursor = System.Windows.Forms.Cursors.Default;
            this.prunePunchTrackBar.Location = new System.Drawing.Point(156, 89);
            this.prunePunchTrackBar.Minimum = 1;
            this.prunePunchTrackBar.Name = "prunePunchTrackBar";
            this.prunePunchTrackBar.Size = new System.Drawing.Size(240, 45);
            this.prunePunchTrackBar.TabIndex = 2;
            this.prunePunchTrackBar.Value = 1;
            this.prunePunchTrackBar.ValueChanged += new System.EventHandler(this.prunePunchTrackBar_ValueChanged);
            // 
            // appleAdeTrackBar
            // 
            this.appleAdeTrackBar.Cursor = System.Windows.Forms.Cursors.Default;
            this.appleAdeTrackBar.Location = new System.Drawing.Point(156, 151);
            this.appleAdeTrackBar.Minimum = 1;
            this.appleAdeTrackBar.Name = "appleAdeTrackBar";
            this.appleAdeTrackBar.Size = new System.Drawing.Size(240, 45);
            this.appleAdeTrackBar.TabIndex = 4;
            this.appleAdeTrackBar.Value = 1;
            this.appleAdeTrackBar.ValueChanged += new System.EventHandler(this.appleAdeTrackBar_ValueChanged);
            // 
            // prunePunchLabel
            // 
            this.prunePunchLabel.AutoSize = true;
            this.prunePunchLabel.Location = new System.Drawing.Point(35, 92);
            this.prunePunchLabel.Name = "prunePunchLabel";
            this.prunePunchLabel.Size = new System.Drawing.Size(86, 15);
            this.prunePunchLabel.TabIndex = 1;
            this.prunePunchLabel.Text = "Prune Punch™";
            // 
            // appleAdeLabel
            // 
            this.appleAdeLabel.AutoSize = true;
            this.appleAdeLabel.Location = new System.Drawing.Point(50, 152);
            this.appleAdeLabel.Name = "appleAdeLabel";
            this.appleAdeLabel.Size = new System.Drawing.Size(70, 15);
            this.appleAdeLabel.TabIndex = 3;
            this.appleAdeLabel.Text = "Apple Ade™";
            // 
            // horizontalDividerLabel
            // 
            this.horizontalDividerLabel.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.horizontalDividerLabel.Location = new System.Drawing.Point(3, 210);
            this.horizontalDividerLabel.Name = "horizontalDividerLabel";
            this.horizontalDividerLabel.Size = new System.Drawing.Size(460, 3);
            this.horizontalDividerLabel.TabIndex = 5;
            // 
            // prunePunchRatingLabel
            // 
            this.prunePunchRatingLabel.AutoSize = true;
            this.prunePunchRatingLabel.Location = new System.Drawing.Point(400, 88);
            this.prunePunchRatingLabel.Name = "prunePunchRatingLabel";
            this.prunePunchRatingLabel.Size = new System.Drawing.Size(43, 15);
            this.prunePunchRatingLabel.TabIndex = 7;
            this.prunePunchRatingLabel.Text = "Rating";
            // 
            // appleAdeRatingLabel
            // 
            this.appleAdeRatingLabel.AutoSize = true;
            this.appleAdeRatingLabel.Location = new System.Drawing.Point(400, 151);
            this.appleAdeRatingLabel.Name = "appleAdeRatingLabel";
            this.appleAdeRatingLabel.Size = new System.Drawing.Size(43, 15);
            this.appleAdeRatingLabel.TabIndex = 8;
            this.appleAdeRatingLabel.Text = "Rating";
            // 
            // ppVsAaMainFormMenuStrip
            // 
            this.ppVsAaMainFormMenuStrip.BackColor = System.Drawing.SystemColors.Control;
            this.ppVsAaMainFormMenuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.rToolStripMenuItem,
            this.helpToolStripMenuItem});
            this.ppVsAaMainFormMenuStrip.Location = new System.Drawing.Point(0, 0);
            this.ppVsAaMainFormMenuStrip.Name = "ppVsAaMainFormMenuStrip";
            this.ppVsAaMainFormMenuStrip.Size = new System.Drawing.Size(466, 24);
            this.ppVsAaMainFormMenuStrip.TabIndex = 9;
            this.ppVsAaMainFormMenuStrip.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.exitToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.fileToolStripMenuItem.Text = "&File";
            // 
            // exitToolStripMenuItem
            // 
            this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            this.exitToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Alt | System.Windows.Forms.Keys.F4)));
            this.exitToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.exitToolStripMenuItem.Text = "E&xit";
            this.exitToolStripMenuItem.Click += new System.EventHandler(this.exitToolStripMenuItem_Click);
            // 
            // rToolStripMenuItem
            // 
            this.rToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.addYourScoresToolStripMenuItem,
            this.toolStripSeparator1,
            this.summaryToolStripMenuItem});
            this.rToolStripMenuItem.Name = "rToolStripMenuItem";
            this.rToolStripMenuItem.Size = new System.Drawing.Size(58, 20);
            this.rToolStripMenuItem.Text = "&Ratings";
            // 
            // addYourScoresToolStripMenuItem
            // 
            this.addYourScoresToolStripMenuItem.Name = "addYourScoresToolStripMenuItem";
            this.addYourScoresToolStripMenuItem.Size = new System.Drawing.Size(197, 22);
            this.addYourScoresToolStripMenuItem.Text = "&Add your scores";
            this.addYourScoresToolStripMenuItem.Click += new System.EventHandler(this.addYourScoresToolStripMenuItem_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(194, 6);
            // 
            // summaryToolStripMenuItem
            // 
            this.summaryToolStripMenuItem.Name = "summaryToolStripMenuItem";
            this.summaryToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)(((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Shift) 
            | System.Windows.Forms.Keys.S)));
            this.summaryToolStripMenuItem.Size = new System.Drawing.Size(197, 22);
            this.summaryToolStripMenuItem.Text = "&Summary";
            this.summaryToolStripMenuItem.Click += new System.EventHandler(this.summaryToolStripMenuItem_Click);
            // 
            // helpToolStripMenuItem
            // 
            this.helpToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.aboutToolStripMenuItem});
            this.helpToolStripMenuItem.Name = "helpToolStripMenuItem";
            this.helpToolStripMenuItem.Size = new System.Drawing.Size(44, 20);
            this.helpToolStripMenuItem.Text = "&Help";
            // 
            // aboutToolStripMenuItem
            // 
            this.aboutToolStripMenuItem.Name = "aboutToolStripMenuItem";
            this.aboutToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.aboutToolStripMenuItem.Text = "&About";
            this.aboutToolStripMenuItem.Click += new System.EventHandler(this.aboutToolStripMenuItem_Click);
            // 
            // PpVsAaMainForm
            // 
            this.AcceptButton = this.addYourScoresButton;
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(466, 266);
            this.Controls.Add(this.appleAdeRatingLabel);
            this.Controls.Add(this.prunePunchRatingLabel);
            this.Controls.Add(this.horizontalDividerLabel);
            this.Controls.Add(this.addYourScoresButton);
            this.Controls.Add(this.appleAdeLabel);
            this.Controls.Add(this.prunePunchLabel);
            this.Controls.Add(this.instructionsLabel);
            this.Controls.Add(this.appleAdeTrackBar);
            this.Controls.Add(this.prunePunchTrackBar);
            this.Controls.Add(this.ppVsAaMainFormMenuStrip);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = global::PrunePunchVsAppleAde.Properties.Resources._1477862040_79;
            this.MainMenuStrip = this.ppVsAaMainFormMenuStrip;
            this.MaximizeBox = false;
            this.Name = "PpVsAaMainForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Prune Punch™ vs Apple Ade™";
            ((System.ComponentModel.ISupportInitialize)(this.prunePunchTrackBar)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.appleAdeTrackBar)).EndInit();
            this.ppVsAaMainFormMenuStrip.ResumeLayout(false);
            this.ppVsAaMainFormMenuStrip.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ToolTip ppVsAaMainFormToolTip;
        private System.Windows.Forms.Label instructionsLabel;
        private System.Windows.Forms.Button addYourScoresButton;
        private System.Windows.Forms.TrackBar prunePunchTrackBar;
        private System.Windows.Forms.TrackBar appleAdeTrackBar;
        private System.Windows.Forms.Label prunePunchLabel;
        private System.Windows.Forms.Label appleAdeLabel;
        private System.Windows.Forms.Label horizontalDividerLabel;
        private System.Windows.Forms.Label prunePunchRatingLabel;
        private System.Windows.Forms.Label appleAdeRatingLabel;
        private System.Windows.Forms.MenuStrip ppVsAaMainFormMenuStrip;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem rToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem addYourScoresToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripMenuItem summaryToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem aboutToolStripMenuItem;
    }
}

