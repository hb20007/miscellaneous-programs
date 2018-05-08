import java.awt.EventQueue;
import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.DefaultListModel;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JSlider;
import javax.swing.JLabel;
import javax.swing.SwingConstants;
import javax.swing.border.TitledBorder;
import javax.swing.JList;
import javax.swing.JScrollPane;
import javax.swing.Timer;

import java.util.Random;

/**  
 * <h1>Room control station</h1>
 * 
 * <p>For the purposes of this simulation, I create a dynamic system with multiple random environemntal factors which update two shared
 * variables: temperature and humidity. I implement a safe method for various threads to write to these variables and I also
 * create a GUI with the rest of the elements described in the exercise such as a display and dials (sliders).</p>
 * 
 * @author hzsab
*/
public class Application {
	private WeatherController weatherController;
	static final int IDEAL_TEMP = 25;
	static final int IDEAL_HUM = 40;
	private JFrame frame;
	private static DefaultListModel<String> jListModel = new DefaultListModel<String>();
	
	private JLabel temperatureLabel;
	private JLabel humidityLabel;
	private JSlider temperatureSlider;
	private JSlider humiditySlider;
	private JScrollPane scrollPane;
	
	Timer timer = new Timer(1000, new ActionListener() {			// The GUI will update every 1000 ms
		@Override
		public void actionPerformed(ActionEvent e) {
			updateGUI();
		}
	});
	
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		WeatherController weatherController = new WeatherController(IDEAL_TEMP, IDEAL_HUM);			// Temperature and humidity start out ideal
		
		// Running application window
		JFrame.setDefaultLookAndFeelDecorated(true);
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Application window = new Application(weatherController);
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
		
		// Running weather event threads
		WeatherEvents heaterEvents = new WeatherEvents(weatherController, jListModel);
		Thread heaterThread = new Thread(new Runnable() {
			@Override
			public void run() {
				try {
					Random random = new Random();
					while (true) {
						Thread.sleep(random.nextInt(50000));
						heaterEvents.heaterTriggered();
					}
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		});
		WeatherEvents airConditionerEvents = new WeatherEvents(weatherController, jListModel);
		Thread airConditionerThread = new Thread(new Runnable() {
			@Override
			public void run() {
				try {
					Random random = new Random();
					while (true) {
						Thread.sleep(random.nextInt(50000));
						airConditionerEvents.airConditionerTriggered();
					}
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		});
		WeatherEvents peopleEvents = new WeatherEvents(weatherController, jListModel);
		Thread peopleThread = new Thread(new Runnable() {
			@Override
			public void run() {
				try {
					Random random = new Random();
					while (true) {
						Thread.sleep(random.nextInt(10000));
						peopleEvents.peopleTriggered();
					}
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		});
		WeatherEvents climateEvents = new WeatherEvents(weatherController, jListModel);
		Thread climateEventsThread = new Thread(new Runnable() {
			@Override
			public void run() {
				try {
					Random random = new Random();
					while (true) {
						Thread.sleep(random.nextInt(100000));
						climateEvents.climateEventTriggered();
					}
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		});
		WeatherEvents cloudEvents = new WeatherEvents(weatherController, jListModel);
		Thread cloudEventsThread = new Thread(new Runnable() {
			@Override
			public void run() {
				try {
					Random random = new Random();
					while (true) {
						Thread.sleep(random.nextInt(50000));
						cloudEvents.cloudsTriggered();
					}
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		});
		WeatherEvents humidityEvents = new WeatherEvents(weatherController, jListModel);
		Thread humidityEventsThread = new Thread(new Runnable() {
			@Override
			public void run() {
				try {
					Random random = new Random();
					while (true) {
						Thread.sleep(random.nextInt(50000));
						humidityEvents.humidityEventTriggered();
					}
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		});
		
		heaterThread.start();	// I avoid heaterStart.join() etc. to avoid dealing with InterruptedExceptions
		airConditionerThread.start();
		peopleThread.start();
		climateEventsThread.start();
		cloudEventsThread.start();
		humidityEventsThread.start();
	}

	/**
	 * Create the application.
	 */
	public Application(WeatherController weatherController) {
		this.weatherController = weatherController;
		initialize();
		timer.start();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.setBounds(100, 100, 450, 300);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setTitle("Room Control System");
		frame.setResizable(false);
		frame.setLocationRelativeTo(null);
		frame.getContentPane().setLayout(null);
		
		JPanel panel = new JPanel();
		panel.setBorder(new TitledBorder(null, "Current Sensor Reading", TitledBorder.LEADING, TitledBorder.TOP, null, null));
		panel.setBounds(10, 130, 424, 131);
		frame.getContentPane().add(panel);
		panel.setLayout(null);
		
		temperatureSlider = new JSlider();
		temperatureSlider.setValue(weatherController.readCurrentTemperature());
		temperatureSlider.setMaximum(50);
		temperatureSlider.setEnabled(false);
		temperatureSlider.setBounds(10, 67, 200, 26);
		panel.add(temperatureSlider);
		
		humiditySlider = new JSlider();
		humiditySlider.setEnabled(false);
		humiditySlider.setBounds(214, 67, 200, 26);
		humiditySlider.setValue(weatherController.readCurrentHumidity());
		panel.add(humiditySlider);
		
		JLabel temperatureTextLabel = new JLabel("Temperature");
		temperatureTextLabel.setHorizontalAlignment(SwingConstants.CENTER);
		temperatureTextLabel.setBounds(60, 42, 105, 14);
		panel.add(temperatureTextLabel);
		
		JLabel humidityTextLabel = new JLabel("Humidity");
		humidityTextLabel.setHorizontalAlignment(SwingConstants.CENTER);
		humidityTextLabel.setBounds(282, 42, 71, 14);
		panel.add(humidityTextLabel);
		
		temperatureLabel = new JLabel(weatherController.readCurrentTemperature() + "\u00B0");
		temperatureLabel.setForeground(Color.GREEN);
		temperatureLabel.setHorizontalAlignment(SwingConstants.CENTER);
		temperatureLabel.setBounds(48, 95, 128, 14);
		panel.add(temperatureLabel);
		
		humidityLabel = new JLabel(weatherController.readCurrentHumidity() + "%");
		humidityLabel.setForeground(Color.GREEN);
		humidityLabel.setHorizontalAlignment(SwingConstants.CENTER);
		humidityLabel.setBounds(264, 95, 111, 14);
		panel.add(humidityLabel);
		
		scrollPane = new JScrollPane();
		scrollPane.setBounds(10, 11, 414, 80);
		frame.getContentPane().add(scrollPane);
		
		JList<String> list = new JList<String>(jListModel);
		jListModel.addElement(String.format("Simulation started with ideal room temperature (%d\u00B0) and humidity (%d%%)", IDEAL_TEMP, IDEAL_HUM));			// NB 2 % signs to display a literal % sign.
		scrollPane.setViewportView(list);
		
		JLabel idealTemperatureTextLabel = new JLabel("Ideal temperature:");
		idealTemperatureTextLabel.setFont(new Font("Tahoma", Font.BOLD, 11));
		idealTemperatureTextLabel.setBounds(55, 105, 108, 14);
		frame.getContentPane().add(idealTemperatureTextLabel);
		
		JLabel idealTemperatureLabel = new JLabel(IDEAL_TEMP + "\u00B0");
		idealTemperatureLabel.setForeground(Color.GREEN);
		idealTemperatureLabel.setBounds(173, 105, 79, 14);
		frame.getContentPane().add(idealTemperatureLabel);
		
		JLabel idealHumidityTextLabel = new JLabel("Ideal humidity:");
		idealHumidityTextLabel.setFont(new Font("Tahoma", Font.BOLD, 11));
		idealHumidityTextLabel.setBounds(262, 105, 96, 14);
		frame.getContentPane().add(idealHumidityTextLabel);
		
		JLabel idealHumidityLabel = new JLabel(IDEAL_HUM + "%");
		idealHumidityLabel.setForeground(Color.GREEN);
		idealHumidityLabel.setBounds(355, 105, 46, 14);
		frame.getContentPane().add(idealHumidityLabel);
	}
	
	/*
	 * Updates the GUI. The only solution is to call it whenever a Timer ActionEvent is trigger.
	 */
	void updateGUI() {
		// Updating GUI values
		temperatureLabel.setText(String.format("%d\u00B0", weatherController.readCurrentTemperature()));
		humidityLabel.setText(String.format("%d%%", weatherController.readCurrentHumidity()));
		temperatureSlider.setValue(weatherController.readCurrentTemperature());
		humiditySlider.setValue(weatherController.readCurrentHumidity());
		
		// Calculating temperature and humidity percentage difference from the ideal and using it to update colors
		float tempPercentageDifference = Math.abs(((weatherController.readCurrentTemperature() - IDEAL_TEMP) / (float)IDEAL_TEMP) * 100);
		float humidityPercentageDifference = Math.abs(((weatherController.readCurrentHumidity() - IDEAL_HUM) / (float)IDEAL_HUM)) * 100;
		if (tempPercentageDifference <= 10.0)
			temperatureLabel.setForeground(Color.GREEN);
		else if (tempPercentageDifference <= 25.0)
			temperatureLabel.setForeground(Color.YELLOW);
		else
			temperatureLabel.setForeground(Color.RED);
		
		if (humidityPercentageDifference <= 10.0)
			humidityLabel.setForeground(Color.GREEN);
		else if (humidityPercentageDifference <= 25.0)
			humidityLabel.setForeground(Color.YELLOW);
		else
			humidityLabel.setForeground(Color.RED);
		
		// Scrolling down to the latest events in the JList
		scrollPane.getVerticalScrollBar().setValue(scrollPane.getVerticalScrollBar().getMaximum());
	}
}
