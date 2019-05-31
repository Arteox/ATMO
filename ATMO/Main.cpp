/*************************************************************************
Main  -  description
-------------------
d�but                : ${date}
copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <Capteur> (fichier Capteur.h) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TraitementDonnees.h"
#include "Date.h"
#include "Capteur.h"
#include "Zone.h"
#include "CoordonneesGPS.h"
#include <vector>
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques

int main() {
	cout << "hello" << endl;

	//TraitementD;
	Zone z(45.746857, 4.827419, 5);
	cout << z.estDansZone(45.769923, 4.880584) << endl;

	//TEST calcul distance GPS
	//CoordonneesGPS cGPS;
	//cout << cGPS.distanceEnKmEntreDeuxPoints(-19.4789835505555, -35.2425725968753, -38.3884286616875, -24.9593580676985) << endl;

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

	cout << "taille mesures filtr�es : " << m.size() << endl;
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

//------------------------------------------------- Surcharge d'op�rateurs

//-------------------------------------------- Constructeurs - destructeur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es


