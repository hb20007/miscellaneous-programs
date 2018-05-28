/// <file>
/// <author>hb20007</author>
/// <datecreated>2016-11-07</datecreated>
/// <summary>
/// Countains the part of the class SeferBookstoreMainForm dealing with the drawing of the form and its components on the screen
/// </summary>
/// </file>

namespace SeferBookstore
{
    partial class SeferBookstoreMainForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(SeferBookstoreMainForm));
            this.seferBookstoreMainFormToolTip = new System.Windows.Forms.ToolTip(this.components);
            this.allTitlesLabel = new System.Windows.Forms.Label();
            this.allTitlesListBox = new System.Windows.Forms.ListBox();
            this.searchPictureBox = new System.Windows.Forms.PictureBox();
            this.searchTextBox = new System.Windows.Forms.TextBox();
            this.advancedSearchButton = new System.Windows.Forms.Button();
            this.addButton = new System.Windows.Forms.Button();
            this.removeButton = new System.Windows.Forms.Button();
            this.shopListListBox = new System.Windows.Forms.ListBox();
            this.shopListLabel = new System.Windows.Forms.Label();
            this.resetShoplistButton = new System.Windows.Forms.Button();
            this.bookPictureBox = new System.Windows.Forms.PictureBox();
            this.wikipediaPageButton = new System.Windows.Forms.Button();
            this.totalLabel = new System.Windows.Forms.Label();
            this.totalTextBox = new System.Windows.Forms.TextBox();
            this.clearButton = new System.Windows.Forms.Button();
            this.checkoutButton = new System.Windows.Forms.Button();
            this.questionMarkPictureBox = new System.Windows.Forms.PictureBox();
            this.seferBookstoreMainFormMenuStrip = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.dailySumarryToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.resetSumarryToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.fileToolStripSeparator = new System.Windows.Forms.ToolStripSeparator();
            this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.editToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.cutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.copyToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.pasteToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.editToolStripSeparator = new System.Windows.Forms.ToolStripSeparator();
            this.selectAllToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.customizeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.changefontToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.changeFontcolorToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.aboutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.seferBookstoreFontDialog = new System.Windows.Forms.FontDialog();
            this.seferBookstoreColorDialog = new System.Windows.Forms.ColorDialog();
            this.seferBookstoreMainFormContextMenuStrip = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.advancedBookSearchToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.clearToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.resetShoplistToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.bookInformationGroupBox = new System.Windows.Forms.GroupBox();
            this.languageTextBox = new System.Windows.Forms.TextBox();
            this.countryTextBox = new System.Windows.Forms.TextBox();
            this.yearTextBox = new System.Windows.Forms.TextBox();
            this.authorTextBox = new System.Windows.Forms.TextBox();
            this.titleTextBox = new System.Windows.Forms.TextBox();
            this.languageLabel = new System.Windows.Forms.Label();
            this.countryLabel = new System.Windows.Forms.Label();
            this.yearLabel = new System.Windows.Forms.Label();
            this.authorLabel = new System.Windows.Forms.Label();
            this.titleLabel = new System.Windows.Forms.Label();
            this.horizontalDividerLabel = new System.Windows.Forms.Label();
            this.seferBookstoreMainFormImageList = new System.Windows.Forms.ImageList(this.components);
            ((System.ComponentModel.ISupportInitialize)(this.searchPictureBox)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.bookPictureBox)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.questionMarkPictureBox)).BeginInit();
            this.seferBookstoreMainFormMenuStrip.SuspendLayout();
            this.seferBookstoreMainFormContextMenuStrip.SuspendLayout();
            this.bookInformationGroupBox.SuspendLayout();
            this.SuspendLayout();
            // 
            // allTitlesLabel
            // 
            this.allTitlesLabel.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.allTitlesLabel.AutoSize = true;
            this.allTitlesLabel.Location = new System.Drawing.Point(93, 35);
            this.allTitlesLabel.Name = "allTitlesLabel";
            this.allTitlesLabel.Size = new System.Drawing.Size(53, 15);
            this.allTitlesLabel.TabIndex = 1;
            this.allTitlesLabel.Text = "All Titles";
            this.seferBookstoreMainFormToolTip.SetToolTip(this.allTitlesLabel, "Select a title here to view book details");
            // 
            // allTitlesListBox
            // 
            this.allTitlesListBox.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.allTitlesListBox.FormattingEnabled = true;
            this.allTitlesListBox.ItemHeight = 15;
            this.allTitlesListBox.Location = new System.Drawing.Point(14, 55);
            this.allTitlesListBox.Name = "allTitlesListBox";
            this.allTitlesListBox.Size = new System.Drawing.Size(225, 154);
            this.allTitlesListBox.TabIndex = 2;
            this.seferBookstoreMainFormToolTip.SetToolTip(this.allTitlesListBox, "Select a title here to view book details");
            this.allTitlesListBox.SelectedIndexChanged += new System.EventHandler(this.allTitlesListBox_SelectedIndexChanged);
            this.allTitlesListBox.DoubleClick += new System.EventHandler(this.allTitlesListBox_DoubleClick);
            // 
            // searchPictureBox
            // 
            this.searchPictureBox.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.searchPictureBox.Image = ((System.Drawing.Image)(resources.GetObject("searchPictureBox.Image")));
            this.searchPictureBox.Location = new System.Drawing.Point(10, 212);
            this.searchPictureBox.Name = "searchPictureBox";
            this.searchPictureBox.Size = new System.Drawing.Size(25, 25);
            this.searchPictureBox.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.searchPictureBox.TabIndex = 3;
            this.searchPictureBox.TabStop = false;
            this.seferBookstoreMainFormToolTip.SetToolTip(this.searchPictureBox, "Find a title");
            // 
            // searchTextBox
            // 
            this.searchTextBox.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.searchTextBox.AutoCompleteMode = System.Windows.Forms.AutoCompleteMode.SuggestAppend;
            this.searchTextBox.AutoCompleteSource = System.Windows.Forms.AutoCompleteSource.CustomSource;
            this.searchTextBox.Location = new System.Drawing.Point(34, 215);
            this.searchTextBox.Name = "searchTextBox";
            this.searchTextBox.Size = new System.Drawing.Size(124, 21);
            this.searchTextBox.TabIndex = 3;
            this.seferBookstoreMainFormToolTip.SetToolTip(this.searchTextBox, "Find a title");
            this.searchTextBox.TextChanged += new System.EventHandler(this.searchTextBox_TextChanged);
            // 
            // advancedSearchButton
            // 
            this.advancedSearchButton.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.advancedSearchButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.advancedSearchButton.Location = new System.Drawing.Point(165, 213);
            this.advancedSearchButton.Name = "advancedSearchButton";
            this.advancedSearchButton.Size = new System.Drawing.Size(75, 24);
            this.advancedSearchButton.TabIndex = 4;
            this.advancedSearchButton.Text = "&Advanced";
            this.seferBookstoreMainFormToolTip.SetToolTip(this.advancedSearchButton, "Launch advanced search");
            this.advancedSearchButton.UseVisualStyleBackColor = true;
            this.advancedSearchButton.Click += new System.EventHandler(this.advancedSearchButton_Click);
            // 
            // addButton
            // 
            this.addButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.addButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.addButton.Location = new System.Drawing.Point(245, 102);
            this.addButton.Name = "addButton";
            this.addButton.Size = new System.Drawing.Size(86, 23);
            this.addButton.TabIndex = 5;
            this.addButton.Text = "&Add >>";
            this.seferBookstoreMainFormToolTip.SetToolTip(this.addButton, "Add selected book to shoplist");
            this.addButton.UseVisualStyleBackColor = true;
            this.addButton.Click += new System.EventHandler(this.addButton_Click);
            // 
            // removeButton
            // 
            this.removeButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.removeButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.removeButton.Location = new System.Drawing.Point(245, 139);
            this.removeButton.Name = "removeButton";
            this.removeButton.Size = new System.Drawing.Size(86, 23);
            this.removeButton.TabIndex = 6;
            this.removeButton.Text = "<< &Remove";
            this.seferBookstoreMainFormToolTip.SetToolTip(this.removeButton, "Remove selected book from shoplist");
            this.removeButton.UseVisualStyleBackColor = true;
            this.removeButton.Click += new System.EventHandler(this.removeButton_Click);
            // 
            // shopListListBox
            // 
            this.shopListListBox.Anchor = System.Windows.Forms.AnchorStyles.Right;
            this.shopListListBox.FormattingEnabled = true;
            this.shopListListBox.ItemHeight = 15;
            this.shopListListBox.Location = new System.Drawing.Point(337, 55);
            this.shopListListBox.Name = "shopListListBox";
            this.shopListListBox.Size = new System.Drawing.Size(225, 154);
            this.shopListListBox.TabIndex = 8;
            this.seferBookstoreMainFormToolTip.SetToolTip(this.shopListListBox, "The list of all books you want to buy");
            this.shopListListBox.DoubleClick += new System.EventHandler(this.shopListListBox_DoubleClick);
            // 
            // shopListLabel
            // 
            this.shopListLabel.Anchor = System.Windows.Forms.AnchorStyles.Right;
            this.shopListLabel.AutoSize = true;
            this.shopListLabel.Location = new System.Drawing.Point(421, 35);
            this.shopListLabel.Name = "shopListLabel";
            this.shopListLabel.Size = new System.Drawing.Size(52, 15);
            this.shopListLabel.TabIndex = 7;
            this.shopListLabel.Text = "Shoplist";
            this.seferBookstoreMainFormToolTip.SetToolTip(this.shopListLabel, "The list of all books you want to buy");
            // 
            // resetShoplistButton
            // 
            this.resetShoplistButton.Anchor = System.Windows.Forms.AnchorStyles.Right;
            this.resetShoplistButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.resetShoplistButton.Location = new System.Drawing.Point(487, 214);
            this.resetShoplistButton.Name = "resetShoplistButton";
            this.resetShoplistButton.Size = new System.Drawing.Size(75, 24);
            this.resetShoplistButton.TabIndex = 11;
            this.resetShoplistButton.Text = "Rese&t shoplist";
            this.seferBookstoreMainFormToolTip.SetToolTip(this.resetShoplistButton, "Remove all items in the shoplist");
            this.resetShoplistButton.UseVisualStyleBackColor = true;
            this.resetShoplistButton.Click += new System.EventHandler(this.resetShoplistButton_Click);
            // 
            // bookPictureBox
            // 
            this.bookPictureBox.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.bookPictureBox.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.bookPictureBox.Location = new System.Drawing.Point(353, 20);
            this.bookPictureBox.Name = "bookPictureBox";
            this.bookPictureBox.Size = new System.Drawing.Size(130, 188);
            this.bookPictureBox.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.bookPictureBox.TabIndex = 11;
            this.bookPictureBox.TabStop = false;
            this.seferBookstoreMainFormToolTip.SetToolTip(this.bookPictureBox, "Book cover");
            // 
            // wikipediaPageButton
            // 
            this.wikipediaPageButton.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.wikipediaPageButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.wikipediaPageButton.Location = new System.Drawing.Point(111, 179);
            this.wikipediaPageButton.Name = "wikipediaPageButton";
            this.wikipediaPageButton.Size = new System.Drawing.Size(113, 23);
            this.wikipediaPageButton.TabIndex = 10;
            this.wikipediaPageButton.Text = "&Wikipedia page";
            this.seferBookstoreMainFormToolTip.SetToolTip(this.wikipediaPageButton, "Visit the Wikipedia page of the selected  book");
            this.wikipediaPageButton.UseVisualStyleBackColor = true;
            this.wikipediaPageButton.Click += new System.EventHandler(this.wikipediaPageButton_Click);
            // 
            // totalLabel
            // 
            this.totalLabel.Anchor = System.Windows.Forms.AnchorStyles.Right;
            this.totalLabel.AutoSize = true;
            this.totalLabel.Location = new System.Drawing.Point(334, 218);
            this.totalLabel.Name = "totalLabel";
            this.totalLabel.Size = new System.Drawing.Size(36, 15);
            this.totalLabel.TabIndex = 9;
            this.totalLabel.Text = "Total:";
            this.seferBookstoreMainFormToolTip.SetToolTip(this.totalLabel, "Total price for books in the shoplist");
            // 
            // totalTextBox
            // 
            this.totalTextBox.Anchor = System.Windows.Forms.AnchorStyles.Right;
            this.totalTextBox.Location = new System.Drawing.Point(371, 216);
            this.totalTextBox.Name = "totalTextBox";
            this.totalTextBox.ReadOnly = true;
            this.totalTextBox.Size = new System.Drawing.Size(84, 21);
            this.totalTextBox.TabIndex = 10;
            this.seferBookstoreMainFormToolTip.SetToolTip(this.totalTextBox, "Total price for books in the shoplist");
            // 
            // clearButton
            // 
            this.clearButton.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
            this.clearButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.clearButton.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.clearButton.Location = new System.Drawing.Point(203, 475);
            this.clearButton.Name = "clearButton";
            this.clearButton.Size = new System.Drawing.Size(87, 23);
            this.clearButton.TabIndex = 13;
            this.clearButton.Text = "C&lear";
            this.seferBookstoreMainFormToolTip.SetToolTip(this.clearButton, "Clear the form");
            this.clearButton.UseVisualStyleBackColor = true;
            this.clearButton.Click += new System.EventHandler(this.clearButton_Click);
            // 
            // checkoutButton
            // 
            this.checkoutButton.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
            this.checkoutButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.checkoutButton.Location = new System.Drawing.Point(296, 475);
            this.checkoutButton.Name = "checkoutButton";
            this.checkoutButton.Size = new System.Drawing.Size(87, 23);
            this.checkoutButton.TabIndex = 14;
            this.checkoutButton.Text = "&Checkout";
            this.seferBookstoreMainFormToolTip.SetToolTip(this.checkoutButton, "Checkout with items in shoplist");
            this.checkoutButton.UseVisualStyleBackColor = true;
            this.checkoutButton.Click += new System.EventHandler(this.checkoutButton_Click);
            // 
            // questionMarkPictureBox
            // 
            this.questionMarkPictureBox.Anchor = System.Windows.Forms.AnchorStyles.Right;
            this.questionMarkPictureBox.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.questionMarkPictureBox.Image = global::SeferBookstore.Properties.Resources.seferQuestionMark;
            this.questionMarkPictureBox.Location = new System.Drawing.Point(437, 216);
            this.questionMarkPictureBox.Name = "questionMarkPictureBox";
            this.questionMarkPictureBox.Size = new System.Drawing.Size(19, 21);
            this.questionMarkPictureBox.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.questionMarkPictureBox.TabIndex = 16;
            this.questionMarkPictureBox.TabStop = false;
            this.questionMarkPictureBox.MouseLeave += new System.EventHandler(this.questionMarkPictureBox_MouseLeave);
            this.questionMarkPictureBox.MouseHover += new System.EventHandler(this.questionMarkPictureBox_MouseHover);
            // 
            // seferBookstoreMainFormMenuStrip
            // 
            this.seferBookstoreMainFormMenuStrip.BackColor = System.Drawing.SystemColors.Control;
            this.seferBookstoreMainFormMenuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.editToolStripMenuItem,
            this.toolsToolStripMenuItem,
            this.helpToolStripMenuItem});
            this.seferBookstoreMainFormMenuStrip.Location = new System.Drawing.Point(0, 0);
            this.seferBookstoreMainFormMenuStrip.Name = "seferBookstoreMainFormMenuStrip";
            this.seferBookstoreMainFormMenuStrip.Size = new System.Drawing.Size(574, 24);
            this.seferBookstoreMainFormMenuStrip.TabIndex = 0;
            this.seferBookstoreMainFormMenuStrip.Text = "seferBookstoreMainFormMenuStrip";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.dailySumarryToolStripMenuItem,
            this.resetSumarryToolStripMenuItem,
            this.fileToolStripSeparator,
            this.exitToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.fileToolStripMenuItem.Text = "&File";
            // 
            // dailySumarryToolStripMenuItem
            // 
            this.dailySumarryToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("dailySumarryToolStripMenuItem.Image")));
            this.dailySumarryToolStripMenuItem.Name = "dailySumarryToolStripMenuItem";
            this.dailySumarryToolStripMenuItem.Size = new System.Drawing.Size(157, 22);
            this.dailySumarryToolStripMenuItem.Text = "Daily &sumarry...";
            this.dailySumarryToolStripMenuItem.Click += new System.EventHandler(this.dailySumarryToolStripMenuItem_Click);
            // 
            // resetSumarryToolStripMenuItem
            // 
            this.resetSumarryToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("resetSumarryToolStripMenuItem.Image")));
            this.resetSumarryToolStripMenuItem.Name = "resetSumarryToolStripMenuItem";
            this.resetSumarryToolStripMenuItem.Size = new System.Drawing.Size(157, 22);
            this.resetSumarryToolStripMenuItem.Text = "&Reset sumarry...";
            this.resetSumarryToolStripMenuItem.Click += new System.EventHandler(this.resetSumarryToolStripMenuItem_Click);
            // 
            // fileToolStripSeparator
            // 
            this.fileToolStripSeparator.Name = "fileToolStripSeparator";
            this.fileToolStripSeparator.Size = new System.Drawing.Size(154, 6);
            // 
            // exitToolStripMenuItem
            // 
            this.exitToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("exitToolStripMenuItem.Image")));
            this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            this.exitToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Alt | System.Windows.Forms.Keys.F4)));
            this.exitToolStripMenuItem.Size = new System.Drawing.Size(157, 22);
            this.exitToolStripMenuItem.Text = "E&xit";
            this.exitToolStripMenuItem.Click += new System.EventHandler(this.exitToolStripMenuItem_Click);
            // 
            // editToolStripMenuItem
            // 
            this.editToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.cutToolStripMenuItem,
            this.copyToolStripMenuItem,
            this.pasteToolStripMenuItem,
            this.editToolStripSeparator,
            this.selectAllToolStripMenuItem});
            this.editToolStripMenuItem.Name = "editToolStripMenuItem";
            this.editToolStripMenuItem.Size = new System.Drawing.Size(39, 20);
            this.editToolStripMenuItem.Text = "&Edit";
            // 
            // cutToolStripMenuItem
            // 
            this.cutToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("cutToolStripMenuItem.Image")));
            this.cutToolStripMenuItem.Name = "cutToolStripMenuItem";
            this.cutToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.X)));
            this.cutToolStripMenuItem.Size = new System.Drawing.Size(164, 22);
            this.cutToolStripMenuItem.Text = "Cu&t";
            this.cutToolStripMenuItem.Click += new System.EventHandler(this.cutToolStripMenuItem_Click);
            // 
            // copyToolStripMenuItem
            // 
            this.copyToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("copyToolStripMenuItem.Image")));
            this.copyToolStripMenuItem.Name = "copyToolStripMenuItem";
            this.copyToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.C)));
            this.copyToolStripMenuItem.Size = new System.Drawing.Size(164, 22);
            this.copyToolStripMenuItem.Text = "&Copy";
            this.copyToolStripMenuItem.Click += new System.EventHandler(this.copyToolStripMenuItem_Click);
            // 
            // pasteToolStripMenuItem
            // 
            this.pasteToolStripMenuItem.Enabled = false;
            this.pasteToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("pasteToolStripMenuItem.Image")));
            this.pasteToolStripMenuItem.Name = "pasteToolStripMenuItem";
            this.pasteToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.V)));
            this.pasteToolStripMenuItem.Size = new System.Drawing.Size(164, 22);
            this.pasteToolStripMenuItem.Text = "&Paste";
            this.pasteToolStripMenuItem.Click += new System.EventHandler(this.pasteToolStripMenuItem_Click);
            // 
            // editToolStripSeparator
            // 
            this.editToolStripSeparator.Name = "editToolStripSeparator";
            this.editToolStripSeparator.Size = new System.Drawing.Size(161, 6);
            // 
            // selectAllToolStripMenuItem
            // 
            this.selectAllToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("selectAllToolStripMenuItem.Image")));
            this.selectAllToolStripMenuItem.Name = "selectAllToolStripMenuItem";
            this.selectAllToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.A)));
            this.selectAllToolStripMenuItem.Size = new System.Drawing.Size(164, 22);
            this.selectAllToolStripMenuItem.Text = "Select &All";
            this.selectAllToolStripMenuItem.Click += new System.EventHandler(this.selectAllToolStripMenuItem_Click);
            // 
            // toolsToolStripMenuItem
            // 
            this.toolsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.customizeToolStripMenuItem});
            this.toolsToolStripMenuItem.Name = "toolsToolStripMenuItem";
            this.toolsToolStripMenuItem.Size = new System.Drawing.Size(47, 20);
            this.toolsToolStripMenuItem.Text = "&Tools";
            // 
            // customizeToolStripMenuItem
            // 
            this.customizeToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.changefontToolStripMenuItem,
            this.changeFontcolorToolStripMenuItem});
            this.customizeToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("customizeToolStripMenuItem.Image")));
            this.customizeToolStripMenuItem.Name = "customizeToolStripMenuItem";
            this.customizeToolStripMenuItem.Size = new System.Drawing.Size(130, 22);
            this.customizeToolStripMenuItem.Text = "&Customize";
            // 
            // changefontToolStripMenuItem
            // 
            this.changefontToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("changefontToolStripMenuItem.Image")));
            this.changefontToolStripMenuItem.Name = "changefontToolStripMenuItem";
            this.changefontToolStripMenuItem.Size = new System.Drawing.Size(179, 22);
            this.changefontToolStripMenuItem.Text = "Change &font...";
            this.changefontToolStripMenuItem.Click += new System.EventHandler(this.changefontToolStripMenuItem_Click);
            // 
            // changeFontcolorToolStripMenuItem
            // 
            this.changeFontcolorToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("changeFontcolorToolStripMenuItem.Image")));
            this.changeFontcolorToolStripMenuItem.Name = "changeFontcolorToolStripMenuItem";
            this.changeFontcolorToolStripMenuItem.Size = new System.Drawing.Size(179, 22);
            this.changeFontcolorToolStripMenuItem.Text = "Change font &color...";
            this.changeFontcolorToolStripMenuItem.Click += new System.EventHandler(this.changeFontcolorToolStripMenuItem_Click);
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
            this.aboutToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("aboutToolStripMenuItem.Image")));
            this.aboutToolStripMenuItem.Name = "aboutToolStripMenuItem";
            this.aboutToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.F1)));
            this.aboutToolStripMenuItem.Size = new System.Drawing.Size(153, 22);
            this.aboutToolStripMenuItem.Text = "&About";
            this.aboutToolStripMenuItem.Click += new System.EventHandler(this.aboutToolStripMenuItem_Click);
            // 
            // seferBookstoreMainFormContextMenuStrip
            // 
            this.seferBookstoreMainFormContextMenuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.advancedBookSearchToolStripMenuItem,
            this.clearToolStripMenuItem,
            this.resetShoplistToolStripMenuItem});
            this.seferBookstoreMainFormContextMenuStrip.Name = "seferBookstoreMainFormContextMenuStrip";
            this.seferBookstoreMainFormContextMenuStrip.Size = new System.Drawing.Size(195, 70);
            // 
            // advancedBookSearchToolStripMenuItem
            // 
            this.advancedBookSearchToolStripMenuItem.Name = "advancedBookSearchToolStripMenuItem";
            this.advancedBookSearchToolStripMenuItem.Size = new System.Drawing.Size(194, 22);
            this.advancedBookSearchToolStripMenuItem.Text = "&Advanced book search";
            this.advancedBookSearchToolStripMenuItem.Click += new System.EventHandler(this.advancedBookSearchToolStripMenuItem_Click);
            // 
            // clearToolStripMenuItem
            // 
            this.clearToolStripMenuItem.Name = "clearToolStripMenuItem";
            this.clearToolStripMenuItem.Size = new System.Drawing.Size(194, 22);
            this.clearToolStripMenuItem.Text = "C&lear";
            this.clearToolStripMenuItem.Click += new System.EventHandler(this.clearToolStripMenuItem_Click);
            // 
            // resetShoplistToolStripMenuItem
            // 
            this.resetShoplistToolStripMenuItem.Name = "resetShoplistToolStripMenuItem";
            this.resetShoplistToolStripMenuItem.Size = new System.Drawing.Size(194, 22);
            this.resetShoplistToolStripMenuItem.Text = "&Reset Shoplist";
            this.resetShoplistToolStripMenuItem.Click += new System.EventHandler(this.resetShoplistToolStripMenuItem_Click);
            // 
            // bookInformationGroupBox
            // 
            this.bookInformationGroupBox.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.bookInformationGroupBox.Controls.Add(this.bookPictureBox);
            this.bookInformationGroupBox.Controls.Add(this.languageTextBox);
            this.bookInformationGroupBox.Controls.Add(this.countryTextBox);
            this.bookInformationGroupBox.Controls.Add(this.yearTextBox);
            this.bookInformationGroupBox.Controls.Add(this.authorTextBox);
            this.bookInformationGroupBox.Controls.Add(this.titleTextBox);
            this.bookInformationGroupBox.Controls.Add(this.wikipediaPageButton);
            this.bookInformationGroupBox.Controls.Add(this.languageLabel);
            this.bookInformationGroupBox.Controls.Add(this.countryLabel);
            this.bookInformationGroupBox.Controls.Add(this.yearLabel);
            this.bookInformationGroupBox.Controls.Add(this.authorLabel);
            this.bookInformationGroupBox.Controls.Add(this.titleLabel);
            this.bookInformationGroupBox.Location = new System.Drawing.Point(10, 245);
            this.bookInformationGroupBox.Name = "bookInformationGroupBox";
            this.bookInformationGroupBox.Size = new System.Drawing.Size(551, 220);
            this.bookInformationGroupBox.TabIndex = 12;
            this.bookInformationGroupBox.TabStop = false;
            this.bookInformationGroupBox.Text = "Book information";
            this.seferBookstoreMainFormToolTip.SetToolTip(this.bookInformationGroupBox, "Information for the selected book");
            // 
            // languageTextBox
            // 
            this.languageTextBox.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.languageTextBox.Location = new System.Drawing.Point(144, 147);
            this.languageTextBox.Name = "languageTextBox";
            this.languageTextBox.ReadOnly = true;
            this.languageTextBox.Size = new System.Drawing.Size(105, 21);
            this.languageTextBox.TabIndex = 9;
            this.languageTextBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // countryTextBox
            // 
            this.countryTextBox.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.countryTextBox.Location = new System.Drawing.Point(129, 118);
            this.countryTextBox.Name = "countryTextBox";
            this.countryTextBox.ReadOnly = true;
            this.countryTextBox.Size = new System.Drawing.Size(140, 21);
            this.countryTextBox.TabIndex = 7;
            this.countryTextBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // yearTextBox
            // 
            this.yearTextBox.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.yearTextBox.Location = new System.Drawing.Point(113, 87);
            this.yearTextBox.Name = "yearTextBox";
            this.yearTextBox.ReadOnly = true;
            this.yearTextBox.Size = new System.Drawing.Size(61, 21);
            this.yearTextBox.TabIndex = 5;
            this.yearTextBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // authorTextBox
            // 
            this.authorTextBox.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.authorTextBox.Location = new System.Drawing.Point(123, 57);
            this.authorTextBox.Name = "authorTextBox";
            this.authorTextBox.ReadOnly = true;
            this.authorTextBox.Size = new System.Drawing.Size(168, 21);
            this.authorTextBox.TabIndex = 3;
            this.authorTextBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // titleTextBox
            // 
            this.titleTextBox.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.titleTextBox.Location = new System.Drawing.Point(111, 26);
            this.titleTextBox.Name = "titleTextBox";
            this.titleTextBox.ReadOnly = true;
            this.titleTextBox.Size = new System.Drawing.Size(219, 21);
            this.titleTextBox.TabIndex = 1;
            this.titleTextBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // languageLabel
            // 
            this.languageLabel.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.languageLabel.AutoSize = true;
            this.languageLabel.Location = new System.Drawing.Point(72, 148);
            this.languageLabel.Name = "languageLabel";
            this.languageLabel.Size = new System.Drawing.Size(66, 15);
            this.languageLabel.TabIndex = 8;
            this.languageLabel.Text = "Language:";
            // 
            // countryLabel
            // 
            this.countryLabel.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.countryLabel.AutoSize = true;
            this.countryLabel.Location = new System.Drawing.Point(72, 118);
            this.countryLabel.Name = "countryLabel";
            this.countryLabel.Size = new System.Drawing.Size(52, 15);
            this.countryLabel.TabIndex = 6;
            this.countryLabel.Text = "Country:";
            // 
            // yearLabel
            // 
            this.yearLabel.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.yearLabel.AutoSize = true;
            this.yearLabel.Location = new System.Drawing.Point(72, 88);
            this.yearLabel.Name = "yearLabel";
            this.yearLabel.Size = new System.Drawing.Size(34, 15);
            this.yearLabel.TabIndex = 4;
            this.yearLabel.Text = "Year:";
            // 
            // authorLabel
            // 
            this.authorLabel.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.authorLabel.AutoSize = true;
            this.authorLabel.Location = new System.Drawing.Point(72, 58);
            this.authorLabel.Name = "authorLabel";
            this.authorLabel.Size = new System.Drawing.Size(45, 15);
            this.authorLabel.TabIndex = 2;
            this.authorLabel.Text = "Author:";
            // 
            // titleLabel
            // 
            this.titleLabel.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.titleLabel.AutoSize = true;
            this.titleLabel.Location = new System.Drawing.Point(72, 28);
            this.titleLabel.Name = "titleLabel";
            this.titleLabel.Size = new System.Drawing.Size(33, 15);
            this.titleLabel.TabIndex = 0;
            this.titleLabel.Text = "Title:";
            // 
            // horizontalDividerLabel
            // 
            this.horizontalDividerLabel.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.horizontalDividerLabel.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.horizontalDividerLabel.Location = new System.Drawing.Point(10, 470);
            this.horizontalDividerLabel.Name = "horizontalDividerLabel";
            this.horizontalDividerLabel.Size = new System.Drawing.Size(552, 2);
            this.horizontalDividerLabel.TabIndex = 15;
            // 
            // seferBookstoreMainFormImageList
            // 
            this.seferBookstoreMainFormImageList.ColorDepth = System.Windows.Forms.ColorDepth.Depth8Bit;
            this.seferBookstoreMainFormImageList.ImageSize = new System.Drawing.Size(16, 16);
            this.seferBookstoreMainFormImageList.TransparentColor = System.Drawing.Color.Transparent;
            // 
            // SeferBookstoreMainForm
            // 
            this.AcceptButton = this.checkoutButton;
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.CancelButton = this.clearButton;
            this.ClientSize = new System.Drawing.Size(574, 503);
            this.ContextMenuStrip = this.seferBookstoreMainFormContextMenuStrip;
            this.Controls.Add(this.questionMarkPictureBox);
            this.Controls.Add(this.horizontalDividerLabel);
            this.Controls.Add(this.checkoutButton);
            this.Controls.Add(this.clearButton);
            this.Controls.Add(this.totalTextBox);
            this.Controls.Add(this.totalLabel);
            this.Controls.Add(this.bookInformationGroupBox);
            this.Controls.Add(this.resetShoplistButton);
            this.Controls.Add(this.shopListListBox);
            this.Controls.Add(this.shopListLabel);
            this.Controls.Add(this.removeButton);
            this.Controls.Add(this.addButton);
            this.Controls.Add(this.advancedSearchButton);
            this.Controls.Add(this.searchTextBox);
            this.Controls.Add(this.searchPictureBox);
            this.Controls.Add(this.allTitlesListBox);
            this.Controls.Add(this.allTitlesLabel);
            this.Controls.Add(this.seferBookstoreMainFormMenuStrip);
            this.Font = new System.Drawing.Font("Arial", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MainMenuStrip = this.seferBookstoreMainFormMenuStrip;
            this.Name = "SeferBookstoreMainForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Sefer Bookstore";
            ((System.ComponentModel.ISupportInitialize)(this.searchPictureBox)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.bookPictureBox)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.questionMarkPictureBox)).EndInit();
            this.seferBookstoreMainFormMenuStrip.ResumeLayout(false);
            this.seferBookstoreMainFormMenuStrip.PerformLayout();
            this.seferBookstoreMainFormContextMenuStrip.ResumeLayout(false);
            this.bookInformationGroupBox.ResumeLayout(false);
            this.bookInformationGroupBox.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ToolTip seferBookstoreMainFormToolTip;
        private System.Windows.Forms.MenuStrip seferBookstoreMainFormMenuStrip;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem editToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem cutToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem copyToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem pasteToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator editToolStripSeparator;
        private System.Windows.Forms.ToolStripMenuItem selectAllToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem toolsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem customizeToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem changefontToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem changeFontcolorToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem aboutToolStripMenuItem;
        private System.Windows.Forms.FontDialog seferBookstoreFontDialog;
        private System.Windows.Forms.ColorDialog seferBookstoreColorDialog;
        private System.Windows.Forms.ToolStripMenuItem dailySumarryToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem resetSumarryToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator fileToolStripSeparator;
        private System.Windows.Forms.ContextMenuStrip seferBookstoreMainFormContextMenuStrip;
        private System.Windows.Forms.ToolStripMenuItem advancedBookSearchToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem clearToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem resetShoplistToolStripMenuItem;
        private System.Windows.Forms.Label allTitlesLabel;
        private System.Windows.Forms.ListBox allTitlesListBox;
        private System.Windows.Forms.PictureBox searchPictureBox;
        private System.Windows.Forms.TextBox searchTextBox;
        private System.Windows.Forms.Button advancedSearchButton;
        private System.Windows.Forms.Button addButton;
        private System.Windows.Forms.Button removeButton;
        private System.Windows.Forms.ListBox shopListListBox;
        private System.Windows.Forms.Label shopListLabel;
        private System.Windows.Forms.Button resetShoplistButton;
        private System.Windows.Forms.GroupBox bookInformationGroupBox;
        private System.Windows.Forms.TextBox titleTextBox;
        private System.Windows.Forms.Button wikipediaPageButton;
        private System.Windows.Forms.Label languageLabel;
        private System.Windows.Forms.Label countryLabel;
        private System.Windows.Forms.Label yearLabel;
        private System.Windows.Forms.Label authorLabel;
        private System.Windows.Forms.Label titleLabel;
        private System.Windows.Forms.TextBox languageTextBox;
        private System.Windows.Forms.TextBox countryTextBox;
        private System.Windows.Forms.TextBox yearTextBox;
        private System.Windows.Forms.TextBox authorTextBox;
        private System.Windows.Forms.PictureBox bookPictureBox;
        private System.Windows.Forms.Label totalLabel;
        private System.Windows.Forms.TextBox totalTextBox;
        private System.Windows.Forms.Button clearButton;
        private System.Windows.Forms.Button checkoutButton;
        private System.Windows.Forms.Label horizontalDividerLabel;
        private System.Windows.Forms.ImageList seferBookstoreMainFormImageList;
        private System.Windows.Forms.PictureBox questionMarkPictureBox;
    }
}