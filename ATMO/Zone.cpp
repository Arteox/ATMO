/*************************************************************************
Zone  -  description
-------------------
d�but                : ${date}
copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <Zone> (fichier Zone.h) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Zone.h"
#include "CoordonneesGPS.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques


//------------------------------------------------- Surcharge d'op�rateurs


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


//------------------------------------------------- Surcharge d'op�rateurs


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es


