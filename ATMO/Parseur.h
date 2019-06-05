/*************************************************************************
Parseur  -  description
-------------------
début                : 07/05/2019
copyright            : (C) 2019 par Mengxing ZHANG, Louis UNG, Fabien GELUS et Baptiste PAULETTO
*************************************************************************/

//---------- Interface de la classe <Parseur> (fichier Parseur.h) ------
#ifndef _Parseur_H
#define _Parseur_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
using namespace std;
#include <list>


//------------------------------------------------------------- Constantes 
#define ParseurInstance Parseur::GetInstance()

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Parseur>
// Le rôle de la classe Parseur est de permettre  à la partie Modèle d'obtenir
// les informations entrées par l'utilisateur dans le menu en mode commande.
// Pour cela il utilise une méthode principale qui va factoriser toutes ces 
// informations. Il est implémenté sous la forme d'un Singleton afin
// d'empêcher de multiples instancions de ce dernier.
//------------------------------------------------------------------------ 
class Parseur
{
	//----------------------------------------------------------------- PUBLIC
public:

	static Parseur & GetInstance()
	{
		static Parseur instance;
		return instance;
	}
	//----------------------------------------------------- Méthodes publiques

	vector<string> ParserCommande(string & entree);
	// Mode d'emploi :
	//  Cette fonction renvoie une suite de valeurs commençant par le code de 
	//  la commande suivie de toutes ses options et paramètres.
	//  C'est la fonction essentielle du parseur et elle réalisera ce travail
	//  sur la chaîne de caractères passée en paramètre.
	//  string & entree : Cette chaîne de caractère est celle tapée par 
	//  l'utilisateur dans le menu.
	//  Elle est notamment utilisées dans le main avant d'exécuter la dite fonction.
	// Contrat : Aucun
	//

	//------------------------------------------------- Surcharge d'opérateurs
	Parseur & operator = (const Parseur & unParseur);
	// Mode d'emploi :
	// RAS
	// Contrat : Aucun
	//
	//-------------------------------------------- Constructeurs - destructeur


	virtual ~Parseur();
	// Mode d'emploi : RAS, contenu vide
	//
	// Contrat : Aucun
	//

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Attributs protégés

	//----------------------------------------------------- Méthodes protégées

private:
	Parseur(const Parseur & unParseur);
	// Mode d'emploi (constructeur de copie) :
	// RAS
	// Contrat : Aucun
	//

	Parseur();
	// Mode d'emploi :
	// Constructeur par défaut de la classe Parseur
	// Contrat :
	//
	//------------------------------------------------------- Attributs privés

	//------------------------------------------------------- Méthodes privées
	bool AttributionCommande(string & commande);
	// Mode d'emploi : Cette méthode permet de faire des vérifications quant ?
	// la validit?de la commande tapée par l'utilisateur
	// string & commande : nom de la commande tapée par l'utilisateur.
	// Contrat : Aucun
	//

	bool AttributionOption(string & option);
	// Mode d'emploi : Cette méthode permet de faire des vérifications quant ?
	// la validit?de l'option tapée par l'utilisateur 
	// string & option : nom de l'option tapée par l'utilisateur.
	// Contrat : Aucun
	//

	unsigned NombreDeParametresCommande(string commande);
	// Mode d'emploi : Cette méthode permet de savoir le nombre de paramètres
	// dont dispose une commande et donc combien d'attributs nous sommes 
	// supposés attendre (utilisée pour la gestion d'erreurs).
	// string & commande : nom de la commande tapée par l'utilisateur.
	// Contrat : Aucun
	//

	bool PossedeDesOptionsCommande(string & commande);
	// Mode d'emploi : Cette méthode permet de savoir si la commande
	// passée en paramètre admet des options ou non.
	// string & commande : nom de la commande tapée par l'utilisateur.
	// Contrat : Aucun
	//

	bool verificationParametre(string & parametre);
	// Mode d'emploi : Cette méthode est uniquement destinée ?la 
	// gestion des erreurs, pour un paramètre donn? elle vérifie qu'il
	// n'est pas vide et adapte un comportement en conséquence.
	// string & parametre : paramètre tap?par l'utilisateur.
	// Contrat : Aucun
	//

};

//----------------------------------------- Types dépendants de <Parseur>

#endif //_Parseur_H