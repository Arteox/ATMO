#include "stdafx.h"
#include "CppUnitTest.h"
#include <string>
#include <vector>
#include <set>
#include "../ATMO/Mesure.h"
#include "../ATMO/Capteur.h"
#include "../ATMO/TypeMesure.h"
#include "../ATMO/TraitementDonnees.h"
#include "../ATMO/Date.h"
#include <algorithm>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	/*TEST_CLASS(ValeurCaracteristique)
	{
	public:
		TEST_METHOD(CaracteristiqueZone)
		{
			Capteur c("1", -8.15758888291083, -34.7692487876719, "");
			std::string toString = c.toString();
			Assert::AreEqual(toString, "Sensor1 Latitude:-8.15758888291083 Longitude:-34.7692487876719");
		}
		TEST_METHOD(ComportementSimilaire)
		{
			Capteur c;
			std::string toString = c.toString();
			Assert::AreEqual(toString, "Sensor1 Latitude:-8.15758888291083 Longitude:-34.7692487876719");
		}
		TEST_METHOD(CaracteristiquePoint)
		{
			Capteur c;
			std::string toString = c.toString();
			Assert::AreEqual(toString, "Sensor1 Latitude:-8.15758888291083 Longitude:-34.7692487876719");
		}
		TEST_METHOD(QualiteAir)
		{
			Capteur c;
			std::string toString = c.toString();
			Assert::AreEqual(toString, "Sensor1 Latitude:-8.15758888291083 Longitude:-34.7692487876719");
		}
	};*/
}