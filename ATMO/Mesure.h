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
#include <set>
#include "Date.h"
#include "Mesure.h"
#include "TypeMesure.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <Mesure>
// Classe pour g�rer l'objet mesure
//
//------------------------------------------------------------------------ 
class Mesure
{
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- M�thodes publiques

	Date getDate() const;
	double getValeur() const;
	TypeMesure getTypeMesure() const;
	int getSensorID() const;


	//------------------------------------------------- Surcharge d'op�rateurs
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
	//----------------------------------------------------- M�thodes prot�g�es

private:
	//------------------------------------------------------- M�thodes priv�es

protected:
	//----------------------------------------------------- Attributs prot�g�s

private:
	//------------------------------------------------------- Attributs priv�s
	Date horodate;
	double valeur;
	TypeMesure typeMesure;
	int sensorID;
	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes priv�es

	//----------------------------------------------------------- Types priv�s
};

//----------------------------------------- Types d�pendants de <Mesure>
struct compareMesure {
	bool operator()(const Mesure &mesureGauche, const Mesure &mesureDroite) {
		return mesureGauche.getDate() < mesureDroite.getDate();
	}
};
typedef multiset<Mesure, compareMesure> collectionMesures;

#endif //_Mesure_H
