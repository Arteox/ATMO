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
	TEST_CLASS(RecupereationDesDonnees)
	{
	public:
		static bool TypeMesureSort(TypeMesure& t1, TypeMesure& t2) {
			return t1.getAttributeId().compare(t2.getAttributeId());
		}
		static bool CapteurSort(Capteur& c1, Capteur& c2) {
			return c1.getId() > c2.getId();
		}
		TEST_METHOD(CapteurTest1)
			/*
			rayon 10km
			*/
		{
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
			//TraitementDonnees t = TraitementDonnees::GetInstance();
			//multiset <Mesure> m;
			Capteur c2(1, -38.3884286616875, -24.9593580676985, "");
			Capteur c3(2, -44.5357010278551, -40.5272071485069, "");
			Capteur c4(3, 18.9026808524051, -60.4696149986561, "");
			collectionCapteurs v1;
			v1.push_back(c2);
			v1.push_back(c3);
			v1.push_back(c4);
			collectionCapteurs v2 = TraitementD.ParcoursCapteurs(-38, -24, 2500);
			Assert::IsTrue(v1.size() == v2.size());
			std::sort(v1.begin(), v1.end(), CapteurSort);
			std::sort(v2.begin(), v2.end(), CapteurSort);
			int size = v1.size();
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
			//TraitementDonnees t = TraitementDonnees::GetInstance();
			collectionCapteurs capteurs;
			/*TypeMesure t1("O3", "µg/m3", "concentration d'ozone");
			TypeMesure t2("SO2", "µg/m3", "concentration de dioxyde de soufre");
			TypeMesure t3("NO2", "µg/m3", "concentration de dioxyde d'azote");
			TypeMesure t4("PM10", "µg/m3", "concentration de particules fines");
			collectionTypesMesure typeMesures;
			typeMesures.push_back(t1);
			typeMesures.push_back(t2);
			typeMesures.push_back(t3);
			typeMesures.push_back(t4);*/
			Date dateDebut(2017, 1, 1, 0, 0, 0);
			Date dateFin(2017, 12, 30, 23, 59, 59);
			collectionMesures v = TraitementD.ParcoursMesures(capteurs, dateDebut,dateFin);
			Assert::IsTrue(v.size() == 0);
		}
		TEST_METHOD(MesureTest2)
		{
			//TraitementDonnees t = TraitementDonnees::GetInstance();
			collectionCapteurs capteurs;
			//multiset <Mesure> m;
			Capteur c1(0, -19.4789835505555, -35.2425725968753,"");
			Capteur c2(1, -38.3884286616875, -24.9593580676985,"");
			Capteur c3(2, -44.5357010278551, -40.5272071485069,"");
			Capteur c4(3, 18.9026808524051, -60.4696149986561,"");
			Capteur c5(4, 11.9072994016611, 18.2016632092193,"");
			capteurs.push_back(c1);
			capteurs.push_back(c2);
			capteurs.push_back(c3);
			capteurs.push_back(c4);
			capteurs.push_back(c5);
			collectionTypesMesure typeMesures;
			Date dateDebut(2017, 1, 1, 0, 0, 0);
			Date dateFin(2017, 12, 30, 23, 59, 59);
			collectionMesures v = TraitementD.ParcoursMesures(capteurs, dateDebut, dateFin);
			Assert::IsTrue(v.size() == 0);
		}
		TEST_METHOD(MesureTest3)
		{
			collectionCapteurs capteurs;
			multiset <Mesure> m;
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
		/*TEST_METHOD(MesureTest3)
		{
			TraitementDonnees t = TraitementDonnees::GetInstance();
			collectionCapteurs capteurs;
			multiset <Mesure> m;
			Capteur c1(0, -19.4789835505555, -35.2425725968753, "", m);
			Capteur c2(1, -38.3884286616875, -24.9593580676985, "", m);
			Capteur c3(2, -44.5357010278551, -40.5272071485069, "", m);
			Capteur c4(3, 18.9026808524051, -60.4696149986561, "", m);
			Capteur c5(4, 11.9072994016611, 18.2016632092193, "", m);
			capteurs.push_back(c1);
			capteurs.push_back(c2);
			capteurs.push_back(c3);
			capteurs.push_back(c4);
			capteurs.push_back(c5);
			TypeMesure t1("O3", "µg/m3", "concentration d'ozone");
			TypeMesure t2("SO2", "µg/m3", "concentration de dioxyde de soufre");
			TypeMesure t3("NO2", "µg/m3", "concentration de dioxyde d'azote");
			TypeMesure t4("PM10", "µg/m3", "concentration de particules fines");
			collectionTypesMesure typeMesures;
			typeMesures.push_back(t1);
			typeMesures.push_back(t2);
			typeMesures.push_back(t3);
			typeMesures.push_back(t4);
			Date dateFin(2017, 1, 1, 0, 0, 0);
			Date dateDebut(2017, 12, 30, 23, 59, 59);
			collectionMesures v = t.ParcoursMesures(capteurs, typeMesures, dateDebut, dateFin);
			Assert::IsTrue(v.size() == 0);
		}*/
	};
}