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
	//version sp¨¦ciale pour le test
	static Analyse & GetInstance(string types,string capteurs,string mesures)
	{
		static Analyse instance(types,capteurs,mesures);
		return instance;
	}

	//----------------------------------------------------- Méthodes publiques
	conteneurMoyMesures caracteristiquesZone( double lat, double longi, double rayon, Date horodateDeb, Date horodateFin);
	// Mode d'emploi : si option -d activée, appeler cette methode puis afficher les moyennes en sortie, puis appeler qualiteAir avec en parametre la sortie 
	//sinon, appeler qualiteair avec en parametre la sortie de cette methode
	//
	// Contrat :
	//

	doubleCollectionCapteurs comportementSimilaire(Date horodateDeb, Date horodateFin);
	// Mode d'emploi :
	//
	// Contrat :
	//
	collectionCapteurs dysfonctionnement(Date horodateDeb, Date horodateFin);

	conteneurMoyMesures caracteristiquesPoint(double lat, double longi, Date horodateDeb, Date horodateFin);
	//appeler qualiteair avec en parametre la sortie de cette methode
	//
	// Contrat :
	//


	int qualiteAir(conteneurMoyMesures MoyMesures);
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
	Analyse(string,string,string);
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
