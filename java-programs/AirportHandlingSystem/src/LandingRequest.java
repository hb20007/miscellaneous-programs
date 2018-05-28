/*
* Airport Handling System GUI
* @hb20007
*/

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JOptionPane;


public class LandingRequest extends SecondaryFrame { 


	private static final long serialVersionUID = -6086490428571821833L; //Serializable class...

	/**
	 * Create the frame.
	 */
	public LandingRequest() {
		super("Record landing request","Insert flight code to record a landing request."); //The landing request is received by the air traffic control from the airplane via radio communication and they record the request in the application
		okButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				int i = flightComboBox.getSelectedIndex();
				if (Scenario.getFlightsArray()[i].getAirplane().getRegistrationStatus() == Registration.REGISTERED && (Scenario.getFlightsArray()[i].getAirplane().getPlaneStatus() == Status.IN_FLIGHT) || (Scenario.getFlightsArray()[i].getAirplane().getPlaneStatus() == Status.CIRCLING_AIRPORT)) { //If plane is registered
					if (Scenario.checkForFreeRunways()) { //If there are free runways. The method also books a runway if a free one is found
						LandingRequest.this.dispose();
						JOptionPane.showMessageDialog(null, "Landing request for flight " + flightComboBox.getSelectedItem() + " successfully processed." , "Success", JOptionPane.INFORMATION_MESSAGE); //Message dialog with custom title
						
						Scenario.getFlightsArray()[i].getAirplane().setPlaneStatus(Status.LANDING); 				
						ApplicationWindow.mainTableModel.setValueAt(Status.LANDING, i, 6); //The change is made in both the data array and the JTable	
						Scenario.getFlightsArray()[i].getAirplane().setLocation(Scenario.getLarnacaAirport().getName()); //Flight location updated to Larnaca Airport
						ApplicationWindow.mainTableModel.setValueAt(Scenario.getLarnacaAirport().getName(), i, 5); 
					
						ApplicationWindow.refreshArrivalsTable(); //Arrivals table is refreshed to reflect changes						
					}
					else { //If there are no free runways the airplane is instructed to circle around the airport and make another landing request later when in a suitable position again to see if landing is possible now
						LandingRequest.this.dispose();
						JOptionPane.showMessageDialog(null, "There are no free runways at the moment.\n\nThe airplane has been instructed to circle the airport\nand to make a new landing request when in a suitable\nposition for landing again." , "No free runways", JOptionPane.INFORMATION_MESSAGE); //Message dialog with custom title						
						Scenario.getFlightsArray()[i].getAirplane().setPlaneStatus(Status.CIRCLING_AIRPORT); 				
						ApplicationWindow.mainTableModel.setValueAt(Status.CIRCLING_AIRPORT, i, 6); //The arrivals table will not be updated to include the status "CIRCLING_AIRPORT" because the arrivals table is less technical in nature. This status is only shown in the main table.
					}
				}
				else { //If plane is not registered or if it registered but not in flight
					java.awt.Toolkit.getDefaultToolkit().beep(); //Generates beep notification sound
					JOptionPane.showMessageDialog(null, "Airplane not applicable for landing at the airport.\n\nPlease check that you have selected a plane\nwhich has registered with the airport and that\n is in flight towards the airport or is circling it.", "Error", JOptionPane.ERROR_MESSAGE); //Error message with custom title								
				}
			}
		});
		
	}
}