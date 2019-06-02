/*************************************************************************
Menu  -  description
-------------------
début                : 07/05/2019
copyright            : (C) 2019 par Mengxing ZHANG, Louis UNG, Fabien GELUS et Baptiste PAULETTO
*************************************************************************/

//---------- Interface de la classe <Menu> (fichier Menu.h) ------
#ifndef _MENU_H
#define _MENU_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
//------------------------------------------------------------- Constantes
#define ParseurInstance Parseur::GetInstance()
#define sortieStandard cout // constantes pouvant être modifiée à l'avenir.
#define sortieErreur cerr // si l'on souhaite travailler dans un fichier par ex.
//------------------------------------------------------------------ Types 
//------------------------------------------------------------------------ 
// Rôle de la classe <Menu>
// Le rôle de la classe Menu est de donner l'aspect visuel à toutes les
// interactions avec l'utilisateur, on retrouve donc notamment, l'affichage
// et la saisie de commande qui sera alors par la suite parsée. 
// Elle constitue une partie essentielle de la partie Vue du projet.
//------------------------------------------------------------------------ 
class Menu
{
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- Méthodes publiques
	void AffichageSortieStandard(string & sortieFonction) const;
	// Mode d'emploi : Cette méthode permet au main de gérer la partie vue en
	// affichant à l'écran l'information passé en paramètre à la méthode.
	// string & ligne : c'est cette chaîne de caractère qui sera affichée sur la 
	// sortie standard.
	// Contrat : Aucun
	//

	void AffichageSortieErreur(string & sortieFonction) const;
	// Mode d'emploi : Cette méthode permet au main de gérer la partie vue en
	// affichant à l'écran des messages d'erreur, en effet, la ligne passée en 
	// paramètre sera envoyée sur la sortie d'erreur.
	// string & ligne : c'est cette chaîne de caractère qui sera affichée sur la 
	// sortie standard.
	// Contrat : Aucun
	//

	void AfficherAide() const;
	// Mode d'emploi : Cette méthode permet d'afficher sur la sortie standard
	// l'aide contenant les commandes ainsi que leurs paramètres et,
	// si elles en ont, leurs options.
	// Contrat : Aucun
	//

	void InitialiserMenu() const;
	// Mode d'emploi : Cette méthodea pour simple objectif d'afficher sur la sortie 
	// standard, le message d'accueil d'un utilisateur et de lui expliquer brièvement
	// comment utiliser l'application ATMO.
	// Contrat : Aucun
	//

	string RecupererEntreeUtilisateur();
	// Mode d'emploi : Cette méthode renvoie sous la forme d'une chaîne de caractères,
	// ce qui a été tapé par l'utilisateur, afin de permettre de parser la commande, 
	// puis d'agir en conséquence.
	// Contrat : Aucun
	//

	//-------------------------------------------- Constructeurs - destructeur
	Menu(const Menu & unMenu);
	// Mode d'emploi (constructeur de copie) :
	// RAS
	// Contrat : Aucun
	//

	Menu();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Menu();
	// Mode d'emploi : RAS, contenu vide
	//
	// Contrat : Aucun
	//
	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Attributs protégés

	//----------------------------------------------------- Méthodes protégées


private:
	//------------------------------------------------------- Attributs privés

	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes privées

	//----------------------------------------------------------- Types privés
};

//----------------------------------------- Types dépendants de <Menu>

#endif _MENU_H