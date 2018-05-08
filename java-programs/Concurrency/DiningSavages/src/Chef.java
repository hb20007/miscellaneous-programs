/*
 * Class representing a chef in the scenario
 * @author hzsab
 */
public class Chef {
	/*
	 * The chef's pot
	 */
	private Pot chefPot;
	
	/*
	 * A pot is assigned to the chef in the contructor
	 * @param pot The pot
	 */
	public Chef(Pot pot) {
		chefPot = pot;
	}
	
	/*
	 * Chef fills their pot with servings
	 * @exception InterruptedException Because it calls a synchronized method
	 * @see InterruptedException
	 */
	public void fillPot() throws InterruptedException {
		chefPot.fill();
	}
}
