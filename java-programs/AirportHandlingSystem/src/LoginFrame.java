/*
* Airport Handling System GUI
* @hb20007
*/

import java.awt.EventQueue; //Allows addition of tasks to the Event Queue using invokeLater()
import java.awt.Image;
import java.awt.Toolkit;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.GroupLayout;
import javax.swing.GroupLayout.Alignment;
import javax.swing.ImageIcon;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.SwingConstants;
import javax.swing.JPasswordField;
import javax.swing.JButton;
import javax.swing.LayoutStyle.ComponentPlacement;
import javax.swing.JTextField;

import java.io.File;
import java.io.FileNotFoundException;

import java.util.Scanner;


public class LoginFrame extends JFrame { //No setters/getters were implemented for this class's variables because the variables do not need to be accessed/mutated from other classes

	private static final long serialVersionUID = -6609992290710223829L;   	 //Since JFrame implements java.io.Serializable, is is recommended that an explicit SerialVersionUID value is declared. This number was generated using the generate serialVersionUID feature in Eclipse
	private JPanel contentPane;
	private final ImageIcon logo = new ImageIcon("HSlogo.png");
	private final Image logoSmall = Toolkit.getDefaultToolkit().getImage("HSlogoSmall.png"); //20x20 pic
	private JPasswordField passwordField;
	private static AirTrafficController user1 = new AirTrafficController(); //Login credentials where implemented for only one user for the purpose of this project
	private JTextField usernameField;
	
	/**
	 * Create the frame.
	 */
	public LoginFrame() {
		loadLoginCredentials(this);
		
		setResizable(false);
		setTitle("Log In");
		setIconImage(logoSmall); //Replaces JFrame's default Java logo		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(0, 0, 361, 276);
		setLocationRelativeTo(null); //Centers the login screen
		
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		
		setContentPane(contentPane);
		
		JLabel logoLabel = new JLabel(logo);
		
		JLabel welcomeLabel = new JLabel("Welcome to the Hanna Sababa Airport Handling System! ");
		welcomeLabel.setHorizontalAlignment(SwingConstants.CENTER);
		
		JPanel loginPanel = new JPanel();
		
		usernameField = new JTextField();
		usernameField.setBounds(36, 30, 101, 20);
		loginPanel.add(usernameField);
		usernameField.setColumns(10);
		
		JLabel usernameLabel = new JLabel("Username");
		usernameLabel.setBounds(36, 11, 90, 14);
		loginPanel.add(usernameLabel);
		
		JLabel passwordLabel = new JLabel("Password");
		passwordLabel.setBounds(36, 53, 78, 20);
		loginPanel.add(passwordLabel);
		
		passwordField = new JPasswordField();
		passwordField.addActionListener(new ActionListener() { //Checks for successful login when the user presses enter after inserting the password
			public void actionPerformed(ActionEvent e) {
				final String password = new String(passwordField.getPassword());
				final String user = new String(usernameField.getText());
				final String userTrimmed = user.trim(); //This erases any trailing spaces the user might insert by mistake at the and of the username
				if (userTrimmed.equals(user1.getUsername()) && password.equals(user1.getPassword()))
					loginVerified();
				else if ((userTrimmed.equals(user1.getUsername())) && (password.equals(user1.getPassword()) == false)) { //If the user inserts a valid username but and incorrect password for the username
					java.awt.Toolkit.getDefaultToolkit().beep(); //Generates beep notification sound
					JOptionPane.showMessageDialog(null, "Incorrect password for this username", "Login unsuccessful", JOptionPane.ERROR_MESSAGE); //Error message with custom title
				}
				else {
					java.awt.Toolkit.getDefaultToolkit().beep(); //Generates beep notification sound
					JOptionPane.showMessageDialog(null, "Please insert a valid username and password", "Login unsuccessful", JOptionPane.ERROR_MESSAGE); 
				}
			}
		});
		
		passwordField.setBounds(36, 74, 101, 20);
		loginPanel.add(passwordField);
		
		JButton quit = new JButton("Quit");
		quit.setIcon(new ImageIcon(LoginFrame.class.getResource("/javax/swing/plaf/metal/icons/ocean/paletteClose-pressed.gif"))); //Using a built in java icon for the Quit button
		quit.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				System.exit(0);
			}
		});
		
		JButton proceed = new JButton("Proceed");
		proceed.addActionListener(new ActionListener() { //Checks for successful login when the user presses the Proceed button
			public void actionPerformed(ActionEvent e) {
				final String password = new String(passwordField.getPassword());
				if (password.equals(user1.getPassword()))
					loginVerified();
			}
		});
		proceed.setIcon(new ImageIcon(LoginFrame.class.getResource("/javax/swing/plaf/metal/icons/ocean/computer.gif")));
		
		GroupLayout gl_contentPane = new GroupLayout(contentPane);
		gl_contentPane.setHorizontalGroup(
			gl_contentPane.createParallelGroup(Alignment.LEADING)
				.addGroup(gl_contentPane.createSequentialGroup()
					.addContainerGap()
					.addGroup(gl_contentPane.createParallelGroup(Alignment.LEADING)
						.addGroup(gl_contentPane.createParallelGroup(Alignment.TRAILING)
							.addGroup(gl_contentPane.createSequentialGroup()
								.addComponent(welcomeLabel)
								.addContainerGap(62, Short.MAX_VALUE))
							.addGroup(gl_contentPane.createSequentialGroup()
								.addComponent(logoLabel, GroupLayout.DEFAULT_SIZE, 148, Short.MAX_VALUE)
								.addPreferredGap(ComponentPlacement.RELATED)
								.addComponent(loginPanel, GroupLayout.PREFERRED_SIZE, 165, GroupLayout.PREFERRED_SIZE)
								.addGap(18)))
						.addGroup(Alignment.TRAILING, gl_contentPane.createSequentialGroup()
							.addComponent(proceed)
							.addPreferredGap(ComponentPlacement.UNRELATED)
							.addComponent(quit, GroupLayout.PREFERRED_SIZE, 71, GroupLayout.PREFERRED_SIZE)
							.addGap(78))))
		);
		gl_contentPane.setVerticalGroup(
			gl_contentPane.createParallelGroup(Alignment.LEADING)
				.addGroup(gl_contentPane.createSequentialGroup()
					.addContainerGap()
					.addComponent(welcomeLabel)
					.addGap(27)
					.addGroup(gl_contentPane.createParallelGroup(Alignment.LEADING, false)
						.addComponent(logoLabel, GroupLayout.DEFAULT_SIZE, GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
						.addComponent(loginPanel, GroupLayout.DEFAULT_SIZE, 105, Short.MAX_VALUE))
					.addGap(27)
					.addGroup(gl_contentPane.createParallelGroup(Alignment.BASELINE)
						.addComponent(quit)
						.addComponent(proceed))
					.addContainerGap())
		);
		loginPanel.setLayout(null);
		contentPane.setLayout(gl_contentPane);
	}

	/**
	 * loads the password from password.txt
	 */
	public static void loadLoginCredentials(LoginFrame frame) {
		try {
		Scanner sc = new Scanner(new File("loginCredentials.txt"));
		user1.setUsername(sc.next());
		user1.setPassword(sc.next());
		        sc.close();
		}
		catch(FileNotFoundException e) {
			System.err.println("Password file not found on machine");
			System.exit(1); //The exit-code 1 is defined to correspond to "File not found"
		}
	}
	
	/**
	 * Executes on successful login
	 */
	void loginVerified() {
		this.dispose();
		
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					ApplicationWindow window = new ApplicationWindow();
					window.appFrame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
		
	}
}