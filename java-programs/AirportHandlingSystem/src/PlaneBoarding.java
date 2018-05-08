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


public class PlaneBoarding extends SecondaryFrame { 

	private static final long serialVersionUID = -7409784810436164199L; //Serializable class...

	/**
	 * Create the frame.
	 */
	public PlaneBoarding() {
		super("Allow passengers to board","Insert flight code to allow boarding of said plane."); 
		okButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				int i = flightComboBox.getSelectedIndex();
				if (((Scenario.getFlightsArray()[i].getAirplane().getPlaneStatus() == Status.DOCKED) || (Scenario.getFlightsArray()[i].getAirplane().getPlaneStatus() == Status.LANDED)) && (Scenario.getFlightsArray()[i].getAirplane().getLocation().equals(Scenario.getLarnacaAirport().getName()))) { //Planes in Larnaca airport that are in the status LANDED or DOCKED are allowed to board passengers
						PlaneBoarding.this.dispose();
						JOptionPane.showMessageDialog(null, "Flight " + flightComboBox.getSelectedItem() + " now boarding." , "Success", JOptionPane.INFORMATION_MESSAGE); //Message dialog with custom title
						Scenario.getFlightsArray()[i].getAirplane().setPlaneStatus(Status.BOARDING); 				
						ApplicationWindow.mainTableModel.setValueAt(Status.BOARDING, i, 6); //The change is made in both the data array and the JTable	
						ApplicationWindow.refreshArrivalsTable(); //We refresh the arrivals table in order to remove a table with status LANDED because it is no longer considered in the Arrivals but the departures list since it is preparing for departure by boarding passengers
						ApplicationWindow.refreshDeparturesTable();
				}
				else { //if the plane was not eligible for boarding passengers
					java.awt.Toolkit.getDefaultToolkit().beep(); //Generates beep notification sound
					JOptionPane.showMessageDialog(null, "Airplane not applicable for boarding passengers.\n\nPlease check that you have selected a plane\nwhich is at " + Scenario.getLarnacaAirport().getName() + " and that\n has DOCKED or LANDED status.", "Error", JOptionPane.ERROR_MESSAGE); //Error message with custom title								
				}
			}
		});	
	}
}