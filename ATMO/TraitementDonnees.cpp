/*************************************************************************
TraitementDonnees  -  description
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

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

vector<Capteur> TraitementDonnees::ParcoursCapteurs(double lat, double longi, double rayon)
{
	return vector<Capteur>();
}

vector<Capteur> TraitementDonnees::ParcoursCapteurs(double lat, double longi)
{
	return vector<Capteur>();
}

multiset<Mesure> TraitementDonnees::ParcoursMesures(vector<Capteur>, vector<TypeMesure>, Date horodateDeb, Date horodateFin)
{
	return multiset<Mesure>();
}

vector<TypeMesure> TraitementDonnees::ParcoursTypesMesure()
{
	//a faire
	return vector<TypeMesure>();
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

TraitementDonnees::TraitementDonnees(const TraitementDonnees & unTraitementDonnees)
{

}

TraitementDonnees::TraitementDonnees()
{

}

TraitementDonnees::~TraitementDonnees()
{
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées


