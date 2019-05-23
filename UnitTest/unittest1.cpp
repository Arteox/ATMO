#include "stdafx.h"
#include "CppUnitTest.h"
#include "string"
#include "vector"
#include "set"
#include "../ATMO/Capteur.h"
#include "../ATMO/TypeMesure.h"
#include "../ATMO/TraitementDonnees.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(RecupereationDesDonnees)
	{
	public:
		TEST_METHOD(TypeMesure) 
		{
			TraitementDonnees t;
			TypeMesure t1 ("O3", "µg/m3", "concentration d'ozone");
			TypeMesure t2("SO2", "µg/m3" ,"concentration de dioxyde de soufre");
			TypeMesure t3("NO2", "µg/m3","concentration de dioxyde d'azote");
			TypeMesure t4("PM10", "µg/m3", "concentration de particules fines");
			std::set<TypeMesure> s1{ t1,t2,t3,t4 };
			std::vector<TypeMesure> v = t.ParcoursTypesMesure();
			std::set<TypeMesure> s2(v.begin(), v.end());
			Assert::IsTrue(s1==s2);
		}
		TEST_METHOD(Capteur)
		{
			TraitementDonnees t;
			Capteur c1("O3", "µg/m3", "concentration d'ozone");
			Capteur c2("SO2", "µg/m3", "concentration de dioxyde de soufre");
			Capteur c3("NO2", "µg/m3", "concentration de dioxyde d'azote");
			Capteur c4("PM10", "µg/m3", "concentration de particules fines");
			C
			std::set<TypeMesure> s1{ t1,t2,t3,t4 };
			std::vector<TypeMesure> v = t.ParcoursTypesMesure();
			std::set<TypeMesure> s2(v.begin(), v.end());
			Assert::IsTrue(s1 == s2);
		}
		
	};
}