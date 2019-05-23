/*************************************************************************
						   Analyse  -  description
							 -------------------
	début                : 07/05/2019
	copyright            : (C) 2019 par Mengxing ZHANG, Louis UNG, Fabien GELUS et Baptiste PAULETTO
*************************************************************************/

//---------- Interface de la classe <Analyse> (fichier Analyse.h) ------
#if ! defined ( ANALYSE_H )
#define ANALYSE_H
 
//--------------------------------------------------- Interfaces utilisées
#include <map>
#include <vector>
#include "TypeMesure.h"
#include "Capteur.h"
#include "Date.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 
typedef vector<vector<Capteur>> doubleCollectionCapteurs;
typedef vector<Capteur> collectionCapteurs;
typedef std::map<TypeMesure, double> conteneurMoyMesures;
//------------------------------------------------------------------------ 
// Rôle de la classe <Analyse>
//
//
//------------------------------------------------------------------------ 

class Analyse
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	static conteneurMoyMesures caracteristiquesZone(bool d, double lat, double longi, double rayon, Date horodateDeb, Date horodateFin);
	// Mode d'emploi :
	//
	// Contrat :
	//

	static  doubleCollectionCapteurs comportementSimilaire(Date horodateDeb, Date horodateFin);
	// Mode d'emploi :
	//
	// Contrat :
	//
	static collectionCapteurs dysfonctionnement(Date horodateDeb, Date horodateFin);

	static conteneurMoyMesures caracteristiquesPoint(double long, double lat, Date horodateDeb, Date horodateFin);

	static int qualiteAir(conteneurMoyMesures MoyMesures);


	//------------------------------------------------------------------ PRIVE 

protected:
	//----------------------------------------------------- Méthodes protégées

private:
	//------------------------------------------------------- Méthodes privées

protected:
	//----------------------------------------------------- Attributs protégés

private:
	//------------------------------------------------------- Attributs privés

	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes privées

	//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Analyse>

#endif // ANALYSE_H
