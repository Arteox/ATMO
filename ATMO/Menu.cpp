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
using namespace std;

//------------------------------------------------------ Include personnel
#include "Menu.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

void Menu::AffichageSortieStandard(string & ligne) const {
	sortieStandard << ligne << endl;
}

void Menu::AffichageSortieErreur(string & ligne) const {
	sortieErreur << ligne << endl;
}

void Menu::InitialiserMenu() const {
	sortieStandard << "Bienvenue sur ATMO ! " << endl
	 << " Les commandes dont vous disposez sont :" << endl
	 << " qm : Pour connaitre la qualite moyenne de l'air " << endl
	 << " sim : Afin de trouver des zones ayant des caractéristiques similaires " << endl
	 << " dysfonc : Afin d'essayer de repérer les capteurs qui sont en dysfonctionnement " << endl
	 << " carac : Pour connaître les caractéristiques spécifiques d'une point précis " << endl
	 << " help : pour obtenir plus d'informations sur les parametres des commandes " << endl;
}

void Menu::AfficherAide() const {
	sortieStandard << "Commandes détaillées :" << endl
	 << " Qualite moyenne : qm [-d] 'lat' 'long' 'rayon' 'horodateDeb' 'horodateFin'" << endl
	 << " Capteurs similaires : sim 'horodateDeb' 'horodateFin'" << endl
	 << " Capteurs dysfonctionnants : dysfonc 'horodateDeb' 'horodateFin'" << endl
	 << " Valeurs caractéristiques d'un point : carac 'long' 'lat' 'horodateDeb' 'horodateFin' " <<endl;

}

string & Menu::RecupererEntreeUtilisateur() {
	string entreeUtilisateur;
	cin >> entreeUtilisateur;
	return entreeUtilisateur;
}


//-------------------------------------------- Constructeurs - destructeur

Menu::Menu(const Menu & unMenu)
{
}

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


