
class Board {
	private char[][] grid = new char[][] {
			{'1', '2', '3'},
			{'4', '5', '6'},
			{'7', '8', '9'}
	};
	
	void showGrid() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j <3; j++) {
				System.out.print(grid[i][j] + " ");
			}
			System.out.println();
		}
	}
	
	void modifyGrid(int cell, char character) {
		switch(cell) {
			case 1: grid[0][0] = character; break;
			case 2:	grid[0][1] = character; break;
			case 3:	grid[0][2] = character; break;
			case 4: grid[1][0] = character; break;
			case 5: grid[1][1] = character; break;
			case 6: grid[1][2] = character; break;
			case 7: grid[2][0] = character; break;
			case 8: grid[2][1] = character; break;
			case 9: grid[2][2] = character; // Could implement a mechanism to see if the cell in the grid already has a character
		}
	}
	// Could implement function for computer to check who won
}
