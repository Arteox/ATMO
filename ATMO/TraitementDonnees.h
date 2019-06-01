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


//------------------------------------------------------------------------ 
// Rôle de la classe <TraitementDonnees>
// Cette classe fait 2 choses :
// 1) Extraction des données des fichiers CSV et stockage dans des structures de données
// 2) Renvoie des données filtrées en parcourant ces structures de données
// en fonction de paramètres données par l'utilisateur
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
	// Mode d'emploi :
	// L'utilisateur indique une zone dont le centre et le rayon sont indiqués en paramètre.
	// Cette méthode renvoie alors tous les capteurs qui sont présents dans cette zone.
	// Contrat : Aucun
	//

	collectionCapteurs ParcoursCapteurs(double lat, double longi);
	// Mode d'emploi :
	// L'utilisateur indique une zone dont le centre est indiqué en paramètre. Le rayon fait 10 km.
	// Cette méthode renvoie alors, s'il y en a, les 3 capteurs les plus proches présents dans cette zone.
	// Contrat : Aucun
	//
	

	collectionMesures ParcoursMesures(collectionCapteurs capteurs, Date horodateDeb, Date horodateFin);
	// Mode d'emploi :
	// Renvoie toutes les mesures réalisées par les capteurs précisés en paramètre, et qui sont entre les
	// 2 dates précisées.
	// Contrat : Aucun
	//

	collectionMesures ParcoursMesures();
	// Mode d'emploi :
	// Renvoie toutes les mesures extraites
	// Contrat : Aucun
	//

	collectionTypesMesure ParcoursTypeeMesure();
	// Mode d'emploi :
	// Renvoie toutes les types de mesures
	// Contrat : Aucun
	//

	collectionCapteurs ParcoursCapteurs();
	// Mode d'emploi :
	// Renvoie tous les capteurs
	// Contrat : Aucun
	//

	//-------------------------------------------- Constructeurs - destructeur

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
	void lectureTypesMesure();
	void lectureMesures();
	void lectureCapteurs();

protected:
	//----------------------------------------------------- Attributs protégés

private:
	//constructeur mis ici pour interdire la creation d'un autre constructeur hormis le singleton
	TraitementDonnees();
	// Mode d'emploi :
	//
	// Contrat :
	//

	TraitementDonnees(const TraitementDonnees &);              

	//------------------------------------------------------- Attributs privés
	static const string fichierTypesMesure;
	static const string fichierCapteurs;
	static const string fichierMesures;
	collectionCapteurs donneesCapteurs;
	collectionTypesMesure donneesTypesMesure;
	collectionMesures donneesMesures;
	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes privées

	//----------------------------------------------------------- Types privés
};

//----------------------------------------- Types dépendants de <TraitementDonnees>

#endif //_TraitementDonnees_H