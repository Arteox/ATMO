/*************************************************************************
						   Analyse  -  description
							 -------------------
	début                : ${date}
	copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <Analyse> (fichier Analyse.h) --
//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Analyse.h"
#include "TraitementDonnees.h"
#include "Mesure.h"
#include "CoordonneesGPS.h"
#include "Menu.h"

//------------------------------------------------------------- Constantes
#define RAYON_TERRE 6371
#define FREQUENCE_CAPTEUR 45 // exprim¨¦ en minutes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
conteneurMoyMesures Analyse::caracteristiquesZone( double lat, double longi, double rayon, Date & horodateDeb, Date & horodateFin)
{
	
	conteneurMoyMesures moyMesures;
	
	collectionCapteurs capteurs;

	capteurs = TraitementD.ParcoursCapteurs(lat, longi, rayon);
	if (capteurs.size() == 0) {
		MenuInstance.AffichageSortieErreur("Pas de capteurs sur cette zone");
		return moyMesures;
	}

	collectionMesures mesures;
	mesures = TraitementD.ParcoursMesures(capteurs,horodateDeb, horodateFin);
	if (mesures.size() == 0) {
		MenuInstance.AffichageSortieErreur("Pas de mesures sur cette plage horaire");
		return moyMesures;
	}


	collectionMesures ::iterator it;  // declare an iterator to a vector of strings

	double moyO3 = 0;
	double moySO2 = 0;
	double moyNO2 = 0;
	double moyPM10 = 0;


	int cptO3 = 0;
	int cptSO2 = 0;
	int cptNO2 = 0;
	int cptPM10 = 0;

	for (it = mesures.begin(); it != mesures.end(); it++)
	{

		string type = it->getTypeMesure().getAttributeId();
		double valeur = it->getValeur();
		if (type == "O3") {
			moyO3 += valeur;
			cptO3++;
		}
		else if (type == "SO2") {
			moySO2 += valeur;
			cptSO2++;
		}
		else if (type == "NO2") {
			moyNO2 += valeur;
			cptNO2++;
		}
		else if (type == "PM10") {
			moyPM10 += valeur;
			cptPM10++;
		}
	}
	
	paireMoyMesures paire;
	paire = paireMoyMesures("O3", moyO3 / cptO3);
	moyMesures.insert(paire);
	paire = paireMoyMesures("SO2", moySO2 / cptSO2);
	moyMesures.insert(paire);
	paire = paireMoyMesures("NO2", moyNO2 / cptNO2);
	moyMesures.insert(paire);
	paire = paireMoyMesures("PM10", moyPM10 / cptPM10);
	moyMesures.insert(paire);
	
	
	return moyMesures;

}
// Algorithme :
//
//{
//} //----- Fin de Méthode

conteneurIndiceCapteurs Analyse::comportementSimilaire(Date & horodateDeb, Date & horodateFin)
{
	
	conteneurIndiceCapteurs capteursIdentiques;

	collectionCapteurs capteurs;

	capteurs = TraitementD.ParcoursCapteurs();

	if (capteurs.size() == 0) {
		MenuInstance.AffichageSortieErreur("Pas de capteurs");
		return capteursIdentiques;
	}

	collectionCapteurs::iterator it;

	for (it = capteurs.begin(); it != capteurs.end(); it++)
	{

		collectionCapteurs capteur;
		capteur.push_back(*it);

		collectionMesures mesures;
		mesures = TraitementD.ParcoursMesures(capteur, horodateDeb, horodateFin);

		if (mesures.size() != 0) {

			conteneurMoyMesures moyMesures;

			double moyO3 = 0;
			double moySO2 = 0;
			double moyNO2 = 0;
			double moyPM10 = 0;

			int cptO3 = 0;
			int cptSO2 = 0;
			int cptNO2 = 0;
			int cptPM10 = 0;

			collectionMesures::iterator it2;
			for (it2 = mesures.begin(); it2 != mesures.end(); it2++)
			{

				string type = it2->getTypeMesure().getAttributeId();
				double valeur = it2->getValeur();
				if (type == "O3") {
					moyO3 += valeur;
					cptO3++;
				}
				else if (type == "SO2") {
					moySO2 += valeur;
					cptSO2++;
				}
				else if (type == "NO2") {
					moyNO2 += valeur;
					cptNO2++;
				}
				else if (type == "PM10") {
					moyPM10 += valeur;
					cptPM10++;
				}
			}

			paireMoyMesures paire;
			paire = paireMoyMesures("O3", moyO3 / cptO3);
			moyMesures.insert(paire);
			paire = paireMoyMesures("SO2", moySO2 / cptSO2);
			moyMesures.insert(paire);
			paire = paireMoyMesures("NO2", moyNO2 / cptNO2);
			moyMesures.insert(paire);
			paire = paireMoyMesures("PM10", moyPM10 / cptPM10);
			moyMesures.insert(paire);

			int indice = qualiteAir(moyMesures);
			if (indice > 0) {
				//score: capteurs accoci¨¦s
				if (capteursIdentiques.find(indice) != capteursIdentiques.end()) {
					capteursIdentiques[indice].push_back(*it);
				}
				else {
					collectionCapteurs c;
					c.push_back(*it);
					capteursIdentiques.insert(make_pair(indice, c));
				}
			}
		}
		
	}

	return capteursIdentiques;
}

collectionCapteurs Analyse::dysfonctionnement(Date & horodateDeb, Date & horodateFin)
{
	collectionCapteurs capteursDysf;

	collectionCapteurs capteurs;

	capteurs = TraitementD.ParcoursCapteurs();

	if (capteurs.size() == 0) {
		MenuInstance.AffichageSortieErreur("Pas de capteurs");
		return capteursDysf;
	}

	collectionCapteurs::iterator it;

	bool dysf; //indique si le capteur dysfonctionne

	//pour chaque capteur
	for (it = capteurs.begin(); it != capteurs.end(); ++it)
	{
		dysf = false;

		collectionCapteurs capteur;
		capteur.push_back(*it);

		collectionMesures mesures;
		mesures = TraitementD.ParcoursMesures(capteur, horodateDeb, horodateFin);

		conteneurMoyMesures moyMesures;

		//on parcourt toutes les mesures d'un capteur puis on vérifie :
		collectionMesures::iterator it2;
		
		/*
		valeurs predefinies pour > 12 h
		*/
		string types[] = { "O3","SO2","NO2","PM10" };
		//dernier moment o¨´ il y a un changement de valeurs pour 4 diff¨¦rents types
		Date lastChanges[] = { horodateDeb ,horodateDeb,horodateDeb,horodateDeb};
		double lastValeurs [] = {-1,-1,-1,-1};
		
		/*
		valeurs predefinies pour frequence 
		*/
		Date lastMoment = horodateDeb;


		for (it2 = mesures.begin(); it2 != mesures.end(); ++it2)
		{
			//si il y a une valeur négative

			if (it2->getValeur() < 0)
			{
				dysf = true;
				//MenuInstance.AffichageSortieErreur("valeur négative");

				break;
			}
			//si il y a des valeurs trop grandes (>=5000)

			if (it2->getValeur() > 5000)
			{
				dysf = true;
				//MenuInstance.AffichageSortieErreur(" valeurs trop grandes (>=5000)");
				break;
			}
			//si la fr¨¦quence de prise de mesures n'est pas respectée
			if (distance(mesures.begin(), it2) == 0) {
				//initialisation
				lastMoment = it2->getDate();
			}
			else {
				if (it2->getDate().getAnnee() != lastMoment.getAnnee()) {
					dysf = true;
					//MenuInstance.AffichageSortieErreur(" fr¨¦quence de prise de mesures annee");
					break;
				}
				else if (it2->getDate().getMois() != lastMoment.getMois()) {
					dysf = true;
					//MenuInstance.AffichageSortieErreur(" fr¨¦quence de prise de mesures mois");
					break;
				}
				else if (it2->getDate().getJour() != lastMoment.getJour()) {
					dysf = true;
					//MenuInstance.AffichageSortieErreur(" fr¨¦quence de prise de mesures jour");
					break;
				}
				else if (it2->getDate().getHeure() != lastMoment.getHeure()) {
					if (abs(it2->getDate().getHeure() - lastMoment.getHeure()) > 1) {
						dysf = true;
						//MenuInstance.AffichageSortieErreur(" fr¨¦quence de prise de mesures heure");
						break;
					}


					// si ses mesures restent constantes dans le temps sur une période trop longue (>12h)
					// selon les different types
					for (int i = 0; i < 4; i++) {
						if (it2->getTypeMesure().getAttributeId() == types[0]) {
							if (it2->getValeur() != lastValeurs[i]) {
								if (it2->getDate().getAnnee() != lastChanges[i].getAnnee()) {
									dysf = true;
									//MenuInstance.AffichageSortieErreur("mesures restent constantes");
									break;
								}
								else if (it2->getDate().getMois() != lastChanges[i].getMois()) {
									dysf = true;
									//MenuInstance.AffichageSortieErreur("mesures restent constantes");
									break;
								}
								else if (it2->getDate().getJour() != lastChanges[i].getJour()) {
									if (abs(it2->getDate().getJour() > -lastChanges[i].getJour()) > 1) {
										dysf = true;
										//MenuInstance.AffichageSortieErreur("mesures restent constantes");
										break;
									}
									else if ((it2->getDate().getJour() - lastChanges[i].getJour())*(it2->getDate().getHeure() - lastChanges[i].getHeure()) > -12)
									{
										dysf = true;
										//MenuInstance.AffichageSortieErreur("mesures restent constantes");
										break;
									}
								}
								else
									//m¨ºme jour
								{
									if (abs(it2->getDate().getHeure() - lastChanges[i].getHeure()) > 12) {
										dysf = true;
										//MenuInstance.AffichageSortieErreur("mesures restent constantes");
										break;
									}
								}
								lastValeurs[i] = it2->getValeur();
								lastChanges[i] = it2->getDate();
							}
						}
					}
				}
				lastMoment = it2->getDate();
			}
		}
			
			
		

		if (dysf)
		{
			capteursDysf.push_back(*it);
		}

	}


	return capteursDysf;
}

conteneurMoyMesures Analyse::caracteristiquesPoint(double lat, double longi, Date & horodateDeb, Date & horodateFin)
{	
	conteneurMoyMesures moyMesures;
	collectionCapteurs capteurs;
	capteurs = TraitementD.ParcoursCapteurs(lat, longi);
	//on a que des capteurs dont distance < 10km
	if (capteurs.size() == 0) {
		MenuInstance.AffichageSortieErreur("Pas de capteurs sur cette zone");
		return moyMesures;
	}

	double moyO3total = 0;
	double moySO2total = 0;
	double moyNO2total = 0;
	double moyPM10total = 0;

	double sommecoef = 0;


	collectionCapteurs::iterator it;
	for (it = capteurs.begin(); it != capteurs.end(); it++)
	{
		collectionCapteurs capteur;
		capteur.push_back(*it);

		collectionMesures mesures;
		mesures = TraitementD.ParcoursMesures(capteur, horodateDeb, horodateFin);

		if (mesures.size() != 0) {

			double moyO3 = 0;
			double moySO2 = 0;
			double moyNO2 = 0;
			double moyPM10 = 0;

			int cptO3 = 0;
			int cptSO2 = 0;
			int cptNO2 = 0;
			int cptPM10 = 0;

			collectionMesures::iterator it2;
			for (it2 = mesures.begin(); it2 != mesures.end(); it2++)
			{

				string type = it2->getTypeMesure().getAttributeId();
				double valeur = it2->getValeur();
				if (type == "O3") {
					moyO3 += valeur;
					cptO3++;
				}
				else if (type == "SO2") {
					moySO2 += valeur;
					cptSO2++;
				}
				else if (type == "NO2") {
					moyNO2 += valeur;
					cptNO2++;
				}
				else if (type == "PM10") {
					moyPM10 += valeur;
					cptPM10++;
				}
			}


			CoordonneesGPS c;
			// calcul distance

			double latCapteur = (*it).getLat();
			double longiCapteur = (*it).getLong();
			double dist = c.distanceEnKmEntreDeuxPoints(latCapteur, longiCapteur, lat, longi);

			double coef = 10.0 - dist;

			sommecoef += coef;

			moyO3total += coef * moyO3 / cptO3;
			moySO2total += coef * moySO2 / cptSO2;
			moyNO2total += coef * moyNO2 / cptNO2;
			moyPM10total += coef * moyPM10 / cptPM10;
		}
	}

	if (sommecoef == 0)
	{
		return moyMesures;
	}

	paireMoyMesures paire;
	paire = paireMoyMesures("O3", moyO3total / sommecoef);
	moyMesures.insert(paire);
	paire = paireMoyMesures("SO2", moySO2total / sommecoef);
	moyMesures.insert(paire);
	paire = paireMoyMesures("NO2", moyNO2total / sommecoef);
	moyMesures.insert(paire);
	paire = paireMoyMesures("PM10", moyPM10total / sommecoef);
	moyMesures.insert(paire);

	return moyMesures;
}

int Analyse::qualiteAir(conteneurMoyMesures & MoyMesures)
{
	if (MoyMesures.size() == 0) {
		return -1;
	}

	int indice = -1;
	string types[4] = { "O3", "SO2", "NO2", "PM10" };
	int atmo[4][9] = { {30,55,80,105,130,150,180,210,240}, {40,80,120,160,200,250,300,400,500}, {30,55,85,110,135,165,200,275,400}, {7,14,21,28,35,42,50,65,80} };
	for (int i = 0; i < 4; i++) {
		//ajouter un if pour ¨¦viter il y a un type qui existe pas dans l'ensemble types
		auto it=MoyMesures.find(types[i]);
		if (it != MoyMesures.end()) {
			double valeur = it->second;
			if (valeur < 0)
			{
				return -1; // erreur 
			}
			for (int j = 0; j < 9; j++) {
				if (valeur < atmo[i][j] && indice <= j + 1)
				{
					indice = j + 1;
					break;
				}
			}
			if (valeur > atmo[i][8] && indice < 10)
			{
				indice = 10;
			}
		}
	}
	return indice;
}

//-------------------------------------------- Constructeurs - destructeur

Analyse::Analyse()
{
}



//------------------------------------------------- Surcharge d'opérateurs


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
