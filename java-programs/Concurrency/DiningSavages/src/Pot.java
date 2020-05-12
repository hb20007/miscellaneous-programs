import java.util.Random;

/*
 * Class representing a pot in the scenario.
 * @author hb20007
 */
final public class Pot {
	/*
	 * Number of servings in the pot
	 */
	private int servings;
	
	/*
	 * Maximum number of servings in pot
	 */
	private final int MAX_SERVINGS;
	
	/*
	 * Sets class variable <code>MAX_SERVINGS to the amount specified in the contructor and initializes the number of servings to that amount
	 * @param MAX_SERVINGS constant representing the max number of servings of the particular pot
	 */
	public Pot(final int MAX_SERVINGS) {
		this.MAX_SERVINGS = MAX_SERVINGS;
		servings = this.MAX_SERVINGS;
		System.out.println("Pot created and filled to the maximum number of servings (" + this.MAX_SERVINGS + ")");
	}
	
	/*
	 * Fills the pot
	 * @exception InterruptedException Because contains synchronized code
	 * @see InterruptedException
	 */
	synchronized public void fill() throws InterruptedException {
		while(true) {
			while (servings != 0)
				wait();
			servings = MAX_SERVINGS;
			notify();
			System.out.println("Chef fills the pot. Servings: " + servings);
		}
	}
	
	/*
	 * Decrements servings
	 * @param eater Name of the savage who called the method.
	 * @exception InterruptedException Because contains synchronized code
	 * @see InterruptedException
	 */
	public void useServing(String eater) throws InterruptedException {
		while (true) {
			Random random = new Random();
			synchronized (this) {
				while (servings == 0)
					wait();
				servings--;
				System.out.println(eater + " grabs a serving from the pot. Servings left: " + servings);
				notifyAll(); // Must be in the synchronized block
			}
			Thread.sleep(random.nextInt(10000));	// Thread sleeps average of 5 secs until the next time the particular savage wants to eat.
		}
	}
}
