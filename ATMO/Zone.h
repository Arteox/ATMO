/*************************************************************************
Zone  -  description
-------------------
d�but                : 07/05/2019
copyright            : (C) 2019 par Mengxing ZHANG, Louis UNG, Fabien GELUS et Baptiste PAULETTO
*************************************************************************/

//---------- Interface de la classe <Zone> (fichier Zone.h) ------
#ifndef _ZONE_H
#define _ZONE_H

//--------------------------------------------------- Interfaces utilis�es

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 
//------------------------------------------------------------------------ 
// R�le de la classe <Zone>
// Classe pour g�rer une zone g�ographique qui correspond ?un cercle
// ayant pour un centre une coordonn�es GPS et un rayon variable
//
//------------------------------------------------------------------------ 
class Zone
{
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- M�thodes publiques
	bool estDansZone(double lat, double longi);

	//------------------------------------------------- Surcharge d'op�rateurs
	// Mode d'emploi :
	// RAS
	// Contrat : Aucun
	//

	//-------------------------------------------- Constructeurs - destructeur
	Zone(const Zone & unZone);
	// Mode d'emploi (constructeur de copie) :
	// RAS
	// Contrat : Aucun
	//

	Zone(double lat, double longi, double rayon);
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Zone();
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
	int id;
	double latCentre;
	double longCentre;
	double rayon;
	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes priv�es

	//----------------------------------------------------------- Types priv�s
};

//----------------------------------------- Types d�pendants de <Zone>

#endif //_ZONE_H