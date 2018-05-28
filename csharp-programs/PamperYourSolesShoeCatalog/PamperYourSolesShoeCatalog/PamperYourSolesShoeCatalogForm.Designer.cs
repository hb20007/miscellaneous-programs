/// <file>
/// <author>hb20007</author>
/// <datecreated>2016-10-24</datecreated>
/// <summary>
/// Contains the part of the class shoeCatalogForm which deals with displaying the form and controls
/// </summary>
/// </file>

namespace PamperYourSolesShoeCatalog
{
    partial class shoeCatalogForm
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
            this.horizontalDividerLabel = new System.Windows.Forms.Label();
            this.clearButton = new System.Windows.Forms.Button();
            this.exitButton = new System.Windows.Forms.Button();
            this.flowLayoutPanel1 = new System.Windows.Forms.FlowLayoutPanel();
            this.maleRadioButton = new System.Windows.Forms.RadioButton();
            this.femaleRadioButton = new System.Windows.Forms.RadioButton();
            this.sexSelectionHiddenButton = new System.Windows.Forms.RadioButton();
            this.maleGroupBox = new System.Windows.Forms.GroupBox();
            this.maleStylesHiddenButton = new System.Windows.Forms.RadioButton();
            this.menSandalsRadioButton = new System.Windows.Forms.RadioButton();
            this.menTennisShoesRadioButton = new System.Windows.Forms.RadioButton();
            this.menWesternBootsRadioButton = new System.Windows.Forms.RadioButton();
            this.menWorkBootsRadioButton = new System.Windows.Forms.RadioButton();
            this.menDressShoesRadioButton = new System.Windows.Forms.RadioButton();
            this.shoePictureBox = new System.Windows.Forms.PictureBox();
            this.femaleGroupBox = new System.Windows.Forms.GroupBox();
            this.femaleStylesHiddenButton = new System.Windows.Forms.RadioButton();
            this.womenSandalsRadioButton = new System.Windows.Forms.RadioButton();
            this.womenWesternBootsRadioButton = new System.Windows.Forms.RadioButton();
            this.womenWorkBootsRadioButton = new System.Windows.Forms.RadioButton();
            this.womenDressShoesRadioButton = new System.Windows.Forms.RadioButton();
            this.leftArrowButton = new System.Windows.Forms.Button();
            this.rightArrowButton = new System.Windows.Forms.Button();
            this.makeASelectionLabel = new System.Windows.Forms.Label();
            this.shoeFormToolTip = new System.Windows.Forms.ToolTip(this.components);
            this.currentIndexLabel = new System.Windows.Forms.Label();
            this.flowLayoutPanel1.SuspendLayout();
            this.maleGroupBox.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.shoePictureBox)).BeginInit();
            this.femaleGroupBox.SuspendLayout();
            this.SuspendLayout();
            // 
            // horizontalDividerLabel
            // 
            this.horizontalDividerLabel.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.horizontalDividerLabel.Location = new System.Drawing.Point(2, 302);
            this.horizontalDividerLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.horizontalDividerLabel.Name = "horizontalDividerLabel";
            this.horizontalDividerLabel.Size = new System.Drawing.Size(534, 3);
            this.horizontalDividerLabel.TabIndex = 0;
            // 
            // clearButton
            // 
            this.clearButton.AccessibleRole = System.Windows.Forms.AccessibleRole.ScrollBar;
            this.clearButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.clearButton.Image = global::PamperYourSolesShoeCatalog.Properties.Resources._1477155211_edit_clear;
            this.clearButton.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.clearButton.Location = new System.Drawing.Point(169, 312);
            this.clearButton.Name = "clearButton";
            this.clearButton.Size = new System.Drawing.Size(69, 31);
            this.clearButton.TabIndex = 4;
            this.clearButton.Text = "&Clear";
            this.clearButton.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.clearButton.UseVisualStyleBackColor = true;
            this.clearButton.Click += new System.EventHandler(this.clearButton_Click);
            // 
            // exitButton
            // 
            this.exitButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.exitButton.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.exitButton.Image = global::PamperYourSolesShoeCatalog.Properties.Resources._1477155479_exit;
            this.exitButton.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.exitButton.Location = new System.Drawing.Point(294, 312);
            this.exitButton.Name = "exitButton";
            this.exitButton.Size = new System.Drawing.Size(65, 31);
            this.exitButton.TabIndex = 5;
            this.exitButton.Text = "E&xit";
            this.exitButton.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.exitButton.UseVisualStyleBackColor = true;
            this.exitButton.Click += new System.EventHandler(this.exitButton_Click);
            // 
            // flowLayoutPanel1
            // 
            this.flowLayoutPanel1.Controls.Add(this.maleRadioButton);
            this.flowLayoutPanel1.Controls.Add(this.femaleRadioButton);
            this.flowLayoutPanel1.Controls.Add(this.sexSelectionHiddenButton);
            this.flowLayoutPanel1.Location = new System.Drawing.Point(258, 25);
            this.flowLayoutPanel1.Name = "flowLayoutPanel1";
            this.flowLayoutPanel1.Size = new System.Drawing.Size(169, 29);
            this.flowLayoutPanel1.TabIndex = 0;
            // 
            // maleRadioButton
            // 
            this.maleRadioButton.AutoSize = true;
            this.maleRadioButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.maleRadioButton.Location = new System.Drawing.Point(3, 3);
            this.maleRadioButton.Name = "maleRadioButton";
            this.maleRadioButton.Size = new System.Drawing.Size(53, 19);
            this.maleRadioButton.TabIndex = 0;
            this.maleRadioButton.TabStop = true;
            this.maleRadioButton.Text = "&Male";
            this.maleRadioButton.UseVisualStyleBackColor = true;
            this.maleRadioButton.CheckedChanged += new System.EventHandler(this.maleRadioButton_CheckedChanged);
            // 
            // femaleRadioButton
            // 
            this.femaleRadioButton.AutoSize = true;
            this.femaleRadioButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.femaleRadioButton.Location = new System.Drawing.Point(62, 3);
            this.femaleRadioButton.Name = "femaleRadioButton";
            this.femaleRadioButton.Size = new System.Drawing.Size(67, 19);
            this.femaleRadioButton.TabIndex = 1;
            this.femaleRadioButton.TabStop = true;
            this.femaleRadioButton.Text = "&Female";
            this.femaleRadioButton.UseVisualStyleBackColor = true;
            this.femaleRadioButton.CheckedChanged += new System.EventHandler(this.femaleRadioButton_CheckedChanged);
            // 
            // sexSelectionHiddenButton
            // 
            this.sexSelectionHiddenButton.AutoSize = true;
            this.sexSelectionHiddenButton.CheckAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.sexSelectionHiddenButton.Checked = true;
            this.sexSelectionHiddenButton.Location = new System.Drawing.Point(135, 3);
            this.sexSelectionHiddenButton.Name = "sexSelectionHiddenButton";
            this.sexSelectionHiddenButton.Size = new System.Drawing.Size(14, 13);
            this.sexSelectionHiddenButton.TabIndex = 10;
            this.sexSelectionHiddenButton.TabStop = true;
            this.sexSelectionHiddenButton.UseVisualStyleBackColor = true;
            this.sexSelectionHiddenButton.Visible = false;
            // 
            // maleGroupBox
            // 
            this.maleGroupBox.Controls.Add(this.maleStylesHiddenButton);
            this.maleGroupBox.Controls.Add(this.menSandalsRadioButton);
            this.maleGroupBox.Controls.Add(this.menTennisShoesRadioButton);
            this.maleGroupBox.Controls.Add(this.menWesternBootsRadioButton);
            this.maleGroupBox.Controls.Add(this.menWorkBootsRadioButton);
            this.maleGroupBox.Controls.Add(this.menDressShoesRadioButton);
            this.maleGroupBox.Location = new System.Drawing.Point(26, 67);
            this.maleGroupBox.Name = "maleGroupBox";
            this.maleGroupBox.Size = new System.Drawing.Size(156, 198);
            this.maleGroupBox.TabIndex = 1;
            this.maleGroupBox.TabStop = false;
            this.maleGroupBox.Text = "Style";
            this.maleGroupBox.Visible = false;
            // 
            // maleStylesHiddenButton
            // 
            this.maleStylesHiddenButton.AutoSize = true;
            this.maleStylesHiddenButton.Location = new System.Drawing.Point(137, 174);
            this.maleStylesHiddenButton.Name = "maleStylesHiddenButton";
            this.maleStylesHiddenButton.Size = new System.Drawing.Size(14, 13);
            this.maleStylesHiddenButton.TabIndex = 5;
            this.maleStylesHiddenButton.TabStop = true;
            this.maleStylesHiddenButton.UseVisualStyleBackColor = true;
            this.maleStylesHiddenButton.Visible = false;
            // 
            // menSandalsRadioButton
            // 
            this.menSandalsRadioButton.AutoSize = true;
            this.menSandalsRadioButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.menSandalsRadioButton.Location = new System.Drawing.Point(34, 156);
            this.menSandalsRadioButton.Name = "menSandalsRadioButton";
            this.menSandalsRadioButton.Size = new System.Drawing.Size(70, 19);
            this.menSandalsRadioButton.TabIndex = 4;
            this.menSandalsRadioButton.TabStop = true;
            this.menSandalsRadioButton.Tag = 4;
            this.menSandalsRadioButton.Text = "Sandals";
            this.menSandalsRadioButton.UseVisualStyleBackColor = true;
            this.menSandalsRadioButton.CheckedChanged += new System.EventHandler(this.menSandalsRadioButton_CheckedChanged);
            // 
            // menTennisShoesRadioButton
            // 
            this.menTennisShoesRadioButton.AutoSize = true;
            this.menTennisShoesRadioButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.menTennisShoesRadioButton.Location = new System.Drawing.Point(34, 122);
            this.menTennisShoesRadioButton.Name = "menTennisShoesRadioButton";
            this.menTennisShoesRadioButton.Size = new System.Drawing.Size(98, 19);
            this.menTennisShoesRadioButton.TabIndex = 3;
            this.menTennisShoesRadioButton.TabStop = true;
            this.menTennisShoesRadioButton.Tag = 3;
            this.menTennisShoesRadioButton.Text = "Tennis shoes";
            this.menTennisShoesRadioButton.UseVisualStyleBackColor = true;
            this.menTennisShoesRadioButton.CheckedChanged += new System.EventHandler(this.menTennisShoesRadioButton_CheckedChanged);
            // 
            // menWesternBootsRadioButton
            // 
            this.menWesternBootsRadioButton.AutoSize = true;
            this.menWesternBootsRadioButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.menWesternBootsRadioButton.Location = new System.Drawing.Point(34, 88);
            this.menWesternBootsRadioButton.Name = "menWesternBootsRadioButton";
            this.menWesternBootsRadioButton.Size = new System.Drawing.Size(103, 19);
            this.menWesternBootsRadioButton.TabIndex = 2;
            this.menWesternBootsRadioButton.TabStop = true;
            this.menWesternBootsRadioButton.Tag = 2;
            this.menWesternBootsRadioButton.Text = "Western boots";
            this.menWesternBootsRadioButton.UseVisualStyleBackColor = true;
            this.menWesternBootsRadioButton.CheckedChanged += new System.EventHandler(this.menWesternBootsRadioButton_CheckedChanged);
            // 
            // menWorkBootsRadioButton
            // 
            this.menWorkBootsRadioButton.AutoSize = true;
            this.menWorkBootsRadioButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.menWorkBootsRadioButton.Location = new System.Drawing.Point(34, 54);
            this.menWorkBootsRadioButton.Name = "menWorkBootsRadioButton";
            this.menWorkBootsRadioButton.Size = new System.Drawing.Size(86, 19);
            this.menWorkBootsRadioButton.TabIndex = 1;
            this.menWorkBootsRadioButton.TabStop = true;
            this.menWorkBootsRadioButton.Tag = 1;
            this.menWorkBootsRadioButton.Text = "Work boots";
            this.menWorkBootsRadioButton.UseVisualStyleBackColor = true;
            this.menWorkBootsRadioButton.CheckedChanged += new System.EventHandler(this.menWorkBootsRadioButton_CheckedChanged);
            // 
            // menDressShoesRadioButton
            // 
            this.menDressShoesRadioButton.AutoSize = true;
            this.menDressShoesRadioButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.menDressShoesRadioButton.Location = new System.Drawing.Point(34, 20);
            this.menDressShoesRadioButton.Name = "menDressShoesRadioButton";
            this.menDressShoesRadioButton.Size = new System.Drawing.Size(93, 19);
            this.menDressShoesRadioButton.TabIndex = 0;
            this.menDressShoesRadioButton.TabStop = true;
            this.menDressShoesRadioButton.Tag = 0;
            this.menDressShoesRadioButton.Text = "Dress shoes";
            this.menDressShoesRadioButton.UseVisualStyleBackColor = true;
            this.menDressShoesRadioButton.CheckedChanged += new System.EventHandler(this.menDressShoesRadioButton_CheckedChanged);
            // 
            // shoePictureBox
            // 
            this.shoePictureBox.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.shoePictureBox.Location = new System.Drawing.Point(211, 72);
            this.shoePictureBox.Name = "shoePictureBox";
            this.shoePictureBox.Size = new System.Drawing.Size(295, 193);
            this.shoePictureBox.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.shoePictureBox.TabIndex = 5;
            this.shoePictureBox.TabStop = false;
            this.shoeFormToolTip.SetToolTip(this.shoePictureBox, "Catalog image");
            this.shoePictureBox.Visible = false;
            // 
            // femaleGroupBox
            // 
            this.femaleGroupBox.Controls.Add(this.femaleStylesHiddenButton);
            this.femaleGroupBox.Controls.Add(this.womenSandalsRadioButton);
            this.femaleGroupBox.Controls.Add(this.womenWesternBootsRadioButton);
            this.femaleGroupBox.Controls.Add(this.womenWorkBootsRadioButton);
            this.femaleGroupBox.Controls.Add(this.womenDressShoesRadioButton);
            this.femaleGroupBox.Location = new System.Drawing.Point(26, 67);
            this.femaleGroupBox.Name = "femaleGroupBox";
            this.femaleGroupBox.Size = new System.Drawing.Size(156, 198);
            this.femaleGroupBox.TabIndex = 5;
            this.femaleGroupBox.TabStop = false;
            this.femaleGroupBox.Text = "Style";
            this.femaleGroupBox.Visible = false;
            // 
            // femaleStylesHiddenButton
            // 
            this.femaleStylesHiddenButton.AutoSize = true;
            this.femaleStylesHiddenButton.Location = new System.Drawing.Point(123, 174);
            this.femaleStylesHiddenButton.Name = "femaleStylesHiddenButton";
            this.femaleStylesHiddenButton.Size = new System.Drawing.Size(14, 13);
            this.femaleStylesHiddenButton.TabIndex = 4;
            this.femaleStylesHiddenButton.TabStop = true;
            this.femaleStylesHiddenButton.UseVisualStyleBackColor = true;
            this.femaleStylesHiddenButton.Visible = false;
            // 
            // womenSandalsRadioButton
            // 
            this.womenSandalsRadioButton.AutoSize = true;
            this.womenSandalsRadioButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.womenSandalsRadioButton.Location = new System.Drawing.Point(34, 164);
            this.womenSandalsRadioButton.Name = "womenSandalsRadioButton";
            this.womenSandalsRadioButton.Size = new System.Drawing.Size(70, 19);
            this.womenSandalsRadioButton.TabIndex = 3;
            this.womenSandalsRadioButton.TabStop = true;
            this.womenSandalsRadioButton.Tag = 8;
            this.womenSandalsRadioButton.Text = "Sandals";
            this.womenSandalsRadioButton.UseVisualStyleBackColor = true;
            this.womenSandalsRadioButton.CheckedChanged += new System.EventHandler(this.womenSandalsRadioButton_CheckedChanged);
            // 
            // womenWesternBootsRadioButton
            // 
            this.womenWesternBootsRadioButton.AutoSize = true;
            this.womenWesternBootsRadioButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.womenWesternBootsRadioButton.Location = new System.Drawing.Point(34, 119);
            this.womenWesternBootsRadioButton.Name = "womenWesternBootsRadioButton";
            this.womenWesternBootsRadioButton.Size = new System.Drawing.Size(103, 19);
            this.womenWesternBootsRadioButton.TabIndex = 2;
            this.womenWesternBootsRadioButton.TabStop = true;
            this.womenWesternBootsRadioButton.Tag = 7;
            this.womenWesternBootsRadioButton.Text = "Western boots";
            this.womenWesternBootsRadioButton.UseVisualStyleBackColor = true;
            this.womenWesternBootsRadioButton.CheckedChanged += new System.EventHandler(this.womenWesternBootsRadioButton_CheckedChanged);
            // 
            // womenWorkBootsRadioButton
            // 
            this.womenWorkBootsRadioButton.AutoSize = true;
            this.womenWorkBootsRadioButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.womenWorkBootsRadioButton.Location = new System.Drawing.Point(34, 74);
            this.womenWorkBootsRadioButton.Name = "womenWorkBootsRadioButton";
            this.womenWorkBootsRadioButton.Size = new System.Drawing.Size(86, 19);
            this.womenWorkBootsRadioButton.TabIndex = 1;
            this.womenWorkBootsRadioButton.TabStop = true;
            this.womenWorkBootsRadioButton.Tag = 6;
            this.womenWorkBootsRadioButton.Text = "Work boots";
            this.womenWorkBootsRadioButton.UseVisualStyleBackColor = true;
            this.womenWorkBootsRadioButton.CheckedChanged += new System.EventHandler(this.womenWorkBootsRadioButton_CheckedChanged);
            // 
            // womenDressShoesRadioButton
            // 
            this.womenDressShoesRadioButton.AutoSize = true;
            this.womenDressShoesRadioButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.womenDressShoesRadioButton.Location = new System.Drawing.Point(34, 29);
            this.womenDressShoesRadioButton.Name = "womenDressShoesRadioButton";
            this.womenDressShoesRadioButton.Size = new System.Drawing.Size(93, 19);
            this.womenDressShoesRadioButton.TabIndex = 0;
            this.womenDressShoesRadioButton.TabStop = true;
            this.womenDressShoesRadioButton.Tag = 5;
            this.womenDressShoesRadioButton.Text = "Dress shoes";
            this.womenDressShoesRadioButton.UseVisualStyleBackColor = true;
            this.womenDressShoesRadioButton.CheckedChanged += new System.EventHandler(this.womenDressShoesRadioButton_CheckedChanged);
            // 
            // leftArrowButton
            // 
            this.leftArrowButton.BackgroundImage = global::PamperYourSolesShoeCatalog.Properties.Resources._1477161328_icon_arrow_left_b;
            this.leftArrowButton.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.leftArrowButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.leftArrowButton.FlatAppearance.BorderSize = 0;
            this.leftArrowButton.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Transparent;
            this.leftArrowButton.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Transparent;
            this.leftArrowButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.leftArrowButton.Location = new System.Drawing.Point(325, 271);
            this.leftArrowButton.Name = "leftArrowButton";
            this.leftArrowButton.Size = new System.Drawing.Size(17, 19);
            this.leftArrowButton.TabIndex = 2;
            this.leftArrowButton.UseVisualStyleBackColor = true;
            this.leftArrowButton.Visible = false;
            this.leftArrowButton.Click += new System.EventHandler(this.leftArrowButton_Click);
            this.leftArrowButton.MouseDown += new System.Windows.Forms.MouseEventHandler(this.leftArrowButton_MouseDown);
            this.leftArrowButton.MouseLeave += new System.EventHandler(this.leftArrowButton_MouseLeave);
            this.leftArrowButton.MouseHover += new System.EventHandler(this.leftArrowButton_MouseHover);
            this.leftArrowButton.MouseUp += new System.Windows.Forms.MouseEventHandler(this.leftArrowButton_MouseUp);
            // 
            // rightArrowButton
            // 
            this.rightArrowButton.BackgroundImage = global::PamperYourSolesShoeCatalog.Properties.Resources._1477161330_icon_arrow_right_b;
            this.rightArrowButton.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.rightArrowButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.rightArrowButton.FlatAppearance.BorderSize = 0;
            this.rightArrowButton.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Transparent;
            this.rightArrowButton.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Transparent;
            this.rightArrowButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rightArrowButton.Location = new System.Drawing.Point(376, 271);
            this.rightArrowButton.Name = "rightArrowButton";
            this.rightArrowButton.Size = new System.Drawing.Size(17, 19);
            this.rightArrowButton.TabIndex = 3;
            this.rightArrowButton.UseVisualStyleBackColor = true;
            this.rightArrowButton.Visible = false;
            this.rightArrowButton.Click += new System.EventHandler(this.rightArrowButton_Click);
            this.rightArrowButton.MouseDown += new System.Windows.Forms.MouseEventHandler(this.rightArrowButton_MouseDown);
            this.rightArrowButton.MouseLeave += new System.EventHandler(this.rightArrowButton_MouseLeave);
            this.rightArrowButton.MouseHover += new System.EventHandler(this.rightArrowButton_MouseHover);
            this.rightArrowButton.MouseUp += new System.Windows.Forms.MouseEventHandler(this.rightArrowButton_MouseUp);
            // 
            // makeASelectionLabel
            // 
            this.makeASelectionLabel.AutoSize = true;
            this.makeASelectionLabel.Location = new System.Drawing.Point(135, 28);
            this.makeASelectionLabel.Name = "makeASelectionLabel";
            this.makeASelectionLabel.Size = new System.Drawing.Size(103, 15);
            this.makeASelectionLabel.TabIndex = 6;
            this.makeASelectionLabel.Text = "Make a selection:";
            // 
            // currentIndexLabel
            // 
            this.currentIndexLabel.AutoSize = true;
            this.currentIndexLabel.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            this.currentIndexLabel.Location = new System.Drawing.Point(344, 273);
            this.currentIndexLabel.Name = "currentIndexLabel";
            this.currentIndexLabel.Size = new System.Drawing.Size(0, 15);
            this.currentIndexLabel.TabIndex = 7;
            this.shoeFormToolTip.SetToolTip(this.currentIndexLabel, "Index of current image / number of images");
            this.currentIndexLabel.Visible = false;
            // 
            // shoeCatalogForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.CancelButton = this.exitButton;
            this.ClientSize = new System.Drawing.Size(536, 350);
            this.Controls.Add(this.currentIndexLabel);
            this.Controls.Add(this.makeASelectionLabel);
            this.Controls.Add(this.rightArrowButton);
            this.Controls.Add(this.leftArrowButton);
            this.Controls.Add(this.femaleGroupBox);
            this.Controls.Add(this.shoePictureBox);
            this.Controls.Add(this.maleGroupBox);
            this.Controls.Add(this.flowLayoutPanel1);
            this.Controls.Add(this.exitButton);
            this.Controls.Add(this.clearButton);
            this.Controls.Add(this.horizontalDividerLabel);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = global::PamperYourSolesShoeCatalog.Properties.Resources._1477153640_fashion;
            this.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
            this.MaximizeBox = false;
            this.Name = "shoeCatalogForm";
            this.RightToLeftLayout = true;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Pamper Your Soles™ Catalog";
            this.flowLayoutPanel1.ResumeLayout(false);
            this.flowLayoutPanel1.PerformLayout();
            this.maleGroupBox.ResumeLayout(false);
            this.maleGroupBox.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.shoePictureBox)).EndInit();
            this.femaleGroupBox.ResumeLayout(false);
            this.femaleGroupBox.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label horizontalDividerLabel;
        private System.Windows.Forms.Button clearButton;
        private System.Windows.Forms.Button exitButton;
        private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel1;
        private System.Windows.Forms.RadioButton maleRadioButton;
        private System.Windows.Forms.RadioButton femaleRadioButton;
        private System.Windows.Forms.GroupBox maleGroupBox;
        private System.Windows.Forms.PictureBox shoePictureBox;
        private System.Windows.Forms.RadioButton menSandalsRadioButton;
        private System.Windows.Forms.RadioButton menTennisShoesRadioButton;
        private System.Windows.Forms.RadioButton menWesternBootsRadioButton;
        private System.Windows.Forms.RadioButton menWorkBootsRadioButton;
        private System.Windows.Forms.RadioButton menDressShoesRadioButton;
        private System.Windows.Forms.GroupBox femaleGroupBox;
        private System.Windows.Forms.RadioButton womenSandalsRadioButton;
        private System.Windows.Forms.RadioButton womenWesternBootsRadioButton;
        private System.Windows.Forms.RadioButton womenWorkBootsRadioButton;
        private System.Windows.Forms.RadioButton womenDressShoesRadioButton;
        private System.Windows.Forms.Button leftArrowButton;
        private System.Windows.Forms.Button rightArrowButton;
        private System.Windows.Forms.RadioButton sexSelectionHiddenButton;
        private System.Windows.Forms.Label makeASelectionLabel;
        private System.Windows.Forms.RadioButton femaleStylesHiddenButton;
        private System.Windows.Forms.RadioButton maleStylesHiddenButton;
        private System.Windows.Forms.ToolTip shoeFormToolTip;
        private System.Windows.Forms.Label currentIndexLabel;
    }
}

