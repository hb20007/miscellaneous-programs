/// <file>
/// <author>Hanna Sababa</author>
/// <datecreated>2016-12-08</datecreated>
/// <summary>
///  Contains the part of the class CountriesForm dealing with displaying the components on the form
/// </summary>
/// </file>

namespace CountriesWindowsForm
{
    partial class CountriesForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(CountriesForm));
            this.country1RadioButton = new System.Windows.Forms.RadioButton();
            this.country2RadioButton = new System.Windows.Forms.RadioButton();
            this.country3RadioButton = new System.Windows.Forms.RadioButton();
            this.radioButtonsFlowLayoutPanel = new System.Windows.Forms.FlowLayoutPanel();
            this.miscellaneousGroupBox = new System.Windows.Forms.GroupBox();
            this.labelsFlowLayoutPanel = new System.Windows.Forms.FlowLayoutPanel();
            this.countryLabel = new System.Windows.Forms.Label();
            this.programmerLabel = new System.Windows.Forms.Label();
            this.hideFormNameCheckbox = new System.Windows.Forms.CheckBox();
            this.hideProgrammerNameCheckbox = new System.Windows.Forms.CheckBox();
            this.hideCountryNameCheckbox = new System.Windows.Forms.CheckBox();
            this.horizontalDividerLabel = new System.Windows.Forms.Label();
            this.countriesFormToolTip = new System.Windows.Forms.ToolTip(this.components);
            this.exitButton = new System.Windows.Forms.Button();
            this.flagPictureBox = new System.Windows.Forms.PictureBox();
            this.countriesFormMenuStrip = new System.Windows.Forms.MenuStrip();
            this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.aboutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.radioButtonsFlowLayoutPanel.SuspendLayout();
            this.miscellaneousGroupBox.SuspendLayout();
            this.labelsFlowLayoutPanel.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.flagPictureBox)).BeginInit();
            this.countriesFormMenuStrip.SuspendLayout();
            this.SuspendLayout();
            // 
            // country1RadioButton
            // 
            this.country1RadioButton.AutoSize = true;
            this.country1RadioButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.country1RadioButton.Location = new System.Drawing.Point(4, 3);
            this.country1RadioButton.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
            this.country1RadioButton.Name = "country1RadioButton";
            this.country1RadioButton.Size = new System.Drawing.Size(14, 13);
            this.country1RadioButton.TabIndex = 0;
            this.country1RadioButton.TabStop = true;
            this.country1RadioButton.UseVisualStyleBackColor = true;
            this.country1RadioButton.CheckedChanged += new System.EventHandler(this.country1RadioButton_CheckedChanged);
            // 
            // country2RadioButton
            // 
            this.country2RadioButton.AutoSize = true;
            this.country2RadioButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.country2RadioButton.Location = new System.Drawing.Point(26, 3);
            this.country2RadioButton.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
            this.country2RadioButton.Name = "country2RadioButton";
            this.country2RadioButton.Size = new System.Drawing.Size(14, 13);
            this.country2RadioButton.TabIndex = 1;
            this.country2RadioButton.TabStop = true;
            this.country2RadioButton.UseVisualStyleBackColor = true;
            this.country2RadioButton.CheckedChanged += new System.EventHandler(this.country2RadioButton_CheckedChanged);
            // 
            // country3RadioButton
            // 
            this.country3RadioButton.AutoSize = true;
            this.country3RadioButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.country3RadioButton.Location = new System.Drawing.Point(48, 3);
            this.country3RadioButton.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
            this.country3RadioButton.Name = "country3RadioButton";
            this.country3RadioButton.Size = new System.Drawing.Size(14, 13);
            this.country3RadioButton.TabIndex = 2;
            this.country3RadioButton.TabStop = true;
            this.country3RadioButton.UseVisualStyleBackColor = true;
            this.country3RadioButton.CheckedChanged += new System.EventHandler(this.country3RadioButton_CheckedChanged);
            // 
            // radioButtonsFlowLayoutPanel
            // 
            this.radioButtonsFlowLayoutPanel.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.radioButtonsFlowLayoutPanel.Controls.Add(this.country1RadioButton);
            this.radioButtonsFlowLayoutPanel.Controls.Add(this.country2RadioButton);
            this.radioButtonsFlowLayoutPanel.Controls.Add(this.country3RadioButton);
            this.radioButtonsFlowLayoutPanel.Location = new System.Drawing.Point(72, 92);
            this.radioButtonsFlowLayoutPanel.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
            this.radioButtonsFlowLayoutPanel.Name = "radioButtonsFlowLayoutPanel";
            this.radioButtonsFlowLayoutPanel.Size = new System.Drawing.Size(138, 76);
            this.radioButtonsFlowLayoutPanel.TabIndex = 0;
            // 
            // miscellaneousGroupBox
            // 
            this.miscellaneousGroupBox.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.miscellaneousGroupBox.Controls.Add(this.labelsFlowLayoutPanel);
            this.miscellaneousGroupBox.Controls.Add(this.hideFormNameCheckbox);
            this.miscellaneousGroupBox.Controls.Add(this.hideProgrammerNameCheckbox);
            this.miscellaneousGroupBox.Controls.Add(this.hideCountryNameCheckbox);
            this.miscellaneousGroupBox.Location = new System.Drawing.Point(14, 251);
            this.miscellaneousGroupBox.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
            this.miscellaneousGroupBox.Name = "miscellaneousGroupBox";
            this.miscellaneousGroupBox.Padding = new System.Windows.Forms.Padding(4, 3, 4, 3);
            this.miscellaneousGroupBox.Size = new System.Drawing.Size(555, 139);
            this.miscellaneousGroupBox.TabIndex = 1;
            this.miscellaneousGroupBox.TabStop = false;
            this.miscellaneousGroupBox.Text = "Miscellaneous";
            // 
            // labelsFlowLayoutPanel
            // 
            this.labelsFlowLayoutPanel.Controls.Add(this.countryLabel);
            this.labelsFlowLayoutPanel.Controls.Add(this.programmerLabel);
            this.labelsFlowLayoutPanel.Location = new System.Drawing.Point(365, 20);
            this.labelsFlowLayoutPanel.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
            this.labelsFlowLayoutPanel.Name = "labelsFlowLayoutPanel";
            this.labelsFlowLayoutPanel.Size = new System.Drawing.Size(183, 67);
            this.labelsFlowLayoutPanel.TabIndex = 0;
            // 
            // countryLabel
            // 
            this.countryLabel.AutoSize = true;
            this.countryLabel.Location = new System.Drawing.Point(4, 0);
            this.countryLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.countryLabel.Name = "countryLabel";
            this.countryLabel.Size = new System.Drawing.Size(0, 14);
            this.countryLabel.TabIndex = 0;
            // 
            // programmerLabel
            // 
            this.programmerLabel.AutoSize = true;
            this.programmerLabel.Location = new System.Drawing.Point(4, 14);
            this.programmerLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.programmerLabel.Name = "programmerLabel";
            this.programmerLabel.Size = new System.Drawing.Size(174, 14);
            this.programmerLabel.TabIndex = 1;
            this.programmerLabel.Text = "Programmer: Hanna Sababa";
            // 
            // hideFormNameCheckbox
            // 
            this.hideFormNameCheckbox.AutoSize = true;
            this.hideFormNameCheckbox.Cursor = System.Windows.Forms.Cursors.Hand;
            this.hideFormNameCheckbox.Location = new System.Drawing.Point(19, 90);
            this.hideFormNameCheckbox.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
            this.hideFormNameCheckbox.Name = "hideFormNameCheckbox";
            this.hideFormNameCheckbox.Size = new System.Drawing.Size(120, 18);
            this.hideFormNameCheckbox.TabIndex = 2;
            this.hideFormNameCheckbox.Text = "Hide form name";
            this.hideFormNameCheckbox.UseVisualStyleBackColor = true;
            this.hideFormNameCheckbox.CheckedChanged += new System.EventHandler(this.hideFormNameCheckbox_CheckedChanged);
            // 
            // hideProgrammerNameCheckbox
            // 
            this.hideProgrammerNameCheckbox.AutoSize = true;
            this.hideProgrammerNameCheckbox.Cursor = System.Windows.Forms.Cursors.Hand;
            this.hideProgrammerNameCheckbox.Location = new System.Drawing.Point(19, 66);
            this.hideProgrammerNameCheckbox.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
            this.hideProgrammerNameCheckbox.Name = "hideProgrammerNameCheckbox";
            this.hideProgrammerNameCheckbox.Size = new System.Drawing.Size(167, 18);
            this.hideProgrammerNameCheckbox.TabIndex = 1;
            this.hideProgrammerNameCheckbox.Text = "Hide programmer name";
            this.hideProgrammerNameCheckbox.UseVisualStyleBackColor = true;
            this.hideProgrammerNameCheckbox.CheckedChanged += new System.EventHandler(this.hideProgrammerNameCheckbox_CheckedChanged);
            // 
            // hideCountryNameCheckbox
            // 
            this.hideCountryNameCheckbox.AutoSize = true;
            this.hideCountryNameCheckbox.Cursor = System.Windows.Forms.Cursors.Hand;
            this.hideCountryNameCheckbox.Location = new System.Drawing.Point(19, 41);
            this.hideCountryNameCheckbox.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
            this.hideCountryNameCheckbox.Name = "hideCountryNameCheckbox";
            this.hideCountryNameCheckbox.Size = new System.Drawing.Size(139, 18);
            this.hideCountryNameCheckbox.TabIndex = 0;
            this.hideCountryNameCheckbox.Text = "Hide country name";
            this.hideCountryNameCheckbox.UseVisualStyleBackColor = true;
            this.hideCountryNameCheckbox.CheckedChanged += new System.EventHandler(this.hideCountryNameCheckbox_CheckedChanged);
            // 
            // horizontalDividerLabel
            // 
            this.horizontalDividerLabel.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.horizontalDividerLabel.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.horizontalDividerLabel.Location = new System.Drawing.Point(12, 240);
            this.horizontalDividerLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.horizontalDividerLabel.Name = "horizontalDividerLabel";
            this.horizontalDividerLabel.Size = new System.Drawing.Size(560, 3);
            this.horizontalDividerLabel.TabIndex = 0;
            // 
            // exitButton
            // 
            this.exitButton.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
            this.exitButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.exitButton.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.exitButton.Image = global::CountriesWindowsForm.Properties.Resources._1476468870_Log_Out;
            this.exitButton.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.exitButton.Location = new System.Drawing.Point(259, 403);
            this.exitButton.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
            this.exitButton.Name = "exitButton";
            this.exitButton.Size = new System.Drawing.Size(58, 29);
            this.exitButton.TabIndex = 2;
            this.exitButton.Text = "E&xit";
            this.exitButton.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.exitButton.UseVisualStyleBackColor = true;
            this.exitButton.Click += new System.EventHandler(this.exitButton_Click);
            // 
            // flagPictureBox
            // 
            this.flagPictureBox.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.flagPictureBox.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.flagPictureBox.Location = new System.Drawing.Point(217, 26);
            this.flagPictureBox.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
            this.flagPictureBox.Name = "flagPictureBox";
            this.flagPictureBox.Size = new System.Drawing.Size(352, 210);
            this.flagPictureBox.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.flagPictureBox.TabIndex = 3;
            this.flagPictureBox.TabStop = false;
            this.countriesFormToolTip.SetToolTip(this.flagPictureBox, "Country flag");
            // 
            // countriesFormMenuStrip
            // 
            this.countriesFormMenuStrip.BackColor = System.Drawing.SystemColors.Control;
            this.countriesFormMenuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.helpToolStripMenuItem});
            this.countriesFormMenuStrip.Location = new System.Drawing.Point(0, 0);
            this.countriesFormMenuStrip.Name = "countriesFormMenuStrip";
            this.countriesFormMenuStrip.Size = new System.Drawing.Size(583, 24);
            this.countriesFormMenuStrip.TabIndex = 4;
            this.countriesFormMenuStrip.Text = "menuStrip1";
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
            // CountriesForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 14F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.CancelButton = this.exitButton;
            this.ClientSize = new System.Drawing.Size(583, 445);
            this.Controls.Add(this.horizontalDividerLabel);
            this.Controls.Add(this.exitButton);
            this.Controls.Add(this.miscellaneousGroupBox);
            this.Controls.Add(this.radioButtonsFlowLayoutPanel);
            this.Controls.Add(this.flagPictureBox);
            this.Controls.Add(this.countriesFormMenuStrip);
            this.Font = new System.Drawing.Font("Georgia", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = Properties.Resources._1479698208_globe_01;
            this.MainMenuStrip = this.countriesFormMenuStrip;
            this.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
            this.MaximizeBox = false;
            this.Name = "CountriesForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Countries";
            this.radioButtonsFlowLayoutPanel.ResumeLayout(false);
            this.radioButtonsFlowLayoutPanel.PerformLayout();
            this.miscellaneousGroupBox.ResumeLayout(false);
            this.miscellaneousGroupBox.PerformLayout();
            this.labelsFlowLayoutPanel.ResumeLayout(false);
            this.labelsFlowLayoutPanel.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.flagPictureBox)).EndInit();
            this.countriesFormMenuStrip.ResumeLayout(false);
            this.countriesFormMenuStrip.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox flagPictureBox;
        private System.Windows.Forms.RadioButton country1RadioButton;
        private System.Windows.Forms.RadioButton country2RadioButton;
        private System.Windows.Forms.FlowLayoutPanel radioButtonsFlowLayoutPanel;
        private System.Windows.Forms.RadioButton country3RadioButton;
        private System.Windows.Forms.GroupBox miscellaneousGroupBox;
        private System.Windows.Forms.FlowLayoutPanel labelsFlowLayoutPanel;
        private System.Windows.Forms.CheckBox hideFormNameCheckbox;
        private System.Windows.Forms.CheckBox hideProgrammerNameCheckbox;
        private System.Windows.Forms.CheckBox hideCountryNameCheckbox;
        private System.Windows.Forms.Label countryLabel;
        private System.Windows.Forms.Label programmerLabel;
        private System.Windows.Forms.Button exitButton;
        private System.Windows.Forms.Label horizontalDividerLabel;
        private System.Windows.Forms.ToolTip countriesFormToolTip;
        private System.Windows.Forms.MenuStrip countriesFormMenuStrip;
        private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem aboutToolStripMenuItem;
    }
}

