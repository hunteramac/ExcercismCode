bool can_eat_ghost(bool powerPelletActive, bool contactGhost) {
	return powerPelletActive && contactGhost;
}

bool scored(bool contactPowerPellet, bool contactDot) {
	return contactPowerPellet || contactDot;
}

bool lost(bool powerPelletActive, bool contactGhost) {
	return !powerPelletActive && contactGhost;
	//if (!powerPelletActive && contactGhost)
	//	return true;
	//else
	//	return false;
}

bool won(bool eatenAllDots, bool powerPelletActive, bool contactGhost) {
	if (eatenAllDots && (!contactGhost || (contactGhost && powerPelletActive)))
		return true;
	else
		return false;
}