/*************************************************************************
CoordonneesGPS  -  description
-------------------
début                : 07/05/2019
copyright            : (C) 2019 par Mengxing ZHANG, Louis UNG, Fabien GELUS et Baptiste PAULETTO
*************************************************************************/

//---------- Interface de la classe <CoordonneesGPS> (fichier CoordonneesGPS.h) ------
#ifndef _COORDONNEESGPS_H
#define _COORDONNEESGPS_H


//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 
#define RAYON_TERRE 6371
//------------------------------------------------------------------ Types 
//------------------------------------------------------------------------ 
// Rôle de la classe <CoordonneesGPS>
//
//
//------------------------------------------------------------------------ 
class CoordonneesGPS
{
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- Méthodes publiques
	double distanceEnKmEntreDeuxPoints(double lat1, double long1, double lat2, double long2);

	//------------------------------------------------- Surcharge d'opérateurs
	// Mode d'emploi :
	// RAS
	// Contrat : Aucun
	//

	//-------------------------------------------- Constructeurs - destructeur
	CoordonneesGPS(const CoordonneesGPS & unCoordonneesGPS);
	// Mode d'emploi (constructeur de copie) :
	// RAS
	// Contrat : Aucun
	//

	CoordonneesGPS();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~CoordonneesGPS();
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

	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes privées

	//----------------------------------------------------------- Types privés
};

//----------------------------------------- Types dépendants de <CoordonneesGPS>

#endif //_COORDONNEESGPS_H