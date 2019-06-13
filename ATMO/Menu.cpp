/*************************************************************************
Menu  -  description
-------------------
début                : ${date}
copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <Menu> (fichier Menu.h) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <list>
#include <iterator>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Menu.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

void Menu::AffichageSortieStandard(string sortieFonction) const {
	sortieStandard << sortieFonction << endl;
}

void Menu::AffichageSortieErreur(string sortieFonction) const {
	sortieErreur << sortieFonction << endl;
}

void Menu::InitialiserMenu() const {
	sortieStandard << "Bienvenue sur ATMO ! " << endl
	 << "Les commandes dont vous disposez sont :" << endl
	 << "qm : Pour connaitre la qualite moyenne de l'air " << endl
	 << "sim : Afin de trouver des zones ayant des caractéristiques similaires " << endl
	 << "dysfonc : Afin d'essayer de repérer les capteurs qui sont en dysfonctionnement " << endl
	 << "carac : Pour connaître les caractéristiques spécifiques d'une point précis " << endl
	 << "help : pour obtenir plus d'informations sur les parametres des commandes " << endl
	 << "quitter : pour obtenir plus d'informations sur les parametres des commandes " << endl;
}

void Menu::AfficherAide() const {
	sortieStandard << "Commandes détaillées :" << endl
		<< "  Qualite moyenne : qm [-d] 'lat' 'long' 'rayon' 'horodateDeb' 'horodateFin'" << endl
		<< "  Capteurs similaires : sim 'horodateDeb' 'horodateFin'" << endl
		<< "  Capteurs dysfonctionnants : dysfonc 'horodateDeb' 'horodateFin'" << endl
		<< "  Valeurs caractéristiques d'un point : carac 'long' 'lat' 'horodateDeb' 'horodateFin' " << endl << endl
		<< "  Entrez les dates sous le format suivant : annee-mois-jourTheure:minute:seconde " << endl
		<< "  et sans oublier les 0 pour le mois, le jour et l'heure, par exemple : 2017-01-01T00:01:20 " << endl;
}

string Menu::RecupererEntreeUtilisateur() {
	string entreeUtilisateur;
	getline(cin, entreeUtilisateur);
	return entreeUtilisateur;
}

void Menu::FormaterAffichageCaracteristiques(int & scoreAtmo, conteneurMoyMesures & retourFonction)
{
	sortieStandard << "Atmo Score " << scoreAtmo << DescriptionValeur(scoreAtmo)
	<< ", valeurs moyennes utilisées :" << endl;
	for (auto it = retourFonction.begin(); it != retourFonction.end(); ++it) {
		sortieStandard << it->first << ";" << it->second << endl;
	}

}

void Menu::FormaterAffichageSimilaires(conteneurIndiceCapteurs & retourFonction)
{
	for (auto it = retourFonction.begin(); it != retourFonction.end(); ++it) {
		int scoreAtmo = it->first;
		sortieStandard << "Atmo Score " << scoreAtmo << DescriptionValeur(scoreAtmo) << endl;
		collectionCapteurs vector_courant = it->second;
		for (auto itFils = vector_courant.begin(); itFils != vector_courant.end(); ++itFils) {
			sortieStandard << "Capteur" << itFils->getId() << endl;
		}
		sortieStandard << endl;
	}
}

void Menu::FormaterAffichageDysfonctionnement(collectionCapteurs & retourFonction)
{
	if(retourFonction.empty()){
		sortieStandard << "Aucun capteur en dysfonctionnement dans cet intervalle" << endl;
	} else {
		sortieStandard << "Capteurs considérés comme en dysfonctionnement :" <<endl;
		for(auto it = retourFonction.begin(); it != retourFonction.end(); ++it){
			sortieStandard << "Capteur" << it->getId() << endl; //affichage de la raison de dysfonctionnement dans une future version.
		}
		sortieStandard << endl;
	}
	
}

void Menu::FormaterAffichageQualite(int & scoreAtmo, conteneurMoyMesures & retourFonction, bool & option) 
{
	sortieStandard << "Atmo Score : " << scoreAtmo <<
	DescriptionValeur(scoreAtmo) << endl;
	if(retourFonction.empty()){
		return;
	} else {
		if (option) {
			for (auto it = retourFonction.begin(); it != retourFonction.end(); ++it) {
				sortieStandard << it->first << ";" << it->second << endl;
			}
		}

	}
}


//-------------------------------------------- Constructeurs - destructeur

Menu::Menu()
{

}

Menu::~Menu()
{
}


//------------------------------------------------- Surcharge d'opérateurs


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées

 string Menu::DescriptionValeur(int & scoreAtmo){
 	string descriptionValeur;
 	switch(scoreAtmo) {
 		case 1 :
 			descriptionValeur = "(Très bon)";
 			break;
 		case 2 :
 			descriptionValeur = "(Très bon)";
 			break;
 		case 3 :
 			descriptionValeur = "(Bon)";
 			break;
 		case 4 :
 			descriptionValeur = "(Bon)";
 			break;
 		case 5 :
 			descriptionValeur = "(Moyen)";
 			break;
 		case 6 :
 			descriptionValeur = "(Médiocre)";
 			break; 		
  		case 7 :
 			descriptionValeur = "(Médiocre)";
 			break;
  		case 8 :
 			descriptionValeur = "(Mauvais)";
 			break; 
  		case 9 :
 			descriptionValeur = "(Mauvais)";
 			break;
   		case 10 :
 			descriptionValeur = "(Très mauvais)";
 			break;	 	 				 					
 	}
 	return descriptionValeur;
 }


