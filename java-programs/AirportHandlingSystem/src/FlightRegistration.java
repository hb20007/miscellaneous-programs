/*
* COMP-212 
* Instructor: Dr Constandinos Mavromoustakis
*
* Final Project - Creating an Airport Handling System GUI
*
* @HANNA SABABA (U144N0959)
*/

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JOptionPane;


public class FlightRegistration extends SecondaryFrame { //Classes that extend SecondaryFrame were created instead of instantiating SecondaryFrame in the main program and adding all the code below there for better distributed code and to avoid clutter in ApplicationWindow.java

	private static final long serialVersionUID = -3913889933991795751L; //Serializable class...

	/**
	 * Create the frame.
	 */
	public FlightRegistration() {
		super("Register flight","Insert the code of the flight you would like to register with the airport.");
		okButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				int i = flightComboBox.getSelectedIndex();
				if (Scenario.getFlightsArray()[i].getAirplane().getRegistrationStatus() == Registration.UNREGISTERED) {
				FlightRegistration.this.dispose();
				JOptionPane.showMessageDialog(null, "Flight with code " + flightComboBox.getSelectedItem() + " successfully registered." , "Success", JOptionPane.INFORMATION_MESSAGE); //Message dialog with custom title
				Scenario.getFlightsArray()[i].getAirplane().setRegistrationStatus(Registration.REGISTERED);				
				ApplicationWindow.mainTableModel.setValueAt(Registration.REGISTERED, i, 7); //The change is made in both the data array and the JTable
				}
				else if (Scenario.getFlightsArray()[i].getAirplane().getRegistrationStatus() == Registration.REGISTERED) {
					java.awt.Toolkit.getDefaultToolkit().beep(); //Generates beep notification sound
					JOptionPane.showMessageDialog(null, "Airplane is already registered.", "Error", JOptionPane.ERROR_MESSAGE); //Error message with custom title								
				}
				else {//if registration is unapplicable
					java.awt.Toolkit.getDefaultToolkit().beep(); //Generates beep notification sound
					JOptionPane.showMessageDialog(null, "Registration not applicable for this plane.", "Error", JOptionPane.ERROR_MESSAGE); //Error message with custom title								
				
				}
			}
		});
	}
}

	
	
