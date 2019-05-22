/*************************************************************************
TypeMesure  -  description
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
#include "TypeMesure.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
int TypeMesure::getId() const
{
	return ID;
}

string TypeMesure::getUnite() const
{
	return unite;
}

string TypeMesure::getDescription() const
{
	return description;
}

TypeMesure & TypeMesure::operator=(const TypeMesure & unTypeMesure)
{
	this->ID = unTypeMesure.getId();
	this->unite = unTypeMesure.getUnite();
	this->description = unTypeMesure.getDescription();
	return *this;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

TypeMesure::TypeMesure(const TypeMesure & unTypeMesure)
{
	this->ID = unTypeMesure.getId();
	this->unite = unTypeMesure.getUnite();
	this->description = unTypeMesure.getDescription();
}

TypeMesure::TypeMesure(int id, string unite, string description)
{
	this->ID = id;
	this->unite = unite;
	this->description = description;
}

TypeMesure::~TypeMesure()
{
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées


