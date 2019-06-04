/*************************************************************************
Capteur  -  description
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
#include "Capteur.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
int Capteur::getId() const
{
	return ID;
}

double Capteur::getLat() const
{
	return lat;
}

double Capteur::getLong() const
{
	return longi;
}

string Capteur::getDescription() const
{
	return description;
}

collectionMesures Capteur::getMesures() const
{
	return mesures;
}

void Capteur::setMesures(collectionMesures mesures)
{
	this->mesures = mesures;
}

//------------------------------------------------- Surcharge d'op�rateurs
Capteur & Capteur::operator=(const Capteur & unCapteur)
{
	this->ID = unCapteur.ID;
	this->lat = unCapteur.lat;
	this->longi = unCapteur.longi;
	this->description = unCapteur.description;
	this->mesures = unCapteur.mesures;
	return *this;
}

ostream & operator<<(ostream & out, const Capteur & capteur)
{
	out << capteur.ID << " " << capteur.lat << " " << capteur.longi<< endl;
	collectionMesures m = capteur.mesures;

	for (collectionMesures::iterator itM = m.begin(); itM != m.end(); ++itM) {
		out << *itM << " ";
	}
	out << endl;

	return out;
}

//-------------------------------------------- Constructeurs - destructeur

Capteur::Capteur(const Capteur & unCapteur)
{
	this->ID = unCapteur.ID;
	this->lat = unCapteur.lat;
	this->longi = unCapteur.longi;
	this->description = unCapteur.description;
	this->mesures = unCapteur.mesures;
}

Capteur::Capteur(int ID, double lat, double longi, string description)
{
	this->ID = ID;
	this->lat = lat;
	this->longi = longi;
	this->description = description;
}

Capteur::Capteur(int id, double lat, double longi, string description, collectionMesures mesures)
{
	this->ID = ID;
	this->lat = lat;
	this->longi = longi;
	this->description = description;
	this->mesures = mesures;
}

Capteur::~Capteur()
{
}


//------------------------------------------------- Surcharge d'op�rateurs


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es


