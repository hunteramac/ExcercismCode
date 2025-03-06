#include "pch.h"

#include "../ExcercismCode/doctor_data.h"

namespace DoctorData
{
	TEST(dummy, dummy1) {
		EXPECT_TRUE(true);
	}

	TEST(CanCall, a1)
	{
		heaven::Vessel bob{ "Robert Johansson", 1 };
		heaven::Vessel will{ "Riker", 2,
		star_map::System::BetaHydri };
	}
}