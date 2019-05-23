/*************************************************************************
TypeMesure  -  description
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
#include "TypeMesure.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
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

//------------------------------------------------- Surcharge d'op�rateurs

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

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es


