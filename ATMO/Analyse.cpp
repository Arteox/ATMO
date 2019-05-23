/*************************************************************************
						   Analyse  -  description
							 -------------------
	début                : ${date}
	copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <Analyse> (fichier Analyse.h) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Analyse.h"
#include "TraitementDonnees.h"
#include "Mesure.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
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
//} //----- Fin de Méthode

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

//------------------------------------------------- Surcharge d'opérateurs


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
