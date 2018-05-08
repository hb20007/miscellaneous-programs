import java.awt.Image;
import java.awt.Toolkit;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.GroupLayout;
import javax.swing.GroupLayout.Alignment;
import javax.swing.JButton;
import javax.swing.LayoutStyle.ComponentPlacement;
import java.awt.event.ActionListener;
import java.awt.event.WindowEvent;
import java.awt.event.ActionEvent;
import javax.swing.JLabel;
import javax.swing.SwingConstants;
import javax.swing.JComboBox;

public abstract class SecondaryFrame extends JFrame { //An abstract class for JFrames other than the main application JFrame and the login page

	private static final long serialVersionUID = -2498805304928425335L; //Serializable class..
	private final Image logoSmall = Toolkit.getDefaultToolkit().getImage("HSlogoSmall.png"); //20x20 pic	
	private JPanel contentPane;
	static protected JButton okButton;
	static protected JComboBox<String> flightComboBox = new JComboBox<String>(Scenario.getListOfAllFlightCodes()); 
	//The last 2 components are declared here as opposed to in the contructor because they will be referred to by inheriting classes
	
	/**
	 * Create the frame.
	 */
	public SecondaryFrame(String title, String instructionText) { //The constructor allows the user to select the title and instruction test of the SecondaryFrame
		okButton = new JButton("OK"); //Calling the constructor here instead of in the variables list lets the JButton be initialized only one time because the constructor of a class runs only once. Calling the constructor in the variables list above would create a problem where in derived classes actions would be recorded twice
		
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		setResizable(false);
		setTitle(title);
		setIconImage(logoSmall); //Replaces JFrame's default Java logo		
		setBounds(0, 0, 419, 173);
		setLocationRelativeTo(null);
		
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));

		setContentPane(contentPane);
		
		JButton cancelButton = new JButton("Cancel");
		cancelButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				SecondaryFrame.this.dispatchEvent(new WindowEvent(SecondaryFrame.this, WindowEvent.WINDOW_CLOSING));				
			}
		});
		
		JLabel instruction = new JLabel(instructionText);
		instruction.setHorizontalAlignment(SwingConstants.CENTER);
		
		JLabel flightCodeLabel = new JLabel("Flight Code:");
		
		flightComboBox.setEditable(true); //an edittable combo box is the best way for the user to insert a flight code
		
		GroupLayout gl_contentPane = new GroupLayout(contentPane);
		gl_contentPane.setHorizontalGroup(
			gl_contentPane.createParallelGroup(Alignment.LEADING)
				.addComponent(instruction, GroupLayout.DEFAULT_SIZE, 403, Short.MAX_VALUE)
				.addGroup(gl_contentPane.createSequentialGroup()
					.addGroup(gl_contentPane.createParallelGroup(Alignment.TRAILING)
						.addGroup(Alignment.LEADING, gl_contentPane.createSequentialGroup()
							.addGap(112)
							.addComponent(flightCodeLabel)
							.addPreferredGap(ComponentPlacement.UNRELATED)
							.addComponent(flightComboBox, GroupLayout.PREFERRED_SIZE, 94, GroupLayout.PREFERRED_SIZE))
						.addGroup(Alignment.LEADING, gl_contentPane.createSequentialGroup()
							.addGap(131)
							.addComponent(okButton)
							.addPreferredGap(ComponentPlacement.RELATED)
							.addComponent(cancelButton)))
					.addContainerGap(129, Short.MAX_VALUE))
		);
		gl_contentPane.setVerticalGroup(
			gl_contentPane.createParallelGroup(Alignment.LEADING)
				.addGroup(gl_contentPane.createSequentialGroup()
					.addComponent(instruction)
					.addGap(30)
					.addGroup(gl_contentPane.createParallelGroup(Alignment.BASELINE)
						.addComponent(flightCodeLabel)
						.addComponent(flightComboBox, GroupLayout.PREFERRED_SIZE, GroupLayout.DEFAULT_SIZE, GroupLayout.PREFERRED_SIZE))
					.addPreferredGap(ComponentPlacement.RELATED, 47, Short.MAX_VALUE)
					.addGroup(gl_contentPane.createParallelGroup(Alignment.BASELINE)
						.addComponent(cancelButton)
						.addComponent(okButton)))
		);
		contentPane.setLayout(gl_contentPane);
	}

}
