#include "stdafx.h"
#include "CppUnitTest.h"
#include <string>
#include <vector>
#include "../ATMO/Capteur.h"
#include "../ATMO/TypeMesure.h"
#include "../ATMO/TraitementDonnees.h"
#include <algorithm>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(RecupereationDesDonnees)
	{
	public:
		bool TypeMesureSort(TypeMesure& t1, TypeMesure& t2) {
			return t1.getId() > t2.getId();
		}
		TEST_METHOD(TypeMesureTest) 
		{
			TraitementDonnees t;
			TypeMesure t1 ("O3", "µg/m3", "concentration d'ozone");
			TypeMesure t2("SO2", "µg/m3" ,"concentration de dioxyde de soufre");
			TypeMesure t3("NO2", "µg/m3","concentration de dioxyde d'azote");
			TypeMesure t4("PM10", "µg/m3", "concentration de particules fines");
			std::vector<TypeMesure> v1;
			v1.push_back(t1);
			v1.push_back(t2);
			v1.push_back(t3);
			v1.push_back(t4);
			
			std::vector<TypeMesure> v2 = t.ParcoursTypesMesure();
			//std::set<TypeMesure> s2(v.begin(), v.end());
			std::sort(v1.begin(), v2.end(), TypeMesureSort);
			std::sort(v2.begin(), v2.end(), TypeMesureSort);
			Assert::IsTrue(v1.size()==v2.size());
			int size = v1.size();
			for (int i = 0; i < size; i++) {
				Assert::IsTrue(v1[i].getId() == v2[i].getId());
			}

		}
		TEST_METHOD(CapteurTest)
		{
			TraitementDonnees t;
			Capteur c1("Sensor0", -19.4789835505555, -35.2425725968753);
			Capteur c2("Sensor1",-38.3884286616875,-24.9593580676985);
			Capteur c3("Sensor2", -44.5357010278551, -40.5272071485069);
			Capteur c4("Sensor3", 18.9026808524051, -60.4696149986561);
			Capteur c5("Sensor4",11.9072994016611,18.2016632092193);
			Capteur c6("Sensor5",37.7525668836909, 68.271804628089);
			Capteur c7("Sensor6", 32.1496770005439, 11.685259370918);
			Capteur c8("Sensor7", -28.5704283665728, 24.1637584633025);
			Capteur c9("Sensor8",18.3597523781283, -58.1587766800815);
			Capteur c10("Sensor9", -2.03317773855905, -70.6545565746047);
			std::vector<Capteur> v1;
			v1.push_back(c1);
			v1.push_back(c2);
			v1.push_back(c3);
			v1.push_back(c4);
			v1.push_back(c5);
			v1.push_back(c6);
			v1.push_back(c7);
			v1.push_back(c8);
			v1.push_back(c9);
			v1.push_back(c10);
			std::vector<Capteur> v2 = t.ParcoursCapteurs();
			//std::set<TypeMesure> s2(v.begin(), v.end());
			std::sort(v1.begin(), v2.end(), TypeMesureSort);
			std::sort(v2.begin(), v2.end(), TypeMesureSort);
			Assert::IsTrue(v1.size() == v2.size());
			int size = v1.size();
			for (int i = 0; i < size; i++) {
				Assert::IsTrue(v1[i].getId() == v2[i].getId());
			}

		}
		
	};
}