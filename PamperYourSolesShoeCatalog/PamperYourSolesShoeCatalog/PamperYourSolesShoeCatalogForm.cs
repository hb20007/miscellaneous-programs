/// <file>
/// <author>Hanna Sababa</author>
/// <datecreated>2016-10-24</datecreated>
/// <summary>
/// Contains the part of the class shoeCatalogForm with the class variables and the form actions
/// </summary>
/// </file>

using System;
using System.Drawing;
using System.Windows.Forms;

namespace PamperYourSolesShoeCatalog
{
    partial class shoeCatalogForm : Form
    {
        /// <summary>
        /// Jagged array holding all the gallery pictures
        /// </summary>
        private Bitmap[][] shoePictures = {
            // Male styles
            new Bitmap[] {Properties.Resources.maledress, Properties.Resources.maledressshoes1},
            new Bitmap[] {Properties.Resources.maleworkboots, Properties.Resources.maleworkboots2, Properties.Resources.maleworkboots3},
            new Bitmap[] {Properties.Resources.malewesternboots, Properties.Resources.malewesternboots2, Properties.Resources.malewesternboots3},
            new Bitmap[] {Properties.Resources.maletennisshoes, Properties.Resources.maletennisshoes2},
            new Bitmap[] {Properties.Resources.malesandals, Properties.Resources.malesandals1},
            // Female styles
            new Bitmap[] {Properties.Resources.femaledressshoes, Properties.Resources.femaledressshoes1, Properties.Resources.femaledressshoes2, Properties.Resources.femaledressshoes3, Properties.Resources.femaledressshoes4},
            new Bitmap[] {Properties.Resources.femaleworkboots, Properties.Resources.femaleworkboots2},
            new Bitmap[] {Properties.Resources.femalewesternboots, Properties.Resources.womenwesternboots2},
            new Bitmap[] { Properties.Resources.femalesandals, Properties.Resources.femalesandals1}
            // Most images used are in the public domain
         };

        /// <summary>
        /// Index of current subarray of the jagged array
        /// </summary>
        private int indexOfCurrentArray;

        /// <summary>
        /// Size of the current subarray of the jagged array
        /// </summary>
        private int sizeOfCurrentArray;

        /// <summary>
        /// Image currently displayed in the picture box
        /// </summary>
        private Bitmap currentImage;

        /// <summary>
        /// Index of picture (in the jagged array) which is currently displayed in the picture box
        /// </summary>
        private int indexOfCurrentImage;

        public shoeCatalogForm()
        {
            this.InitializeComponent();
        }

        // I NO LONGER USE THE METHOD BELOW BECAUSE OF THE INTRODUCTION OF THE FIELD indexOfCurrentArray
        //RadioButton whichStyleIsChecked()
        //{
        //    foreach (RadioButton r in maleGroupBox.Controls)
        //        if (r.Checked == true && r != maleStylesHiddenButton)
        //            return r;
        //    foreach (RadioButton r in femaleGroupBox.Controls)
        //        if (r.Checked == true && r != femaleStylesHiddenButton)
        //            return r;
        //    return null;
        //}

        /// <summary>
        /// Returns true if the user has selected a male or female style, else false
        /// </summary>
        /// <returns></returns>
        private bool aStyleIsChecked()
        {
            foreach (RadioButton r in maleGroupBox.Controls)
                if (r.Checked == true && r != maleStylesHiddenButton)
                    return true;
            foreach (RadioButton r in femaleGroupBox.Controls)
                if (r.Checked == true && r != femaleStylesHiddenButton)
                    return true;
            return false;
        }

        /// <summary>
        /// Displays appropriate controls if the male radio button is selected
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void maleRadioButton_CheckedChanged(object sender, EventArgs e)
        {
            if (this.maleRadioButton.Checked == true)
            {
                this.maleGroupBox.Show();
                this.femaleGroupBox.Hide();
                this.shoePictureBox.Show();
                this.leftArrowButton.Show();
                this.rightArrowButton.Show();
            }
            if (this.maleRadioButton.Checked == false)
            {
                this.shoePictureBox.Image = null;
                this.maleStylesHiddenButton.Checked = true;
                this.currentIndexLabel.Hide();
            }
        }

        /// <summary>
        /// Displays appropriate controls if the female radio button is selected
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void femaleRadioButton_CheckedChanged(object sender, EventArgs e)
        {
            if (this.femaleRadioButton.Checked == true)
            {
                this.femaleGroupBox.Show();
                this.maleGroupBox.Hide();
                this.maleGroupBox.Invalidate(); // Necessary for the female control to appear in that location
                this.shoePictureBox.Show();
                this.leftArrowButton.Show();
                this.rightArrowButton.Show();
            }
            if (this.femaleRadioButton.Checked == false)
            {
                this.shoePictureBox.Image = null;
                this.femaleStylesHiddenButton.Checked = true;
                this.currentIndexLabel.Hide();
            }
        }

        /// <summary>
        /// Clears all user selections with the help of the hidden buttons
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void clearButton_Click(object sender, EventArgs e)
        {
            this.maleGroupBox.Hide();
            this.femaleGroupBox.Hide();
            this.sexSelectionHiddenButton.Checked = true;
            this.shoePictureBox.Hide();
            this.leftArrowButton.Hide();
            this.rightArrowButton.Hide();
            this.currentIndexLabel.Hide();
        }

        /// <summary>
        /// Closes the form
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void exitButton_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        /// <summary>
        /// Updates class properties to reflect user's selection and displays the correct image
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void menDressShoesRadioButton_CheckedChanged(object sender, EventArgs e)
        {
            if (this.menDressShoesRadioButton.Checked == true)
            {
                this.indexOfCurrentArray = (int)this.menDressShoesRadioButton.Tag;
                this.sizeOfCurrentArray = this.shoePictures[this.indexOfCurrentArray].Length;
                this.currentImage = this.shoePictures[this.indexOfCurrentArray][0];
                this.indexOfCurrentImage = 0;
                this.shoePictureBox.Image = this.currentImage;
                this.currentIndexLabel.Text = "(" + (this.indexOfCurrentImage + 1) + "/" + this.sizeOfCurrentArray + ")";
                this.currentIndexLabel.Show();
            }
        }

        /// <summary>
        /// Updates class properties to reflect user's selection and displays the correct image
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void menWorkBootsRadioButton_CheckedChanged(object sender, EventArgs e)
        {
            if (this.menWorkBootsRadioButton.Checked == true)
            {
                this.indexOfCurrentArray = (int)this.menWorkBootsRadioButton.Tag;
                this.sizeOfCurrentArray = this.shoePictures[this.indexOfCurrentArray].Length;
                this.currentImage = this.shoePictures[this.indexOfCurrentArray][0];
                this.indexOfCurrentImage = 0;
                this.shoePictureBox.Image = this.currentImage;
                this.currentIndexLabel.Text = "(" + (this.indexOfCurrentImage + 1) + "/" + this.sizeOfCurrentArray + ")";
                this.currentIndexLabel.Show();
            }
        }

        /// <summary>
        /// Updates class properties to reflect user's selection and displays the correct image
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void menWesternBootsRadioButton_CheckedChanged(object sender, EventArgs e)
        {
            if (this.menWesternBootsRadioButton.Checked == true)
            {
                this.indexOfCurrentArray = (int)this.menWesternBootsRadioButton.Tag;
                this.sizeOfCurrentArray = this.shoePictures[this.indexOfCurrentArray].Length;
                this.currentImage = this.shoePictures[this.indexOfCurrentArray][0];
                this.indexOfCurrentImage = 0;
                this.shoePictureBox.Image = this.currentImage;
                this.currentIndexLabel.Text = "(" + (this.indexOfCurrentImage + 1) + "/" + this.sizeOfCurrentArray + ")";
                this.currentIndexLabel.Show();
            }
        }

        /// <summary>
        /// Updates class properties to reflect user's selection and displays the correct image
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void menTennisShoesRadioButton_CheckedChanged(object sender, EventArgs e)
        {
            if (this.menTennisShoesRadioButton.Checked == true)
            {
                this.indexOfCurrentArray = (int)this.menTennisShoesRadioButton.Tag;
                this.sizeOfCurrentArray = this.shoePictures[this.indexOfCurrentArray].Length;
                this.currentImage = this.shoePictures[this.indexOfCurrentArray][0];
                this.indexOfCurrentImage = 0;
                this.shoePictureBox.Image = this.currentImage;
                this.currentIndexLabel.Text = "(" + (this.indexOfCurrentImage + 1) + "/" + this.sizeOfCurrentArray + ")";
                this.currentIndexLabel.Show();
            }
        }

        /// <summary>
        /// Updates class properties to reflect user's selection and displays the correct 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void menSandalsRadioButton_CheckedChanged(object sender, EventArgs e)
        {
            if (this.menSandalsRadioButton.Checked == true)
            {
                this.indexOfCurrentArray = (int)this.menSandalsRadioButton.Tag;
                this.sizeOfCurrentArray = this.shoePictures[this.indexOfCurrentArray].Length;
                this.currentImage = this.shoePictures[this.indexOfCurrentArray][0];
                this.indexOfCurrentImage = 0;
                this.shoePictureBox.Image = this.currentImage;
                this.currentIndexLabel.Text = "(" + (this.indexOfCurrentImage + 1) + "/" + this.sizeOfCurrentArray + ")";
                this.currentIndexLabel.Show();
            }
        }

        /// <summary>
        /// Updates class properties to reflect user's selection and displays the correct image
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void womenDressShoesRadioButton_CheckedChanged(object sender, EventArgs e)
        {
            if (this.womenDressShoesRadioButton.Checked == true)
            {
                this.indexOfCurrentArray = (int)this.womenDressShoesRadioButton.Tag;
                this.sizeOfCurrentArray = this.shoePictures[this.indexOfCurrentArray].Length;
                this.currentImage = this.shoePictures[this.indexOfCurrentArray][0];
                this.indexOfCurrentImage = 0;
                this.shoePictureBox.Image = this.currentImage;
                this.currentIndexLabel.Text = "(" + (this.indexOfCurrentImage + 1) + "/" + this.sizeOfCurrentArray + ")";
                this.currentIndexLabel.Show();
            }
        }

        /// <summary>
        /// Updates class properties to reflect user's selection and displays the correct image
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void womenWorkBootsRadioButton_CheckedChanged(object sender, EventArgs e)
        {
            if (this.womenWorkBootsRadioButton.Checked == true)
            {
                this.indexOfCurrentArray = (int)this.womenWorkBootsRadioButton.Tag;
                this.sizeOfCurrentArray = this.shoePictures[this.indexOfCurrentArray].Length;
                this.currentImage = this.shoePictures[this.indexOfCurrentArray][0];
                this.indexOfCurrentImage = 0;
                this.shoePictureBox.Image = this.currentImage;
                this.currentIndexLabel.Text = "(" + (this.indexOfCurrentImage + 1) + "/" + this.sizeOfCurrentArray + ")";
                this.currentIndexLabel.Show();
            }
        }

        /// <summary>
        /// Updates class properties to reflect user's selection and displays the correct image
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void womenWesternBootsRadioButton_CheckedChanged(object sender, EventArgs e)
        {
            if (this.womenWesternBootsRadioButton.Checked == true)
            {
                this.indexOfCurrentArray = (int)this.womenWesternBootsRadioButton.Tag;
                this.sizeOfCurrentArray = this.shoePictures[this.indexOfCurrentArray].Length;
                this.currentImage = this.shoePictures[this.indexOfCurrentArray][0];
                this.indexOfCurrentImage = 0;
                this.shoePictureBox.Image = this.currentImage;
                this.currentIndexLabel.Text = "(" + (this.indexOfCurrentImage + 1) + "/" + this.sizeOfCurrentArray + ")";
                this.currentIndexLabel.Show();
            }
        }

        /// <summary>
        /// Updates class properties to reflect user's selection and displays the correct image
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void womenSandalsRadioButton_CheckedChanged(object sender, EventArgs e)
        {
            if (this.womenSandalsRadioButton.Checked == true)
            {
                this.indexOfCurrentArray = (int)this.womenSandalsRadioButton.Tag;
                this.sizeOfCurrentArray = this.shoePictures[this.indexOfCurrentArray].Length;
                this.currentImage = this.shoePictures[this.indexOfCurrentArray][0];
                this.indexOfCurrentImage = 0;
                this.shoePictureBox.Image = this.currentImage;
                this.currentIndexLabel.Text = "(" + (this.indexOfCurrentImage + 1) + "/" + this.sizeOfCurrentArray + ")";
                this.currentIndexLabel.Show();
            }
        }

        /// <summary>
        /// Animation for left arrow button
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void leftArrowButton_MouseHover(object sender, EventArgs e)
        {
            this.leftArrowButton.BackgroundImage = Properties.Resources._1477161328_icon_arrow_left_b2;
        }

        /// <summary>
        /// Animation for left arrow button
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void leftArrowButton_MouseDown(object sender, MouseEventArgs e)
        {
            this.leftArrowButton.BackgroundImage = Properties.Resources._1477161328_icon_arrow_left_b3;
        }

        /// <summary>
        /// Animation for left arrow button
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void leftArrowButton_MouseUp(object sender, MouseEventArgs e)
        {
            this.leftArrowButton.BackgroundImage = Properties.Resources._1477161328_icon_arrow_left_b2;
        }

        /// <summary>
        /// Animation for left arrow button
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void leftArrowButton_MouseLeave(object sender, EventArgs e)
        {
            this.leftArrowButton.BackgroundImage = Properties.Resources._1477161328_icon_arrow_left_b;
        }

        /// <summary>
        /// Displays the previous picture and updates class properties to reflect the change
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void leftArrowButton_Click(object sender, EventArgs e)
        {
            if (aStyleIsChecked())
            {
                // int indexOfCurrentImage = Array.IndexOf(this.shoePictures[this.indexOfCurrentArray], this.currentImage); // I NO LONGER NEED THIS LINE BECAUSE OF THE INTRODUCTION OF THE FIELD indexOfCurrentImage
                this.indexOfCurrentImage = Utilities.previousIndex(this.indexOfCurrentImage, this.sizeOfCurrentArray);
                this.currentImage = shoePictures[this.indexOfCurrentArray][this.indexOfCurrentImage];
                this.shoePictureBox.Image = this.currentImage;
                this.currentIndexLabel.Text = "(" + (this.indexOfCurrentImage + 1) + "/" + this.sizeOfCurrentArray + ")";
            }
        }

        /// <summary>
        /// Animation for right arrow button
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void rightArrowButton_MouseHover(object sender, EventArgs e)
        {
            this.rightArrowButton.BackgroundImage = Properties.Resources._1477161330_icon_arrow_right_b2;
        }

        /// <summary>
        /// Animation for right arrow button
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void rightArrowButton_MouseDown(object sender, MouseEventArgs e)
        {
            this.rightArrowButton.BackgroundImage = Properties.Resources._1477161330_icon_arrow_right_b3;
        }

        /// <summary>
        /// Animation for right arrow button
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void rightArrowButton_MouseUp(object sender, MouseEventArgs e)
        {
            this.rightArrowButton.BackgroundImage = Properties.Resources._1477161330_icon_arrow_right_b2;
        }

        /// <summary>
        /// Animation for right arrow button
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void rightArrowButton_MouseLeave(object sender, EventArgs e)
        {
            this.rightArrowButton.BackgroundImage = Properties.Resources._1477161330_icon_arrow_right_b;
        }

        /// <summary>
        /// Displays the next picture and updates the class properties to reflect the change
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void rightArrowButton_Click(object sender, EventArgs e)
        {
            if (aStyleIsChecked())
            {
                //int indexOfCurrentImage = Array.IndexOf(this.shoePictures[this.indexOfCurrentArray], this.currentImage); // I NO LONGER NEED THIS LINE BECAUSE OF THE INTRODUCTION OF THE FIELD indexOfCurrentImage
                this.indexOfCurrentImage = Utilities.nextIndex(this.indexOfCurrentImage, this.sizeOfCurrentArray);
                this.currentImage = this.shoePictures[this.indexOfCurrentArray][this.indexOfCurrentImage];
                this.shoePictureBox.Image = this.currentImage;
                this.currentIndexLabel.Text = "(" + (this.indexOfCurrentImage + 1) + "/" + this.sizeOfCurrentArray + ")";
            }
        }
    }
}