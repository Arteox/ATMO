/*************************************************************************
TraitementDonnees  -  description
-------------------
début                : 07/05/2019
copyright            : (C) 2019 par Mengxing ZHANG, Louis UNG, Fabien GELUS et Baptiste PAULETTO
*************************************************************************/

//---------- Interface de la classe <TraitementDonnees> (fichier TraitementDonnees.h) ------
#ifndef _TraitementDonnees_H
#define _TraitementDonnees_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <vector>
#include <set>
#include "Mesure.h"
#include "Capteur.h"
#include "TypeMesure.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <TraitementDonnees>
//
//
//------------------------------------------------------------------------ 
class TraitementDonnees
{
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- Méthodes publiques
	//mettre en static ?
	vector<Capteur> ParcoursCapteurs(double lat, double longi, double rayon);

	vector<Capteur> ParcoursCapteurs(double lat, double longi);

	multiset<Mesure> ParcoursMesures(vector<Capteur>, vector<TypeMesure>, Date horodateDeb, Date horodateFin);

	vector<TypeMesure> ParcoursTypesMesure();

	//-------------------------------------------- Constructeurs - destructeur
	TraitementDonnees(const TraitementDonnees & unTraitementDonnees);
	// Mode d'emploi (constructeur de copie) :
	// RAS
	// Contrat : Aucun
	//

	TraitementDonnees();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~TraitementDonnees();
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
	string FichierTypesMesure = "AttributeType.csv";
	string FichierCapteurs = "Sensors.csv";
	string FichierMesures = "MesuresSample.csv";
	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes privées

	//----------------------------------------------------------- Types privés
};

//----------------------------------------- Types dépendants de <TraitementDonnees>

#endif //_TraitementDonnees_H