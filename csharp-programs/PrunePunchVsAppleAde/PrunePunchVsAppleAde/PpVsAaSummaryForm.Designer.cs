/// <file>
/// <author>hb20007</author>
/// <datecreated>2016-10-30</datecreated>
/// <summary>
///  Contains the part of the class PpVsAaSummaryForm dealing with the displaying of the form and its controls
/// </summary>
/// </file>

namespace PrunePunchVsAppleAde
{
    partial class PpVsAaSummaryForm
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
            this.okButton = new System.Windows.Forms.Button();
            this.meanRatingPrunePunchLabel = new System.Windows.Forms.Label();
            this.meanRatingAppleAdeLabel = new System.Windows.Forms.Label();
            this.totalNumberOfVotesLabel = new System.Windows.Forms.Label();
            this.winnerLabel = new System.Windows.Forms.Label();
            this.totalNumberOfVotesTextBox = new System.Windows.Forms.TextBox();
            this.meanRatingPrunePunchTextBox = new System.Windows.Forms.TextBox();
            this.meanRatingAppleAdeTextBox = new System.Windows.Forms.TextBox();
            this.winnerTextBox = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // okButton
            // 
            this.okButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.okButton.Location = new System.Drawing.Point(101, 218);
            this.okButton.Name = "okButton";
            this.okButton.Size = new System.Drawing.Size(87, 27);
            this.okButton.TabIndex = 0;
            this.okButton.Text = "OK";
            this.okButton.UseVisualStyleBackColor = true;
            this.okButton.Click += new System.EventHandler(this.okButton_Click);
            // 
            // meanRatingPrunePunchLabel
            // 
            this.meanRatingPrunePunchLabel.AutoSize = true;
            this.meanRatingPrunePunchLabel.Location = new System.Drawing.Point(24, 76);
            this.meanRatingPrunePunchLabel.Name = "meanRatingPrunePunchLabel";
            this.meanRatingPrunePunchLabel.Size = new System.Drawing.Size(172, 15);
            this.meanRatingPrunePunchLabel.TabIndex = 1;
            this.meanRatingPrunePunchLabel.Text = "Mean rating for Prune Punch™";
            // 
            // meanRatingAppleAdeLabel
            // 
            this.meanRatingAppleAdeLabel.AutoSize = true;
            this.meanRatingAppleAdeLabel.Location = new System.Drawing.Point(24, 125);
            this.meanRatingAppleAdeLabel.Name = "meanRatingAppleAdeLabel";
            this.meanRatingAppleAdeLabel.Size = new System.Drawing.Size(156, 15);
            this.meanRatingAppleAdeLabel.TabIndex = 2;
            this.meanRatingAppleAdeLabel.Text = "Mean rating for Apple Ade™";
            // 
            // totalNumberOfVotesLabel
            // 
            this.totalNumberOfVotesLabel.AutoSize = true;
            this.totalNumberOfVotesLabel.Location = new System.Drawing.Point(24, 27);
            this.totalNumberOfVotesLabel.Name = "totalNumberOfVotesLabel";
            this.totalNumberOfVotesLabel.Size = new System.Drawing.Size(130, 15);
            this.totalNumberOfVotesLabel.TabIndex = 3;
            this.totalNumberOfVotesLabel.Text = "Total number of votes: ";
            // 
            // winnerLabel
            // 
            this.winnerLabel.AutoSize = true;
            this.winnerLabel.Location = new System.Drawing.Point(24, 174);
            this.winnerLabel.Name = "winnerLabel";
            this.winnerLabel.Size = new System.Drawing.Size(71, 15);
            this.winnerLabel.TabIndex = 4;
            this.winnerLabel.Text = "The winner:";
            // 
            // totalNumberOfVotesTextBox
            // 
            this.totalNumberOfVotesTextBox.Location = new System.Drawing.Point(160, 26);
            this.totalNumberOfVotesTextBox.Name = "totalNumberOfVotesTextBox";
            this.totalNumberOfVotesTextBox.ReadOnly = true;
            this.totalNumberOfVotesTextBox.Size = new System.Drawing.Size(36, 21);
            this.totalNumberOfVotesTextBox.TabIndex = 5;
            // 
            // meanRatingPrunePunchTextBox
            // 
            this.meanRatingPrunePunchTextBox.Location = new System.Drawing.Point(202, 76);
            this.meanRatingPrunePunchTextBox.Name = "meanRatingPrunePunchTextBox";
            this.meanRatingPrunePunchTextBox.ReadOnly = true;
            this.meanRatingPrunePunchTextBox.Size = new System.Drawing.Size(55, 21);
            this.meanRatingPrunePunchTextBox.TabIndex = 6;
            // 
            // meanRatingAppleAdeTextBox
            // 
            this.meanRatingAppleAdeTextBox.Location = new System.Drawing.Point(186, 122);
            this.meanRatingAppleAdeTextBox.Name = "meanRatingAppleAdeTextBox";
            this.meanRatingAppleAdeTextBox.ReadOnly = true;
            this.meanRatingAppleAdeTextBox.Size = new System.Drawing.Size(55, 21);
            this.meanRatingAppleAdeTextBox.TabIndex = 7;
            // 
            // winnerTextBox
            // 
            this.winnerTextBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.winnerTextBox.Location = new System.Drawing.Point(101, 171);
            this.winnerTextBox.Name = "winnerTextBox";
            this.winnerTextBox.ReadOnly = true;
            this.winnerTextBox.Size = new System.Drawing.Size(104, 21);
            this.winnerTextBox.TabIndex = 8;
            // 
            // PpVsAaSummaryForm
            // 
            this.AcceptButton = this.okButton;
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(296, 254);
            this.Controls.Add(this.winnerTextBox);
            this.Controls.Add(this.meanRatingAppleAdeTextBox);
            this.Controls.Add(this.meanRatingPrunePunchTextBox);
            this.Controls.Add(this.totalNumberOfVotesTextBox);
            this.Controls.Add(this.winnerLabel);
            this.Controls.Add(this.totalNumberOfVotesLabel);
            this.Controls.Add(this.meanRatingAppleAdeLabel);
            this.Controls.Add(this.meanRatingPrunePunchLabel);
            this.Controls.Add(this.okButton);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = global::PrunePunchVsAppleAde.Properties.Resources._1477862040_79;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "PpVsAaSummaryForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Results";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button okButton;
        private System.Windows.Forms.Label meanRatingPrunePunchLabel;
        private System.Windows.Forms.Label meanRatingAppleAdeLabel;
        private System.Windows.Forms.Label totalNumberOfVotesLabel;
        private System.Windows.Forms.Label winnerLabel;
        private System.Windows.Forms.TextBox totalNumberOfVotesTextBox;
        private System.Windows.Forms.TextBox meanRatingPrunePunchTextBox;
        private System.Windows.Forms.TextBox meanRatingAppleAdeTextBox;
        private System.Windows.Forms.TextBox winnerTextBox;
    }
}