#include "stdafx.h"
#include "CppUnitTest.h"
#include <string>
#include <vector>
#include <set>
#include "../ATMO/Mesure.h"
#include "../ATMO/Capteur.h"
#include "../ATMO/TypeMesure.h"
#include "../ATMO/TraitementDonnees.h"
#include "../ATMO/Zone.h"
#include "../ATMO/CoordonneesGPS.h"
#include "../ATMO/Analyse.h"
#include "../ATMO/Date.h"
#include "../ATMO/Analyse.h"
#include <algorithm>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(AnalyseTest)
	{
	public:
		TEST_METHOD(CaracteristiqueZoneTest1)
		{
			conteneurMoyMesures c=AnalyseInstance.caracteristiquesZone(18.902680, -60.469614,20,Date(2017,1,1,0,0,0),Date(2017,1,1,0,0,12));
			Assert::IsTrue(c.size() == 4);
			for (auto it = c.begin(); it != c.end(); ++it) {
				if (it->first == "O3") {
					Assert::IsTrue(it->second == double(8.3227398357248535));
				}
				else if (it->first == "NO2") {
					Assert::IsTrue(it->second == double(25.21910455671518));
				}
				else if (it->first == "SO2") {
					Assert::IsTrue(it->second == double(9.56403873576716));
				}
				else if (it->first == "PM10") {
					Assert::IsTrue(it->second == double(0.00888436901712503165));
				}
			}
		}
		TEST_METHOD(CaracteristiqueZoneTest2)
		{
			conteneurMoyMesures c = AnalyseInstance.caracteristiquesZone(18.902680, -60.469614, 20,  Date(2017, 1, 1, 0, 0, 12),Date(2017, 1, 1, 0, 0, 0));
			Assert::IsTrue(c.size() == 0);
		}
		TEST_METHOD(CaracteristiqueZoneTest3)
		{
			conteneurMoyMesures c = AnalyseInstance.caracteristiquesZone(18.902680, -60.469614, -20, Date(2017, 1, 1, 0, 0, 0), Date(2017, 1, 1, 0, 0, 12));
			Assert::IsTrue(c.size() == 0);
		}
		TEST_METHOD(CaracteristiqueZoneTest4)
		{
			conteneurMoyMesures c = AnalyseInstance.caracteristiquesZone(750, 500, 20, Date(2017, 1, 1, 0, 0, 0), Date(2017, 1, 1, 0, 0, 12));
			Assert::IsTrue(c.size() == 0);
		}
		TEST_METHOD(CaracteristiquePointTest1)
		{
			conteneurMoyMesures c = AnalyseInstance.caracteristiquesPoint(18.902680, -60.469614, Date(2017, 1, 1, 0, 0, 0), Date(2017, 1, 1, 0, 0, 12));
			//dans rayon 10 km il y a qu'un seul capteur, ?a doit ¨ºtre le m¨ºme que caracteristiqueZone
			Assert::IsTrue(c.size() == 4);
			for (auto it = c.begin(); it != c.end(); ++it) {
				if (it->first == "O3") {
					Assert::IsTrue(it->second == double(8.3227398357248535));
				}
				else if (it->first == "NO2") {
					Assert::IsTrue(it->second == double(25.21910455671518));
				}
				else if (it->first == "SO2") {
					Assert::IsTrue(it->second == double(9.56403873576716));
				}
				else if (it->first == "PM10") {
					Assert::IsTrue(it->second == double(0.00888436901712503165));
				}
			}
		}
		TEST_METHOD(CaracteristiquePointTest2)
		{
			conteneurMoyMesures c = AnalyseInstance.caracteristiquesPoint(18.902680, -60.469614, Date(2017, 1, 1, 0, 0, 12), Date(2017, 1, 1, 0, 0, 0));
			Assert::IsTrue(c.size() == 0);
		}
		TEST_METHOD(CaracteristiquePointTest3)
		{
			conteneurMoyMesures c = AnalyseInstance.caracteristiquesPoint(750, 500, Date(2017, 1, 1, 0, 0, 0), Date(2017, 1, 1, 0, 0, 12));
			Assert::IsTrue(c.size() == 0);
		}
		TEST_METHOD(QualiteAirTest1)
		{
			conteneurMoyMesures c = AnalyseInstance.caracteristiquesZone(18.902680, -60.469614, 20, Date(2017, 1, 1, 0, 0, 0), Date(2017, 1, 1, 0, 0, 12));
			int indice = AnalyseInstance.qualiteAir(c);
			Assert::IsTrue(indice == 1);
		}
		TEST_METHOD(QualiteAirTest2)
		{
			conteneurMoyMesures c ;
			c["O3"] = 5;
			c["SO2"] = -5;
			int indice = AnalyseInstance.qualiteAir(c);
			Assert::IsTrue(indice == -1);
		}
		TEST_METHOD(QualiteAirTest3)
		{
			conteneurMoyMesures c;
			c["O2"] = 5;
			int indice = AnalyseInstance.qualiteAir(c);
			Assert::IsTrue(indice == 0);
		}
		TEST_METHOD(QualiteAirTest4)
		{
			conteneurMoyMesures c;
			c["O3"] = 35;
			c["O3"] = 85;
			c["O3"] = 500;
			c["O3"] = 5;
			int indice = AnalyseInstance.qualiteAir(c);
			Assert::IsTrue(indice == 10);
		}
	};
}