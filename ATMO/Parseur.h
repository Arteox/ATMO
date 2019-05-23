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

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Parseur>
// Le rôle de la classe Parseur est de permettre à la partie Modèle d'obtenir
// les informations entrées par l'utilisateur dans le menu en mode commande.
// Pour cela il utilise une méthode principale qui va factoriser toutes ces 
// informations.
//------------------------------------------------------------------------ 
class Parseur
{
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- Méthodes publiques

	list<double> ParserCommande();
	// Mode d'emploi :
	//  Cette fonction renvoie une suite de valeurs commençant par le code de 
	//  la commande suivie de toutes ses options et paramètres.
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
	//------------------------------------------------------- Attributs privés

	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes privées

	//----------------------------------------------------------- Types privés

	//------------------------------------------------------- Méthodes privées
};

//----------------------------------------- Types dépendants de <Parseur>

#endif //_Parseur_H

