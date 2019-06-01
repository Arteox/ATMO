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
// Classe pour gérer les dates qui sont au format annee-mois-jour heure:minute:seconde
//------------------------------------------------------------------------typedef enum TokenType

class Date
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques

	int getHeure() const;
	// Mode d'emploi : 
	// Renvoie l'attribut protég?heure
	// Contrat : Aucun

	int getMin() const;
	// Mode d'emploi : 
	// Renvoie l'attribut protég?min
	// Contrat : Aucun

	int getSec() const;
	// Mode d'emploi : 
	// Renvoie l'attribut protég?sec
	// Contrat : Aucun

	int getJour() const;
	// Mode d'emploi : 
	// Renvoie l'attribut protég?jour
	// Contrat : Aucun

	int getMois() const;
	// Mode d'emploi : 
	// Renvoie l'attribut protég?mois
	// Contrat : Aucun

	int getAnnee() const;
	// Mode d'emploi : 
	// Renvoie l'attribut protég?annee
	// Contrat : Aucun


	//------------------------------------------------- Surcharge d'opérateurs
	bool operator < (const Date & unDate);

	bool operator == (const Date & unDate);

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

	Date(string date_brute);

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