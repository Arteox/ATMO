/*************************************************************************
TraitementDonnees  -  description
-------------------
d�but                : 07/05/2019
copyright            : (C) 2019 par Mengxing ZHANG, Louis UNG, Fabien GELUS et Baptiste PAULETTO
*************************************************************************/

//---------- Interface de la classe <TraitementDonnees> (fichier TraitementDonnees.h) ------
#ifndef _TraitementDonnees_H
#define _TraitementDonnees_H

//--------------------------------------------------- Interfaces utilis�es
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
// R�le de la classe <TraitementDonnees>
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

	//----------------------------------------------------- M�thodes publiques
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
	//----------------------------------------------------- M�thodes prot�g�es

private:
	//------------------------------------------------------- M�thodes priv�es

protected:
	//----------------------------------------------------- Attributs prot�g�s

private:
	//constructeur mis ici pour interdire la creation d'un autre constructeur hormis le singleton
	TraitementDonnees();
	// Mode d'emploi :
	//
	// Contrat :
	//

	//------------------------------------------------------- Attributs priv�s
	static const string FichierTypesMesure;
	static const string FichierCapteurs;
	static const string FichierMesures;
	collectionCapteurs donneesCapteurs;
	collectionTypesMesure donneesTypesMesure;
	collectionMesures donneesMesures;
	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes priv�es

	//----------------------------------------------------------- Types priv�s
};

//----------------------------------------- Types d�pendants de <TraitementDonnees>

#endif //_TraitementDonnees_H