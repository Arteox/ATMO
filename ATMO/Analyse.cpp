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

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
conteneurMoyMesures Analyse::caracteristiquesZone(bool d, double lat, double longi, double rayon, Date horodateDeb, Date horodateFin)
{
	collectionCapteurs capteurs;
	//todo : typedef TraitementDonnesInstance
	capteurs = TraitementDonnesInstance::ParcoursCapteurs(lat, longi, rayon);
	//todo : typedef collectionMesures
	collectionMesures mesures;
	mesures = TraitementDonnesInstance::ParcoursCapteurs(lat, longi, rayon);





}
// Algorithme :
//
//{
//} //----- Fin de Méthode

doubleCollectionCapteurs Analyse::comportementSimilaire(Date horodateDeb, Date horodateFin)
{

}

collectionCapteurs Analyse::dysfonctionnement(Date horodateDeb, Date horodateFin)
{

}

conteneurMoyMesures Analyse::caracteristiquesPoint(double long, double lat, Date horodateDeb, Date horodateFin)
{

}

int Analyse::qualiteAir(conteneurMoyMesures MoyMesures)
{

}

//------------------------------------------------- Surcharge d'opérateurs


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
