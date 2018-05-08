/*
* COMP-212 
* Instructor: Dr Constandinos Mavromoustakis
*
* Final Project - Creating an Airport Handling System GUI
*
* @HANNA SABABA (U144N0959)
*/

public enum Status {
	IN_FLIGHT, LANDING, LANDED, BOARDING, TAKEOFF, DOCKED, CIRCLING_AIRPORT 
	//DOCKED = Plane parked in airport.
	//LANDED = When a plane lands, it is assumed that it has moved away from the runway it used for landing so that another plane can land on it
}
