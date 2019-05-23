/*************************************************************************
Analyse  -  description
-------------------
début                : 07/05/2019
copyright            : (C) 2019 par Mengxing ZHANG, Louis UNG, Fabien GELUS et Baptiste PAULETTO
*************************************************************************/

//---------- Interface de la classe <Capteur> (fichier Capteur.h) ------
#ifndef _CAPTEUR_H
#define _CAPTEUR_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <set>
#include "Mesure.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 
typedef multiset<Mesure> collectionMesures;
//------------------------------------------------------------------------ 
// Rôle de la classe <Capteur>
//
//
//------------------------------------------------------------------------ 
class Capteur 
{
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- Méthodes publiques

	int getId() const;
	double getLat() const;
	double getLong() const;
	string getDescription() const;
	collectionMesures getMesures() const;

	//------------------------------------------------- Surcharge d'opérateurs
	Capteur & operator = (const Capteur & unCapteur);
	// Mode d'emploi :
	// RAS
	// Contrat : Aucun
	//
	//-------------------------------------------- Constructeurs - destructeur
	Capteur(const Capteur & unCapteur);
	// Mode d'emploi (constructeur de copie) :
	// RAS
	// Contrat : Aucun
	//

	Capteur(int ID, double lat, double longi, string description, collectionMesures mesures);
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Capteur();
	// Mode d'emploi : RAS, contenu vide
	//
	// Contrat : Aucun
	//
	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées

private:
	//------------------------------------------------------- Méthodes privées
	
protected:
	//----------------------------------------------------- Attributs protégés

private:
	//------------------------------------------------------- Attributs privés
	int ID;
	double lat;
	double longi;
	string description;
	collectionMesures mesures;
	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes privées

	//----------------------------------------------------------- Types privés
};

//----------------------------------------- Types dépendants de <Capteur>

#endif //_CAPTEUR_H