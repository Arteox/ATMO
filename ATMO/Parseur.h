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
#define ParseurInstance Parseur::GetInstance()

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <Parseur>
// Le r�le de la classe Parseur est de permettre  � la partie Mod�le d'obtenir
// les informations entr�es par l'utilisateur dans le menu en mode commande.
// Pour cela il utilise une m�thode principale qui va factoriser toutes ces 
// informations. Il est impl�ment� sous la forme d'un Singleton afin
// d'emp�cher de multiples instancions de ce dernier.
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
	//----------------------------------------------------- M�thodes publiques

	vector<string> ParserCommande(string & entree);
	// Mode d'emploi :
	//  Cette fonction renvoie une suite de valeurs commen�ant par le code de 
	//  la commande suivie de toutes ses options et param�tres.
	//  C'est la fonction essentielle du parseur et elle r�alisera ce travail
	//  sur la cha�ne de caract�res pass�e en param�tre.
	//  string & entree : Cette cha�ne de caract�re est celle tap�e par 
	//  l'utilisateur dans le menu.
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
	//------------------------------------------------------- Attributs priv�s

	//------------------------------------------------------- M�thodes priv�es
	bool AttributionCommande(string & commande);
	// Mode d'emploi : Cette m�thode permet de faire des v�rifications quant ?
	// la validit?de la commande tap�e par l'utilisateur
	// string & commande : nom de la commande tap�e par l'utilisateur.
	// Contrat : Aucun
	//

	bool AttributionOption(string & option);
	// Mode d'emploi : Cette m�thode permet de faire des v�rifications quant ?
	// la validit?de l'option tap�e par l'utilisateur 
	// string & option : nom de l'option tap�e par l'utilisateur.
	// Contrat : Aucun
	//

	unsigned NombreDeParametresCommande(string commande);
	// Mode d'emploi : Cette m�thode permet de savoir le nombre de param�tres
	// dont dispose une commande et donc combien d'attributs nous sommes 
	// suppos�s attendre (utilis�e pour la gestion d'erreurs).
	// string & commande : nom de la commande tap�e par l'utilisateur.
	// Contrat : Aucun
	//

	bool PossedeDesOptionsCommande(string & commande);
	// Mode d'emploi : Cette m�thode permet de savoir si la commande
	// pass�e en param�tre admet des options ou non.
	// string & commande : nom de la commande tap�e par l'utilisateur.
	// Contrat : Aucun
	//

	bool verificationParametre(string & parametre);
	// Mode d'emploi : Cette m�thode est uniquement destin�e ?la 
	// gestion des erreurs, pour un param�tre donn? elle v�rifie qu'il
	// n'est pas vide et adapte un comportement en cons�quence.
	// string & parametre : param�tre tap?par l'utilisateur.
	// Contrat : Aucun
	//

};

//----------------------------------------- Types d�pendants de <Parseur>

#endif //_Parseur_H