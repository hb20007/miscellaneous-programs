import java.util.Random;

import javax.swing.DefaultListModel;

/*
 * The weather events class with methods that trigger weather events that use the weather controller to register changes to the temperature and humidity.
 * @author hzsab
 */
public class WeatherEvents {
	private WeatherController weatherController;
	private DefaultListModel<String> jListModel;
	
	public WeatherEvents(WeatherController weatherController, DefaultListModel<String> jListModel) {
		this.weatherController = weatherController;
		this.jListModel = jListModel;
	}
	
	/*
	 * Triggers a random heater event and logs it into the JList model.
	 */
	synchronized public void heaterTriggered() {
		Boolean coinFlip = new Random().nextBoolean();		// If true a heater will be turned on, else a heater will be turned off.
		if (coinFlip) {
			weatherController.updateWeather(2, 0);
			jListModel.addElement("Somebody turned on a heater in the room. Temperature rises by 2.");
		}
		else {
			weatherController.updateWeather(-2, 0);
			jListModel.addElement("The power supply on a heater was lost! Temperature decreases by 2.");			
		}
	}
	
	/*
	 * Triggers a random air conditioner event and logs it into the JList model.
	 */
	synchronized public void airConditionerTriggered() {
		Boolean coinFlip = new Random().nextBoolean();		// If true an air conditioner will be turned on, else a heater will be turned off.
		if (coinFlip) {
			weatherController.updateWeather(-1, -5);
			jListModel.addElement("Someone turned on an AC. Temperature and humidity go down.");
		}
		else {
			weatherController.updateWeather(1, 5);
			jListModel.addElement("A person turned off an AC. Temperature and humidity soar.");			
		}
	}
	
	/*
	 * Triggers a random people event and logs it into the JList model.
	 */
	synchronized public void peopleTriggered() {
		Boolean coinFlip = new Random().nextBoolean();		// If true somebody enters, else someone exits
		if (coinFlip) {
			weatherController.updateWeather(0, 1);
			jListModel.addElement("A guest enters the room, humidity increases slightly.");
		}
		else {
			weatherController.updateWeather(0, -1);
			jListModel.addElement("An occupant leaves the room, humidity drops a little.");
		}
	}
	
	/*
	 * Triggers a random climate event and logs it into the JList model.
	 */
	synchronized public void climateEventTriggered() {
		int randomNum = new Random().nextInt(4);		// Generates random int from 0 to 3. If 0, it starts raining outside. If 1, its starts snowing. If 2, the wind brings forth a hot breeze. If 3, A meteor falls on the house.
		switch (randomNum) {
		case 0:
			weatherController.updateWeather(-2, 0);
			jListModel.addElement("It is raining heavily outside, temperature falls.");
			break;
		case 1:
			weatherController.updateWeather(-4, 0);
			jListModel.addElement("It is snowing! Temperature plummets.");
			break;
		case 2:
			weatherController.updateWeather(2, 0);
			jListModel.addElement("The wind brings forth a hot breeze, temperature gets higher.");
			break;
		default:
			weatherController.updateWeather(4, 0);
			jListModel.addElement("A meteor falls on the house! Temperature shoots up.");
			break;
		}
	}
	
	/*
	 * Triggers a random cloud event and logs it into the JList model.
	 */
	synchronized public void cloudsTriggered() {
		Boolean coinFlip = new Random().nextBoolean();		// If true clouds increase, else they decrease
		if (coinFlip) {
			weatherController.updateWeather(-1, 0);
			jListModel.addElement("More clouds are covering the sun outside, temperature decrements.");
		}
		else {
			weatherController.updateWeather(1, 0);
			jListModel.addElement("The clouds are clearing up outside, temperature increments.");
		}
	}
	
	/*
	 * Triggers a random humidity event and logs it into the JList model.
	 */
	synchronized public void humidityEventTriggered() {
		Boolean coinFlip = new Random().nextBoolean();		// If true humidity increases, else decreases
		if (coinFlip) {
			weatherController.updateWeather(0, 2);
			jListModel.addElement("Somebody overwatered the house plants. Humidity escalates.");
		}
		else {
			weatherController.updateWeather(0, -2);
			jListModel.addElement("A visitor turns on a dehumidifier. Humidity drops.");
		}
	}
}