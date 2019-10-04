import java.util.ArrayList;

/**  
 * <h1>The Dining Savages</h1>
 * 
 * <p>For the purposes of this simulation I will implement the dining savages scenario using monitors. I use 3 savages and a maximum
 * of 5 servings in the pot however both these constants (located at the beginning of main()) can be modified.</p>
 * 
 * @author hb20007
*/
public class Application {
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		final int SAVAGE_NO = 3, MAX_POT_SERVINGS = 5;
		
		// Creating pot, chef and savages
		Pot pot = new Pot(MAX_POT_SERVINGS);
		Chef chef = new Chef(pot);
		ArrayList<Savage> savages = new ArrayList<Savage>();
		for (int i = 0; i < SAVAGE_NO; i++) {
			savages.add(new Savage(String.format("Savage %d", i + 1), pot));
		}

		// Creating threads for savages
		ArrayList<Thread> savageThreads = new ArrayList<Thread>();
		for (Savage savage : savages) {
			savageThreads.add(new Thread(new Runnable() {
				@Override
				public void run() {
					try {
						savage.eat();
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
				}
			}));
		}
		
		// Creating thread for chef
		Thread chefThread = new Thread(new Runnable() {
			@Override
			public void run() {
				try {
					chef.fillPot();
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		});
		
		// Starting threads
		for (Thread thread : savageThreads)
			thread.start();
		chefThread.start();
		
		// When threads stop
		for (Thread thread : savageThreads)
			try {
				thread.join();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		try {
			chefThread.join();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		
	}
}
