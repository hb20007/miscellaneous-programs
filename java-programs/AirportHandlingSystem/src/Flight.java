/*
* Airport Handling System GUI
* @hb20007
*/

public class Flight {
	private String flightCode;
	private Plane airplane = new Plane();
	private String startingCity;
	private String destinationCity;
	
	/**
	 * @return the flightCode
	 */
	public String getFlightCode() {
		return flightCode;
	}
	
	/**
	 * @param flightCode the flightCode to set
	 */
	public void setFlightCode(String flightCode) {
		this.flightCode = flightCode;
	}
	
	/**
	 * @return the airplane
	 */
	public Plane getAirplane() {
		return airplane;
	}
	
	/**
	 * @param airplane the airplane to set
	 */
	public void setAirplane(Plane airplane) {
		this.airplane = airplane;
	}
	
	/**
	 * @return the startingCity
	 */
	public String getStartingCity() {
		return startingCity;
	}
	
	/**
	 * @param startingCity the startingCity to set
	 */
	public void setStartingCity(String startingCity) {
		this.startingCity = startingCity;
	}
	
	/**
	 * @return the destinationCity
	 */
	public String getDestinationCity() {
		return destinationCity;
	}
	
	/**
	 * @param destinationCity the destinationCity to set
	 */
	public void setDestinationCity(String destinationCity) {
		this.destinationCity = destinationCity;
	}
}
