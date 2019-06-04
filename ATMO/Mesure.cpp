/*************************************************************************
Mesure  -  description
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
#include "Mesure.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques


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

//------------------------------------------------- Surcharge d'op�rateurs
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

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es


