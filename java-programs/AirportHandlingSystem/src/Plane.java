/*
* COMP-212 
* Instructor: Dr Constandinos Mavromoustakis
*
* Final Project - Creating an Airport Handling System GUI
*
* @HANNA SABABA (U144N0959)
*/

public class Plane {
	private String airline;
	private String model;
	private String location; //"Airborne" or the name of an airport
	private Status planeStatus; 
	private Registration registrationStatus;
	
	/**
	 * Create a plane
	 */	
	public Plane() {
		setLocation(Scenario.getLarnacaAirport().getName());
		setPlaneStatus(Status.DOCKED);
		setRegistrationStatus(Registration.UNAPPLICABLE);
	}

	/**
	 * @return the airline
	 */
	public String getAirline() {
		return airline;
	}

	/**
	 * @param airline the airline to set
	 */
	public void setAirline(String airline) {
		this.airline = airline;
	}

	/**
	 * @return the model
	 */
	public String getModel() {
		return model;
	}

	/**
	 * @param model the model to set
	 */
	public void setModel(String model) {
		this.model = model;
	}

	/**
	 * @return the location
	 */
	public String getLocation() {
		return location;
	}

	/**
	 * @param location the location to set
	 */
	public void setLocation(String location) {
		this.location = location;
	}

	/**
	 * @return the planeStatus
	 */
	public Status getPlaneStatus() {
		return planeStatus;
	}

	/**
	 * @param planeStatus the planeStatus to set
	 */
	public void setPlaneStatus(Status planeStatus) {
		this.planeStatus = planeStatus;
	}

	/**
	 * @return the registrationStatus
	 */
	public Registration getRegistrationStatus() {
		return registrationStatus;
	}

	/**
	 * @param registrationStatus the registrationStatus to set
	 */
	public void setRegistrationStatus(Registration registrationStatus) {
		this.registrationStatus = registrationStatus;
	}
}
