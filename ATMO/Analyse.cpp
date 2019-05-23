/*************************************************************************
						   Analyse  -  description
							 -------------------
	d�but                : ${date}
	copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <Analyse> (fichier Analyse.h) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Analyse.h"
#include "TraitementDonnees.h"
#include "Mesure.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
conteneurMoyMesures Analyse::caracteristiquesZone(bool d, double lat, double longi, double rayon, Date horodateDeb, Date horodateFin)
{
	
	conteneurMoyMesures moyMesures;
	
	collectionCapteurs capteurs;
	//todo : typedef TraitementDonnesInstance
	capteurs = TraitementD.ParcoursCapteurs(lat, longi, rayon);
	//todo : typedef collectionMesures
	collectionMesures mesures;
	mesures = TraitementD.ParcoursMesures(capteurs,horodateDeb, horodateFin);

	collectionMesures ::iterator it;  // declare an iterator to a vector of strings

	for (it = mesures.begin(); it != mesures.end(); it++) 
	{	
		
		it->getTypeMesure().getAttributeId();
		
			
			
	}

	
	

	return moyMesures;

}
// Algorithme :
//
//{
//} //----- Fin de M�thode

doubleCollectionCapteurs Analyse::comportementSimilaire(Date horodateDeb, Date horodateFin)
{
	return doubleCollectionCapteurs();
}

collectionCapteurs Analyse::dysfonctionnement(Date horodateDeb, Date horodateFin)
{
	return collectionCapteurs();
}

conteneurMoyMesures Analyse::caracteristiquesPoint(double long, double lat, Date horodateDeb, Date horodateFin)
{
	return conteneurMoyMesures();
}

int Analyse::qualiteAir(conteneurMoyMesures MoyMesures)
{
	return int();
}

//------------------------------------------------- Surcharge d'op�rateurs


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
