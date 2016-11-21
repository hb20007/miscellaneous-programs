/// <file>
/// <author>Hanna Sababa</author>
/// <datecreated>2016-11-21</datecreated>
/// <summary>
///  Contains the part of the class USAStateLookupForm with the designer code
/// </summary>
/// </file>

namespace USAStateLookup
{
    partial class USAStateLookupForm
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
            this.lookupByCodeRadioButton = new System.Windows.Forms.RadioButton();
            this.lookupByNameRadioButton = new System.Windows.Forms.RadioButton();
            this.nameComboBox = new System.Windows.Forms.ComboBox();
            this.codeComboBox = new System.Windows.Forms.ComboBox();
            this.lookupModeGroupBox = new System.Windows.Forms.GroupBox();
            this.stateNameLabel = new System.Windows.Forms.Label();
            this.codeLabel = new System.Windows.Forms.Label();
            this.nameTextBox = new System.Windows.Forms.TextBox();
            this.codeTextBox = new System.Windows.Forms.TextBox();
            this.searchButton = new System.Windows.Forms.Button();
            this.horizontalDividerLabel = new System.Windows.Forms.Label();
            this.lookupModeGroupBox.SuspendLayout();
            this.SuspendLayout();
            // 
            // lookupByCodeRadioButton
            // 
            this.lookupByCodeRadioButton.AutoSize = true;
            this.lookupByCodeRadioButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.lookupByCodeRadioButton.Location = new System.Drawing.Point(169, 28);
            this.lookupByCodeRadioButton.Name = "lookupByCodeRadioButton";
            this.lookupByCodeRadioButton.Size = new System.Drawing.Size(111, 19);
            this.lookupByCodeRadioButton.TabIndex = 1;
            this.lookupByCodeRadioButton.Text = "Lookup by code";
            this.lookupByCodeRadioButton.UseVisualStyleBackColor = true;
            this.lookupByCodeRadioButton.CheckedChanged += new System.EventHandler(this.lookupByCodeRadioButton_CheckedChanged);
            // 
            // lookupByNameRadioButton
            // 
            this.lookupByNameRadioButton.AutoSize = true;
            this.lookupByNameRadioButton.Checked = true;
            this.lookupByNameRadioButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.lookupByNameRadioButton.Location = new System.Drawing.Point(32, 28);
            this.lookupByNameRadioButton.Name = "lookupByNameRadioButton";
            this.lookupByNameRadioButton.Size = new System.Drawing.Size(116, 19);
            this.lookupByNameRadioButton.TabIndex = 0;
            this.lookupByNameRadioButton.TabStop = true;
            this.lookupByNameRadioButton.Text = "Lookup by name";
            this.lookupByNameRadioButton.UseVisualStyleBackColor = true;
            // 
            // nameComboBox
            // 
            this.nameComboBox.AutoCompleteMode = System.Windows.Forms.AutoCompleteMode.SuggestAppend;
            this.nameComboBox.AutoCompleteSource = System.Windows.Forms.AutoCompleteSource.ListItems;
            this.nameComboBox.BackColor = System.Drawing.SystemColors.Window;
            this.nameComboBox.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.nameComboBox.FormattingEnabled = true;
            this.nameComboBox.Location = new System.Drawing.Point(46, 106);
            this.nameComboBox.Name = "nameComboBox";
            this.nameComboBox.Size = new System.Drawing.Size(135, 23);
            this.nameComboBox.TabIndex = 2;
            // 
            // codeComboBox
            // 
            this.codeComboBox.AutoCompleteMode = System.Windows.Forms.AutoCompleteMode.SuggestAppend;
            this.codeComboBox.AutoCompleteSource = System.Windows.Forms.AutoCompleteSource.ListItems;
            this.codeComboBox.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.codeComboBox.FormattingEnabled = true;
            this.codeComboBox.Location = new System.Drawing.Point(229, 106);
            this.codeComboBox.MaxLength = 2;
            this.codeComboBox.Name = "codeComboBox";
            this.codeComboBox.Size = new System.Drawing.Size(49, 23);
            this.codeComboBox.TabIndex = 6;
            this.codeComboBox.Visible = false;
            // 
            // lookupModeGroupBox
            // 
            this.lookupModeGroupBox.Controls.Add(this.lookupByNameRadioButton);
            this.lookupModeGroupBox.Controls.Add(this.lookupByCodeRadioButton);
            this.lookupModeGroupBox.Location = new System.Drawing.Point(9, 12);
            this.lookupModeGroupBox.Name = "lookupModeGroupBox";
            this.lookupModeGroupBox.Size = new System.Drawing.Size(308, 70);
            this.lookupModeGroupBox.TabIndex = 7;
            this.lookupModeGroupBox.TabStop = false;
            this.lookupModeGroupBox.Text = "Lookup mode";
            // 
            // stateNameLabel
            // 
            this.stateNameLabel.AutoSize = true;
            this.stateNameLabel.Location = new System.Drawing.Point(44, 87);
            this.stateNameLabel.Name = "stateNameLabel";
            this.stateNameLabel.Size = new System.Drawing.Size(70, 15);
            this.stateNameLabel.TabIndex = 0;
            this.stateNameLabel.Text = "State name";
            // 
            // codeLabel
            // 
            this.codeLabel.AutoSize = true;
            this.codeLabel.Location = new System.Drawing.Point(226, 87);
            this.codeLabel.Name = "codeLabel";
            this.codeLabel.Size = new System.Drawing.Size(36, 15);
            this.codeLabel.TabIndex = 4;
            this.codeLabel.Text = "Code";
            // 
            // nameTextBox
            // 
            this.nameTextBox.Location = new System.Drawing.Point(46, 106);
            this.nameTextBox.Name = "nameTextBox";
            this.nameTextBox.ReadOnly = true;
            this.nameTextBox.Size = new System.Drawing.Size(118, 21);
            this.nameTextBox.TabIndex = 1;
            this.nameTextBox.Visible = false;
            // 
            // codeTextBox
            // 
            this.codeTextBox.Location = new System.Drawing.Point(229, 106);
            this.codeTextBox.MaxLength = 2;
            this.codeTextBox.Name = "codeTextBox";
            this.codeTextBox.ReadOnly = true;
            this.codeTextBox.Size = new System.Drawing.Size(33, 21);
            this.codeTextBox.TabIndex = 5;
            // 
            // searchButton
            // 
            this.searchButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.searchButton.Location = new System.Drawing.Point(127, 147);
            this.searchButton.Name = "searchButton";
            this.searchButton.Size = new System.Drawing.Size(75, 23);
            this.searchButton.TabIndex = 3;
            this.searchButton.Text = "Search";
            this.searchButton.UseVisualStyleBackColor = true;
            this.searchButton.Click += new System.EventHandler(this.searchButton_Click);
            // 
            // horizontalDividerLabel
            // 
            this.horizontalDividerLabel.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.horizontalDividerLabel.Location = new System.Drawing.Point(5, 138);
            this.horizontalDividerLabel.Name = "horizontalDividerLabel";
            this.horizontalDividerLabel.Size = new System.Drawing.Size(320, 2);
            this.horizontalDividerLabel.TabIndex = 1;
            // 
            // USAStateLookupForm
            // 
            this.AcceptButton = this.searchButton;
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(330, 178);
            this.Controls.Add(this.horizontalDividerLabel);
            this.Controls.Add(this.searchButton);
            this.Controls.Add(this.codeTextBox);
            this.Controls.Add(this.nameTextBox);
            this.Controls.Add(this.codeLabel);
            this.Controls.Add(this.stateNameLabel);
            this.Controls.Add(this.lookupModeGroupBox);
            this.Controls.Add(this.codeComboBox);
            this.Controls.Add(this.nameComboBox);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = global::USAStateLookup.Properties.Resources._1479732986_United_States_of_America_USA_;
            this.MaximizeBox = false;
            this.Name = "USAStateLookupForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "USA State Lookup";
            this.lookupModeGroupBox.ResumeLayout(false);
            this.lookupModeGroupBox.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }
        #endregion

        private System.Windows.Forms.RadioButton lookupByCodeRadioButton;
        private System.Windows.Forms.RadioButton lookupByNameRadioButton;
        private System.Windows.Forms.ComboBox nameComboBox;
        private System.Windows.Forms.ComboBox codeComboBox;
        private System.Windows.Forms.GroupBox lookupModeGroupBox;
        private System.Windows.Forms.Label stateNameLabel;
        private System.Windows.Forms.Label codeLabel;
        private System.Windows.Forms.TextBox nameTextBox;
        private System.Windows.Forms.TextBox codeTextBox;
        private System.Windows.Forms.Button searchButton;
        private System.Windows.Forms.Label horizontalDividerLabel;
    }
}