namespace targets{
class Alien {
	private:
		int health;

	public:
		int x_coordinate;
		int y_coordinate;

		Alien(int x, int y);

		int get_health() { return health; }

		bool hit();

		bool is_alive() { return (health > 0); };

		bool teleport(int x, int y);

		bool collision_detection(Alien check);
};

Alien::Alien(int x, int y) {
	x_coordinate = x;
	y_coordinate = y;
	health = 3;
}

bool Alien::collision_detection(Alien check) {
	if (
		this->x_coordinate == check.x_coordinate &&
		this->y_coordinate == check.y_coordinate
		)
		return true;
	else
		return false;
}

bool Alien::hit() {
	if(health>0)
		--health;

	return true;
}

bool Alien::teleport(int x, int y) {
	x_coordinate = x;
	y_coordinate = y;
	return true;
}

} // namespace targets