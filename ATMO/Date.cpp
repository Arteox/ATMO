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

int Date::getHeure() const
// Algorithme : RAS
{
	return heure;
}

int Date::getMin() const
// Algorithme : RAS
{
	return min;
}

int Date::getSec() const
// Algorithme : RAS
{
	return sec;
}

int Date::getJour() const
// Algorithme : RAS
{
	return jour;
}

int Date::getMois() const
// Algorithme : RAS
{
	return mois;
}

int Date::getAnnee() const
// Algorithme : RAS
{
	return annee;
}


bool Date::operator<(const Date & unDate)
{
	if (annee != unDate.getAnnee()) {
		return annee < unDate.getAnnee();
	}
	else{
		if (mois != unDate.getMois()) {
			return mois < unDate.getMois();
		}
		else {
			if (jour != unDate.getJour()) {
				return jour < unDate.getJour();
			}
			else {
				if (heure != unDate.getHeure()) {
					return heure < unDate.getHeure();
				}
				else {
					if (min != unDate.getMin()) {
						return min < unDate.getMin();
					}
					else {
						return sec < unDate.getSec();
					}
				}
			}
		}
	}
}

//------------------------------------------------- Surcharge d'opérateurs
Date & Date::operator = (const Date & unDate)
// Algorithme :
// Même algorithme que l'opérateur par défaut
{
	sec = unDate.getSec();
	min = unDate.getMin();
	heure = unDate.getHeure();
	jour = unDate.getJour();
	mois = unDate.getMois();
	annee = unDate.getAnnee();
	return *this;
} //----- Fin de operator =

ostream & operator << (ostream &out, const Date &date)
{
	out << date.getAnnee() << '-' << date.getMois() << '-' << date.getJour() << " ";
	out << date.getHeure() << ':' << date.getMin() << ':' << date.getSec();
	return out;
}
//-------------------------------------------- Constructeurs - destructeur
Date::Date(const Date & unDate)
// Algorithme :
// Même algorithme que le constructeur de copie par défaut
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Date>" << endl;
#endif
	sec = unDate.getSec();
	min = unDate.getMin();
	heure = unDate.getHeure();
	jour = unDate.getJour();
	mois = unDate.getMois();
	annee = unDate.getAnnee();
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

Date::Date(string date_brute)
{
	annee = stoi(date_brute.substr(0, 4));
	mois = stoi(date_brute.substr(5, 2));
	jour = stoi(date_brute.substr(8, 2));
	heure = stoi(date_brute.substr(11, 2));
	min = stoi(date_brute.substr(14, 2));
	sec = stoi(date_brute.substr(17, 2));
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
