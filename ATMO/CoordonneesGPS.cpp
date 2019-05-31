/*************************************************************************
CoordonneesGPS  -  description
-------------------
d�but                : ${date}
copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <CoordonneesGPS> (fichier CoordonneesGPS.h) --


//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "CoordonneesGPS.h"
#define _USE_MATH_DEFINES
#include <math.h>

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques

double CoordonneesGPS::distanceEnKmEntreDeuxPoints(double lat1, double long1, double lat2, double long2)

{
	lat1 = lat1 * M_PI / 180.0;
	lat2 = lat2 * M_PI / 180.0;
	long1 = long1 * M_PI / 180.0;
	long2 = long2 * M_PI / 180.0;
	double dLat = lat2 - lat1;
	double dLong = long2 - long1;

	double a = sin(dLat / 2.0) * sin(dLat / 2.0) + sin(dLong / 2.0) * sin(dLong / 2.0) * cos(lat1) * cos(lat2);
	double c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));
	return RAYON_TERRE * c;
}
//------------------------------------------------- Surcharge d'op�rateurs


//-------------------------------------------- Constructeurs - destructeur



CoordonneesGPS::CoordonneesGPS(const CoordonneesGPS & unCoordonneesGPS)
{
}

CoordonneesGPS::CoordonneesGPS()
{

}


CoordonneesGPS::~CoordonneesGPS()
{
}


//------------------------------------------------- Surcharge d'op�rateurs


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es


