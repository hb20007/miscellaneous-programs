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


public class PlaneTakeoff extends SecondaryFrame { 

	private static final long serialVersionUID = -7409784810436164199L; //Serializable class...

	/**
	 * Create the frame.
	 */
	public PlaneTakeoff() {
		super("Initiate plane takeoff","Insert flight code to initiate takeoff of said plane."); 
		okButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				final int i = flightComboBox.getSelectedIndex(); //i defined as final so that it can be referred to in the TimerTask
				if (((Scenario.getFlightsArray()[i].getAirplane().getPlaneStatus() == Status.BOARDING)) && (Scenario.getFlightsArray()[i].getAirplane().getLocation().equals(Scenario.getLarnacaAirport().getName()))) { //Planes in Larnaca airport that are in the status BOARDING are allowed to takeoff
					if(Scenario.checkForFreeRunways()) { //If a free runway is found it is booked
						PlaneTakeoff.this.dispose();
						JOptionPane.showMessageDialog(null, "Flight " + flightComboBox.getSelectedItem() + " now taking off." , "Success", JOptionPane.INFORMATION_MESSAGE); //Message dialog with custom title
						Scenario.getFlightsArray()[i].getAirplane().setPlaneStatus(Status.TAKEOFF); 				
						ApplicationWindow.mainTableModel.setValueAt(Status.TAKEOFF, i, 6); //The change is made in both the data array and the JTable	
						
						ApplicationWindow.refreshDeparturesTable();
						
						new java.util.Timer().schedule( //After a certain amount of time, the status of the airplane is no longer at TAKEOFF so its status will be changed to IN_FLIGHT and the runway it booked will free up
						        new java.util.TimerTask() {
						            @Override
						            public void run() {
										Scenario.getFlightsArray()[i].getAirplane().setPlaneStatus(Status.IN_FLIGHT);
										ApplicationWindow.mainTableModel.setValueAt(Status.IN_FLIGHT, i, 6); 
										Scenario.getFlightsArray()[i].getAirplane().setLocation("Airborne");
										ApplicationWindow.mainTableModel.setValueAt("Airborne", i, 5); 
										
										ApplicationWindow.refreshDeparturesTable();
										
										
										Scenario.freeUpRunway(); //Frees up the runway used	
						            }
						        }, 
						        10000 //It was assumed that the time taken for takeoff is 10 seconds. It would take more in real life but this is more suitable for this model application in order to avoid waiting
						);
					}
					else { //if there are no free runways at the moment for the plane to take off
						PlaneTakeoff.this.dispose();
						JOptionPane.showMessageDialog(null, "There are no free runways at the moment.\n\nThe airplane has been instructed to issue a takeoff request\nagain at a later point." , "No free runways", JOptionPane.INFORMATION_MESSAGE); //Message dialog with custom title							
					}
						}
				else { //if the plane was not eligible for takeoff
					java.awt.Toolkit.getDefaultToolkit().beep(); //Generates beep notification sound
					JOptionPane.showMessageDialog(null, "Airplane not applicable for takeoff.\n\nPlease check that you have selected a plane\nwhich is at " + Scenario.getLarnacaAirport().getName() + " and that\n was in BOARDING status.", "Error", JOptionPane.ERROR_MESSAGE); //Error message with custom title								
				}
			}
		});	
	}
}