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

Mesure & Mesure::operator=(const Mesure & unMesure)
{
	this->horodate = unMesure.getDate();
	this->valeur = unMesure.getValeur();
	this->typeMesure = unMesure.getTypeMesure();
	return *this;
}

//------------------------------------------------- Surcharge d'opérateurs

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

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées


