/// <file>
/// <author>hb20007</author>
/// <datecreated>2016-11-21</datecreated>
/// <summary>
///  Contains the part of the class USAStateLookupForm with the form behavior
/// </summary>
/// </file>

// The file states.csv was obtained from https://github.com/openfoodfoundation/l10n_us/blob/master/states.csv
// It was editted as follows: District of Columbia (DC) was removed because it is not a state, states were sorted in alphabetical order

using System;
using System.IO;
using System.Windows.Forms;

namespace USAStateLookup
{
    partial class USAStateLookupForm : Form
    {
        private static string STATES_FILE_NAME = "states.csv";
        public USAStateLookupForm()
        {
            this.InitializeComponent();

            this.loadDataIntoComboBoxes();

            // The only way to change the height of a text box without changing font size. After disabling AutoSize, this.nameTextBox.Size = this.nameComboBox.Size; doesn't change anything for some reason
            this.nameTextBox.AutoSize = false;
            this.nameTextBox.Size = new System.Drawing.Size(118, 23);
            this.codeTextBox.AutoSize = false;
            this.codeTextBox.Size = new System.Drawing.Size(33, 23);
        }

        /// <summary>
        /// Sets the lookup mode to lookup by code. Also clears all text and combo boxes. This deals with the functionality of setting the lookup mode by name too because there are only 2 radio buttons
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void lookupByCodeRadioButton_CheckedChanged(object sender, System.EventArgs e)
        {  // Using lookupByNameRadioButton_CheckChanged() instead of lookupByCodeRadioButton_CheckedChanged() for implementing all the functionality doesn't work because it starts of as selected when the form is launched and that causes problems
            this.nameTextBox.Visible = this.lookupByCodeRadioButton.Checked;
            this.nameComboBox.Visible = !this.lookupByCodeRadioButton.Checked;
            this.codeTextBox.Visible = !this.lookupByCodeRadioButton.Checked;
            this.codeComboBox.Visible = this.lookupByCodeRadioButton.Checked;

            this.nameTextBox.Clear();
            this.nameComboBox.SelectedIndex = -1; // Unlike list boxes, combo boxes do not have the ClearSelected() method but this is equivalent
            this.codeTextBox.Clear();
            this.codeComboBox.SelectedIndex = -1;
        }

        /// <summary>
        /// Performs the lookup operation
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void searchButton_Click(object sender, System.EventArgs e)
        {
            if (this.lookupByNameRadioButton.Checked)
            {
                if (this.nameComboBox.Text == string.Empty)
                    MessageBox.Show("Please select a state first.", "Message", MessageBoxButtons.OK, MessageBoxIcon.Information);
                else
                    this.codeTextBox.Text = this.codeComboBox.Items[this.nameComboBox.SelectedIndex].ToString();
            }
            else
            {
                if (this.codeComboBox.Text == string.Empty)
                    MessageBox.Show("Please select a state code first.", "Message", MessageBoxButtons.OK, MessageBoxIcon.Information);
                else
                    this.nameTextBox.Text = this.nameComboBox.Items[this.codeComboBox.SelectedIndex].ToString();
            }
        }

        /// <summary>
        /// loads data from the list of states .csv file into the name and code combo boxes
        /// </summary>
        private void loadDataIntoComboBoxes()
        {
            try
            {
                StreamReader reader = new StreamReader(File.OpenRead(USAStateLookupForm.STATES_FILE_NAME));
                string line = reader.ReadLine(); // The first line is done away with because it has the column headings
                string[] values;
                while (!reader.EndOfStream)
                {
                    line = reader.ReadLine();
                    values = line.Split(',');
                    // The first column in the .csv file is completely ignored because it is just a row index
                    this.nameComboBox.Items.Add(values[1]);
                    this.codeComboBox.Items.Add(values[2]);
                }
                reader.Close();
            }
            catch
            {
                MessageBox.Show($"The file {USAStateLookupForm.STATES_FILE_NAME} was not found", "Fatal error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                Environment.Exit(1); 
            }
        }
    }
}