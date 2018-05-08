

class Player {
	private String name;
	
	Player() {
		setName("Anonymous");
	}
	
	Player(String name_) {
		setName(name_);
	}
	
	void setName(String playerName) {
		name = playerName;
	}
	
	String getName() {
		return name;
	}
	
}