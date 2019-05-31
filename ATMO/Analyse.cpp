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

	capteurs = TraitementD.ParcoursCapteurs(lat, longi, rayon);

	collectionMesures mesures;
	mesures = TraitementD.ParcoursMesures(capteurs,horodateDeb, horodateFin);

	//collectionTypesMesure types = TraitementD.ParcoursTypesMesure();



	collectionMesures ::iterator it;  // declare an iterator to a vector of strings

	double moyO3 = 0;
	double moySO2 = 0;
	double moyNO2 = 0;
	double moyPM10 = 0;

	for (it = mesures.begin(); it != mesures.end(); it++)
	{

		string type = it->getTypeMesure().getAttributeId();
		double valeur = it->getValeur();
		if (type == "O3") {
			moyO3 += valeur;
		}
		else if (type == "SO2") {
			moySO2 += valeur;
		}
		else if (type == "NO2") {
			moyNO2 += valeur;
		}
		else if (type == "PM10") {
			moyPM10 += valeur;
		}
	}
	
	paireMoyMesures paire;
	paire = paireMoyMesures("O3", moyO3);
	moyMesures.insert(paire); 
	paire = paireMoyMesures("SO2", moyO3);
	moyMesures.insert(paire);
	paire = paireMoyMesures("NO2", moyO3);
	moyMesures.insert(paire);
	paire = paireMoyMesures("PM10", moyO3);
	moyMesures.insert(paire);
	
	
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
	int indice = 0;

	string types[4] = { "O3", "SO2", "NO2", "PM10" };
	double atmo[4][9] = { (30,55,80,105,130,150,180,210,240), (40,80,120,160,200,250,300,400,500), (30,55,85,110,135,165,200,275,400), (7,14,21,28,35,42,50,65,80) };

	for (int i = 0; i < 4; i++) {
		double valeur = MoyMesures.find(types[i])->second;

		if (valeur < 0)
		{
			return -1; // erreur 
		}

		for (int j = 0; j < 9; j++) {
			if (valeur < atmo[i][j] && indice < j + 1)
			{
				indice = j + 1;
			}
		}

		if (valeur > atmo[i][8] && indice < 10)
		{
			indice = 10;
		}
		
	}
	
	return indice;
}

//------------------------------------------------- Surcharge d'opérateurs


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
