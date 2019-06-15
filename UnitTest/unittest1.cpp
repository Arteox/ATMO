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
#include <algorithm>
#include <codecvt>
#include <io.h>
#include <fcntl.h>
#include <cstdlib>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	static void setFichierName() {
		/*
		TraitementD.setFichierTypesMesure("C:\\Users\\Louis Ung\\Documents\\Insa 3a\\Semestre 2\\Genie_logiciel\\TP\\ATMO\\ATMO\\DonneesCSV\\AttributeType.csv");
		TraitementD.setFichierMesures("C:\\Users\\Louis Ung\\Documents\\Insa 3a\\Semestre 2\\Genie_logiciel\\TP\\ATMO\\ATMO\\DonneesCSV\\Test.csv");
		TraitementD.setFichierCapteurs("C:\\Users\\Louis Ung\\Documents\\Insa 3a\\Semestre 2\\Genie_logiciel\\TP\\ATMO\\ATMO\\DonneesCSV\\Sensors.csv");
		*/
		
		TraitementD.setFichierMesures("..\\..\\ATMO\\DonneesCSV\\Test.csv");
		TraitementD.setFichierCapteurs("..\\..\\ATMO\\DonneesCSV\\Sensors.csv");
		TraitementD.setFichierTypesMesure("..\\..\\ATMO\\DonneesCSV\\AttributeType.csv");
		
	}

	TEST_CLASS(RecupereationDesDonnees)
	{
	public:
		static bool TypeMesureSort(TypeMesure& t1, TypeMesure& t2) {
			return t1.getAttributeId().compare(t2.getAttributeId());
		}
		static bool CapteurSort(Capteur& c1, Capteur& c2) {
			return c1.getId() > c2.getId();
		}
		TEST_METHOD(TypeCapteurTest)
		{
			setFichierName();
			std::string unite = "µg/m3";
			std::wstring wunite(unite.begin(), unite.end());
			TypeMesure t1("O3", wunite, "concentration d'ozone");
			TypeMesure t2("SO2", wunite, "concentration de dioxyde de soufre");
			TypeMesure t3("NO2", wunite, "concentration de dioxyde d'azote");
			TypeMesure t4("PM10", wunite, "concentration de particules fines");
			//resultat expecte:
			collectionTypesMesure v1{ t1,t2,t3,t4 };
			collectionTypesMesure v2 = TraitementD.ParcoursTypeMesure();
			Assert::IsTrue(v2.size() == v1.size());
			//std::sort(v1.begin(), v1.end(), TypeMesureSort);
			//std::sort(v2.begin(), v2.end(), TypeMesureSort);
			for (int i = 0; i < v2.size(); i++) {
				Assert::IsTrue(v1[i].getAttributeId() == v2[i].getAttributeId());
			}

		}
		TEST_METHOD(CapteurTest1)
			/*
			rayon 10km
			*/
		{
			setFichierName();
			//resultat expecte:
			Capteur c(3 , 18.9026808524051, -60.4696149986561,"");
			collectionCapteurs v = TraitementD.ParcoursCapteurs(18.902680, -60.469614);
			//il y a un seul capteur dans la collection reponse
			Assert::IsTrue(v.size() == 1);
			//et c'est bien le capteur c
			Assert::IsTrue(v[0].getId() == c.getId());

		}
		TEST_METHOD(CapteurTest2)
		{
			//TraitementDonnees t=TraitementDonnees::GetInstance();
			collectionCapteurs v = TraitementD.ParcoursCapteurs(-25.123456, 45.123456);
			Assert::IsTrue(v.size() == 0);
		}
		TEST_METHOD(CapteurTest3)
		{
			//TraitementDonnees t = TraitementDonnees::GetInstance();
			collectionCapteurs v = TraitementD.ParcoursCapteurs(-480, 560);
			Assert::IsTrue(v.size() == 0);
		}
		TEST_METHOD(CapteurRayonTest1)
		{
			setFichierName();
			Capteur c2(0, -19.4789835505555, -35.2425725968753, "");
			Capteur c3(1, -38.3884286616875, -24.9593580676985, "");
			Capteur c4(2, -44.5357010278551, -40.5272071485069, "");
			collectionCapteurs v1;
			v1.push_back(c2);
			v1.push_back(c3);
			v1.push_back(c4);
			Assert::IsTrue(TraitementD.ParcoursMesures().size()>0);
			collectionCapteurs v2 = TraitementD.ParcoursCapteurs(-38, -24, 2500);
			Assert::IsTrue(v1.size() == v2.size());
			std::sort(v1.begin(), v1.end(), CapteurSort);
			std::sort(v2.begin(), v2.end(), CapteurSort);
			int size = v1.size();
			Assert::IsTrue(v1.size() == v2.size());
			for (int i = 0; i < size; i++) {
				Assert::IsTrue(v1[i].getId() == v2[i].getId());
			}
			
		}
		TEST_METHOD(CapteurRayonTest2)
		{
			//TraitementDonnees t = TraitementDonnees::GetInstance();
			collectionCapteurs v = TraitementD.ParcoursCapteurs(-38, -24, 1);
			Assert::IsTrue(v.size() == 0);
		}
		TEST_METHOD(CapteurRayonTest3)
		{
			//TraitementDonnees t = TraitementDonnees::GetInstance();
			collectionCapteurs v = TraitementD.ParcoursCapteurs(-480, 560,1);
			Assert::IsTrue(v.size() == 0);
		}
		TEST_METHOD(CapteurRayonTest4)
		{
			//TraitementDonnees t = TraitementDonnees::GetInstance();
			collectionCapteurs v = TraitementD.ParcoursCapteurs(-25.123456, 45.123456, -1);
			Assert::IsTrue(v.size() == 0);
		}
		TEST_METHOD(MesureTest1)
		{
			//ensemble capteurs est vide
			collectionCapteurs capteurs;
			Date dateDebut(2017, 1, 1, 0, 0, 0);
			Date dateFin(2017, 12, 30, 23, 59, 59);
			collectionMesures v = TraitementD.ParcoursMesures(capteurs, dateDebut,dateFin);
			Assert::IsTrue(v.size() == 0);
		}

		TEST_METHOD(MesureTest2)
		{
			//date début > date fin
			collectionCapteurs capteurs;
			Capteur c1(0, -19.4789835505555, -35.2425725968753, "");
			Capteur c2(1, -38.3884286616875, -24.9593580676985, "");
			Capteur c3(2, -44.5357010278551, -40.5272071485069, "");
			Capteur c4(3, 18.9026808524051, -60.4696149986561, "");
			Capteur c5(4, 11.9072994016611, 18.2016632092193, "");
			capteurs.push_back(c1);
			capteurs.push_back(c2);
			capteurs.push_back(c3);
			capteurs.push_back(c4);
			capteurs.push_back(c5);
			Date dateFin(2017, 1, 1, 0, 0, 0);
			Date dateDebut(2017, 12, 30, 23, 59, 59);
			collectionMesures v = TraitementD.ParcoursMesures(capteurs, dateDebut, dateFin);
			Assert::IsTrue(v.size() == 0);
		}
		TEST_METHOD(MesureTest3)
		{
			//un capteur qui n'existe pas
			collectionCapteurs capteurs;
			Capteur c1(10, -19.4789835505555, -35.2425725968753, "");
			capteurs.push_back(c1);
			Date dateFin(2017, 1, 1, 0, 0, 0);
			Date dateDebut(2017, 12, 30, 23, 59, 59);
			collectionMesures v = TraitementD.ParcoursMesures(capteurs, dateDebut, dateFin);
			Assert::IsTrue(v.size() == 0);
		}
		TEST_METHOD(MesureTest4)
		{	
			std::wstring wunite(L"µg/m3");
			Date d(2017, 1, 1, 0, 30, 39);
			Mesure m1(d, 36.7797600526823, TypeMesure("O3", wunite, "concentration d'ozone"),0);
			Mesure m2(d, 80.2280346451481, TypeMesure("SO2", wunite, "concentration de dioxyde de soufre"), 0);
			Mesure m3(d, 38.151540049253, TypeMesure("NO2", wunite, "concentration de dioxyde d'azote"), 0);
			Mesure m4(d, 1.99603267330184, TypeMesure("PM10", wunite, "concentration de particules fines"), 0);
			collectionMesures v1 = { m1,m2,m3,m4 };
			
			collectionCapteurs capteurs;
			Capteur c1(0, -19.4789835505555, -35.2425725968753, "", v1);
			capteurs.push_back(c1);
			Date dateDebut(2017, 1, 1, 0, 0, 0);
			Date dateFin(2017, 1, 1, 0, 59, 00);
			collectionMesures v2 = TraitementD.ParcoursMesures(capteurs,  dateDebut, dateFin);
			Assert::IsTrue(v1.size() == v2.size());
			auto it1 = v1.begin();
			auto it2 = v2.begin();
			for (; it1 != v1.end() && it2!=v2.end();++it1,++it2) {
				Assert::IsTrue((*it1).getValeur() == (*it2).getValeur());
				Assert::IsTrue((*it1).getTypeMesure().getAttributeId()== (*it2).getTypeMesure().getAttributeId());
			}
		}
	};
}