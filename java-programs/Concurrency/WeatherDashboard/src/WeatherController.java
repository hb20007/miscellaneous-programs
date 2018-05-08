/*
 * The weather controller class
 * @author hzsab
 */
public class WeatherController {
	private int temperature;
	private int humidity;
	
	public WeatherController(int startingTemperature, int startingHumidity) {
		temperature = startingTemperature;
		humidity = startingHumidity;
	}
	
	/*
	 * Getter method for <code>temperature</code>
	 */
	public int readCurrentTemperature() {
		return temperature;
	}
	
	/*
	 * Getter method for <code>humidity</code>
	 */
	public int readCurrentHumidity() {
		return humidity;
	}
	
	/*
	 * Setter method for both temperature and humidity
	 * @param temperatureIncrement Increment for temperature
	 * @param humidityIncrement Increment for humidity
	 */
	public void updateWeather(int temperatureIncrement, int humidityIncrement) {
		temperature += temperatureIncrement;
		humidity += humidityIncrement;
	}
}
