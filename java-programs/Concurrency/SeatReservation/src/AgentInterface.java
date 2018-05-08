import java.util.ArrayList;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.Color;
import java.awt.Component;
import java.awt.Cursor;

import javax.swing.JTextField;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JButton;
import javax.swing.SwingConstants;
import javax.swing.border.LineBorder;
import javax.swing.border.BevelBorder;

//import org.apache.commons.lang3.StringUtils;	// For an easy way to format string to title case

import com.jgoodies.forms.layout.FormLayout;
import com.jgoodies.forms.layout.ColumnSpec;
import com.jgoodies.forms.layout.FormSpecs;
import com.jgoodies.forms.layout.RowSpec;
import java.awt.event.WindowFocusListener;
import java.awt.event.WindowEvent;

public class AgentInterface extends JFrame {

	private static final long serialVersionUID = 1L;
	private String name;
	private ArrayList<Seat> allSeats;
	private Seat selectedSeat;
	private JPanel seatsPanel;
	private JTextField seatNumberTextField;
	private JTextField seatStatusTextField;
	private JButton btnReserve;
	
	/**
	 * Create the frame.
	 * @param center Whether the frame should be centered on the monitor
	 * @param agentName The identifier of the Agent instance
	 * @param seats The seats in the environment
	 */
	public AgentInterface(Boolean center, String agentName, ArrayList<Seat> seats) {
		name = agentName;
		allSeats = seats;
		initializeGUI(center, agentName);

		addWindowFocusListener(new WindowFocusListener() {	// NB we need a WindowFocusListener not just a FocusListener
			public void windowGainedFocus(WindowEvent e) {	// When focus is gained the GUI is updated because the other thread could have done something while in control.
				displaySelectedSeatStatus();	// Used to update seat status text box
				updateSeatPanelColors();
				updateReserveAvailability();
			}

			@Override
			public void windowLostFocus(WindowEvent arg0) {
				// Must be implemented
			}
		});
	}
	
	/*
	 * Initializes the Agent GUI.
	 */
	void initializeGUI(Boolean center, String agentName) {
		setTitle("Seat Reservation System" + " \u2014 " + agentName);
		setResizable(false);
		setBounds(100, 100, 450, 300);
		if (center)
			setLocationRelativeTo(null);	// Centers the frame. Has to be called after setBounds() has been executed.
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		getContentPane().setLayout(null);		// I can use an absolute layout because the form is non-resizable.
		
		// When a seat panel is clicked, it is selected and the color becomes a darker green. Before that, all other seat panels with the same parent get the original background color first.
		MouseAdapter seatPanelMouseAdapter = new MouseAdapter() {
            @Override
            public void mousePressed(MouseEvent e) {
            	this.onSeatPanelClicked(e);
            }

            /**
             * Called when a seat panel is clicked and resets the colors of all other seat panels in with the same parent while setting the color of the current seat panel to be a darker green to show that it is selected.
             * @param ev The MouseEvent of clicking the seat panel
             */
        	private void onSeatPanelClicked(MouseEvent ev) {				// The method needs to be defined in here so that it is for the type MouseEvent.
        		findSelectedSeatByNumber(Integer.parseInt(ev.getComponent().getName()));	// The selected seat needs to be updated first because other methods depend on the correct new selectedSeat class variable
            	updateSeatPanelColors();
            	seatNumberTextField.setEnabled(false);
            	seatNumberTextField.setText(ev.getComponent().getName());
           	 	seatStatusTextField.setEnabled(false);
           	 	displaySelectedSeatStatus();
            	updateReserveAvailability();
        	}
			
        	@Override
			public void mouseEntered(MouseEvent ev) {
        		((JPanel)ev.getComponent()).setBorder(new BevelBorder(BevelBorder.LOWERED, null, null, null, null));	// Casting to JPanel is necessary to use setBorder(). It's safe.
			}
        	
			@Override
			public void mouseExited(MouseEvent ev) {
				((JPanel)ev.getComponent()).setBorder(null);
			}
        };
        
     // When the seat parent panel is clicked, any selected seat is deselected
     		MouseAdapter seatParentPanelMouseAdapter = new MouseAdapter() {
                 @Override
                 public void mousePressed(MouseEvent e) {
                	 selectedSeat = null;
                	 updateSeatPanelColors();
                	 seatNumberTextField.setEnabled(false);
                	 seatNumberTextField.setText("");
                	 seatStatusTextField.setEnabled(false);
                	 seatStatusTextField.setText("");
                	 updateReserveAvailability();	// This will always resolve to disabling the reserve button. I call the method for consistency.
                 }
             };
		
		seatsPanel = new JPanel();
		seatsPanel.setBackground(Color.PINK);
		seatsPanel.setBorder(new LineBorder(new Color(0, 0, 0)));
		seatsPanel.setBounds(63, 11, 301, 110);
		getContentPane().add(seatsPanel);
		seatsPanel.setLayout(null);
		seatsPanel.addMouseListener(seatParentPanelMouseAdapter);
		
		JLabel lblSeats = new JLabel("Seats");
		lblSeats.setHorizontalAlignment(SwingConstants.CENTER);
		lblSeats.setBounds(127, 5, 47, 14);
		seatsPanel.add(lblSeats);
		
		JPanel seat1Panel = new JPanel();
		seat1Panel.setToolTipText("Seat 1");
		seat1Panel.setBackground(Color.GREEN);
		seat1Panel.setBounds(67, 29, 27, 33);
		seat1Panel.setCursor(new Cursor(Cursor.HAND_CURSOR));
		seat1Panel.addMouseListener(seatPanelMouseAdapter);
		seat1Panel.setName("1");	// Used to identify it in a loop
		seatsPanel.add(seat1Panel);
		
		JPanel seat2Panel = new JPanel();
		seat2Panel.setToolTipText("Seat 3");
		seat2Panel.setBackground(Color.GREEN);
		seat2Panel.setBounds(67, 66, 27, 33);
		seat2Panel.setCursor(new Cursor(Cursor.HAND_CURSOR));		
		seat2Panel.addMouseListener(seatPanelMouseAdapter);
		seat2Panel.setName("2");
		seatsPanel.add(seat2Panel);
		
		JPanel seat3Panel = new JPanel();
		seat3Panel.setToolTipText("Seat 2");
		seat3Panel.setBackground(Color.GREEN);
		seat3Panel.setBounds(208, 29, 27, 33);
		seat3Panel.setCursor(new Cursor(Cursor.HAND_CURSOR));		
		seat3Panel.addMouseListener(seatPanelMouseAdapter);
		seat3Panel.setName("3");
		seatsPanel.add(seat3Panel);
		
		JPanel seat4Panel = new JPanel();
		seat4Panel.setToolTipText("Seat 4");
		seat4Panel.setBackground(Color.GREEN);
		seat4Panel.setBounds(208, 66, 27, 33);
		seat4Panel.setCursor(new Cursor(Cursor.HAND_CURSOR));		
		seat4Panel.addMouseListener(seatPanelMouseAdapter);
		seat4Panel.setName("4");
		seatsPanel.add(seat4Panel);
		
		JPanel seatInfoPanel = new JPanel();
		seatInfoPanel.setBounds(63, 132, 301, 56);
		getContentPane().add(seatInfoPanel);
		seatInfoPanel.setLayout(new FormLayout(new ColumnSpec[] {
				ColumnSpec.decode("72px"),
				ColumnSpec.decode("65px"),
				FormSpecs.LABEL_COMPONENT_GAP_COLSPEC,
				ColumnSpec.decode("86px:grow"),},
			new RowSpec[] {
				FormSpecs.LINE_GAP_ROWSPEC,
				RowSpec.decode("20px"),
				FormSpecs.RELATED_GAP_ROWSPEC,
				FormSpecs.DEFAULT_ROWSPEC,}));
		
		JLabel lblSeatNumber = new JLabel("Seat number:");
		seatInfoPanel.add(lblSeatNumber, "1, 2, 2, 1, right, center");
		
		seatNumberTextField = new JTextField();
		seatNumberTextField.setEnabled(false);
		seatNumberTextField.setHorizontalAlignment(SwingConstants.RIGHT);
		seatNumberTextField.setEditable(false);
		seatInfoPanel.add(seatNumberTextField, "4, 2, fill, default");
		seatNumberTextField.setColumns(10);
		
		JLabel lblSeatStatus = new JLabel("Seat status:");
		seatInfoPanel.add(lblSeatStatus, "1, 4, 2, 1, right, default");
		
		seatStatusTextField = new JTextField();
		seatStatusTextField.setEditable(false);
		seatStatusTextField.setHorizontalAlignment(SwingConstants.RIGHT);
		seatInfoPanel.add(seatStatusTextField, "4, 4, fill, default");
		
		btnReserve = new JButton("Reserve");
		btnReserve.setEnabled(false);
		btnReserve.setBounds(169, 199, 89, 23);
		btnReserve.setCursor(new Cursor(Cursor.HAND_CURSOR));
		btnReserve.addMouseListener(new MouseAdapter() {
			@Override
			public void mousePressed(MouseEvent e) {
				try {
					selectedSeat.reserveSeat(name);		// try catch block needed for the InterruptedException
				} catch (InterruptedException ex) {
					ex.printStackTrace();
				}
				displaySelectedSeatStatus();	// Used to update seat status text box
				updateSeatPanelColors();
				updateReserveAvailability();
			}
		});
		getContentPane().add(btnReserve);
	}
	
	/*
	 * Sets the class variable <code>selectedSeat</code> to the current selected seat
	 * @param seatNumber The seat number used to find the right seat
	 */
	void findSelectedSeatByNumber(int seatNumber) {
		for (Seat seat : allSeats)
			if (seat.readSeatNumber() == seatNumber) {
				selectedSeat = seat;
			}
	}
	
	/*
	 * Displays the status of <code>selectedSeat</code> in the text box.
	 */
	void displaySelectedSeatStatus() {
		if (selectedSeat != null) {
//			seatStatusTextField.setText(StringUtils.capitalize(selectedSeat.readSeatStatus().name().toLowerCase()));
			seatStatusTextField.setText(selectedSeat.readSeatStatus().name());
			if (selectedSeat.readSeatStatus() == SeatStatus.RESERVED)
				seatStatusTextField.setText(seatStatusTextField.getText() + " by " + selectedSeat.readOwnerName());		// .getText() is used to append text in this manner.
		}
	}
	
	/*
	 * Updates the background color of all seat panels. Called when a seat's status is changed.
	 */
	void updateSeatPanelColors() {
		for (Component seatPanel : seatsPanel.getComponents())
			if (seatPanel instanceof JPanel) // This check avoids an error with a null component.
	     		if (allSeats.get((Integer.parseInt(seatPanel.getName())) - 1).readSeatStatus() == SeatStatus.FREE)
	     			if (selectedSeat != null && Integer.parseInt(seatPanel.getName()) == selectedSeat.readSeatNumber())		// If selected seat exists and the current seat in the loop is the selected seat
	     				seatPanel.setBackground(new Color(0, 100, 0));
	     			else
	     				seatPanel.setBackground(Color.GREEN);
	     		else if (selectedSeat != null && Integer.parseInt(seatPanel.getName()) == selectedSeat.readSeatNumber())
	     			seatPanel.setBackground(new Color(200, 0, 0));
	     		else
	     			seatPanel.setBackground(Color.RED);
				
	}
	
	/*
	 * Updates whether the Reserve button is enabled.
	 */
	void updateReserveAvailability() {
		if (selectedSeat == null || selectedSeat.readSeatStatus() == SeatStatus.RESERVED)
			btnReserve.setEnabled(false);
		else
			btnReserve.setEnabled(true);
	}
}
