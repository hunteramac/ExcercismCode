#include "vehicle_purchase.h"

using namespace vehicle_purchase;

bool vehicle_purchase::needs_license(std::string kind) {
	if (kind == "car" ||
		kind == "truck")
		return true;
	else
		return false;
}

std::string vehicle_purchase::choose_vehicle(std::string option1, std::string option2) {
	std::string append = " is clearly the better choice.";

	if (option1 <= option2)
		return option1 + append;
	else
		return option2 + append;
}

double vehicle_purchase::calculate_resell_price(double original_price, double age) {
	if (age == 0)
		return original_price;
	else if (age > 0 && age < 3)
		return original_price * .8;
	else if (age >= 3 && age < 10)
		return original_price * .7;
	else if(age>=10)
		return original_price*.5;

	return original_price;
}