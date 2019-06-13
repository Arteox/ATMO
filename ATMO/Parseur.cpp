#define _CRT_SECURE_NO_WARNINGS
/*************************************************************************
Parseur  -  description
-------------------
début                : ${date}
copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <Parseur> (fichier Parseur.h) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <list>
#include <sstream>
#include <regex>
#include <string.h>
#include <algorithm>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Parseur.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

vector<string> Parseur::ParserCommande(string & entree) // mettre ici le paramètre entrée
{
	//Initialisation des différentes variables utilisées.
	vector<string> commandeParsee;
	vector<string> commandeErreur({ "-1" });
	unsigned nbParametres(0);
	bool aDesOptions = false;
	char chaineEntree[100];

	strcpy(chaineEntree, entree.c_str());
	char * pointeurCourant = strtok(chaineEntree, " ");
	while (pointeurCourant) {
		commandeParsee.push_back(string(pointeurCourant));
		pointeurCourant = strtok(NULL, " ");
	}
	if (!AttributionCommande(commandeParsee[0])) {
		//faire l'affichage menu de l'erreur cerr
		cout << "Commande invalide" << endl;
		return commandeErreur;
	}
	else {
		nbParametres = NombreDeParametresCommande(commandeParsee[0]);
		aDesOptions = PossedeDesOptionsCommande(commandeParsee[0]);
		if (aDesOptions) nbParametres++;
		if (commandeParsee.size() >= nbParametres) { // les paramètres attendus + la commande elle même sont dans commandeParsee
			if (aDesOptions) { // on récupère la dite option
				if (!AttributionOption(commandeParsee[1])) {
					if (!verificationParametre(commandeParsee[1])) {
						cout << "Option invalide" << endl;
						return commandeErreur;
					}
				}
			}
			for (int i(1); i < commandeParsee.size(); i++) {
				if (!verificationParametre(commandeParsee[i])) {
					cout << "Paramètre invalide" << endl;
					return commandeErreur;
				}
			}
		}
		else {
				cout << "Pas assez de paramètres" << endl;
				return commandeErreur;
			}
		}

	return commandeParsee;
}


//-------------------------------------------- Constructeurs - destructeur

Parseur::Parseur(const Parseur & unParseur)
{
}

Parseur::Parseur()
{

}

Parseur::~Parseur()
{
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
bool Parseur::AttributionCommande(string & commande) {
	//Vous trouvez ci-dessous la liste des commandes gérées par le système. 
	list<string> commandes({ "qm", "sim", "dysfonc", "carac", "help", "quitter" });
	if (find(commandes.begin(), commandes.end(), commande) != commandes.end()) {
		return true;
	}
	return false;
}

bool Parseur::AttributionOption(string & option) {
	//Vous trouvez ci-dessous la liste des options gérées par le système. 
	list<string> options({ "-d" });
	if (find(options.begin(), options.end(), option) != options.end()) {
		return true;
	}
	regex const patternOption{ "-\." };
	if (regex_match(option, patternOption)) return false; // si l'option n'est pas gérée
	else return false;
}

unsigned Parseur::NombreDeParametresCommande(string commande) {
	unsigned nbParametres(0);
	if (commande == "qm") nbParametres = 4;
	if (commande == "sim") nbParametres = 2;
	if (commande == "dysfonc") nbParametres = 2;
	if (commande == "carac") nbParametres = 4;
	if (commande == "help") nbParametres = 0;
	return nbParametres;
}

bool Parseur::PossedeDesOptionsCommande(string & commande) {
	//Vous trouvez ci-dessous la liste des commandes AVEC OPTION gérées par le système. 
	list<string> commandesAvecOptions({ "qm" });
	if (find(commandesAvecOptions.begin(), commandesAvecOptions.end(), commande) != commandesAvecOptions.end()) {
		return true;
	}
	return false;
}


bool Parseur::verificationParametre(string & parametre) {
	regex const patternDouble{ "[0-9]+(\.[0-9]+)?" };
	if (regex_match(parametre, patternDouble)) return true;
	else if (parametre.size() >=2) return true;
	else return false;
}

