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
#include <windows.h>
#include <tchar.h>

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

	if (commandesAvecParams[0] == "help") {
		MenuInstance.AfficherAide();
	}

	else if (commandesAvecParams[0] == "carac") {
		Date debut(commandesAvecParams[3]);
		Date fin(commandesAvecParams[4]);
		conteneurMoyMesures moyMesures = AnalyseInstance.caracteristiquesPoint(stod(commandesAvecParams[1]), stod(commandesAvecParams[2]), debut, fin);
		int scoreAtmo = AnalyseInstance.qualiteAir(moyMesures);
		MenuInstance.FormaterAffichageCaracteristiques(scoreAtmo, moyMesures);
	}

	else if (commandesAvecParams[0] == "dysfonc") {
		Date debut(commandesAvecParams[1]);
		Date fin(commandesAvecParams[2]);
		collectionCapteurs capteursDysf = AnalyseInstance.dysfonctionnement(debut, fin); //marche pas
		MenuInstance.FormaterAffichageDysfonctionnement(capteursDysf); 
	}

	else if (commandesAvecParams[0] == "sim") {
		Date debut(commandesAvecParams[1]);
		Date fin(commandesAvecParams[2]);
		conteneurIndiceCapteurs capteursSim = AnalyseInstance.comportementSimilaire(debut, fin);
		MenuInstance.FormaterAffichageSimilaires(capteursSim);

	}
	else if (commandesAvecParams[0] == "qm") {
		bool option = false;
		if (commandesAvecParams[1].find("-") != string::npos) {
			option = true;
		}
		Date debut(commandesAvecParams[4 + option]);
		Date fin(commandesAvecParams[5 + option]);
		conteneurMoyMesures moyMesures = AnalyseInstance.caracteristiquesZone(stod(commandesAvecParams[1+option]), stod(commandesAvecParams[2+option]), stod(commandesAvecParams[3 + option]), debut, fin);
		int scoreAtmo = AnalyseInstance.qualiteAir(moyMesures);
		
		MenuInstance.FormaterAffichageQualite(scoreAtmo, moyMesures, option);
	}
}

int main(int argc, char** argv) {
	
	MenuInstance.InitialiserMenu();
	
	while (true) {
		MenuInstance.AffichageSortieStandard("\nVeuillez rentrer votre commande\n");
		string entree = MenuInstance.RecupererEntreeUtilisateur();
		if (entree == "quitter") {
			cout << "A bientôt !" << endl;
			break;
		}
		vector<string> commandes = ParseurInstance.ParserCommande(entree);
		executerCommandes(commandes);

	}
	return 0;
}


