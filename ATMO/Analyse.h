/*************************************************************************
						   Analyse  -  description
							 -------------------
	début                : 07/05/2019
	copyright            : (C) 2019 par Mengxing ZHANG, Louis UNG, Fabien GELUS et Baptiste PAULETTO
*************************************************************************/

//---------- Interface de la classe <Analyse> (fichier Analyse.h) ------
#if ! defined ANALYSE_H 
#define ANALYSE_H
 
//--------------------------------------------------- Interfaces utilisées
#include <map>
#include <vector>
#include <string>

#include "TypeMesure.h"
#include "Capteur.h"
#include "Date.h"
#include "CoordonneesGPS.h"

//------------------------------------------------------------- Constantes
#define AnalyseInstance Analyse::GetInstance()

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

	static Analyse & GetInstance()
	{
		static Analyse instance;
		return instance;
	}


	//----------------------------------------------------- Méthodes publiques
	conteneurMoyMesures caracteristiquesZone( double lat, double longi, double rayon, Date & horodateDeb, Date & horodateFin);
	// Mode d'emploi : si option -d activée, appeler cette methode puis afficher les moyennes en sortie, puis appeler qualiteAir avec en parametre la sortie 
	//sinon, appeler qualiteair avec en parametre la sortie de cette methode
	//
	// Contrat :recupere les données de mesure de tous les capteurs situés dans la zone et l’intervalle de temps
	//	donnés. chaque type de mesure, fait la moyenne de toutes les mesures de ce type. 


	conteneurIndiceCapteurs comportementSimilaire(Date & horodateDeb, Date & horodateFin);
	// Mode d'emploi :
	//
	// Contrat : Pour une période de temps, récupère tous les capteurs 
	// ayant réalisé des mesures pendant cette période de temps et calcule le score ATMO de chaque capteur. 
	// Tous les capteurs qui auront alors le même score ATMO serons considérés comme ayant un comportement similaire.
	// Ces listes de capteurs (second) seront classés par indices (first)

	collectionCapteurs dysfonctionnement(Date & horodateDeb, Date & horodateFin);
	// Contrat : Sur a période de temps précisée, donne la liste des capteurs qui ont : réalisé des mesures dont
	//	la valeur est négative - réalisé des mesures trop grandes par rapport à ce qui est défini 
	//	par le score ATMO (>=5000 μg/m3) - arrêté de réaliser des mesures pendant une période de temps >1h 
	// des mesures qui restent constantes dans le temps sur une période trop longue (>12h)

	conteneurMoyMesures caracteristiquesPoint(double lat, double longi, Date & horodateDeb, Date & horodateFin);
	//Appeler qualiteair avec en parametre la sortie de cette methode
	//
	// Contrat :recupere les données de mesure de tous les capteurs situés dans la zone et l’intervalle de temps
	//	donnés. chaque type de mesure, fait la moyenne de toutes les mesures de ce type. 


	int qualiteAir(conteneurMoyMesures & MoyMesures);
	// Mode d'emploi :
	// entrée : moyenne des mesures pour chaque type
	// sortie : indice de qualit?de l'air de 1 a 10  ou -1 si données incohérentes
	// on choisit le plus grand des sous - indices calculés pour le dioxyde de soufre, le dioxyde d'azote, l'ozone et les particules fines;
	// Contrat :
	// 

	//-------------------------------------------- Constructeurs - destructeur

	
	// Mode d'emploi :
	//
	// Contrat :
	//

	//------------------------------------------------------------------ PRIVE 

protected:
	//----------------------------------------------------- Méthodes protégées

private:
	Analyse();
	Analyse(const Analyse &);
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
