/*
 * Class representing a savage in the scenario.
 * @author hzsab
 */
public class Savage {
	/*
	 * Identifier for Savage instance
	 */
	private String name;
	/*
	 * Pot which the savage eats from
	 */
	private Pot foodSource;
	
	/*
	 * The savage is initialized with a name and a food source
	 * @param savageName The name
	 * @param savagePot The food source
	 */
	public Savage(String savageName, Pot savagePot) {
		name = savageName;
		foodSource = savagePot;
	}
	
	/*
	 * The savage eats a serving from their food source
	 * @exception InterruptedException Because it calls a synchronized method
	 * @see InterruptedException
	 */
	public void eat() throws InterruptedException {
		foodSource.useServing(name);
	}
}
