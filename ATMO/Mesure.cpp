/*************************************************************************
Mesure  -  description
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
#include "Mesure.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques


Date Mesure::getDate() const
{
	return horodate;
}

double Mesure::getValeur() const
{
	return valeur;
}

TypeMesure Mesure::getTypeMesure() const
{
	return typeMesure;
}

int Mesure::getSensorID() const
{
	return sensorID;
}


bool Mesure::operator<(const Mesure & unMesure)
{
	return horodate < unMesure.horodate ;
}

Mesure & Mesure::operator=(const Mesure & unMesure)
{
	this->horodate = unMesure.horodate;
	this->valeur = unMesure.valeur;
	this->typeMesure = unMesure.typeMesure;
	this->sensorID = unMesure.sensorID;
	return *this;
}

//------------------------------------------------- Surcharge d'opérateurs
ostream & operator << (ostream &out, const Mesure &mesure)
{
	out << mesure.typeMesure.getAttributeId() << " " << mesure.valeur << " "<< mesure.horodate << " " << mesure.sensorID << endl;
	return out;
}
//-------------------------------------------- Constructeurs - destructeur

Mesure::Mesure(const Mesure & unMesure)
{
	this->horodate = unMesure.horodate;
	this->valeur = unMesure.valeur;
	this->typeMesure = unMesure.typeMesure;
	this->sensorID = unMesure.sensorID;
}

Mesure::Mesure(Date horodate, double valeur, TypeMesure typeMesure, int sensorID)
{
	this->horodate = horodate;
	this->valeur = valeur;
	this->typeMesure = typeMesure;
	this->sensorID = sensorID;
}

Mesure::~Mesure()
{
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées


