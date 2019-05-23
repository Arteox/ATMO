/*************************************************************************
Date  -  description
-------------------
début                : 07/05/2019
copyright            : (C) 2019 par Mengxing ZHANG, Louis UNG, Fabien GELUS et Baptiste PAULETTO
*************************************************************************/

//---------- Réalisation de la classe <Date> (fichier Date.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Date.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Date::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

int Date::GetHeure() const
// Algorithme : RAS
{
	return heure;
}

int Date::GetMin() const
// Algorithme : RAS
{
	return min;
}

int Date::GetSec() const
// Algorithme : RAS
{
	return sec;
}

int Date::GetJour() const
// Algorithme : RAS
{
	return jour;
}

int Date::GetMois() const
// Algorithme : RAS
{
	return mois;
}

int Date::GetAnnee() const
// Algorithme : RAS
{
	return annee;
}


//------------------------------------------------- Surcharge d'opérateurs
Date & Date::operator = (const Date & unDate)
// Algorithme :
// Même algorithme que l'opérateur par défaut
{
	sec = unDate.GetSec();
	min = unDate.GetMin();
	heure = unDate.GetHeure();
	jour = unDate.GetJour();
	mois = unDate.GetMois();
	annee = unDate.GetAnnee();
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Date::Date(const Date & unDate)
// Algorithme :
// Même algorithme que le constructeur de copie par défaut
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Date>" << endl;
#endif
	sec = unDate.GetSec();
	min = unDate.GetMin();
	heure = unDate.GetHeure();
	jour = unDate.GetJour();
	mois = unDate.GetMois();
	annee = unDate.GetAnnee();
} //----- Fin de Date (constructeur de copie)

Date::Date(const int& annee, const int& mois, const int& jour, const int& heure, const int& min, const int& sec)
// Algorithme : RAS
{
	this->annee = annee;
	this->mois = mois;
	this->jour = jour;
	this->heure = heure;
	this->min = min;
	this->sec = sec;
}

Date::Date()
{
}

Date::~Date()
// Algorithme : RAS
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Date>" << endl;
#endif
} //----- Fin de ~Date


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Méthodes protégées
