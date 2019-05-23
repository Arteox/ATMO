/*************************************************************************
Parseur  -  description
-------------------
d�but                : 07/05/2019
copyright            : (C) 2019 par Mengxing ZHANG, Louis UNG, Fabien GELUS et Baptiste PAULETTO
*************************************************************************/

//---------- Interface de la classe <Parseur> (fichier Parseur.h) ------
#ifndef _Parseur_H
#define _Parseur_H

//--------------------------------------------------- Interfaces utilis�es
#include <string>
using namespace std;
#include <list>


//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <Parseur>
// Le r�le de la classe Parseur est de permettre � la partie Mod�le d'obtenir
// les informations entr�es par l'utilisateur dans le menu en mode commande.
// Pour cela il utilise une m�thode principale qui va factoriser toutes ces 
// informations.
//------------------------------------------------------------------------ 
class Parseur
{
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- M�thodes publiques

	list<double> ParserCommande();
	// Mode d'emploi :
	//  Cette fonction renvoie une suite de valeurs commen�ant par le code de 
	//  la commande suivie de toutes ses options et param�tres.
	//  Elle est notamment utilis�es dans le main avant d'ex�cuter la dite fonction.
	// Contrat : Aucun
	//

	//------------------------------------------------- Surcharge d'op�rateurs
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
	// Constructeur par d�faut de la classe Parseur
	// Contrat :
	//

	virtual ~Parseur();
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

	//------------------------------------------------------- M�thodes priv�es
};

//----------------------------------------- Types d�pendants de <Parseur>

#endif //_Parseur_H

