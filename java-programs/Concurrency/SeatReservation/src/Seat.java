import java.util.concurrent.Semaphore;

/**
 * Class representing the seat entity in this simulation.
 * @author hb20007
 */
public class Seat {
	private int number;
	private SeatStatus seatStatus;
	private Semaphore seatLock;
	private String ownerName;
	
	public Seat(int num) {
		number = num;
		seatStatus = SeatStatus.FREE;
		seatLock = new Semaphore(1);
		ownerName = "";
	}
	
	/*
	 * Getter method for <code>number</code>
	 */
	public int readSeatNumber() {
		return number;
	}
	
	/*
	 * Getter method for <code>seatStatus</code>
	 */
	public SeatStatus readSeatStatus() {
		return seatStatus;
	}
	
	/*
	 * Getter method for <code>ownerName</code>
	 */
	public String readOwnerName() {
		return ownerName;
	}
	
	/*
	 * Reserves seat. The semaphore ensures that the instructions in the critical section are not composed in parallel by more than one thread.
	 * @param newOwner The agent booking the seat
	 * @exception InterruptedException if the thread is waiting or executing and is interrupted
	 * @see InterruptedException
	 */
	public void reserveSeat(String newOwner) throws InterruptedException {				// The exception must be thrown for the case the thread acquires the lock but doesn't return it.
		assert seatStatus == SeatStatus.FREE;		// There is no way to reserve a seat if it's not free.
		// Write
		seatLock.acquire(1);
		try { 										// The critical section
			seatStatus = SeatStatus.RESERVED;
			ownerName = newOwner;
		}
		finally {
			seatLock.release(1);
		}
	}
	
	/*
	 * Called when an observer of the seat deselects it. Resets the seat status to be <code>FREE</code> and the owner to <code>null</code>.
	 */
	public void seatAbandoned() {
		seatStatus = SeatStatus.FREE;
		ownerName = "";
	}
}
