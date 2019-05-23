/*************************************************************************
Date  -  description
-------------------
d�but                : 07/05/2019
copyright            : (C) 2019 par Mengxing ZHANG, Louis UNG, Fabien GELUS et Baptiste PAULETTO
*************************************************************************/

//---------- Interface de la classe <Date> (fichier Date.h) ----------------
#if ! defined ( Date_H )
#define Date_H

//--------------------------------------------------- Interfaces utilis�es
#include <string>
#include <iostream>
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Date>
//
//------------------------------------------------------------------------typedef enum TokenType

class Date
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques

	int GetHeure() const;
	// Mode d'emploi : 
	// Renvoie l'attribut prot�g� heure
	// Contrat : Aucun

	int GetMin() const;
	// Mode d'emploi : 
	// Renvoie l'attribut prot�g� min
	// Contrat : Aucun

	int GetSec() const;
	// Mode d'emploi : 
	// Renvoie l'attribut prot�g� sec
	// Contrat : Aucun

	int GetJour() const;
	// Mode d'emploi : 
	// Renvoie l'attribut prot�g� jour
	// Contrat : Aucun

	int GetMois() const;
	// Mode d'emploi : 
	// Renvoie l'attribut prot�g� mois
	// Contrat : Aucun

	int GetAnnee() const;
	// Mode d'emploi : 
	// Renvoie l'attribut prot�g� annee
	// Contrat : Aucun


	//------------------------------------------------- Surcharge d'op�rateurs
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
	// Mode d'emploi : Constructeur sans param�tres, contenu vide
	//
	// Contrat : Ne pas mettre de param�tre
	//

	virtual ~Date();
	// Mode d'emploi : RAS, contenu vide
	//
	// Contrat : Aucun
	//

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s
	int sec;
	int min;
	int heure;
	int jour;
	int mois;
	int annee;

};

//-------------------------------- Autres d�finitions d�pendantes de <Date>

#endif // Date_H