#include "pch.h"
#include "../ExcercismCode/vehicle_purchase.cpp"

namespace VehiclePurchase {
	TEST(VehiclePurchase, NeedsLicense) {
		EXPECT_EQ(needs_license("car"), true);
		EXPECT_EQ(needs_license("truck"), true);
		EXPECT_EQ(needs_license("bike"), false);
	}

	TEST(VehiclePurchase, ChooseVehicle) {
		EXPECT_EQ(
			choose_vehicle("alpha vehicle", "beta vehicle"),
			"alpha vehicle is clearly the better choice."
		);

		EXPECT_EQ(
			choose_vehicle("beta vehicle", "kappa vehicle"),
			"beta vehicle is clearly the better choice."
		);

		EXPECT_EQ(
			choose_vehicle("kappa vehicle", "beta vehicle"),
			"beta vehicle is clearly the better choice."
		);

		EXPECT_EQ(
			choose_vehicle("Wuling Hongguang", "Toyota Corolla"),
			"Toyota Corolla is clearly the better choice."
		);

		EXPECT_EQ(
			choose_vehicle("Volkswagen Beetle", "Volkswagen Golf"),
			"Volkswagen Beetle is clearly the better choice."
		);

		EXPECT_EQ(
			choose_vehicle("aaaaab", "aaaaaz"),
			"aaaaab is clearly the better choice."
		);
	}

	TEST(VehiclePurchase, CalculateResellPrice) {
		//simple case
		EXPECT_EQ(calculate_resell_price(1, 0), 1);

		//A 'brand new car' is 0 yrs old
		EXPECT_EQ(calculate_resell_price(100, 0), 100);

		EXPECT_EQ(calculate_resell_price(100, 1), 80);

		//Boundary
		EXPECT_EQ(calculate_resell_price(100, 4), 70);

		//Boundary in case
		EXPECT_EQ(calculate_resell_price(100, 3), 70);

		EXPECT_EQ(calculate_resell_price(100, 2), 80);

		// 10 yrs age boundary
		EXPECT_EQ(calculate_resell_price(100, 9), 70);
		EXPECT_EQ(calculate_resell_price(100, 10), 50);
		EXPECT_EQ(calculate_resell_price(100, 11), 50);
	}

	TEST(VehiclePurchase, CalculateResellPriceEdgeCases) {
		//Negative should just be 0 yrs
		EXPECT_EQ(calculate_resell_price(100, -1), 100);

		//Odd prices
		//Zero,
		EXPECT_EQ(calculate_resell_price(0, -1), 0);
	}
}
