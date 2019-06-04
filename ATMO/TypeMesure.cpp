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
#include <io.h>
#include <fcntl.h>
#include <cstdlib>

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

wstring TypeMesure::getUnite() const
{
	return unite;
}

string TypeMesure::getDescription() const
{
	return description;
}

//------------------------------------------------- Surcharge d'op�rateurs
TypeMesure & TypeMesure::operator=(const TypeMesure & unTypeMesure)
{
	this->attributeID = unTypeMesure.attributeID;
	this->unite = unTypeMesure.unite;
	this->description = unTypeMesure.description;
	return *this;
}

wostream & operator<<(wostream & out, const TypeMesure & typemesure)
{
	//passage au format unicode
	_setmode(_fileno(stdout), _O_U16TEXT);
	wstring id (typemesure.attributeID.begin(), typemesure.attributeID.end());
	wstring descrip (typemesure.description.begin(), typemesure.description.end());
	out << id << " " <<typemesure.unite << " "<< descrip;

	//re-passage au format non unicode
	_setmode(_fileno(stdout), _O_TEXT);
	return out;
}

//-------------------------------------------- Constructeurs - destructeur

TypeMesure::TypeMesure(const TypeMesure & unTypeMesure)
{
	//Je pense que l'on a acc��s aux attributs de la classe si on est dans la m��me classe
	//Il me semble que l'on n'a pas besoin d'utiliser get -- Mengxin
	this->attributeID = unTypeMesure.attributeID;
	this->unite = unTypeMesure.unite;
	this->description = unTypeMesure.description;
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

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es


