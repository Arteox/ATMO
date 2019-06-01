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
#include <string>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Parseur.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

list<string> Parseur::ParserCommande(string & entree) // mettre ici le paramètre entrée
{
    //Initialisation des différentes variables utilisées.
	list<string> commandeParsee;
    string parametreCourant;
    unsigned nbParametres (0);
    bool aDesOptions = false;
	string option = "-1";
    //L'utilisateur entre sa commande (à mettre dans le menu à terme)
    //string entree;
    //getline(cin,entree);
    //jusqu'ici
    istringstream fluxEntree (entree);
    getline(fluxEntree, parametreCourant,' ');
	
    if(AttributionCommande(parametreCourant) == commandeInvalide){
        //faire l'affichage menu de l'erreur cerr
		cout << "Commande invalide" << endl;
	} else {
		commandeParsee.push_back(to_string(AttributionCommande(parametreCourant)));
		nbParametres = NombreDeParametresCommande(parametreCourant);
		aDesOptions = PossedeDesOptionsCommande(parametreCourant);
		if(nbParametres > 1){
			if (aDesOptions) { // on récupère la dite option
                getline(fluxEntree, parametreCourant,' ');
				if(AttributionOption(parametreCourant) == optionInvalide) {
					cout << "Option invalide" << endl;
				}
				else if (AttributionOption(parametreCourant) == optionAbsente) {
					commandeParsee.push_back(to_string(optionAbsente)); // on envoie le fait qu'il n'y ait pas d'options
					option = parametreCourant; // l'option n'étant pas présente, on pousse le premier paramètre.
					nbParametres--; // et on retire donc un au nombre de tours nécessaires.
				}
				else {
					option = AttributionOption(parametreCourant);
				}
				commandeParsee.push_back(option);
			}
			for (unsigned i(0); i< nbParametres; i++) {
				getline(fluxEntree, parametreCourant, ' ');
				if (!verificationParametre(parametreCourant)) {
					//faire l'affichage menu de l'erreur cerr
					cout << "Paramètre vide" << endl;
				}
				else {
					commandeParsee.push_back(parametreCourant);
				}
            }      
        }
    }

	cout << "Resultat" << endl;
	for (auto v : commandeParsee) {
		cout << "Valeur : " << v << endl;
	}

    return commandeParsee;
}

//------------------------------------------------- Surcharge d'opérateurs
Parseur & Parseur::operator=(const Parseur & unParseur) {
	return *this;
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
int Parseur::AttributionCommande(string & commande) {
	int codeCommande (0);
	switch (trouverCommande(commande)) {
		case qm:
			codeCommande = 0;
			break;
		case sim:
			codeCommande = 1;
			break;
		case dysfonc:
			codeCommande = 2;
			break;
		case carac:
			codeCommande = 3;
			break;
		case help:
			codeCommande = 4;
			break;
		case commandeInvalide:
			codeCommande = -1;
			break;		
	}
	return codeCommande;
}

double Parseur::AttributionOption(string & option) {
	double codeOption(0);
	switch (trouverOption(option)) {
		case d:
			codeOption = 0;
			break;
		case optionAbsente:
			codeOption = -2;
			break;
		case optionInvalide:
			codeOption = -1;
			break;
	}
	return codeOption;
}

unsigned Parseur::NombreDeParametresCommande(string & commande) {
	unsigned nbParametres(0);
	switch (trouverCommande(commande)) {
		case qm:
			nbParametres = 5;
			break;
		case sim:
			nbParametres = 2;
			break;
		case dysfonc:
			nbParametres = 2;
			break;
		case carac:
			nbParametres = 4;
			break;
		case help:
			nbParametres = 0;
			break;
		case commandeInvalide:
			nbParametres = -1;
			break;
	}
	return nbParametres;
}

bool Parseur::PossedeDesOptionsCommande(string & commande) {
	bool possedeDesOptions = false;
	switch (trouverCommande(commande)) {
		case qm:
			possedeDesOptions = true;
			break;
		case sim:
			possedeDesOptions = false;
			break;
		case dysfonc:
			possedeDesOptions = false;
			break;
		case carac:
			possedeDesOptions = false;
			break;
		case help:
			possedeDesOptions = false;
			break;
		case commandeInvalide:
			possedeDesOptions = false;
			break;
		}
	return possedeDesOptions;
}

bool Parseur::verificationParametre(string & parametre) {
	bool parametreOk = false;
	if (parametre.empty()) parametreOk = false;
	if (!parametre.empty()) parametreOk = true;
	return parametreOk;
}


Commandes Parseur::trouverCommande(string & commande) {
	if (commande == "qm") return qm;
	if (commande == "sim") return sim;
	if (commande == "dysfonc") return dysfonc;
	if (commande == "carac") return carac;
	if (commande == "help") return help;
	return commandeInvalide;
}

Options Parseur::trouverOption(string & option) {
	if (option == "-d") return d;
	regex const patternOption{ "-\." };
	regex const patternDouble{ "[0-9]+(\.[0-9]+)?" };
	if (regex_match(option, patternOption)) return optionInvalide;
	if (regex_match(option, patternDouble)) return optionAbsente;
	return optionInvalide;
}
