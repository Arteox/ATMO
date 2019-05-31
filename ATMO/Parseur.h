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
enum Commandes {qm, sim, dysfonc, carac, help, commandeInvalide = -1};
enum Options { d, optionAbsente = -2, optionInvalide = -1 };
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

	//------------------------------------------------------- M�thodes priv�es
	double AttributionCommande(string & commande);
	// Mode d'emploi : Cette m�thode permet de faire des v�rifications quant �
	// la validit� de la commande tap�e par l'utilisateur ainsi que d'attribuer
	// cette derni�re sa valeur num�rique pour qu'elle puisse ensuite 
	// �tre utilis�e par le syst�me.
	// string & commande : nom de la commande tap�e par l'utilisateur.
	// Contrat : Aucun
	//

	double AttributionOption(string & option);
	// Mode d'emploi : Cette m�thode permet de faire des v�rifications quant �
	// la validit� de l'option tap�e par l'utilisateur ainsi que d'attribuer
	// cette derni�re sa valeur num�rique pour qu'elle puisse ensuite 
	// �tre utilis�e par le syst�me.
	// string & option : nom de l'option tap�e par l'utilisateur.
	// Contrat : Aucun
	//

	unsigned NombreDeParametresCommande(string & commande);
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
	// Mode d'emploi : Cette m�thode est uniquement destin�e � la 
	// gestion des erreurs, pour un param�tre donn�, elle v�rifie qu'il
	// n'est pas vide et adapte un comportement en cons�quence.
	// string & parametre : param�tre tap� par l'utilisateur.
	// Contrat : Aucun
	//

	Commandes trouverCommande(string & commande);
	// Mode d'emploi : Cette m�thode est uniquement utlis�e dans la m�thode
	// AttributionCommande pour avoir un comportement des plus maintenables
	// possibles, elle permet simplement d'associer une des valeurs de l'�num
	// � sa valeur en cha�ne de caract�res.
	// Contrat : Aucun
	//

	Options trouverOption(string & option);
	// Mode d'emploi : Dans le m�me but que la pr�c�dente m�thode, cette m�thode
	// est uniquement utlis�e dans la m�thode AttributionOption pour avoir un
	// comportement des plus maintenables possibles, elle permet simplement 
	// d'associer une des valeurs de l'�num � sa valeur en cha�ne de caract�res.
	// Contrat : Aucun
	//
};

//----------------------------------------- Types d�pendants de <Parseur>

#endif //_Parseur_H

