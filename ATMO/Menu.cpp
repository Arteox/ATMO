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
using namespace std;

//------------------------------------------------------ Include personnel
#include "Menu.h"
#include <string>

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

void Menu::FormaterAffichageCaracteristiques(map<TypeMesure, double>& retourFonction)
{
}

void Menu::FormaterAffichageSimilaires(list<list<Capteur>>& retourFonction)
{
}

void Menu::FormaterAffichageDysfonctionnement(list<Capteur>& retourFonction)
{
}

void Menu::FormaterAffichageQualite(list<double>& retourFonction)
{
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


