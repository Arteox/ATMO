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

wstring TypeMesure::getUnite() const
{
	return unite;
}

string TypeMesure::getDescription() const
{
	return description;
}

void TypeMesure::afficher() const
{
	cout << attributeID;
	wcout << unite;
	cout << description << endl;
}

//------------------------------------------------- Surcharge d'opérateurs
TypeMesure & TypeMesure::operator=(const TypeMesure & unTypeMesure)
{
	this->attributeID = unTypeMesure.getAttributeId();
	this->unite = unTypeMesure.getUnite();
	this->description = unTypeMesure.getDescription();
	return *this;
}

ostream & operator<<(ostream & out, const TypeMesure & typemesure)
{
	out << typemesure.getAttributeId() << " " << typemesure.getDescription() << endl;
	return out;
}

//-------------------------------------------- Constructeurs - destructeur

TypeMesure::TypeMesure(const TypeMesure & unTypeMesure)
{
	//Je pense que l'on a acc¨¨s aux attributs de la classe si on est dans la m¨ºme classe
	//Il me semble que l'on n'a pas besoin d'utiliser get -- Mengxin
	this->attributeID = unTypeMesure.getAttributeId();
	this->unite = unTypeMesure.getUnite();
	this->description = unTypeMesure.getDescription();
}

TypeMesure::TypeMesure(string attributeID, wstring unite, string description)
{
	this->attributeID = attributeID;
	this->unite = unite;
	this->description = description;
}

TypeMesure::TypeMesure()
{
}

TypeMesure::~TypeMesure()
{
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées


