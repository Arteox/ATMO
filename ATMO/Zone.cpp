/*************************************************************************
Zone  -  description
-------------------
début                : ${date}
copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <Zone> (fichier Zone.h) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Zone.h"
#include "CoordonneesGPS.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

bool Zone::estDansZone(double lat, double longi)
{
	CoordonneesGPS cGPS;
	double distance = cGPS.distanceEnKmEntreDeuxPoints(this->latCentre, this->longCentre, lat, longi);
	//cout << "distance : " << distance << endl;
	return distance < rayon;
}

Zone::Zone(const Zone & unZone)
{
}

Zone::Zone(double lat, double longi, double rayon)
{
	this->latCentre = lat;
	this->longCentre = longi;
	this->rayon = rayon;
}


Zone::~Zone()
{
}


//------------------------------------------------- Surcharge d'opérateurs


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées


