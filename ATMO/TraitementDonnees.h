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
	
	collectionCapteurs ParcoursCapteurs(); // tous les capteurs (pour le comportement similaire)

	collectionMesures ParcoursMesures(collectionCapteurs capteurs, Date horodateDeb, Date horodateFin);
	
	collectionMesures ParcoursMesures();

	collectionTypesMesure ParcoursTypeeMesure();

	

	//-------------------------------------------- Constructeurs - destructeur

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
	void lectureTypesMesure();
	void lectureMesures();
	void lectureCapteurs();

protected:
	//----------------------------------------------------- Attributs prot�g�s

private:
	//constructeur mis ici pour interdire la creation d'un autre constructeur hormis le singleton
	TraitementDonnees();
	// Mode d'emploi :
	//
	// Contrat :
	//

	TraitementDonnees(const TraitementDonnees &);              

	//------------------------------------------------------- Attributs priv�s
	static const string fichierTypesMesure;
	static const string fichierCapteurs;
	static const string fichierMesures;
	collectionCapteurs donneesCapteurs;
	collectionTypesMesure donneesTypesMesure;
	collectionMesures donneesMesures;
	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes priv�es

	//----------------------------------------------------------- Types priv�s
};

//----------------------------------------- Types d�pendants de <TraitementDonnees>

#endif //_TraitementDonnees_H