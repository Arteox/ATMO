/*************************************************************************
Capteur  -  description
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
#include "Capteur.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
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

multiset<Mesure> Capteur::getMesures() const
{
	return mesures;
}

//------------------------------------------------- Surcharge d'opérateurs
Capteur & Capteur::operator=(const Capteur & unCapteur)
{
	this->ID = unCapteur.getId();
	this->lat = unCapteur.getLat();
	this->longi = unCapteur.getLong();
	this->description = unCapteur.getDescription();
	this->mesures = unCapteur.getMesures();
	return *this;
}

//-------------------------------------------- Constructeurs - destructeur

Capteur::Capteur(const Capteur & unCapteur)
{
}

Capteur::Capteur(int id, double lat, double longi, string description, multiset<Mesure> mesures)
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


//------------------------------------------------- Surcharge d'opérateurs


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées


