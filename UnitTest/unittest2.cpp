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
		/*
					TraitementD.setFichierMesures("C:\\Users\\untra\\OneDrive\\ÎÄµµ\\insa\\18-19 2\\GL UML\\ATMO\\ATMO\\DonneesCSV\\Test.csv");
			TraitementD.setFichierCapteurs("C:\\Users\\untra\\OneDrive\\ÎÄµµ\\insa\\18-19 2\\GL UML\\ATMO\\ATMO\\DonneesCSV\\Sensors.csv");
		
		*/
		static void setFichierName() {
		/*
			TraitementD.setFichierTypesMesure("C:\\Users\\Louis Ung\\Documents\\Insa 3a\\Semestre 2\\Genie_logiciel\\TP\\ATMO\\ATMO\\DonneesCSV\\AttributeType.csv");
			TraitementD.setFichierMesures("C:\\Users\\Louis Ung\\Documents\\Insa 3a\\Semestre 2\\Genie_logiciel\\TP\\ATMO\\ATMO\\DonneesCSV\\Test.csv");
			TraitementD.setFichierCapteurs("C:\\Users\\Louis Ung\\Documents\\Insa 3a\\Semestre 2\\Genie_logiciel\\TP\\ATMO\\ATMO\\DonneesCSV\\Sensors.csv");
			*/
			TraitementD.setFichierCapteurs("..\\..\\ATMO\\DonneesCSV\\Sensors.csv");
			TraitementD.setFichierTypesMesure("..\\..\\ATMO\\DonneesCSV\\AttributeType.csv");
			TraitementD.setFichierMesures("..\\..\\ATMO\\DonneesCSV\\Test.csv");


			
		}
		TEST_METHOD(CaracteristiqueZoneTest1)
		{	
			setFichierName();
			conteneurMoyMesures c= AnalyseInstance.caracteristiquesZone(-38.3884286616875, -24.9593580676985,20,Date(2017,1,1,0,0,0.00),Date(2017,1,1,0,0,12));
			Assert::IsTrue(c.size() == 4);
			for (auto it = c.begin(); it != c.end(); ++it) {
				if (it->first == "O3") {
					Assert::IsTrue(it->second == 20);
				}
				else if (it->first == "NO2") {
					Assert::IsTrue(it->second == 28);
				}
				else if (it->first == "SO2") {
					Assert::IsTrue(it->second == 35);
				}
				else if (it->first == "PM10") {
					Assert::IsTrue(it->second == 4);
				}
			}
		}
		TEST_METHOD(CaracteristiqueZoneTest2)
		{
			setFichierName();
			conteneurMoyMesures c = AnalyseInstance.caracteristiquesZone(-38.3884286616875, -24.9593580676985, 20,  Date(2017, 1, 1, 0, 0, 12),Date(2017, 1, 1, 0, 0, 0));
			Assert::IsTrue(c.size() == 0);
		}
		TEST_METHOD(CaracteristiqueZoneTest3)
		{
			setFichierName();
			conteneurMoyMesures c = AnalyseInstance.caracteristiquesZone(18.902680, -60.469614, -20, Date(2017, 1, 1, 0, 0, 0), Date(2017, 1, 1, 0, 0, 12));
			Assert::IsTrue(c.size() == 0);
		}
		TEST_METHOD(CaracteristiqueZoneTest4)
		{
			setFichierName();
			conteneurMoyMesures c = AnalyseInstance.caracteristiquesZone(750, 500, 20, Date(2017, 1, 1, 0, 0, 0), Date(2017, 1, 1, 0, 0, 12));
			Assert::IsTrue(c.size() == 0);
		}
		TEST_METHOD(CaracteristiquePointTest1)
		{
			setFichierName();
			conteneurMoyMesures c = AnalyseInstance.caracteristiquesPoint(-38.3884286616875, -24.9593580676985, Date(2017, 1, 1, 0, 0, 0), Date(2017, 1, 1, 0, 0, 12));
			//dans rayon 10 km il y a qu'un seul capteur, ?a doit ¨ºtre le m¨ºme que caracteristiqueZone
			Assert::IsTrue(c.size() == 4);
			for (auto it = c.begin(); it != c.end(); ++it) {
				if (it->first == "O3") {
					Assert::IsTrue(it->second == 20);
				}
				else if (it->first == "NO2") {
					Assert::IsTrue(it->second == 28);
				}
				else if (it->first == "SO2") {
					Assert::IsTrue(it->second == 35);
				}
				else if (it->first == "PM10") {
					Assert::IsTrue(it->second == 4);
				}
			}
		}
		TEST_METHOD(CaracteristiquePointTest2)
		{
			setFichierName();
			conteneurMoyMesures c = AnalyseInstance.caracteristiquesPoint(18.902680, -60.469614, Date(2017, 1, 1, 0, 0, 12), Date(2017, 1, 1, 0, 0, 0));
			Assert::IsTrue(c.size() == 0);
		}
		TEST_METHOD(CaracteristiquePointTest3)
		{
			setFichierName();
			conteneurMoyMesures c = AnalyseInstance.caracteristiquesPoint(750, 500, Date(2017, 1, 1, 0, 0, 0), Date(2017, 1, 1, 0, 0, 12));
			Assert::IsTrue(c.size() == 0);
		}
		TEST_METHOD(QualiteAirTest1)
		{
			setFichierName();
			conteneurMoyMesures c = AnalyseInstance.caracteristiquesZone(-38.3884286616875, -24.9593580676985, 20, Date(2017, 1, 1, 0, 0, 0), Date(2017, 1, 1, 0, 0, 12));
			int indice = AnalyseInstance.qualiteAir(c);
			Assert::IsTrue(indice == 1);
		}
		TEST_METHOD(QualiteAirTest2)
		{
			setFichierName();
			//renvoi -1 si une valeur negative
			conteneurMoyMesures c ;
			c["O3"] = 5;
			c["SO2"] = -5;
			int indice = AnalyseInstance.qualiteAir(c);
			Assert::IsTrue(indice == -1);
		}
		TEST_METHOD(QualiteAirTest3)
		{
			setFichierName();
			//valeurs recu non contenue dans l'ensemble prevues
			conteneurMoyMesures c;
			c["O2"] = 5;
			int indice = AnalyseInstance.qualiteAir(c);
			Assert::IsTrue(indice == -1);
		}
		TEST_METHOD(QualiteAirTest4)
		{
			setFichierName();
			//verifier si cette methode prend bien le plus haut
			conteneurMoyMesures c;
			c["O3"] = 35;
			c["SO2"] = 85;
			c["NO2"] = 500;
			c["PM10"] = 5;
			int indice = AnalyseInstance.qualiteAir(c);
			Assert::IsTrue(indice == 10);
		}
		TEST_METHOD(DysfonctionnementTest1)
		{
			// detection si plus d'1h d'intervalle
			setFichierName();
			collectionCapteurs capteursDysf;

			capteursDysf=AnalyseInstance.dysfonctionnement(Date(2018, 1, 1, 0, 0, 0), Date(2018, 1, 2, 0, 0, 0));

			collectionCapteurs::iterator it = capteursDysf.begin();
			Assert::IsTrue(it->getId()==0);
		}
		TEST_METHOD(DysfonctionnementTest2)
		{
			// detection si valeur negative
			setFichierName();
			collectionCapteurs capteursDysf;

			capteursDysf = AnalyseInstance.dysfonctionnement(Date(2018, 2, 1, 0, 0, 0), Date(2018, 2, 2, 0, 0, 0));

			collectionCapteurs::iterator it = capteursDysf.begin();
			Assert::IsTrue(it->getId() == 1);
		}
		TEST_METHOD(DysfonctionnementTest3)
		{
			// detection si valeur grande
			setFichierName();
			collectionCapteurs capteursDysf;

			capteursDysf = AnalyseInstance.dysfonctionnement(Date(2018, 3, 1, 0, 0, 0), Date(2018, 3, 2, 0, 0, 0));

			collectionCapteurs::iterator it = capteursDysf.begin();
			Assert::IsTrue(it->getId() == 2);
		}
		TEST_METHOD(SimilaireTest3)
		{
			// detection si valeur grande
			setFichierName();
			conteneurIndiceCapteurs capteurs;

			capteurs = AnalyseInstance.comportementSimilaire(Date(2017, 2, 1, 0, 0, 0), Date(2017, 2, 2, 0, 0, 0));

			conteneurIndiceCapteurs::iterator it = capteurs.begin();
			Assert::IsTrue(it->first == 1);
			Assert::IsTrue(it->second[0].getId() == 1);
			Assert::IsTrue(it->second[1].getId() == 2);
		}
	};
}