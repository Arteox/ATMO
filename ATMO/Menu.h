/*************************************************************************
Menu  -  description
-------------------
d�but                : 07/05/2019
copyright            : (C) 2019 par Mengxing ZHANG, Louis UNG, Fabien GELUS et Baptiste PAULETTO
*************************************************************************/

//---------- Interface de la classe <Menu> (fichier Menu.h) ------
#ifndef _MENU_H
#define _MENU_H

//--------------------------------------------------- Interfaces utilis�es
#include <string>
//------------------------------------------------------------- Constantes
#define ParseurInstance Parseur::GetInstance()
#define sortieStandard cout // constantes pouvant �tre modifi�e � l'avenir.
#define sortieErreur cerr // si l'on souhaite travailler dans un fichier par ex.
//------------------------------------------------------------------ Types 
//------------------------------------------------------------------------ 
// R�le de la classe <Menu>
// Le r�le de la classe Menu est de donner l'aspect visuel � toutes les
// interactions avec l'utilisateur, on retrouve donc notamment, l'affichage
// et la saisie de commande qui sera alors par la suite pars�e. 
// Elle constitue une partie essentielle de la partie Vue du projet.
//------------------------------------------------------------------------ 
class Menu
{
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- M�thodes publiques
	void AffichageSortieStandard(string & sortieFonction) const;
	// Mode d'emploi : Cette m�thode permet au main de g�rer la partie vue en
	// affichant � l'�cran l'information pass� en param�tre � la m�thode.
	// string & ligne : c'est cette cha�ne de caract�re qui sera affich�e sur la 
	// sortie standard.
	// Contrat : Aucun
	//

	void AffichageSortieErreur(string & sortieFonction) const;
	// Mode d'emploi : Cette m�thode permet au main de g�rer la partie vue en
	// affichant � l'�cran des messages d'erreur, en effet, la ligne pass�e en 
	// param�tre sera envoy�e sur la sortie d'erreur.
	// string & ligne : c'est cette cha�ne de caract�re qui sera affich�e sur la 
	// sortie standard.
	// Contrat : Aucun
	//

	void AfficherAide() const;
	// Mode d'emploi : Cette m�thode permet d'afficher sur la sortie standard
	// l'aide contenant les commandes ainsi que leurs param�tres et,
	// si elles en ont, leurs options.
	// Contrat : Aucun
	//

	void InitialiserMenu() const;
	// Mode d'emploi : Cette m�thodea pour simple objectif d'afficher sur la sortie 
	// standard, le message d'accueil d'un utilisateur et de lui expliquer bri�vement
	// comment utiliser l'application ATMO.
	// Contrat : Aucun
	//

	string RecupererEntreeUtilisateur();
	// Mode d'emploi : Cette m�thode renvoie sous la forme d'une cha�ne de caract�res,
	// ce qui a �t� tap� par l'utilisateur, afin de permettre de parser la commande, 
	// puis d'agir en cons�quence.
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
	//----------------------------------------------------- Attributs prot�g�s

	//----------------------------------------------------- M�thodes prot�g�es


private:
	//------------------------------------------------------- Attributs priv�s

	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes priv�es

	//----------------------------------------------------------- Types priv�s
};

//----------------------------------------- Types d�pendants de <Menu>

#endif _MENU_H