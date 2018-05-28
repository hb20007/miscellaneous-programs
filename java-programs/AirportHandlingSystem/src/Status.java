/*
* Airport Handling System GUI
* @hb20007
*/

public enum Status {
	IN_FLIGHT, LANDING, LANDED, BOARDING, TAKEOFF, DOCKED, CIRCLING_AIRPORT 
	//DOCKED = Plane parked in airport.
	//LANDED = When a plane lands, it is assumed that it has moved away from the runway it used for landing so that another plane can land on it
}
