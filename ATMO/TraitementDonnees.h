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

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <TraitementDonnees>
//
//
//------------------------------------------------------------------------ 
class TraitementDonnees
{
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- M�thodes publiques
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
	//----------------------------------------------------- M�thodes prot�g�es

private:
	//------------------------------------------------------- M�thodes priv�es

protected:
	//----------------------------------------------------- Attributs prot�g�s

private:
	//------------------------------------------------------- Attributs priv�s
	string FichierTypesMesure = "AttributeType.csv";
	string FichierCapteurs = "Sensors.csv";
	string FichierMesures = "MesuresSample.csv";
	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes priv�es

	//----------------------------------------------------------- Types priv�s
};

//----------------------------------------- Types d�pendants de <TraitementDonnees>

#endif //_TraitementDonnees_H