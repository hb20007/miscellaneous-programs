/*
* Airport Handling System GUI
* @hb20007
*/

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JOptionPane;


public class FlightLanding extends SecondaryFrame { //Classes that extend SecondaryFrame were created instead of instantiating SecondaryFrame in the main program and adding all the code below there for better distributed code and to avoid clutter in ApplicationWindow.java
	
	private static final long serialVersionUID = -3718779423936769929L; //Serializable class...

	/**
	 * Create the frame.
	 */
	public FlightLanding() {
		super("Record flight landing","Insert the code of the flight you would like to record as landed.");
		okButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				int i = flightComboBox.getSelectedIndex();
				if (Scenario.getFlightsArray()[i].getAirplane().getPlaneStatus() == Status.LANDING) { //If the status of the flight was landing
					FlightLanding.this.dispose();
					JOptionPane.showMessageDialog(null, "Flight with code " + flightComboBox.getSelectedItem() + " successfully recorded as landed." , "Success", JOptionPane.INFORMATION_MESSAGE); //Message dialog with custom title

					Scenario.getFlightsArray()[i].getAirplane().setRegistrationStatus(Registration.UNAPPLICABLE);				
					ApplicationWindow.mainTableModel.setValueAt(Registration.UNAPPLICABLE, i, 7); //The change is made in both the data array and the JTable
					Scenario.getFlightsArray()[i].getAirplane().setPlaneStatus(Status.LANDED);				
					ApplicationWindow.mainTableModel.setValueAt(Status.LANDED, i, 6); 
					
					ApplicationWindow.refreshArrivalsTable();
					
					Scenario.getFlightsArray()[i].setDestinationCity(Scenario.getFlightsArray()[i].getStartingCity()); //The plane's destination and starting city are also updated in preparation for a return flight later on
					ApplicationWindow.mainTableModel.setValueAt(Scenario.getFlightsArray()[i].getStartingCity(), i, 4); 
					Scenario.getFlightsArray()[i].setStartingCity(Scenario.getLarnacaAirport().getCity());
					ApplicationWindow.mainTableModel.setValueAt(Scenario.getLarnacaAirport().getCity(), i, 3); 
					
					Scenario.freeUpRunway(); //Frees up the runway used
				}
				else { //This is the case when the plane couldn't have landed and the user made a mistake in the selection
					java.awt.Toolkit.getDefaultToolkit().beep(); //Generates beep notification sound
					JOptionPane.showMessageDialog(null, "Landing not applicable for this plane.\n\nPlease check that you have selected a plane\nwhich was previously in the status LANDING.", "Error", JOptionPane.ERROR_MESSAGE); //Error message with custom title									
				}
			}
		});
		
	}
}

	
	
