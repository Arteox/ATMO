/*************************************************************************
Menu  -  description
-------------------
d�but                : ${date}
copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <Menu> (fichier Menu.h) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <iostream>
#include <string>
#include <list>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Menu.h"



//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques

void Menu::AffichageSortieStandard(string & sortieFonction) const {
	sortieStandard << sortieFonction << endl;
}

void Menu::AffichageSortieErreur(string & sortieFonction) const {
	sortieErreur << sortieFonction << endl;
}

void Menu::InitialiserMenu() const {
	sortieStandard << "Bienvenue sur ATMO ! " << endl
	 << " Les commandes dont vous disposez sont :" << endl
	 << " qm : Pour connaitre la qualite moyenne de l'air " << endl
	 << " sim : Afin de trouver des zones ayant des caract�ristiques similaires " << endl
	 << " dysfonc : Afin d'essayer de rep�rer les capteurs qui sont en dysfonctionnement " << endl
	 << " carac : Pour conna�tre les caract�ristiques sp�cifiques d'une point pr�cis " << endl
	 << " help : pour obtenir plus d'informations sur les parametres des commandes " << endl;
}

void Menu::AfficherAide() const {
	sortieStandard << "Commandes d�taill�es :" << endl
		<< " Qualite moyenne : qm [-d] 'lat' 'long' 'rayon' 'horodateDeb' 'horodateFin'" << endl
		<< " Capteurs similaires : sim 'horodateDeb' 'horodateFin'" << endl
		<< " Capteurs dysfonctionnants : dysfonc 'horodateDeb' 'horodateFin'" << endl
		<< " Valeurs caract�ristiques d'un point : carac 'long' 'lat' 'horodateDeb' 'horodateFin' " << endl << endl
		<< " Entrez les dates sous le format suivant : annee-mois-jourTheure:minute:seconde " << endl
		<< " et sans oublier les 0 pour le mois, le jour et l'heure, par exemple : 2017-01-01T00:01:20 " << endl;
}

string Menu::RecupererEntreeUtilisateur() {
	string entreeUtilisateur;
	cin >> entreeUtilisateur;
	return entreeUtilisateur;
}

void Menu::FormaterAffichageCaracteristiques(int & scoreAtmo, conteneurMoyMesures & retourFonction)
{
	sortieStandard << "Atmo Score " << scoreAtmo << DescriptionValeur(scoreAtmo)
	<< ", valeurs moyennes utilis�es :" << endl;
	for( auto it : retourFonction){
		sortieStandard << it->first << ";" << it->second << endl;
	}

}

void Menu::FormaterAffichageSimilaires(doubleCollectionCapteurs & retourFonction)
{
	for(auto it : retourFonction){
		sortieStandard << "Atmo Score " << distance(it, retourFonction.begin()) <<
		DescriptionValeur(distance(it, retourFonction.begin())) << " :" << endl;
		for(auto itFils : *it){
			sortieStandard << *itFils << endl;
		}
	}
}

void Menu::FormaterAffichageDysfonctionnement(collectionCapteurs & retourFonction)
{
	if(collectionCapteurs.empty()){
		sortieStandard << "Aucun capteur en dysfonctionnement dans cet intervalle" << endl;
	} else {
		sortieStandard << "Capteurs consid�r�s comme en dysfonctionnement :" <<endl;
		for(auto it : retourFonction){
			sortieStandard << *it << endl; //affichage de la raison dans une future version.
		}
	}
	
}

void Menu::FormaterAffichageQualite(int & scoreAtmo, conteneurMoyMesures & retourFonction) 
{
	sortieStandard << "Atmo Score : " << scoreAtmo <<
	DescriptionValeur(scoreAtmo) << endl;
	if(retourFonction.empty()){
		return;
	} else {
		for( auto it : retourFonction){
			sortieStandard << it->first << ";" << it->second << endl;
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


//------------------------------------------------- Surcharge d'op�rateurs


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es

 string DescriptionValeur(int & scoreAtmo){
 	string descriptionValeur;
 	switch(scoreAtmo) {
 		case 1 :
 			descriptionValeur = "(Tr�s bon)";
 			break;
 		case 2 :
 			descriptionValeur = "(Tr�s bon)";
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
 			descriptionValeur = "(M�diocre)";
 			break; 		
  		case 7 :
 			descriptionValeur = "(M�diocre)";
 			break;
  		case 8 :
 			descriptionValeur = "(Mauvais)";
 			break; 
  		case 9 :
 			descriptionValeur = "(Mauvais)";
 			break;
   		case 10 :
 			descriptionValeur = "(Tr�s mauvais)";
 			break;	 	 				 					
 	}
 	return descriptionValeur;
 }


