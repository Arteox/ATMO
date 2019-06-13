#define _CRT_SECURE_NO_WARNINGS
/*************************************************************************
Parseur  -  description
-------------------
d�but                : ${date}
copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <Parseur> (fichier Parseur.h) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
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

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques

vector<string> Parseur::ParserCommande(string & entree) // mettre ici le param�tre entr�e
{
	//Initialisation des diff�rentes variables utilis�es.
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
		if (commandeParsee.size() >= nbParametres) { // les param�tres attendus + la commande elle m�me sont dans commandeParsee
			if (aDesOptions) { // on r�cup�re la dite option
				if (!AttributionOption(commandeParsee[1])) {
					if (!verificationParametre(commandeParsee[1])) {
						cout << "Option invalide" << endl;
						return commandeErreur;
					}
				}
			}
			for (int i(1); i < commandeParsee.size(); i++) {
				if (!verificationParametre(commandeParsee[i])) {
					cout << "Param�tre invalide" << endl;
					return commandeErreur;
				}
			}
		}
		else {
				cout << "Pas assez de param�tres" << endl;
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

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
bool Parseur::AttributionCommande(string & commande) {
	//Vous trouvez ci-dessous la liste des commandes g�r�es par le syst�me. 
	list<string> commandes({ "qm", "sim", "dysfonc", "carac", "help", "quitter" });
	if (find(commandes.begin(), commandes.end(), commande) != commandes.end()) {
		return true;
	}
	return false;
}

bool Parseur::AttributionOption(string & option) {
	//Vous trouvez ci-dessous la liste des options g�r�es par le syst�me. 
	list<string> options({ "-d" });
	if (find(options.begin(), options.end(), option) != options.end()) {
		return true;
	}
	regex const patternOption{ "-\." };
	if (regex_match(option, patternOption)) return false; // si l'option n'est pas g�r�e
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
	//Vous trouvez ci-dessous la liste des commandes AVEC OPTION g�r�es par le syst�me. 
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

