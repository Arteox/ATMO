/*************************************************************************
Analyse  -  description
-------------------
d�but                : 07/05/2019
copyright            : (C) 2019 par Mengxing ZHANG, Louis UNG, Fabien GELUS et Baptiste PAULETTO
*************************************************************************/

//---------- Interface de la classe <Capteur> (fichier Capteur.h) ------
#ifndef _CAPTEUR_H
#define _CAPTEUR_H

//--------------------------------------------------- Interfaces utilis�es
#include <string>
#include <set>
#include <algorithm>
#include <vector>
#include "Mesure.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 
//------------------------------------------------------------------------ 
// R�le de la classe <Capteur>
// Classe pour g�rer l'objet Capteur
//
//------------------------------------------------------------------------ 
class Capteur 
{
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- M�thodes publiques

	int getId() const;
	double getLat() const;
	double getLong() const;
	string getDescription() const;
	collectionMesures getMesures() const;
	
	void setMesures(collectionMesures mesures);

	//------------------------------------------------- Surcharge d'op�rateurs
	Capteur & operator = (const Capteur & unCapteur);
	// Mode d'emploi :
	// RAS
	// Contrat : Aucun
	//

	friend ostream & operator << (ostream &out, const Capteur &capteur);
	//-------------------------------------------- Constructeurs - destructeur
	Capteur(const Capteur & unCapteur);
	// Mode d'emploi (constructeur de copie) :
	// RAS
	// Contrat : Aucun
	//

	Capteur(int ID, double lat, double longi, string description);
	// Mode d'emploi :
	//
	// Contrat :
	//

	Capteur(int ID, double lat, double longi, string description, const collectionMesures &mesures);
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
	//----------------------------------------------------- M�thodes prot�g�es

private:
	//------------------------------------------------------- M�thodes priv�es
	
protected:
	//----------------------------------------------------- Attributs prot�g�s

private:
	//------------------------------------------------------- Attributs priv�s
	int ID;
	double lat;
	double longi;
	string description;
	collectionMesures mesures;
	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes priv�es

	//----------------------------------------------------------- Types priv�s
};

//----------------------------------------- Types d�pendants de <Capteur>
typedef vector<vector<Capteur>> doubleCollectionCapteurs;
typedef vector<Capteur> collectionCapteurs;
#endif //_CAPTEUR_H