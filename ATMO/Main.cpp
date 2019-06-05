/*************************************************************************
Main  -  description
-------------------
début                : ${date}
copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <Capteur> (fichier Capteur.h) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <string>
#include <iterator>
#include <io.h>
#include <fcntl.h>
#include <cstdlib>
#include <locale>
#include <codecvt>
#include <fstream>
#include <sstream>
#include <vector>

//------------------------------------------------------ Include personnel
#include "TraitementDonnees.h"
#include "Date.h"
#include "Capteur.h"
#include "Zone.h"
#include "CoordonneesGPS.h"
#include "Menu.h"
#include "Parseur.h"
#include "Analyse.h"


//------------------------------------------------------------- Constantes
//---------------------------------------------------- Variables de classe

void executerCommandes(vector<string> commandesAvecParams) {

	//on convertit la liste en vector pour faciliter les accès par index
	vector<string> commandesV{ make_move_iterator(begin(commandesAvecParams)),std::make_move_iterator(end(commandesAvecParams)) };

	if (commandesV[0] == "4") {
		MenuInstance.AfficherAide();
	}
	else if (commandesV[0] == "3") {
		cout << stod(commandesV[2]) << " " << stod(commandesV[1]) << " " << Date(commandesV[3]) << " " << Date(commandesV[4]) << endl;
		//AnalyseInstance.caracteristiquesPoint(stod(commandesV[2]), stod(commandesV[1]), Date(commandesV[3]), Date(commandesV[4]));
		//print les resultats
	}
	else if (commandesV[0] == "2") {
		cout << Date(commandesV[1]) << " " << Date(commandesV[2]) << endl;
		//AnalyseInstance.dysfonctionnement(Date(commandesV[1]), Date(commandesV[2]));
		//print les resultats
	}
	else if (commandesV[0] == "1") {
		cout << commandesV[1] << " " << commandesV[2] << endl;
		//AnalyseInstance.comportementSimilaire(Date(commandesV[1]), Date(commandesV[2]));
		//print les resultats
	}
	else if (commandesV[0] == "0") {
		cout << stod(commandesV[3]) << " " << stod(commandesV[2]) << " " << stod(commandesV[4]) << " " << Date(commandesV[5]) << " " << Date(commandesV[6]) << endl;
		cout << "option : " << commandesV[1] << endl;
		//AnalyseInstance.qualiteAir(stod(commandesV[3]), stod(commandesV[2]), stod(commandesV[4]), Date(commandesV[5]), Date(commandesV[6])));
		//print les resultats
	}
}

int main(int argc, char** argv) {


	MenuInstance.InitialiserMenu();

	while (true) {
		cout << endl << "Veuillez rentrer votre commande" << endl << endl;
		string entree = MenuInstance.RecupererEntreeUtilisateur();
		if (entree == "quitter") {
			cout << "A bientôt !" << endl;
			break;
		}
		vector<string> commandes = ParseurInstance.ParserCommande(entree);
		executerCommandes(commandes);
		
	}





	/*
	collectionCapteurs v = TraitementD.ParcoursCapteurs(18.902680, -60.469614);
	cout << "taille : " << v.size() << endl;
	cout << v[0].getId() << endl;*/
	
	/*collectionCapteurs v2 = TraitementD.ParcoursCapteurs(-38, -24, 2500);
	cout << "taille : " << v2.size() << endl;
	for (collectionCapteurs::iterator it = v2.begin(); it != v2.end(); ++it) {
		cout << it->getId() << " " << it->getLat() << " " << it->getLong() << endl;
	}*/

	//TEST parcoursCapteurs avec zone
	/*collectionCapteurs capteursPoint;
	capteursPoint = TraitementD.ParcoursCapteurs(-2.03317773855905, -70.6545565746047, 3000);
	cout << capteursPoint.size() << endl;
	for (collectionCapteurs::iterator it = capteursPoint.begin(); it != capteursPoint.end(); ++it) {
		cout << it->getLat() << " " << it->getLong() << endl;
	}*/

	//TEST parcoursCapteurs avec point
	/*collectionCapteurs capteursPoint;
	capteursPoint = TraitementD.ParcoursCapteurs(-2.03317773855905, -70.6545565746047);
	cout << capteursPoint.size() << endl;
	for (collectionCapteurs::iterator it = capteursPoint.begin(); it != capteursPoint.end(); ++it) {
		cout << it->getLat() << " " << it->getLong() << endl;
	}*/

	//TEST appartenance a une zone
	/*Zone z(45.746857, 4.827419, 10);
	cout << z.estDansZone(45.746857, 4.827419) << endl;*/

	//TEST calcul distance GPS
	/*CoordonneesGPS cGPS;
	cout << cGPS.distanceEnKmEntreDeuxPoints(-38, -24, 18.9026808524051, -60.4696149986561) << endl;*/

	//TEST ParcoursMesures avec parametres
	/*
	string deb = "2017-01-01T00:00:10.0000000;";
	string f = "2017-01-01T00:00:10.0800000;";
	Date debut(deb);
	Date fin(f);

	collectionCapteurs tousLesCapteurs = TraitementD.ParcoursCapteurs();
	collectionCapteurs capteurs;
	capteurs.push_back(tousLesCapteurs[1]);
	capteurs.push_back(tousLesCapteurs[2]);
	capteurs.push_back(tousLesCapteurs[3]);

	collectionMesures m = TraitementD.ParcoursMesures(capteurs, debut, fin);

	cout << "taille mesures filtrées : " << m.size() << endl;
	for (collectionMesures::iterator it = m.begin(); it != m.end(); ++it) {
		cout << *it << endl;
	}*/

	//TEST LECTURE TYPE MESURES
	/*TraitementD.lectureTypesMesure();
	for (collectionTypesMesure::iterator it = typeMesures.begin(); it != typeMesures.end(); ++it) {
		it->afficher();
	}*/



	//Test Analyse caracteristiquesZone
		/*
		//on vise sensor5 avec une mesure
		string deb = "2017-01-01T00:01:00.4550000";
		string f = "2017-01-01T00:01:30.4570000";
		Date debut(deb);
		Date fin(f);
		conteneurMoyMesures moy = AnalyseInstance.caracteristiquesZone(37.7525668836909, 68.271804628089, 1, debut, fin);

		for (conteneurMoyMesures::iterator it = moy.begin(); it != moy.end(); ++it) {
			cout << it->first << endl;
			cout << it->second << endl;
		}
		//test ok
		*/
		/*
		//on vise sensor5 avec 2 mesures
		string deb = "2017-01-01T00:01:00.4550000";
		string f = "2017-01-01T00:30:45.5270000";
		Date debut(deb);
		Date fin(f);
		conteneurMoyMesures moy = AnalyseInstance.caracteristiquesZone(37.7525668836909, 68.271804628089, 1, debut, fin);

		for (conteneurMoyMesures::iterator it = moy.begin(); it != moy.end(); ++it) {
			cout << it->first << endl;
			cout << it->second << endl;
		}
		//test ok
		*/
	
	//Test Analyse caracteristiquesPoint
		/*
		//on vise sensor5 avec une mesure
		string deb = "2017-01-01T00:01:00.4550000";
		string f = "2017-01-01T00:01:30.4570000";
		Date debut(deb);
		Date fin(f);
		conteneurMoyMesures moy = AnalyseInstance.caracteristiquesPoint(37.7525668836909, 68.271804628089, debut, fin);

		for (conteneurMoyMesures::iterator it = moy.begin(); it != moy.end(); ++it) {
			cout << it->first << endl;
			cout << it->second << endl;
		}
		// ok
		*/
	//Test Analyse ZoneTest1
/*
		conteneurMoyMesures c = AnalyseInstance.caracteristiquesZone(18.902680, -60.469614, 20, Date(2017, 1, 1, 0, 0, 0), Date(2017, 1, 1, 0, 1, 0));
		cout<<"start"<<c.size()<<4<<endl;

		for (conteneurMoyMesures::iterator it = c.begin(); it != c.end(); ++it) {
			cout << it->first << endl;
			cout << it->second << endl;
		}

		for (conteneurMoyMesures::iterator it = c.begin(); it != c.end(); ++it) {
			if (it->first == "O3") {
				cout<<it->second<< double(8.3227398357248535)<<endl;
			}
			else if (it->first == "NO2") {
				cout << it->second << double(25.21910455671518)<<endl;
			}
			else if (it->first == "SO2") {
				cout << it->second << double(9.56403873576716)<<endl;
			}
			else if (it->first == "PM10") {
				cout << it->second <<double(0.00888436901712503165)<<endl;
			}
		}
		
		*/
	return 0;
}


