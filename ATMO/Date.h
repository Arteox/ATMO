/*************************************************************************
Date  -  description
-------------------
début                : 07/05/2019
copyright            : (C) 2019 par Mengxing ZHANG, Louis UNG, Fabien GELUS et Baptiste PAULETTO
*************************************************************************/

//---------- Interface de la classe <Date> (fichier Date.h) ----------------
#if ! defined ( Date_H )
#define Date_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <iostream>
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Date>
//
//------------------------------------------------------------------------typedef enum TokenType

class Date
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques

	int GetHeure() const;
	// Mode d'emploi : 
	// Renvoie l'attribut protégé heure
	// Contrat : Aucun

	int GetMin() const;
	// Mode d'emploi : 
	// Renvoie l'attribut protégé min
	// Contrat : Aucun

	int GetSec() const;
	// Mode d'emploi : 
	// Renvoie l'attribut protégé sec
	// Contrat : Aucun

	int GetJour() const;
	// Mode d'emploi : 
	// Renvoie l'attribut protégé jour
	// Contrat : Aucun

	int GetMois() const;
	// Mode d'emploi : 
	// Renvoie l'attribut protégé mois
	// Contrat : Aucun

	int GetAnnee() const;
	// Mode d'emploi : 
	// Renvoie l'attribut protégé annee
	// Contrat : Aucun


	//------------------------------------------------- Surcharge d'opérateurs
	Date & operator = (const Date & unDate);
	// Mode d'emploi :
	// RAS
	// Contrat : Aucun
	//

	friend ostream & operator << (ostream &out, const Date &date);
	//-------------------------------------------- Constructeurs - destructeur
	Date(const Date & unDate);
	// Mode d'emploi (constructeur de copie) :
	// RAS
	// Contrat : Aucun
	//

	Date(const int& annee, const int& mois, const int& jour, const int& heure, const int& min, const int& sec);

	Date();
	// Mode d'emploi : Constructeur sans paramètres, contenu vide
	//
	// Contrat : Ne pas mettre de paramètre
	//

	virtual ~Date();
	// Mode d'emploi : RAS, contenu vide
	//
	// Contrat : Aucun
	//

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés
	int sec;
	int min;
	int heure;
	int jour;
	int mois;
	int annee;

};

//-------------------------------- Autres définitions dépendantes de <Date>

#endif // Date_H