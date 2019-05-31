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
#include <string>

#include "TypeMesure.h"
#include "Capteur.h"
#include "Date.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 
typedef vector<vector<Capteur>> doubleCollectionCapteurs;
typedef vector<Capteur> collectionCapteurs;
typedef std::map<string, double> conteneurMoyMesures; // string = TypeMesure.getAttributeId()
typedef std::pair<string, double> paireMoyMesures;

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

	static conteneurMoyMesures caracteristiquesPoint(double longi, double lat, Date horodateDeb, Date horodateFin);

	static int qualiteAir(conteneurMoyMesures MoyMesures);
	// Mode d'emploi :
	// entrée : moyenne des mesures pour chaque type
	// sortie : indice de qualit?de l'air de 1 ?10  ou -1 si données incohérentes
	// on choisit le plus grand des sous - indices calculés pour le dioxyde de soufre, le dioxyde d'azote, l'ozone et les particules fines;
	// Contrat :
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

	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes privées

	//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Analyse>

#endif // ANALYSE_H
