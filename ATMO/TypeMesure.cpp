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
string TypeMesure::getAttributeId() const
{
	return attributeID;
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
	this->attributeID = unTypeMesure.getAttributeId();
	this->unite = unTypeMesure.getUnite();
	this->description = unTypeMesure.getDescription();
	return *this;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

TypeMesure::TypeMesure(const TypeMesure & unTypeMesure)
{
	this->attributeID = unTypeMesure.getAttributeId();
	this->unite = unTypeMesure.getUnite();
	this->description = unTypeMesure.getDescription();
}

TypeMesure::TypeMesure(string attributeID, string unite, string description)
{
	this->attributeID = attributeID;
	this->unite = unite;
	this->description = description;
}

TypeMesure::~TypeMesure()
{
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées


