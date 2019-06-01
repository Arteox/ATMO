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
// Cette classe fait 2 choses :
// 1) Extraction des donn�es des fichiers CSV et stockage dans des structures de donn�es
// 2) Renvoie des donn�es filtr�es en parcourant ces structures de donn�es
// en fonction de param�tres donn�es par l'utilisateur
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
	// Mode d'emploi :
	// L'utilisateur indique une zone dont le centre et le rayon sont indiqu�s en param�tre.
	// Cette m�thode renvoie alors tous les capteurs qui sont pr�sents dans cette zone.
	// Contrat : Aucun
	//

	collectionCapteurs ParcoursCapteurs(double lat, double longi);
	// Mode d'emploi :
	// L'utilisateur indique une zone dont le centre est indiqu� en param�tre. Le rayon fait 10 km.
	// Cette m�thode renvoie alors, s'il y en a, les 3 capteurs les plus proches pr�sents dans cette zone.
	// Contrat : Aucun
	//
	

	collectionMesures ParcoursMesures(collectionCapteurs capteurs, Date horodateDeb, Date horodateFin);
	// Mode d'emploi :
	// Renvoie toutes les mesures r�alis�es par les capteurs pr�cis�s en param�tre, et qui sont entre les
	// 2 dates pr�cis�es.
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