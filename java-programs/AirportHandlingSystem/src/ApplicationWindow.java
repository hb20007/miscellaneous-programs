/*
* Airport Handling System GUI
* @hb20007
*/

import java.awt.Image;
import java.awt.Toolkit; //Contains an assortment of various useful functions 
import java.awt.Component;
import java.awt.EventQueue;

import java.awt.event.KeyEvent;
import java.awt.event.InputEvent;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

import javax.swing.JFrame;
import javax.swing.BorderFactory; //Used in creating custom borders for containers
import javax.swing.GroupLayout;
import javax.swing.GroupLayout.Alignment;
import javax.swing.JMenuBar;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.KeyStroke;
import javax.swing.JTabbedPane;
import javax.swing.JPanel;
import javax.swing.JOptionPane;
import javax.swing.border.Border; //Used in creating custom borders for containers
import javax.swing.border.EtchedBorder; //Used in creating custom borders for containers
import javax.swing.JButton;
import javax.swing.LayoutStyle.ComponentPlacement;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;
import javax.swing.JScrollPane;

import org.eclipse.wb.swing.FocusTraversalOnArray; //A Cyclic FocusTraversalPolicy. A FocusTraversalPolicy defines the order in which Components with a particular focus cycle root are traversed. This inherits from java.awt.FocusTraversalPolicy and is used to give focus to the buttons on the screen so that the user can select them using keyboard shortcuts

public class ApplicationWindow extends JFrame {  //No setters/getters were implemented for this class's variables because the variables do not need to be accessed/mutated from other classes
	private static final long serialVersionUID = 7249425476085960113L;
	protected JFrame appFrame; 
	private final Image logoSmall = Toolkit.getDefaultToolkit().getImage("HSlogoSmall.png"); //20x20 pic
	private static JTable flightListTable; //Also referred to as the main table
	private static JTable arrivalsTable; //The arrivals table contains planes with the status IN_FLIGHT, LANDING, LANDED flying towards the airport
	private static JTable departuresTable; //The departures table contains planes with the status DOCKED, BOARDING or TAKEOFF leaving from Larnaca 
	protected static DefaultTableModel mainTableModel;
	protected static DefaultTableModel arrivalsTableModel;
	protected static DefaultTableModel departuresTableModel;
	
	private static Object[][] allFlightData;
	
	/**
	 * Create the application.
	 */
	public ApplicationWindow() {
		initialize();
	}

	/**
	 * Initialize the contents of the application frame.
	 */
	private void initialize() {
		
		ApplicationWindow.allFlightData = Scenario.getFlightData(); //The table data. An Object array is used because the data is in different forms (String, int, enums etc.)
		
		mainTableModel = new MyTableModel(
				allFlightData, //The table data. An Object array is used because the data is in different forms (String, int, enums etc.)
				new Object[] { //The column labels
				"Flight Code", "Airline", "Model", "Starting City", "Destination City", "Location", "Status", "Registration"
			});
		
		arrivalsTableModel = new MyTableModel(
				Scenario.getArrivalsOrDeparturesList(false),
				new String[] {
						"AIRLINES", "FLIGHT", "FROM", "TO", "STATUS"
				});
		
		departuresTableModel = new MyTableModel(
				Scenario.getArrivalsOrDeparturesList(true),
				new String[] {
						"AIRLINES", "FLIGHT", "FROM", "TO", "STATUS"
				});
		
		appFrame = new JFrame();
		
		appFrame.setIconImage(logoSmall); //Replaces JFrame's default Java logo
		appFrame.setTitle("Hanna Sababa Airport System");
		appFrame.setBounds(0, 0, 739, 473); 
		appFrame.setLocationRelativeTo(null); //Passing a null argument causes the frame to be displayed in the center of the screen
		appFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JMenuBar menuBar = new JMenuBar();
		menuBar.setToolTipText("Main menu");
		appFrame.setJMenuBar(menuBar);
		
		JMenu fileMenu = new JMenu("File");
		fileMenu.setMnemonic('F'); //Allows navigating the menu via the keyboard (Alt-F etc...)
		menuBar.add(fileMenu);
		
		JMenuItem fileOpen = new JMenuItem("Open");
		fileOpen.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String fileName = JOptionPane.showInputDialog(null, "Insert the name of the file (without extension)");
				fileName += ".bak";
				Scenario.loadFromFile(fileName);				
			}
		});
		fileOpen.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_O, InputEvent.CTRL_MASK)); //Applies the keyboard shortcut Ctrl-O to this menu item
		fileMenu.add(fileOpen);
		
		JMenuItem fileSave = new JMenuItem("Save");
		fileSave.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				String fileName = JOptionPane.showInputDialog(null, "Insert the name of the file (without extension)");
				fileName += ".bak";
				Scenario.saveToFile(fileName);
			}
		});
		fileSave.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_S, InputEvent.CTRL_MASK));
		fileMenu.add(fileSave);
		
		JMenuItem fileExit = new JMenuItem("Exit");
		fileExit.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				System.exit(0);
			}
		});
		
		fileExit.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_F4, InputEvent.ALT_MASK));
		fileMenu.add(fileExit);
		
		JMenu helpMenu = new JMenu("Help");
		helpMenu.setMnemonic('H');
		menuBar.add(helpMenu);
		
		JMenuItem helpAbout = new JMenuItem("About");
		helpAbout.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_F1, 0));
		helpAbout.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				JOptionPane.showMessageDialog(null, "Hanna Sababa Airport Handling System v1.0 \n\n\u00a9 2016 Hanna Sababa (All rights reserved)\n\nNo part of this application may be reproduced\nin any form or by any means without the prior\nwritten permission of the developer.", "About", JOptionPane.INFORMATION_MESSAGE); //Message dialog with custom title
			}
		});
		helpMenu.add(helpAbout);
		
		JTabbedPane tabbedPane = new JTabbedPane(JTabbedPane.TOP);
		
		JPanel controlPanel = new JPanel();
		tabbedPane.addTab("Flight Control", null, controlPanel, "Control current flights");
		
		JPanel buttonsPanel = new JPanel();
		Border loweredetched = BorderFactory.createEtchedBorder(EtchedBorder.LOWERED);
		Border lineBorder = BorderFactory.createTitledBorder(loweredetched, "Select an option");
		buttonsPanel.setBorder(lineBorder);
		
		JPanel flightListPanel = new JPanel();
		Border lineBorder2 = BorderFactory.createTitledBorder(loweredetched, "List of flights");
		flightListPanel.setBorder(lineBorder2);
		
		JScrollPane controlScrollPane = new JScrollPane();
		
		JPanel arrivalsPanel = new JPanel();
		tabbedPane.addTab("Flight Arrivals", null, arrivalsPanel, "List flight arrivals");
		
		JPanel arrivalsListPanel = new JPanel();
		Border lineBorder3 = BorderFactory.createTitledBorder(loweredetched, "Arrivals");
		arrivalsListPanel.setBorder(lineBorder3);
		
		JScrollPane arrivalsScrollPane = new JScrollPane();
		
		JPanel departuresPanel = new JPanel();
		tabbedPane.addTab("Flight Departures", null, departuresPanel, "List flight departures");
		
		JPanel departuresListPanel = new JPanel();
		Border lineBorder4 = BorderFactory.createTitledBorder(loweredetched, "Departures");
		departuresListPanel.setBorder(lineBorder4);
		
		JScrollPane departuresScrollPane = new JScrollPane();
		
		JButton registerPlaneButton = new JButton("Register a flight");
		registerPlaneButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				EventQueue.invokeLater(new Runnable() {
					public void run() {
						try {
							FlightRegistration frame = new FlightRegistration();
							frame.setVisible(true);
						} catch (Exception e) {
							e.printStackTrace();
						}
					}
				});
			}
		});
		registerPlaneButton.setMnemonic('R');
		buttonsPanel.add(registerPlaneButton);
		
		JButton landingRequestButton = new JButton("Process landing request");
		landingRequestButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				EventQueue.invokeLater(new Runnable() {
					public void run() {
						try {
							LandingRequest frame = new LandingRequest();
							frame.setVisible(true);
						} catch (Exception e) {
							e.printStackTrace();
						}
					}
				});
			}
		});
		landingRequestButton.setMnemonic('P');
		buttonsPanel.add(landingRequestButton);
		
		JButton planeLandingButton = new JButton("Record landing");
		planeLandingButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				EventQueue.invokeLater(new Runnable() {
					public void run() {
						try {
							FlightLanding frame = new FlightLanding();
							frame.setVisible(true);
						} catch (Exception e) {
							e.printStackTrace();
						}
					}
				});
			}
		});
		planeLandingButton.setMnemonic('L');
		buttonsPanel.add(planeLandingButton);
		
		JButton boardAirplaneButton = new JButton("Board airplane");
		boardAirplaneButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				EventQueue.invokeLater(new Runnable() {
					public void run() {
						try {
							PlaneBoarding frame = new PlaneBoarding();
							frame.setVisible(true);
						} catch (Exception e) {
							e.printStackTrace();
						}
					}
				});
			}
		});
		
		boardAirplaneButton.setMnemonic('B');
		buttonsPanel.add(boardAirplaneButton);
		
		JButton takeOffButton = new JButton("Take off");
		takeOffButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				EventQueue.invokeLater(new Runnable() {
					public void run() {
						try {
							PlaneTakeoff frame = new PlaneTakeoff();
							frame.setVisible(true);
						} catch (Exception e) {
							e.printStackTrace();
						}
					}
				});
			}
		});
		takeOffButton.setMnemonic('T');
		buttonsPanel.add(takeOffButton);
		
		buttonsPanel.setFocusTraversalPolicy(new FocusTraversalOnArray(new Component[]{registerPlaneButton, landingRequestButton, planeLandingButton, boardAirplaneButton, takeOffButton}));
		tabbedPane.setMnemonicAt(0, KeyEvent.VK_C);
		
		flightListTable = new JTable(mainTableModel);
		flightListTable.getColumnModel().getColumn(4).setPreferredWidth(86);
		
		controlScrollPane.setViewportView(flightListTable);

		arrivalsTable = new JTable(arrivalsTableModel);
		arrivalsTable.setShowVerticalLines(false);
		arrivalsTable.setShowHorizontalLines(false);
		arrivalsTable.setShowGrid(false);

		arrivalsScrollPane.setViewportView(arrivalsTable);
		tabbedPane.setMnemonicAt(1, KeyEvent.VK_A);
		
		departuresTable = new JTable(departuresTableModel);
		departuresTable.setShowVerticalLines(false);
		departuresTable.setShowHorizontalLines(false);
		departuresTable.setShowGrid(false);
		
		departuresScrollPane.setViewportView(departuresTable);
		tabbedPane.setMnemonicAt(2, KeyEvent.VK_D);
		

		GroupLayout groupLayout = new GroupLayout(appFrame.getContentPane());
		groupLayout.setHorizontalGroup(
			groupLayout.createParallelGroup(Alignment.LEADING)
				.addComponent(tabbedPane, GroupLayout.DEFAULT_SIZE, 403, Short.MAX_VALUE)
		);
		groupLayout.setVerticalGroup(
			groupLayout.createParallelGroup(Alignment.LEADING)
				.addComponent(tabbedPane, GroupLayout.DEFAULT_SIZE, 245, Short.MAX_VALUE)
		);
		GroupLayout gl_flightListPanel = new GroupLayout(flightListPanel);
		gl_flightListPanel.setHorizontalGroup(
			gl_flightListPanel.createParallelGroup(Alignment.LEADING)
				.addComponent(controlScrollPane, GroupLayout.DEFAULT_SIZE, 706, Short.MAX_VALUE)
		);
		gl_flightListPanel.setVerticalGroup(
			gl_flightListPanel.createParallelGroup(Alignment.LEADING)
				.addComponent(controlScrollPane, GroupLayout.DEFAULT_SIZE, 301, Short.MAX_VALUE)
		);
		GroupLayout gl_controlPanel = new GroupLayout(controlPanel);
		gl_controlPanel.setHorizontalGroup(
			gl_controlPanel.createParallelGroup(Alignment.LEADING)
				.addComponent(flightListPanel, GroupLayout.DEFAULT_SIZE, GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
				.addComponent(buttonsPanel, GroupLayout.DEFAULT_SIZE, 718, Short.MAX_VALUE)
		);
		gl_controlPanel.setVerticalGroup(
			gl_controlPanel.createParallelGroup(Alignment.TRAILING)
				.addGroup(gl_controlPanel.createSequentialGroup()
					.addComponent(flightListPanel, GroupLayout.DEFAULT_SIZE, 319, Short.MAX_VALUE)
					.addPreferredGap(ComponentPlacement.RELATED)
					.addComponent(buttonsPanel, GroupLayout.PREFERRED_SIZE, 61, GroupLayout.PREFERRED_SIZE))
		);
		GroupLayout gl_arrivalsListPanel = new GroupLayout(arrivalsListPanel);
		gl_arrivalsListPanel.setHorizontalGroup(
			gl_arrivalsListPanel.createParallelGroup(Alignment.LEADING)
				.addComponent(arrivalsScrollPane, GroupLayout.DEFAULT_SIZE, 706, Short.MAX_VALUE)
		);
		gl_arrivalsListPanel.setVerticalGroup(
			gl_arrivalsListPanel.createParallelGroup(Alignment.LEADING)
				.addComponent(arrivalsScrollPane, GroupLayout.DEFAULT_SIZE, 364, Short.MAX_VALUE)
		);
		GroupLayout gl_arrivalsPanel = new GroupLayout(arrivalsPanel);
		gl_arrivalsPanel.setHorizontalGroup(
			gl_arrivalsPanel.createParallelGroup(Alignment.LEADING)
				.addComponent(arrivalsListPanel, GroupLayout.DEFAULT_SIZE, 718, Short.MAX_VALUE)
		);
		gl_arrivalsPanel.setVerticalGroup(
			gl_arrivalsPanel.createParallelGroup(Alignment.TRAILING)
				.addComponent(arrivalsListPanel, GroupLayout.DEFAULT_SIZE, 370, Short.MAX_VALUE)
		);
		GroupLayout gl_departuresListPanel = new GroupLayout(departuresListPanel);
		gl_departuresListPanel.setHorizontalGroup(
			gl_departuresListPanel.createParallelGroup(Alignment.TRAILING)
				.addComponent(departuresScrollPane, Alignment.LEADING, GroupLayout.DEFAULT_SIZE, 706, Short.MAX_VALUE)
		);
		gl_departuresListPanel.setVerticalGroup(
			gl_departuresListPanel.createParallelGroup(Alignment.LEADING)
				.addComponent(departuresScrollPane, GroupLayout.DEFAULT_SIZE, 364, Short.MAX_VALUE)
		);
		GroupLayout gl_departuresPanel = new GroupLayout(departuresPanel);
		gl_departuresPanel.setHorizontalGroup(
			gl_departuresPanel.createParallelGroup(Alignment.LEADING)
				.addComponent(departuresListPanel, GroupLayout.DEFAULT_SIZE, 718, Short.MAX_VALUE)
		);
		gl_departuresPanel.setVerticalGroup(
			gl_departuresPanel.createParallelGroup(Alignment.LEADING)
				.addComponent(departuresListPanel, GroupLayout.DEFAULT_SIZE, 370, Short.MAX_VALUE)
		);
		
		appFrame.getContentPane().setLayout(groupLayout);
		flightListPanel.setLayout(gl_flightListPanel);
		controlPanel.setLayout(gl_controlPanel);
		arrivalsListPanel.setLayout(gl_arrivalsListPanel);
		arrivalsPanel.setLayout(gl_arrivalsPanel);
		departuresListPanel.setLayout(gl_departuresListPanel);
		departuresPanel.setLayout(gl_departuresPanel);
		
	}
	
	/**
	 * @return the allFlightData
	 */
	public static Object[][] getAllFlightData() {
		return allFlightData;
	}

	/**
	 * @param allFlightData the allFlightData to set
	 */
	public static void setAllFlightData(Object[][] allFlightData) {
		ApplicationWindow.allFlightData = allFlightData;
	}

	/**
	 * Refreshes main flight table table 
	 */
	public static void refreshMainTable() {
		ApplicationWindow.mainTableModel = new MyTableModel(
				getAllFlightData(), //The table data. An Object array is used because the data is in different forms (String, int, enums etc.)
				new Object[] { //The column labels
				"Flight Code", "Airline", "Model", "Starting City", "Destination City", "Location", "Status", "Registration"
			});
		ApplicationWindow.flightListTable.setModel(ApplicationWindow.mainTableModel);
		
	}
	
	/**
	 * Refreshes arrivals list table 
	 */
	public static void refreshArrivalsTable() {
		ApplicationWindow.arrivalsTableModel = new MyTableModel(
				Scenario.getArrivalsOrDeparturesList(false),
				new String[] {
						"AIRLINES", "FLIGHT", "FROM", "TO", "STATUS"
				});
		ApplicationWindow.arrivalsTable.setModel(ApplicationWindow.arrivalsTableModel);
	}

	/**
	 * Refreshes arrivals list table 
	 */
	public static void refreshDeparturesTable() {
		ApplicationWindow.departuresTableModel = new MyTableModel(
				Scenario.getArrivalsOrDeparturesList(true),
				new String[] {
						"AIRLINES", "FLIGHT", "FROM", "TO", "STATUS"
				});
		ApplicationWindow.departuresTable.setModel(ApplicationWindow.departuresTableModel);
	}
}
