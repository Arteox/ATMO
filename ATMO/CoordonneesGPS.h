/*************************************************************************
CoordonneesGPS  -  description
-------------------
d�but                : 07/05/2019
copyright            : (C) 2019 par Mengxing ZHANG, Louis UNG, Fabien GELUS et Baptiste PAULETTO
*************************************************************************/

//---------- Interface de la classe <CoordonneesGPS> (fichier CoordonneesGPS.h) ------
#ifndef _COORDONNEESGPS_H
#define _COORDONNEESGPS_H


//--------------------------------------------------- Interfaces utilis�es

//------------------------------------------------------------- Constantes 
#define RAYON_TERRE 6371
//------------------------------------------------------------------ Types 
//------------------------------------------------------------------------ 
// R�le de la classe <CoordonneesGPS>
//
//
//------------------------------------------------------------------------ 
class CoordonneesGPS
{
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- M�thodes publiques
	double distanceEnKmEntreDeuxPoints(double lat1, double long1, double lat2, double long2);

	//------------------------------------------------- Surcharge d'op�rateurs
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
	//----------------------------------------------------- M�thodes prot�g�es

private:
	//------------------------------------------------------- M�thodes priv�es

protected:
	//----------------------------------------------------- Attributs prot�g�s

private:
	//------------------------------------------------------- Attributs priv�s

	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes priv�es

	//----------------------------------------------------------- Types priv�s
};

//----------------------------------------- Types d�pendants de <CoordonneesGPS>

#endif //_COORDONNEESGPS_H