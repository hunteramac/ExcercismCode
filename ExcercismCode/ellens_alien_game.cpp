namespace targets{
class Alien {
private:
	int health;

public:
	int x_coordinate;
	int y_coordinate;

	Alien(int x, int y);

	int get_health() { return health; }

	void hit();

	bool is_alive() { return (health > 0); };
};

Alien::Alien(int x, int y) {
	x_coordinate = x;
	y_coordinate = y;
	health = 3;
}

void Alien::hit() {
	--health;
}

} // namespace targets