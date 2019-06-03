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
#include <vector>
#include "TypeMesure.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <TypeMesure>
// Classe pour gérer l'objet TypeMesure
//
//------------------------------------------------------------------------ 
class TypeMesure
{
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- Méthodes publiques

	string getAttributeId() const;
	wstring getUnite() const;
	string getDescription() const;
	void afficher() const;

	//------------------------------------------------- Surcharge d'opérateurs
	TypeMesure & operator = (const TypeMesure & unTypeMesure);
	// Mode d'emploi :
	// RAS
	// Contrat : Aucun
	//

	friend ostream & operator << (ostream &out, const TypeMesure &typemesure);

	
	//-------------------------------------------- Constructeurs - destructeur
	TypeMesure(const TypeMesure & unTypeMesure);
	// Mode d'emploi (constructeur de copie) :
	// RAS
	// Contrat : Aucun
	//

	TypeMesure(string attributeID, wstring unite, string description);
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
	wstring unite;
	string description;

	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes privées

	//----------------------------------------------------------- Types privés
};

//----------------------------------------- Types dépendants de <TypeMesure>
typedef vector<TypeMesure> collectionTypesMesure;

#endif //_TypeMesure_H
