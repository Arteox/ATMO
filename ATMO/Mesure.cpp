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

Mesure & Mesure::operator=(const Mesure & unMesure)
{
	this->horodate = unMesure.getDate();
	this->valeur = unMesure.getValeur();
	this->typeMesure = unMesure.getTypeMesure();
	return *this;
}

//------------------------------------------------- Surcharge d'op�rateurs

//-------------------------------------------- Constructeurs - destructeur

Mesure::Mesure(const Mesure & unMesure)
{
	this->horodate = unMesure.getDate();
	this->valeur = unMesure.getValeur();
	this->typeMesure = unMesure.getTypeMesure();
}

Mesure::Mesure(Date horodate, double valeur, TypeMesure typeMesure)
{
	this->horodate = horodate;
	this->valeur = valeur;
	this->typeMesure = typeMesure;
}

Mesure::~Mesure()
{
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es


