/*************************************************************************
Mesure  -  description
-------------------
d�but                : 07/05/2019
copyright            : (C) 2019 par Mengxing ZHANG, Louis UNG, Fabien GELUS et Baptiste PAULETTO
*************************************************************************/

//---------- Interface de la classe <Mesure> (fichier Mesure.h) ------
#ifndef _Mesure_H
#define _Mesure_H

//--------------------------------------------------- Interfaces utilis�es
#include <string>
#include "Date.h"
#include "Mesure.h"
#include "TypeMesure.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <Mesure>
//
//
//------------------------------------------------------------------------ 
class Mesure
{
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- M�thodes publiques

	//------------------------------------------------- Surcharge d'op�rateurs
	Mesure & operator = (const Mesure & unMesure);
	// Mode d'emploi :
	// RAS
	// Contrat : Aucun
	//
	//-------------------------------------------- Constructeurs - destructeur
	Mesure(const Mesure & unMesure);
	// Mode d'emploi (constructeur de copie) :
	// RAS
	// Contrat : Aucun
	//

	Mesure();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Mesure();
	// Mode d'emploi : RAS, contenu vide
	//
	// Contrat : Aucun
	//

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- M�thodes prot�g�es

private:
	//------------------------------------------------------- M�thodes priv�es

protected:
	//----------------------------------------------------- Attributs prot�g�s

private:
	//------------------------------------------------------- Attributs priv�s
	Date horodate;
	double value;
	TypeMesure typeMesure;
	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes priv�es

	//----------------------------------------------------------- Types priv�s
};

//----------------------------------------- Types d�pendants de <Mesure>

#endif //_Mesure_H
