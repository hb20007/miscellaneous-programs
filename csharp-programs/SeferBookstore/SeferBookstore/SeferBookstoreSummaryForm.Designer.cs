/// <file>
/// <author>Hanna Sababa</author>
/// <datecreated>2016-12-16</datecreated>
/// <summary>
/// Contains the part of the class SeferBookstoreSummaryForm with the automatically-genned code
/// </summary>
/// </file>

namespace SeferBookstore
{
    partial class SeferBookstoreSummaryForm
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
            this.totalSalesLabel = new System.Windows.Forms.Label();
            this.totalItemsSoldLabel = new System.Windows.Forms.Label();
            this.totalSalesTextBox = new System.Windows.Forms.TextBox();
            this.totalItemsSoldTextBox = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // okButton
            // 
            this.okButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.okButton.Location = new System.Drawing.Point(107, 126);
            this.okButton.Name = "okButton";
            this.okButton.Size = new System.Drawing.Size(84, 29);
            this.okButton.TabIndex = 4;
            this.okButton.Text = "&OK";
            this.okButton.UseVisualStyleBackColor = true;
            this.okButton.Click += new System.EventHandler(this.okButton_Click);
            // 
            // totalSalesLabel
            // 
            this.totalSalesLabel.AutoSize = true;
            this.totalSalesLabel.Location = new System.Drawing.Point(72, 33);
            this.totalSalesLabel.Name = "totalSalesLabel";
            this.totalSalesLabel.Size = new System.Drawing.Size(69, 15);
            this.totalSalesLabel.TabIndex = 0;
            this.totalSalesLabel.Text = "Total sales:";
            // 
            // totalItemsSoldLabel
            // 
            this.totalItemsSoldLabel.AutoSize = true;
            this.totalItemsSoldLabel.Location = new System.Drawing.Point(73, 76);
            this.totalItemsSoldLabel.Name = "totalItemsSoldLabel";
            this.totalItemsSoldLabel.Size = new System.Drawing.Size(96, 15);
            this.totalItemsSoldLabel.TabIndex = 2;
            this.totalItemsSoldLabel.Text = "Total items sold:";
            // 
            // totalSalesTextBox
            // 
            this.totalSalesTextBox.Location = new System.Drawing.Point(147, 33);
            this.totalSalesTextBox.Name = "totalSalesTextBox";
            this.totalSalesTextBox.Size = new System.Drawing.Size(75, 21);
            this.totalSalesTextBox.TabIndex = 1;
            this.totalSalesTextBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // totalItemsSoldTextBox
            // 
            this.totalItemsSoldTextBox.Location = new System.Drawing.Point(175, 73);
            this.totalItemsSoldTextBox.Name = "totalItemsSoldTextBox";
            this.totalItemsSoldTextBox.Size = new System.Drawing.Size(47, 21);
            this.totalItemsSoldTextBox.TabIndex = 3;
            this.totalItemsSoldTextBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // SeferBookstoreSummaryForm
            // 
            this.AcceptButton = this.okButton;
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(296, 167);
            this.Controls.Add(this.totalItemsSoldTextBox);
            this.Controls.Add(this.totalSalesTextBox);
            this.Controls.Add(this.totalItemsSoldLabel);
            this.Controls.Add(this.totalSalesLabel);
            this.Controls.Add(this.okButton);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.Icon = global::SeferBookstore.Properties.Resources.seferIcon;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "SeferBookstoreSummaryForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Daily summary";
            this.TopMost = true;
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button okButton;
        private System.Windows.Forms.Label totalSalesLabel;
        private System.Windows.Forms.Label totalItemsSoldLabel;
        private System.Windows.Forms.TextBox totalSalesTextBox;
        private System.Windows.Forms.TextBox totalItemsSoldTextBox;
    }
}