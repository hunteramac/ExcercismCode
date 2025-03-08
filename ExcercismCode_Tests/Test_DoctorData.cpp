#include "pch.h"

#include "../ExcercismCode/doctor_data.h"

namespace DoctorData
{
	TEST(dummy, dummy1) {
		EXPECT_TRUE(true);
	}

	TEST(CanCall, t1)
	{
		heaven::Vessel bob{ "Robert Johansson", 1 };
		heaven::Vessel will{ "Riker", 2,
		star_map::System::BetaHydri };
	}

	TEST(CanCall, t2)
	{
		heaven::Vessel bob{ "Robert Johansson", 1 };
		
		ASSERT_TRUE(bob.current_system == star_map::System::Sol);
		ASSERT_TRUE(bob.generation == 1);
		heaven::Vessel bob5 = bob.replicate("Mario");
		ASSERT_TRUE(bob5.current_system == star_map::System::Sol);
		ASSERT_TRUE(bob5.generation == 2);
	}

	TEST(CanCall, t3)
	{
		heaven::Vessel bob6{ "Homer", 3, star_map::System::EpsilonEridani };
		ASSERT_TRUE(bob6.busters == 0);
		bob6.make_buster();
		ASSERT_TRUE(bob6.busters == 1);
		bool success = bob6.shoot_buster();
		ASSERT_TRUE(success);
		ASSERT_TRUE(bob6.busters == 0);
		success = bob6.shoot_buster();
		ASSERT_FALSE(success);
	}

	TEST(CanCall, t4)
	{
		heaven::Vessel bob1{ "Bob", 1, star_map::System::AlphaCentauri };
		heaven::Vessel marv{ "Marvin", 2, star_map::System::DeltaEridani };
		heaven::Vessel milo{ "Milo", 3, star_map::System::DeltaEridani };
		heaven::Vessel howie{ "Howard", 4, star_map::System::Omicron2Eridani };

		ASSERT_TRUE("Bob" == heaven::get_older_bob(bob1, marv));
		ASSERT_TRUE(heaven::in_the_same_system(marv, milo));
	}
}