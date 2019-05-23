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
#define TraitementD TraitementDonnees::GetInstance()

//------------------------------------------------------------------ Types 
typedef vector<vector<Capteur>> doubleCollectionCapteurs;
typedef vector<Capteur> collectionCapteurs;
typedef vector<TypeMesure> collectionTypesMesure;
typedef multiset<Mesure, compareMesure> collectionMesures;

//------------------------------------------------------------------------ 
// Rôle de la classe <TraitementDonnees>
//
//
//------------------------------------------------------------------------ 
class TraitementDonnees
{
	//----------------------------------------------------------------- PUBLIC
public:

	static TraitementDonnees & GetInstance()
	{
		static TraitementDonnees instance;
		return instance;
	}

	//----------------------------------------------------- Méthodes publiques
	collectionCapteurs ParcoursCapteurs(double lat, double longi, double rayon);

	collectionCapteurs ParcoursCapteurs(double lat, double longi);

	collectionMesures ParcoursMesures(collectionCapteurs, Date horodateDeb, Date horodateFin);

	collectionTypesMesure ParcoursTypesMesure();

	//-------------------------------------------- Constructeurs - destructeur
	TraitementDonnees(const TraitementDonnees & unTraitementDonnees);
	// Mode d'emploi (constructeur de copie) :
	// RAS
	// Contrat : Aucun
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
	//constructeur mis ici pour interdire la creation d'un autre constructeur hormis le singleton
	TraitementDonnees();
	// Mode d'emploi :
	//
	// Contrat :
	//

	//------------------------------------------------------- Attributs privés
	static const string FichierTypesMesure;
	static const string FichierCapteurs;
	static const string FichierMesures;
	collectionCapteurs donneesCapteurs;
	collectionTypesMesure donneesTypesMesure;
	collectionMesures donneesMesures;
	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes privées

	//----------------------------------------------------------- Types privés
};

//----------------------------------------- Types dépendants de <TraitementDonnees>

#endif //_TraitementDonnees_H