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

double Date::getSec() const
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
	if (annee != unDate.annee) {
		return annee < unDate.annee;
	}
	else{
		if (mois != unDate.mois) {
			return mois < unDate.mois;
		}
		else {
			if (jour != unDate.jour) {
				return jour < unDate.jour;
			}
			else {
				if (heure != unDate.heure) {
					return heure < unDate.heure;
				}
				else {
					if (min != unDate.min) {
						return min < unDate.min;
					}
					else {
						return sec < unDate.sec;
					}
				}
			}
		}
	}
}

bool Date::operator==(const Date & unDate)
{
	if (annee != unDate.annee) {
		return false;
	}
	else {
		if (mois != unDate.mois) {
			return false;
		}
		else {
			if (jour != unDate.jour) {
				return false;
			}
			else {
				if (heure != unDate.heure) {
					return false;
				}
				else {
					if (min != unDate.min) {
						return false;
					}
					else {
						return (sec == unDate.sec);
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
	sec = unDate.sec;
	min = unDate.min;
	heure = unDate.heure;
	jour = unDate.jour;
	mois = unDate.mois;
	annee = unDate.annee;
	return *this;
} //----- Fin de operator =

//

ostream & operator << (ostream &out, const Date &date)
{
	out << date.annee << '-' << date.mois << '-' << date.jour << " ";
	out << date.heure << ':' << date.min << ':' << date.sec;
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
	sec = unDate.sec;
	min = unDate.min;
	heure = unDate.heure;
	jour = unDate.jour;
	mois = unDate.mois;
	annee = unDate.annee;
} //----- Fin de Date (constructeur de copie)

Date::Date(const int& annee, const int& mois, const int& jour, const int& heure, const int& min, const double& sec)
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
	sec = stod(date_brute.substr(17, 8));
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
