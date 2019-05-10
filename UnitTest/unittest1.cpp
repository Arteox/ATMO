#include "stdafx.h"
#include "CppUnitTest.h"
#include "string"
#include "../ATMO/Capteur.h"
#in

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(RecupereationDesDonnees)
	{
	public:
		TEST_METHOD(RecupereationDesDonnees) 
		{
			TraitementDeDonnees
			Assert::AreEqual(toString, "Sensor1 Latitude:-8.15758888291083 Longitude:-34.7692487876719");
		}
		TEST_METHOD(ConstructeurParDefaut)
		{
			Capteur c;
			std::string toString = c.toString();
			Assert::AreEqual(toString, "Sensor1 Latitude:-8.15758888291083 Longitude:-34.7692487876719");
		}
		TEST8
	};
}