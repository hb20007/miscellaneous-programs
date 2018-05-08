/// <file>
/// <author>Hanna Sababa</author>
/// <datecreated>2016-12-23</datecreated>
/// <summary>
/// Contains the part of the class SeferBookstoreAdvancedSearchForm with the Windows Form Designer code
/// </summary>
/// </file>

namespace SeferBookstore
{
    partial class SeferBookstoreAdvancedSearchForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(SeferBookstoreAdvancedSearchForm));
            this.searchByLabel = new System.Windows.Forms.Label();
            this.searchByComboBox = new System.Windows.Forms.ComboBox();
            this.searchPictureBox = new System.Windows.Forms.PictureBox();
            this.resultsLabel = new System.Windows.Forms.Label();
            this.resultsListBox = new System.Windows.Forms.ListBox();
            this.okButton = new System.Windows.Forms.Button();
            this.cancelButton = new System.Windows.Forms.Button();
            this.searchTextBox = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.searchPictureBox)).BeginInit();
            this.SuspendLayout();
            // 
            // searchByLabel
            // 
            this.searchByLabel.AutoSize = true;
            this.searchByLabel.Location = new System.Drawing.Point(64, 27);
            this.searchByLabel.Name = "searchByLabel";
            this.searchByLabel.Size = new System.Drawing.Size(64, 15);
            this.searchByLabel.TabIndex = 0;
            this.searchByLabel.Text = "Search by:";
            // 
            // searchByComboBox
            // 
            this.searchByComboBox.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.searchByComboBox.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.searchByComboBox.FormattingEnabled = true;
            this.searchByComboBox.Location = new System.Drawing.Point(134, 24);
            this.searchByComboBox.Name = "searchByComboBox";
            this.searchByComboBox.Size = new System.Drawing.Size(121, 23);
            this.searchByComboBox.TabIndex = 1;
            this.searchByComboBox.SelectedIndexChanged += new System.EventHandler(this.searchByComboBox_SelectedIndexChanged);
            // 
            // searchPictureBox
            // 
            this.searchPictureBox.Image = ((System.Drawing.Image)(resources.GetObject("searchPictureBox.Image")));
            this.searchPictureBox.Location = new System.Drawing.Point(91, 57);
            this.searchPictureBox.Name = "searchPictureBox";
            this.searchPictureBox.Size = new System.Drawing.Size(25, 25);
            this.searchPictureBox.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.searchPictureBox.TabIndex = 6;
            this.searchPictureBox.TabStop = false;
            // 
            // resultsLabel
            // 
            this.resultsLabel.AutoSize = true;
            this.resultsLabel.Location = new System.Drawing.Point(25, 104);
            this.resultsLabel.Name = "resultsLabel";
            this.resultsLabel.Size = new System.Drawing.Size(241, 15);
            this.resultsLabel.TabIndex = 3;
            this.resultsLabel.Text = "Titles that match your search string for Title:";
            // 
            // resultsListBox
            // 
            this.resultsListBox.FormattingEnabled = true;
            this.resultsListBox.ItemHeight = 15;
            this.resultsListBox.Location = new System.Drawing.Point(12, 127);
            this.resultsListBox.Name = "resultsListBox";
            this.resultsListBox.Size = new System.Drawing.Size(307, 154);
            this.resultsListBox.TabIndex = 4;
            this.resultsListBox.DoubleClick += new System.EventHandler(this.resultsListBox_DoubleClick);
            // 
            // okButton
            // 
            this.okButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.okButton.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.okButton.Location = new System.Drawing.Point(167, 290);
            this.okButton.Name = "okButton";
            this.okButton.Size = new System.Drawing.Size(84, 29);
            this.okButton.TabIndex = 6;
            this.okButton.Text = "&OK";
            this.okButton.UseVisualStyleBackColor = true;
            this.okButton.Click += new System.EventHandler(this.okButton_Click);
            // 
            // cancelButton
            // 
            this.cancelButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.cancelButton.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.cancelButton.Location = new System.Drawing.Point(77, 290);
            this.cancelButton.Name = "cancelButton";
            this.cancelButton.Size = new System.Drawing.Size(84, 29);
            this.cancelButton.TabIndex = 5;
            this.cancelButton.Text = "&Cancel";
            this.cancelButton.UseVisualStyleBackColor = true;
            this.cancelButton.Click += new System.EventHandler(this.cancelButton_Click);
            // 
            // searchTextBox
            // 
            this.searchTextBox.Location = new System.Drawing.Point(115, 60);
            this.searchTextBox.Name = "searchTextBox";
            this.searchTextBox.Size = new System.Drawing.Size(124, 21);
            this.searchTextBox.TabIndex = 2;
            this.searchTextBox.TextChanged += new System.EventHandler(this.searchTextBox_TextChanged);
            // 
            // SeferBookstoreAdvancedSearchForm
            // 
            this.AcceptButton = this.okButton;
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.CancelButton = this.cancelButton;
            this.ClientSize = new System.Drawing.Size(331, 329);
            this.Controls.Add(this.cancelButton);
            this.Controls.Add(this.okButton);
            this.Controls.Add(this.resultsListBox);
            this.Controls.Add(this.resultsLabel);
            this.Controls.Add(this.searchTextBox);
            this.Controls.Add(this.searchPictureBox);
            this.Controls.Add(this.searchByComboBox);
            this.Controls.Add(this.searchByLabel);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.Icon = global::SeferBookstore.Properties.Resources.seferIcon;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "SeferBookstoreAdvancedSearchForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Advanced search";
            this.TopMost = true;
            ((System.ComponentModel.ISupportInitialize)(this.searchPictureBox)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label searchByLabel;
        private System.Windows.Forms.ComboBox searchByComboBox;
        private System.Windows.Forms.PictureBox searchPictureBox;
        private System.Windows.Forms.Label resultsLabel;
        private System.Windows.Forms.ListBox resultsListBox;
        private System.Windows.Forms.Button okButton;
        private System.Windows.Forms.Button cancelButton;
        private System.Windows.Forms.TextBox searchTextBox;
    }
}