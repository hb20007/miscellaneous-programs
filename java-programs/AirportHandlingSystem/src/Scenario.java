/*
* Airport Handling System GUI
* @hb20007
*/

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.Scanner;

import javax.swing.JOptionPane;

public class Scenario { //This class contains the scenario for this particular application. There is 1 airport with 3 runways, 10 planes and therefore 10 flights, 300 passengers (30 in each flight) and 
	public static final int numberOfFlights = 10;
	public static final int numberOfPassengers = 300;
	public static final int larnacaAirportNumberOfRunways = 2; //Fun fact: In real life, Larnaca airport has only 1 runway
	public static final int numberOfFlightAttributes = 8;
	
	private static Airport larnacaAirport = new Airport(); //All the variables and methods are static because the scenario is fixed so there is no need for different instances of the class
	private static Plane[] planesArray = new Plane[numberOfFlights];
	private static Flight[] flightsArray = new Flight[numberOfFlights];
	private static Passenger[] passengersArray = new Passenger[numberOfPassengers];
	private static Runway[] runwaysArray = new Runway[larnacaAirportNumberOfRunways]; 
	
	/**
	 * Create the scenario
	 */
	Scenario() {
		initializeLarnacaAirport();
		initializePlanesArray();
		initializeFlightsArray();
		initializePassengersArray();
		initializeRunwaysArray();
	}

	/**
	 * larnacaAirport initializer
	 */
	private static void initializeLarnacaAirport() {
		getLarnacaAirport().setName("Larnaca_Airport");
		getLarnacaAirport().setCity("Larnaca");
		getLarnacaAirport().setCountry("Cyprus");
		getLarnacaAirport().setCode("LCA");		
	}
	
	/**
	 * planesArray initializer
	 */
	private static void initializePlanesArray() {
		for (int i = 0; i < getPlanesArray().length; i++) {
			getPlanesArray()[i] = new Plane();
			if (i < 4) {
				getPlanesArray()[i].setAirline("Aegean");
				getPlanesArray()[i].setModel("Boeing-777");
			}
			else if (i< 7){
				getPlanesArray()[i].setAirline("Emirates");
				getPlanesArray()[i].setModel("Boeing-787");
			}
			else {
				getPlanesArray()[i].setAirline("Ryanair");
				getPlanesArray()[i].setModel("Airbus-A350");
				getPlanesArray()[i].setLocation("Airborne");	
				getPlanesArray()[i].setPlaneStatus(Status.IN_FLIGHT);				
				getPlanesArray()[i].setRegistrationStatus(Registration.UNREGISTERED);				
			}
		}
	}
	
	/**
	 * flightsArray initializer
	 */
	private static void initializeFlightsArray() {
		for (int i = 0; i < getFlightsArray().length; i++) {
			getFlightsArray()[i] = new Flight();
			getFlightsArray()[i].setAirplane(planesArray[i]); 
			if (i < 4) {
				getFlightsArray()[i].setFlightCode("AEE-" + ((int)(Math.random()*1000))); //Generates a random flight code (composed of the IATA airline designator of the airline + a random 3 digit integer) for the purpose of this application
				getFlightsArray()[i].setStartingCity("Larnaca");
				getFlightsArray()[i].setDestinationCity("Heraklion");
			}
			else if (i< 7){
				getFlightsArray()[i].setFlightCode("EK-" + ((int)(Math.random()*1000))); //Generates a random flight code (composed of the IATA airline designator of the airline + a random 3 digit integer) for the purpose of this application
				getFlightsArray()[i].setStartingCity("Larnaca");
				getFlightsArray()[i].setDestinationCity("Dubai");
			}
			else {	
				getFlightsArray()[i].setFlightCode("RYR-" + ((int)(Math.random()*1000))); //Generates a random flight code (composed of the IATA airline designator of the airline + a random 3 digit integer) for the purpose of this application
				getFlightsArray()[i].setStartingCity("Athens");
				getFlightsArray()[i].setDestinationCity("Larnaca");
			}
		}
	}
	
	/**
	 * passengersArray initializer
	 */
	private static void initializePassengersArray() {
		for (int i = 0; i < getPassengersArray().length; i++) {
			getPassengersArray()[i] = new Passenger(i);
			getPassengersArray()[i].setPassengerFlight(flightsArray[i%10]); //The index of the flight assigned to each passenger is "i modulus 10". Therefore passenger 0 is assigned to flight 0, passenger 1 to flight 1 etc.. until passenger 10 is assigned again to flight 0 and so on... In the end each flight will have 30 passengers
		}
	}
	
	/**
	 * runwaysArray initializer
	 */
	private static void initializeRunwaysArray() {
		for (int i = 0; i < getRunwaysArray().length; i++) {
			getRunwaysArray()[i] = new Runway(i+1); //The first valid runway number is 01 not 00 hence the "+1"
			getRunwaysArray()[i].setRunwayAirport(Scenario.getLarnacaAirport());
		}
	}
	
	/**
	 * @return the larnacaAirport
	 */
	public static Airport getLarnacaAirport() {
		return larnacaAirport;
	}

	/**
	 * @param larnacaAirport the larnacaAirport to set
	 */
	public static void setLarnacaAirport(Airport larnacaAirport) {
		Scenario.larnacaAirport = larnacaAirport;
	}

	/**
	 * @return the planesArray
	 */
	public static Plane[] getPlanesArray() {
		return planesArray;
	}

	/**
	 * @param planesArray the planesArray to set
	 */
	public static void setPlanesArray(Plane[] planesArray) {
		Scenario.planesArray = planesArray;
	}

	/**
	 * @return the flightsArray
	 */
	public static Flight[] getFlightsArray() {
		return flightsArray;
	}

	/**
	 * @param flightsArray the flightsArray to set
	 */
	public static void setFlightsArray(Flight[] flightsArray) {
		Scenario.flightsArray = flightsArray;
	}

	/**
	 * @return the passengersArray
	 */
	public static Passenger[] getPassengersArray() {
		return passengersArray;
	}

	/**
	 * @param passengersArray the passengersArray to set
	 */
	public static void setPassengersArray(Passenger[] passengersArray) {
		Scenario.passengersArray = passengersArray;
	}

	/**
	 * @return the runwaysArray
	 */
	public static Runway[] getRunwaysArray() {
		return runwaysArray;
	}

	/**
	 * @param runwaysArray the runwaysArray to set
	 */
	public static void setRunwaysArray(Runway[] runwaysArray) {
		Scenario.runwaysArray = runwaysArray;
	}

	/**
	 * @param i the index 
	 * @return an array with all the data about the i'th flight
	 */
	public static Object[] getFlightsRow(int i) {
		Object[] ithFlightRow = {getFlightsArray()[i].getFlightCode(), getFlightsArray()[i].getAirplane().getAirline(), getFlightsArray()[i].getAirplane().getModel(), getFlightsArray()[i].getStartingCity(), getFlightsArray()[i].getDestinationCity(), getFlightsArray()[i].getAirplane().getLocation(), getFlightsArray()[i].getAirplane().getPlaneStatus(), getFlightsArray()[i].getAirplane().getRegistrationStatus() };
		//In the above code, I refer to the Airplane instances within the flightsArray and not the ones in the planesArray. This creates more flexible code because if the scenario is modified and an airplane is assigned to a different flight, my code will still work since only the flightsArray is referenced throughtout		
		return ithFlightRow;
	}
	
	/**
	 * @return all flight data
	 */
	public static Object[][] getFlightData() {
		Object[][] allFlightData = new Object[numberOfFlights][];
		for (int i = 0; i < numberOfFlights; i++) {
			allFlightData[i] = getFlightsRow(i);
		}	
		return allFlightData;
	}
	
	/**
	 * @param i the index
	 * @return an array with arrivals or departures data for the i'th flight
	 */
	public static Object[] getArrivalsOrDeparturesRecord(int i) {
		Object[] ithArrivalsOrDeparturesRow = {ApplicationWindow.getAllFlightData()[i][1],ApplicationWindow.getAllFlightData()[i][0], ApplicationWindow.getAllFlightData()[i][3], ApplicationWindow.getAllFlightData()[i][4], ApplicationWindow.getAllFlightData()[i][6]};
			return ithArrivalsOrDeparturesRow;	
	}
	
	/**
	 * @param arrivalsOrDepartures: 0 = arrivals, 1 = departures. Determines which list to return  
	 * @return Arrivals list
	 */
	public static Object[][] getArrivalsOrDeparturesList(boolean arrivalsOrDepartures) {
		if (arrivalsOrDepartures == false) { //ie. if Arrivals list is needed
			Object[][] arrivalsList = new Object[numberOfFlights][]; //The number of arrival flights can be less than the numberOfFlights but this is not a problem because the extra elements will remain = null and will not be displayed in the GUI
			int j = 0; //Secondary counter to be used in for loop
			for (int i = 0; i < numberOfFlights; i++) {
				if(getFlightsArray()[i].getDestinationCity() == "Larnaca") { //If the plane is coming towards Larnaca
				arrivalsList[j] = getArrivalsOrDeparturesRecord(i);
				j++;
				}
			}	
			return arrivalsList;
		}
		else { //ie. if Departures list is needed
			Object[][] departuresList = new Object[numberOfFlights][];
			int j = 0; //Secondary counter to be used in for loop
			for (int i = 0; i < numberOfFlights; i++) {
				if(getFlightsArray()[i].getStartingCity() == "Larnaca" && ((getFlightsArray()[i].getAirplane().getPlaneStatus() == Status.DOCKED) || (getFlightsArray()[i].getAirplane().getPlaneStatus() == Status.BOARDING) || (getFlightsArray()[i].getAirplane().getPlaneStatus() == Status.TAKEOFF))){ //If the plane is leaving from Larnaca and its status is DOCKED or BOARDING or TAKEOFF
				departuresList[j] = getArrivalsOrDeparturesRecord(i);
				j++;
				}
			}	
			return departuresList;
		}
	}
	
	/**
	 * @return List of all flight codes
	 */
	public static String[] getListOfAllFlightCodes() {
		String[] listOfAllFlightCodes = new String[numberOfFlights];
		for (int i = 0; i < numberOfFlights; i++) 
			listOfAllFlightCodes[i] = Scenario.getFlightsArray()[i].getFlightCode();
		return listOfAllFlightCodes;
	}
	
	/**
	 * @return True if there are free runways, false if not
	 */
	public static boolean checkForFreeRunways() { //If a free runway is found, this method also books the runway by setting its status to "occupied"
		boolean toBeReturned = false;
		for (int i = 0; i < larnacaAirportNumberOfRunways; i++)
			if (Scenario.getRunwaysArray()[i].isRunwayOccupied() == false) {
				toBeReturned = true;
				Scenario.getRunwaysArray()[i].setRunwayOccupied(true); //As far as the air traffic control and this application are concerned, it is not required to record which plane occupies a runway. Once a runway is engaged by a plane it is occupied and once it lands the runway becomes free again.
				break; //Breaks the for loop to make sure no more than one runway is booked
			}
		return toBeReturned;
		}
	
	/**
	 * Free up runway
	 */
	public static void freeUpRunway() { //Runways are delegated and freed up on a sequential basis
		for (int i = 0; i < larnacaAirportNumberOfRunways; i++)
			if (Scenario.getRunwaysArray()[i].isRunwayOccupied()) {
				Scenario.getRunwaysArray()[i].setRunwayOccupied(false); 
				break;
			}
	}
	
	/**
	 * @param fileName the name of the file to save to
	 */
	public static void saveToFile(String fileName) { //Creates file if does not already exist, overwrites it if it exists
		try (
                PrintStream output = new PrintStream(new File(fileName));
            ){
			for (int i = 0; i < numberOfFlights; i++) {
				for (int j = 0; j < numberOfFlightAttributes; j++) {
					String toPrint = "";
					toPrint += getFlightData()[i][j];
					output.print(toPrint);
					output.print(" ");
				}	
				output.println();
			}	
			
            output.close();
            JOptionPane.showMessageDialog(null, "Flight data saved");
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
	}
	
	/**
	 * load file data from file
	 */
	public static void loadFromFile(String fileName) {
		Object[][] arr = new Object[numberOfFlights][numberOfFlightAttributes];

		try {
			 Scanner scn= new Scanner(new BufferedReader(new FileReader(fileName)));
			 String line = scn.nextLine(); 
			 String[] strings = line.split(" "); 

			 scn.close();
			 for(int i = 0; i < numberOfFlights; i++){
			     for(int j = 0; j < numberOfFlightAttributes; j++){
			         arr[i][j] = strings[j]; 
			     }
			 }
     		 ApplicationWindow.setAllFlightData(arr);
			 ApplicationWindow.refreshMainTable();
			 ApplicationWindow.refreshArrivalsTable();
		  	 ApplicationWindow.refreshDeparturesTable();
				
			 JOptionPane.showMessageDialog(null, "Flight data loaded from file.");
			
		} catch (FileNotFoundException e) {
			JOptionPane.showMessageDialog(null, "File not found", "Failure", JOptionPane.ERROR_MESSAGE);
		}
	}
}