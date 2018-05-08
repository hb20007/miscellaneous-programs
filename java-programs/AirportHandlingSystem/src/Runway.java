/*
* COMP-212 
* Instructor: Dr Constandinos Mavromoustakis
*
* Final Project - Creating an Airport Handling System GUI
*
* @HANNA SABABA (U144N0959)
*/

public class Runway {
	private int runwayNumber; //Runways are named by a number between 01 and 36, which is generally the magnetic azimuth of the runway's heading in decadegrees.
	private Airport runwayAirport = new Airport();
	boolean runwayOccupied;
	
	/**
	 * Create a runway
	 */
	public Runway(int i) {
		setRunwayNumber(i);
		setRunwayOccupied(false);
	}
	
	/**
	 * @return the runwayNumber
	 */
	public int getRunwayNumber() {
		return runwayNumber;
	}
	
	/**
	 * @param runwayNumber the runwayNumber to set
	 */
	public void setRunwayNumber(int runwayNumber) {
		this.runwayNumber = runwayNumber;
	}
	
	/**
	 * @return the runwayAirport
	 */
	public Airport getRunwayAirport() {
		return runwayAirport;
	}
	
	/**
	 * @param runwayAirport the runwayAirport to set
	 */
	public void setRunwayAirport(Airport runwayAirport) {
		this.runwayAirport = runwayAirport;
	}
	
	/**
	 * @return the runwayOccupied
	 */
	public boolean isRunwayOccupied() {
		return runwayOccupied;
	}
	
	/**
	 * @param runwayOccupied the runwayOccupied to set
	 */
	public void setRunwayOccupied(boolean runwayOccupied) {
		this.runwayOccupied = runwayOccupied;
	}
}
