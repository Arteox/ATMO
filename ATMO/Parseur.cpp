/*************************************************************************
Parseur  -  description
-------------------
d�but                : ${date}
copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <Parseur> (fichier Parseur.h) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <iostream>
#include <list>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Parseur.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques

list<double> Parseur::ParserCommande()
{
	list<double> commande;
	return commande;
}

//------------------------------------------------- Surcharge d'op�rateurs
Parseur & Parseur::operator=(const Parseur & unParseur) {
	return *this;
}


//-------------------------------------------- Constructeurs - destructeur

Parseur::Parseur(const Parseur & unParseur)
{
}

Parseur::Parseur()
{

}

Parseur::~Parseur()
{
}


//------------------------------------------------- Surcharge d'op�rateurs


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es


