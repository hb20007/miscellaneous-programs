/*
* COMP-212 
* Instructor: Dr Constandinos Mavromoustakis
*
* Final Project - Creating an Airport Handling System GUI
*
* @HANNA SABABA (U144N0959)
*/

import java.awt.EventQueue;

import javax.swing.JFrame;

public class RunApplication {
	
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		new Scenario(); //Calls the constructor of the class Scenario() so that its static methods can be accesssed

		JFrame.setDefaultLookAndFeelDecorated(true); //Static method that makes JFrames look fancier
		
		EventQueue.invokeLater(new Runnable() { //The code modifying the UI is put in an anonymous class that derives from Runnable. This anonymous class overrides the run method of the interface runnable. The anonymous instance is passed as an object into EventQueue.invokeLater method. The new Runnable() is used because in Swing all code that modifies the UI should not be executed in the main thread, but the event-dispatching thread
			public void run() {
				try {
					LoginFrame frame = new LoginFrame();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}
}
