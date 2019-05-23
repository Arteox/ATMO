/*************************************************************************
TraitementDonnees  -  description
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
#include <fstream>
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe
const string TraitementDonnees::FichierCapteurs = "Sensors.csv";
const string TraitementDonnees::FichierTypesMesure = "AttributeType.csv";
const string TraitementDonnees::FichierMesures = "MesuresSample.csv";
//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques

collectionCapteurs TraitementDonnees::ParcoursCapteurs(double lat, double longi, double rayon)
{
	ifstream fic;
	string lectLigne;
	fic.open(FichierCapteurs);
	if (fic) {
		for (lectLigne; getline(fic, lectLigne); ) {
			cout << lectLigne << endl;
		}
	}
	fic.close();
	return collectionCapteurs();
}

collectionCapteurs TraitementDonnees::ParcoursCapteurs(double lat, double longi)
{
	return collectionCapteurs();
}

collectionMesures TraitementDonnees::ParcoursMesures(collectionCapteurs, Date horodateDeb, Date horodateFin)
{
	return multiset<Mesure>();
}

collectionTypesMesure TraitementDonnees::ParcoursTypesMesure()
{
	//a faire
	return vector<TypeMesure>();
}

//------------------------------------------------- Surcharge d'op�rateurs

//-------------------------------------------- Constructeurs - destructeur

TraitementDonnees::TraitementDonnees(const TraitementDonnees & unTraitementDonnees)
{

}

TraitementDonnees::~TraitementDonnees()
{
}

//------------------------------------------------------------------ PRIVE
TraitementDonnees::TraitementDonnees()
{
	
}

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es


