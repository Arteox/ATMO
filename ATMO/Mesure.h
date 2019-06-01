/*************************************************************************
Mesure  -  description
-------------------
début                : 07/05/2019
copyright            : (C) 2019 par Mengxing ZHANG, Louis UNG, Fabien GELUS et Baptiste PAULETTO
*************************************************************************/

//---------- Interface de la classe <Mesure> (fichier Mesure.h) ------
#ifndef _Mesure_H
#define _Mesure_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <set>
#include "Date.h"
#include "Mesure.h"
#include "TypeMesure.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Mesure>
// Classe pour gérer l'objet mesure
//
//------------------------------------------------------------------------ 
class Mesure
{
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- Méthodes publiques

	Date getDate() const;
	double getValeur() const;
	TypeMesure getTypeMesure() const;
	int getSensorID() const;


	//------------------------------------------------- Surcharge d'opérateurs
	bool operator < (const Mesure & unMesure);

	Mesure & operator = (const Mesure & unMesure);
	// Mode d'emploi :
	// RAS
	// Contrat : Aucun
	//

	friend ostream & operator << (ostream &out, const Mesure &mesure);
	//-------------------------------------------- Constructeurs - destructeur
	Mesure(const Mesure & unMesure);
	// Mode d'emploi (constructeur de copie) :
	// RAS
	// Contrat : Aucun
	//

	Mesure(Date horodate, double valeur, TypeMesure typeMesure, int sensorID);
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
	//----------------------------------------------------- Méthodes protégées

private:
	//------------------------------------------------------- Méthodes privées

protected:
	//----------------------------------------------------- Attributs protégés

private:
	//------------------------------------------------------- Attributs privés
	Date horodate;
	double valeur;
	TypeMesure typeMesure;
	int sensorID;
	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes privées

	//----------------------------------------------------------- Types privés
};

//----------------------------------------- Types dépendants de <Mesure>
struct compareMesure {
	bool operator()(const Mesure &mesureGauche, const Mesure &mesureDroite) {
		return mesureGauche.getDate() < mesureDroite.getDate();
	}
};
typedef multiset<Mesure, compareMesure> collectionMesures;

#endif //_Mesure_H
