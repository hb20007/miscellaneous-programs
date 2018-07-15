import java.awt.Color;
import java.awt.EventQueue;
import java.util.ArrayList;

import javax.swing.JFrame;
import javax.swing.UIManager;
import javax.swing.plaf.ColorUIResource;

/**  
 * <h1>Seat Reservation System</h1>
 * 
 * <p>For the purposes of this simulation I will consider a system with 4 seats and 2 agents. Each agent has their own interface to
 * view and reserve seats.</p>
 * 
 * @author hb20007
*/
public class Application {
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		JFrame.setDefaultLookAndFeelDecorated(true);
		// Change Windows inactive field colors
		UIManager.put("TextField.inactiveBackground", new ColorUIResource(new Color(255, 255, 255)));
		UIManager.put("TextField.inactiveForeground", new ColorUIResource(new Color(0, 0, 0)));
		
		Agent agentA = new Agent("Agent A"), agentB = new Agent("Agent B");
		ArrayList<Seat> seatsArray = new ArrayList<Seat>();		// I use ArrayList instead of a normal array to create multiple objects with different names in a loop to store in an array list
		for (int i = 0; i < 4; i++) {		// There are 4 seats in the simulation
			seatsArray.add(new Seat(i + 1));
		}
		
		// First thread
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					AgentInterface agent1Frame = new AgentInterface(false, agentA.queryAgentName(), seatsArray);
					agent1Frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
		
		// Second thread 
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					AgentInterface agent2Frame = new AgentInterface(true, agentB.queryAgentName(), seatsArray);
					agent2Frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}
}
