/*
* COMP-212 
* Instructor: Dr Constandinos Mavromoustakis
*
* Final Project - Creating an Airport Handling System GUI
*
* @HANNA SABABA (U144N0959)
*/

public class Passenger {	
	private int ticketNumber;
	private Flight passengerFlight = new Flight();

	/**
	 * Create a passenger
	 */
	Passenger(int num) {
		setTicketNumber(num);
	}

	/**
	 * @return the ticketNumber
	 */
	public int getTicketNumber() {
		return ticketNumber;
	}
	
	/**
	 * @param ticketNumber the ticketNumber to set
	 */
	public void setTicketNumber(int ticketNumber) {
		this.ticketNumber = ticketNumber;
	}
	
	/**
	 * @return the passengerFlight
	 */
	public Flight getPassengerFlight() {
		return passengerFlight;
	}
	
	/**
	 * @param passengerFlight the passengerFlight to set
	 */
	public void setPassengerFlight(Flight passengerFlight) {
		this.passengerFlight = passengerFlight;
	}

}

