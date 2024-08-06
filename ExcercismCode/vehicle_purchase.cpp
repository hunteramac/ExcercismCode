#include <string>

bool needs_license(std::string vehicle) {
	if (vehicle == "car" ||
		vehicle == "truck")
		return true;
	else
		return false;
}

std::string choose_vehicle(std::string VehicleOptionA, std::string VehicleOptionB) {
	std::string append = " is clearly the better choice.";

	//Which is first in lexigraphical order?

	//can we just compare? yes we can, operator must be overloaded
	if (VehicleOptionA <= VehicleOptionB)
		return VehicleOptionA + append;
	else
		return VehicleOptionB + append;
}

//Something buggy here
double calculate_resell_price(double originalVehiclePrice, int vehicleAge) {
	if (vehicleAge == 0)
		return originalVehiclePrice;
	else if (vehicleAge > 0 && vehicleAge < 3)
		return originalVehiclePrice * .8;
	else if (vehicleAge >= 3 && vehicleAge < 10)
		return originalVehiclePrice * .7;
	else if(vehicleAge>=10)
		return originalVehiclePrice*.5;

	return 0;
}