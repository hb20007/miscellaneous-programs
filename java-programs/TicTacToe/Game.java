import java.io.IOException;
import java.util.Scanner;

class Game {
	static void menu() {
		int selection;
		Scanner in = new Scanner(System.in);
		System.out.println("TIC TAC TOE");
		System.out.println();
		System.out.println("1. Start game");
		System.out.print("2-99. Quit\n>");
		selection = in.nextInt(); // Could implement validation check by making 'selection' a string, using nextLine() and implementing an isInt() boolean function which checks what the user insert with the help of String.length() and String.charAt()
		if (selection != 1) System.exit(0);
		//Scanner 'in' not closed cuz caused error
	}	
	
//	static void clearScreen() throws IOException { 
//		final String OS = System.getProperty("os.name");
//		if (OS.contains("Windows")) 
//			Runtime.getRuntime().exec("cls");
//		Runtime.getRuntime().exec("clear");
//}
// DIDN'T WORK FOR SOME REASON, EXCEPTION WAS THROWN

//	static void clearScreen() {
//		for (int clear = 0; clear < 100; clear++) {
//			System.out.println("\b");
//		}
//	}
// Didn't work cuz of eclipse bug in handling backspace
	
	public static void main(String[] args) throws IOException {
		menu();
		Player p1 = new Player(), p2 = new Player();
		int p1Cell, p2Cell;
		Scanner input = new Scanner(System.in);
//		clearScreen();
		System.out.print("Welcome to Tic Tac Toe for 2 players. Player 1 please enter your name\n>");
		p1.setName(input.next());
		System.out.print("Player 2 please enter your name\n>");
		p2.setName(input.next());
		Board gameBoard = new Board();
		
		for (int turn = 0; turn < 5; turn++) {
//			clearScreen();
			gameBoard.showGrid();
			System.out.println(p1.getName() + " choose a cell\n>");
			p1Cell = input.nextInt();
			gameBoard.modifyGrid(p1Cell, 'X');
//			clearScreen();
			gameBoard.showGrid();
			if (turn != 4) {
				System.out.print(p2.getName() + " choose a cell\n>");
				p2Cell = input.nextInt();
				gameBoard.modifyGrid(p2Cell, 'O');				
			}
			else 
				System.out.println("Nice game!");
		}
		input.close();
	} 
}

//So this game sucks cuz it goes till the end but every move u should check if 3 in a row were made and stop the game if it happened. At every move u check horizontally, vertically and diagonally. 
