/// <file>
/// <author>Hanna Sababa</author>
/// <datecreated>2016-10-27</datecreated>
/// <summary>
/// Contains part of the class CrunchYourInvestmentForm dealing with the display of the form and the controls
/// </summary>
/// </file>

namespace CrunchYourInvestment
{
    partial class CrunchYourInvestmentForm
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
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(CrunchYourInvestmentForm));
            this.startingInvestmentLabel = new System.Windows.Forms.Label();
            this.startingInvestmentTextBox = new System.Windows.Forms.TextBox();
            this.interestRateTextBox = new System.Windows.Forms.TextBox();
            this.interestRateLabel = new System.Windows.Forms.Label();
            this.numberOfYearsTextBox = new System.Windows.Forms.TextBox();
            this.numberOfYearsLabel = new System.Windows.Forms.Label();
            this.horizontalDividerLabel = new System.Windows.Forms.Label();
            this.futureValueLabel = new System.Windows.Forms.Label();
            this.futureValueTextBox = new System.Windows.Forms.TextBox();
            this.calculateButton = new System.Windows.Forms.Button();
            this.exitButton = new System.Windows.Forms.Button();
            this.clearButton = new System.Windows.Forms.Button();
            this.crunchYourInvestmentToolTip = new System.Windows.Forms.ToolTip(this.components);
            this.SuspendLayout();
            // 
            // startingInvestmentLabel
            // 
            resources.ApplyResources(this.startingInvestmentLabel, "startingInvestmentLabel");
            this.startingInvestmentLabel.Name = "startingInvestmentLabel";
            this.crunchYourInvestmentToolTip.SetToolTip(this.startingInvestmentLabel, resources.GetString("startingInvestmentLabel.ToolTip"));
            // 
            // startingInvestmentTextBox
            // 
            resources.ApplyResources(this.startingInvestmentTextBox, "startingInvestmentTextBox");
            this.startingInvestmentTextBox.Name = "startingInvestmentTextBox";
            this.crunchYourInvestmentToolTip.SetToolTip(this.startingInvestmentTextBox, resources.GetString("startingInvestmentTextBox.ToolTip"));
            this.startingInvestmentTextBox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.startingInvestmentTextBox_KeyDown);
            // 
            // interestRateTextBox
            // 
            resources.ApplyResources(this.interestRateTextBox, "interestRateTextBox");
            this.interestRateTextBox.Name = "interestRateTextBox";
            this.crunchYourInvestmentToolTip.SetToolTip(this.interestRateTextBox, resources.GetString("interestRateTextBox.ToolTip"));
            this.interestRateTextBox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.interestRateTextBox_KeyDown);
            // 
            // interestRateLabel
            // 
            resources.ApplyResources(this.interestRateLabel, "interestRateLabel");
            this.interestRateLabel.Name = "interestRateLabel";
            this.crunchYourInvestmentToolTip.SetToolTip(this.interestRateLabel, resources.GetString("interestRateLabel.ToolTip"));
            // 
            // numberOfYearsTextBox
            // 
            resources.ApplyResources(this.numberOfYearsTextBox, "numberOfYearsTextBox");
            this.numberOfYearsTextBox.Name = "numberOfYearsTextBox";
            this.crunchYourInvestmentToolTip.SetToolTip(this.numberOfYearsTextBox, resources.GetString("numberOfYearsTextBox.ToolTip"));
            this.numberOfYearsTextBox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.numberOfYearsTextBox_KeyDown);
            // 
            // numberOfYearsLabel
            // 
            resources.ApplyResources(this.numberOfYearsLabel, "numberOfYearsLabel");
            this.numberOfYearsLabel.Name = "numberOfYearsLabel";
            this.crunchYourInvestmentToolTip.SetToolTip(this.numberOfYearsLabel, resources.GetString("numberOfYearsLabel.ToolTip"));
            // 
            // horizontalDividerLabel
            // 
            this.horizontalDividerLabel.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            resources.ApplyResources(this.horizontalDividerLabel, "horizontalDividerLabel");
            this.horizontalDividerLabel.Name = "horizontalDividerLabel";
            // 
            // futureValueLabel
            // 
            resources.ApplyResources(this.futureValueLabel, "futureValueLabel");
            this.futureValueLabel.ForeColor = System.Drawing.SystemColors.ControlText;
            this.futureValueLabel.Name = "futureValueLabel";
            this.crunchYourInvestmentToolTip.SetToolTip(this.futureValueLabel, resources.GetString("futureValueLabel.ToolTip"));
            // 
            // futureValueTextBox
            // 
            resources.ApplyResources(this.futureValueTextBox, "futureValueTextBox");
            this.futureValueTextBox.Name = "futureValueTextBox";
            this.futureValueTextBox.ReadOnly = true;
            this.crunchYourInvestmentToolTip.SetToolTip(this.futureValueTextBox, resources.GetString("futureValueTextBox.ToolTip"));
            // 
            // calculateButton
            // 
            resources.ApplyResources(this.calculateButton, "calculateButton");
            this.calculateButton.Name = "calculateButton";
            this.calculateButton.UseVisualStyleBackColor = true;
            this.calculateButton.Click += new System.EventHandler(this.calculateButton_Click);
            // 
            // exitButton
            // 
            this.exitButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.exitButton.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            resources.ApplyResources(this.exitButton, "exitButton");
            this.exitButton.Name = "exitButton";
            this.exitButton.UseVisualStyleBackColor = true;
            this.exitButton.Click += new System.EventHandler(this.exitButton_Click);
            // 
            // clearButton
            // 
            this.clearButton.Cursor = System.Windows.Forms.Cursors.Hand;
            resources.ApplyResources(this.clearButton, "clearButton");
            this.clearButton.Name = "clearButton";
            this.clearButton.UseVisualStyleBackColor = true;
            this.clearButton.Click += new System.EventHandler(this.clearButton_Click);
            // 
            // CrunchYourInvestmentForm
            // 
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.CancelButton = this.exitButton;
            this.Controls.Add(this.exitButton);
            this.Controls.Add(this.calculateButton);
            this.Controls.Add(this.futureValueTextBox);
            this.Controls.Add(this.futureValueLabel);
            this.Controls.Add(this.horizontalDividerLabel);
            this.Controls.Add(this.numberOfYearsTextBox);
            this.Controls.Add(this.numberOfYearsLabel);
            this.Controls.Add(this.interestRateTextBox);
            this.Controls.Add(this.interestRateLabel);
            this.Controls.Add(this.startingInvestmentTextBox);
            this.Controls.Add(this.startingInvestmentLabel);
            this.Controls.Add(this.clearButton);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = global::CrunchYourInvestment.Properties.Resources._1477602496_Money_Increase;
            this.MaximizeBox = false;
            this.Name = "CrunchYourInvestmentForm";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label startingInvestmentLabel;
        private System.Windows.Forms.TextBox startingInvestmentTextBox;
        private System.Windows.Forms.TextBox interestRateTextBox;
        private System.Windows.Forms.Label interestRateLabel;
        private System.Windows.Forms.TextBox numberOfYearsTextBox;
        private System.Windows.Forms.Label numberOfYearsLabel;
        private System.Windows.Forms.Label horizontalDividerLabel;
        private System.Windows.Forms.Label futureValueLabel;
        private System.Windows.Forms.TextBox futureValueTextBox;
        private System.Windows.Forms.Button calculateButton;
        private System.Windows.Forms.Button exitButton;
        private System.Windows.Forms.Button clearButton;
        private System.Windows.Forms.ToolTip crunchYourInvestmentToolTip;
    }
}

