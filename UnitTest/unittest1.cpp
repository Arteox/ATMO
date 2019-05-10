#include "stdafx.h"
#include "CppUnitTest.h"
#include "string"
#include "../ATMO/Capteur.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		Capteur c("1", -8.15758888291083, -34.7692487876719, "");
		std::string toString = c.toString();
		Assert::AreEqual(toString, "Sensor1 Latitude:-8.15758888291083 Longitude:-34.7692487876719");

	};
}