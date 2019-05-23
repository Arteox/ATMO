/*************************************************************************
TypeMesure  -  description
-------------------
début                : 07/05/2019
copyright            : (C) 2019 par Mengxing ZHANG, Louis UNG, Fabien GELUS et Baptiste PAULETTO
*************************************************************************/

//---------- Interface de la classe <TypeMesure> (fichier TypeMesure.h) ------
#ifndef _TypeMesure_H
#define _TypeMesure_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "TypeMesure.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <TypeMesure>
//
//
//------------------------------------------------------------------------ 
class TypeMesure
{
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- Méthodes publiques

	string getAttributeId() const;
	string getUnite() const;
	string getDescription() const;

	//------------------------------------------------- Surcharge d'opérateurs
	TypeMesure & operator = (const TypeMesure & unTypeMesure);
	// Mode d'emploi :
	// RAS
	// Contrat : Aucun
	//
	//-------------------------------------------- Constructeurs - destructeur
	TypeMesure(const TypeMesure & unTypeMesure);
	// Mode d'emploi (constructeur de copie) :
	// RAS
	// Contrat : Aucun
	//

	TypeMesure(string attributeID, string unite, string description);
	// Mode d'emploi :
	//
	// Contrat :
	//

	TypeMesure();

	virtual ~TypeMesure();
	// Mode d'emploi : RAS, contenu vide
	//
	// Contrat : Aucun
	//

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées

private:
	//------------------------------------------------------- Méthodes privées

protected:
	//----------------------------------------------------- Attributs protégés

private:
	//------------------------------------------------------- Attributs privés
	string attributeID;
	string unite;
	string description;

	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes privées

	//----------------------------------------------------------- Types privés
};

//----------------------------------------- Types dépendants de <TypeMesure>

#endif //_TypeMesure_H
