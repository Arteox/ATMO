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

//------------------------------------------------------ Include personnel
#include "TraitementDonnees.h"
#include "Date.h"
#include "Capteur.h"
#include <vector>
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

int main() {
	cout << "hello" << endl;

	TraitementD;



	//TEST ParcoursMesures avec parametres
	/*
	string deb = "2017-01-01T00:00:10.0100000;";
	string f = "2017-01-01T00:00:25.5880000;";
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
	}*:

	//TEST LECTURE TYPE MESURES
	/*TraitementD.lectureTypesMesure();
	for (collectionTypesMesure::iterator it = typeMesures.begin(); it != typeMesures.end(); ++it) {
		it->afficher();
	}*/
	return 0;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées


