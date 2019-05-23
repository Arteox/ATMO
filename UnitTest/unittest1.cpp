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
			TypeMesure t1("O3", "µg/m3", "concentration d'ozone");
			TypeMesure t2("SO2", "µg/m3", "concentration de dioxyde de soufre");
			TypeMesure t3("NO2", "µg/m3", "concentration de dioxyde d'azote");
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
			Assert::IsTrue(v1.size() == v2.size());
			int size = v1.size();
			for (int i = 0; i < size; i++) {
				Assert::IsTrue(v1[i].getId() == v2[i].getId());
			}

		}
		
	};
}