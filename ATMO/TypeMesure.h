/*************************************************************************
TypeMesure  -  description
-------------------
d�but                : 07/05/2019
copyright            : (C) 2019 par Mengxing ZHANG, Louis UNG, Fabien GELUS et Baptiste PAULETTO
*************************************************************************/

//---------- Interface de la classe <TypeMesure> (fichier TypeMesure.h) ------
#ifndef _TypeMesure_H
#define _TypeMesure_H

//--------------------------------------------------- Interfaces utilis�es
#include <string>
#include <vector>
#include "TypeMesure.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <TypeMesure>
// Classe pour g�rer l'objet TypeMesure
//
//------------------------------------------------------------------------ 
class TypeMesure
{
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- M�thodes publiques

	string getAttributeId() const;
	wstring getUnite() const;
	string getDescription() const;
	void afficher() const;

	//------------------------------------------------- Surcharge d'op�rateurs
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
	//----------------------------------------------------- M�thodes prot�g�es

private:
	//------------------------------------------------------- M�thodes priv�es

protected:
	//----------------------------------------------------- Attributs prot�g�s

private:
	//------------------------------------------------------- Attributs priv�s
	string attributeID;
	wstring unite;
	string description;

	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes priv�es

	//----------------------------------------------------------- Types priv�s
};

//----------------------------------------- Types d�pendants de <TypeMesure>
typedef vector<TypeMesure> collectionTypesMesure;

#endif //_TypeMesure_H
