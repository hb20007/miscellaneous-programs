/// <file>
/// <author>Hanna Sababa</author>
/// <datecreated>2016-10-29</datecreated>
/// <summary>
/// Contains part of the class CrunchYourInvestmentForm dealing with the user interface
/// 
/// 
/// </summary>
/// </file>

namespace RifleBeautySalon
{
    partial class RifleBeautySalonForm
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
            this.discountGroupBox = new System.Windows.Forms.GroupBox();
            this.twentyPercentRadioButton = new System.Windows.Forms.RadioButton();
            this.tenPercentRadioButton = new System.Windows.Forms.RadioButton();
            this.noneRadioButton = new System.Windows.Forms.RadioButton();
            this.servicesGroupBox = new System.Windows.Forms.GroupBox();
            this.permanentMakeupPriceLabel = new System.Windows.Forms.Label();
            this.manicurePriceLabel = new System.Windows.Forms.Label();
            this.hairstylingPriceLabel = new System.Windows.Forms.Label();
            this.makeoverPriceLabel = new System.Windows.Forms.Label();
            this.permanentMakeupCheckBox = new System.Windows.Forms.CheckBox();
            this.manicureCheckBox = new System.Windows.Forms.CheckBox();
            this.hairstylingCheckbox = new System.Windows.Forms.CheckBox();
            this.makeoverCheckBox = new System.Windows.Forms.CheckBox();
            this.totalPriceLabel = new System.Windows.Forms.Label();
            this.totalPriceTextBox = new System.Windows.Forms.TextBox();
            this.horizontalDividerLabel = new System.Windows.Forms.Label();
            this.clearButton = new System.Windows.Forms.Button();
            this.calculateButton = new System.Windows.Forms.Button();
            this.exitButton = new System.Windows.Forms.Button();
            this.rifleBeautySalonFormToolTip = new System.Windows.Forms.ToolTip(this.components);
            this.discountGroupBox.SuspendLayout();
            this.servicesGroupBox.SuspendLayout();
            this.SuspendLayout();
            // 
            // discountGroupBox
            // 
            this.discountGroupBox.Controls.Add(this.twentyPercentRadioButton);
            this.discountGroupBox.Controls.Add(this.tenPercentRadioButton);
            this.discountGroupBox.Controls.Add(this.noneRadioButton);
            this.discountGroupBox.Location = new System.Drawing.Point(23, 20);
            this.discountGroupBox.Name = "discountGroupBox";
            this.discountGroupBox.Size = new System.Drawing.Size(382, 56);
            this.discountGroupBox.TabIndex = 0;
            this.discountGroupBox.TabStop = false;
            this.discountGroupBox.Text = "Discount";
            // 
            // twentyPercentRadioButton
            // 
            this.twentyPercentRadioButton.AutoSize = true;
            this.twentyPercentRadioButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.twentyPercentRadioButton.Location = new System.Drawing.Point(287, 22);
            this.twentyPercentRadioButton.Name = "twentyPercentRadioButton";
            this.twentyPercentRadioButton.Size = new System.Drawing.Size(45, 17);
            this.twentyPercentRadioButton.TabIndex = 2;
            this.twentyPercentRadioButton.TabStop = true;
            this.twentyPercentRadioButton.Text = "20%";
            this.twentyPercentRadioButton.UseVisualStyleBackColor = true;
            this.twentyPercentRadioButton.CheckedChanged += new System.EventHandler(this.twentyPercentRadioButton_CheckedChanged);
            // 
            // tenPercentRadioButton
            // 
            this.tenPercentRadioButton.AutoSize = true;
            this.tenPercentRadioButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.tenPercentRadioButton.Location = new System.Drawing.Point(172, 22);
            this.tenPercentRadioButton.Name = "tenPercentRadioButton";
            this.tenPercentRadioButton.Size = new System.Drawing.Size(45, 17);
            this.tenPercentRadioButton.TabIndex = 1;
            this.tenPercentRadioButton.TabStop = true;
            this.tenPercentRadioButton.Text = "10%";
            this.tenPercentRadioButton.UseVisualStyleBackColor = true;
            this.tenPercentRadioButton.CheckedChanged += new System.EventHandler(this.tenPercentRadioButton_CheckedChanged);
            // 
            // noneRadioButton
            // 
            this.noneRadioButton.AutoSize = true;
            this.noneRadioButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.noneRadioButton.Location = new System.Drawing.Point(51, 22);
            this.noneRadioButton.Name = "noneRadioButton";
            this.noneRadioButton.Size = new System.Drawing.Size(51, 17);
            this.noneRadioButton.TabIndex = 0;
            this.noneRadioButton.TabStop = true;
            this.noneRadioButton.Text = "None";
            this.noneRadioButton.UseVisualStyleBackColor = true;
            this.noneRadioButton.CheckedChanged += new System.EventHandler(this.noneRadioButton_CheckedChanged);
            // 
            // servicesGroupBox
            // 
            this.servicesGroupBox.Controls.Add(this.permanentMakeupPriceLabel);
            this.servicesGroupBox.Controls.Add(this.manicurePriceLabel);
            this.servicesGroupBox.Controls.Add(this.hairstylingPriceLabel);
            this.servicesGroupBox.Controls.Add(this.makeoverPriceLabel);
            this.servicesGroupBox.Controls.Add(this.permanentMakeupCheckBox);
            this.servicesGroupBox.Controls.Add(this.manicureCheckBox);
            this.servicesGroupBox.Controls.Add(this.hairstylingCheckbox);
            this.servicesGroupBox.Controls.Add(this.makeoverCheckBox);
            this.servicesGroupBox.Location = new System.Drawing.Point(23, 82);
            this.servicesGroupBox.Name = "servicesGroupBox";
            this.servicesGroupBox.Size = new System.Drawing.Size(381, 162);
            this.servicesGroupBox.TabIndex = 1;
            this.servicesGroupBox.TabStop = false;
            this.servicesGroupBox.Text = "Services";
            // 
            // permanentMakeupPriceLabel
            // 
            this.permanentMakeupPriceLabel.AutoSize = true;
            this.permanentMakeupPriceLabel.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            this.permanentMakeupPriceLabel.Location = new System.Drawing.Point(177, 129);
            this.permanentMakeupPriceLabel.Name = "permanentMakeupPriceLabel";
            this.permanentMakeupPriceLabel.Size = new System.Drawing.Size(0, 13);
            this.permanentMakeupPriceLabel.TabIndex = 7;
            this.permanentMakeupPriceLabel.Visible = false;
            // 
            // manicurePriceLabel
            // 
            this.manicurePriceLabel.AutoSize = true;
            this.manicurePriceLabel.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            this.manicurePriceLabel.Location = new System.Drawing.Point(128, 94);
            this.manicurePriceLabel.Name = "manicurePriceLabel";
            this.manicurePriceLabel.Size = new System.Drawing.Size(0, 13);
            this.manicurePriceLabel.TabIndex = 6;
            this.manicurePriceLabel.Visible = false;
            // 
            // hairstylingPriceLabel
            // 
            this.hairstylingPriceLabel.AutoSize = true;
            this.hairstylingPriceLabel.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            this.hairstylingPriceLabel.Location = new System.Drawing.Point(134, 60);
            this.hairstylingPriceLabel.Name = "hairstylingPriceLabel";
            this.hairstylingPriceLabel.Size = new System.Drawing.Size(0, 13);
            this.hairstylingPriceLabel.TabIndex = 5;
            this.hairstylingPriceLabel.Visible = false;
            // 
            // makeoverPriceLabel
            // 
            this.makeoverPriceLabel.AutoSize = true;
            this.makeoverPriceLabel.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            this.makeoverPriceLabel.Location = new System.Drawing.Point(134, 25);
            this.makeoverPriceLabel.Name = "makeoverPriceLabel";
            this.makeoverPriceLabel.Size = new System.Drawing.Size(0, 13);
            this.makeoverPriceLabel.TabIndex = 4;
            this.makeoverPriceLabel.Visible = false;
            // 
            // permanentMakeupCheckBox
            // 
            this.permanentMakeupCheckBox.AutoSize = true;
            this.permanentMakeupCheckBox.Cursor = System.Windows.Forms.Cursors.Hand;
            this.permanentMakeupCheckBox.Location = new System.Drawing.Point(51, 129);
            this.permanentMakeupCheckBox.Name = "permanentMakeupCheckBox";
            this.permanentMakeupCheckBox.Size = new System.Drawing.Size(118, 17);
            this.permanentMakeupCheckBox.TabIndex = 3;
            this.permanentMakeupCheckBox.Text = "Permanent makeup";
            this.rifleBeautySalonFormToolTip.SetToolTip(this.permanentMakeupCheckBox, "Look sway till the day you pass away");
            this.permanentMakeupCheckBox.UseVisualStyleBackColor = true;
            this.permanentMakeupCheckBox.CheckedChanged += new System.EventHandler(this.permanentMakeupCheckBox_CheckedChanged);
            // 
            // manicureCheckBox
            // 
            this.manicureCheckBox.AutoSize = true;
            this.manicureCheckBox.Cursor = System.Windows.Forms.Cursors.Hand;
            this.manicureCheckBox.Location = new System.Drawing.Point(51, 94);
            this.manicureCheckBox.Name = "manicureCheckBox";
            this.manicureCheckBox.Size = new System.Drawing.Size(70, 17);
            this.manicureCheckBox.TabIndex = 2;
            this.manicureCheckBox.Text = "Manicure";
            this.rifleBeautySalonFormToolTip.SetToolTip(this.manicureCheckBox, "1000s of nail art designs to choose from");
            this.manicureCheckBox.UseVisualStyleBackColor = true;
            this.manicureCheckBox.CheckedChanged += new System.EventHandler(this.manicureCheckBox_CheckedChanged);
            // 
            // hairstylingCheckbox
            // 
            this.hairstylingCheckbox.AutoSize = true;
            this.hairstylingCheckbox.Cursor = System.Windows.Forms.Cursors.Hand;
            this.hairstylingCheckbox.Location = new System.Drawing.Point(51, 59);
            this.hairstylingCheckbox.Name = "hairstylingCheckbox";
            this.hairstylingCheckbox.Size = new System.Drawing.Size(74, 17);
            this.hairstylingCheckbox.TabIndex = 1;
            this.hairstylingCheckbox.Text = "Hairstyling";
            this.rifleBeautySalonFormToolTip.SetToolTip(this.hairstylingCheckbox, "Haircut, dying and extensions");
            this.hairstylingCheckbox.UseVisualStyleBackColor = true;
            this.hairstylingCheckbox.CheckedChanged += new System.EventHandler(this.hairstylingCheckbox_CheckedChanged);
            // 
            // makeoverCheckBox
            // 
            this.makeoverCheckBox.AutoSize = true;
            this.makeoverCheckBox.Cursor = System.Windows.Forms.Cursors.Hand;
            this.makeoverCheckBox.Location = new System.Drawing.Point(51, 24);
            this.makeoverCheckBox.Name = "makeoverCheckBox";
            this.makeoverCheckBox.Size = new System.Drawing.Size(74, 17);
            this.makeoverCheckBox.TabIndex = 0;
            this.makeoverCheckBox.Text = "Makeover";
            this.rifleBeautySalonFormToolTip.SetToolTip(this.makeoverCheckBox, "Hollywood-style dramatic makeover");
            this.makeoverCheckBox.UseVisualStyleBackColor = true;
            this.makeoverCheckBox.CheckedChanged += new System.EventHandler(this.makeoverCheckBox_CheckedChanged);
            // 
            // totalPriceLabel
            // 
            this.totalPriceLabel.AutoSize = true;
            this.totalPriceLabel.Location = new System.Drawing.Point(130, 272);
            this.totalPriceLabel.Name = "totalPriceLabel";
            this.totalPriceLabel.Size = new System.Drawing.Size(60, 13);
            this.totalPriceLabel.TabIndex = 2;
            this.totalPriceLabel.Text = "Total price:";
            // 
            // totalPriceTextBox
            // 
            this.totalPriceTextBox.Location = new System.Drawing.Point(200, 268);
            this.totalPriceTextBox.Name = "totalPriceTextBox";
            this.totalPriceTextBox.ReadOnly = true;
            this.totalPriceTextBox.Size = new System.Drawing.Size(92, 20);
            this.totalPriceTextBox.TabIndex = 3;
            // 
            // horizontalDividerLabel
            // 
            this.horizontalDividerLabel.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.horizontalDividerLabel.Location = new System.Drawing.Point(8, 312);
            this.horizontalDividerLabel.Name = "horizontalDividerLabel";
            this.horizontalDividerLabel.Size = new System.Drawing.Size(410, 3);
            this.horizontalDividerLabel.TabIndex = 4;
            // 
            // clearButton
            // 
            this.clearButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.clearButton.Location = new System.Drawing.Point(47, 318);
            this.clearButton.Name = "clearButton";
            this.clearButton.Size = new System.Drawing.Size(75, 23);
            this.clearButton.TabIndex = 5;
            this.clearButton.Text = "C&lear";
            this.clearButton.UseVisualStyleBackColor = true;
            this.clearButton.Click += new System.EventHandler(this.clearButton_Click);
            // 
            // calculateButton
            // 
            this.calculateButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.calculateButton.Location = new System.Drawing.Point(173, 318);
            this.calculateButton.Name = "calculateButton";
            this.calculateButton.Size = new System.Drawing.Size(75, 23);
            this.calculateButton.TabIndex = 6;
            this.calculateButton.Text = "&Calculate";
            this.rifleBeautySalonFormToolTip.SetToolTip(this.calculateButton, "Calculate total price");
            this.calculateButton.UseVisualStyleBackColor = true;
            this.calculateButton.Click += new System.EventHandler(this.calculateButton_Click);
            // 
            // exitButton
            // 
            this.exitButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.exitButton.Location = new System.Drawing.Point(299, 318);
            this.exitButton.Name = "exitButton";
            this.exitButton.Size = new System.Drawing.Size(75, 23);
            this.exitButton.TabIndex = 7;
            this.exitButton.Text = "E&xit";
            this.exitButton.UseVisualStyleBackColor = true;
            this.exitButton.Click += new System.EventHandler(this.exitButton_Click);
            // 
            // RifleBeautySalonForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(425, 349);
            this.Controls.Add(this.exitButton);
            this.Controls.Add(this.calculateButton);
            this.Controls.Add(this.clearButton);
            this.Controls.Add(this.horizontalDividerLabel);
            this.Controls.Add(this.totalPriceTextBox);
            this.Controls.Add(this.totalPriceLabel);
            this.Controls.Add(this.servicesGroupBox);
            this.Controls.Add(this.discountGroupBox);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = global::RifleBeautySalon.Properties.Resources.sniper_rifle__1_;
            this.MaximizeBox = false;
            this.Name = "RifleBeautySalonForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Rifle Beauty Salon";
            this.discountGroupBox.ResumeLayout(false);
            this.discountGroupBox.PerformLayout();
            this.servicesGroupBox.ResumeLayout(false);
            this.servicesGroupBox.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox discountGroupBox;
        private System.Windows.Forms.RadioButton twentyPercentRadioButton;
        private System.Windows.Forms.RadioButton tenPercentRadioButton;
        private System.Windows.Forms.RadioButton noneRadioButton;
        private System.Windows.Forms.GroupBox servicesGroupBox;
        private System.Windows.Forms.CheckBox permanentMakeupCheckBox;
        private System.Windows.Forms.CheckBox manicureCheckBox;
        private System.Windows.Forms.CheckBox hairstylingCheckbox;
        private System.Windows.Forms.CheckBox makeoverCheckBox;
        private System.Windows.Forms.Label totalPriceLabel;
        private System.Windows.Forms.TextBox totalPriceTextBox;
        private System.Windows.Forms.Label permanentMakeupPriceLabel;
        private System.Windows.Forms.Label manicurePriceLabel;
        private System.Windows.Forms.Label hairstylingPriceLabel;
        private System.Windows.Forms.Label makeoverPriceLabel;
        private System.Windows.Forms.Label horizontalDividerLabel;
        private System.Windows.Forms.Button clearButton;
        private System.Windows.Forms.Button calculateButton;
        private System.Windows.Forms.Button exitButton;
        private System.Windows.Forms.ToolTip rifleBeautySalonFormToolTip;
    }
}

