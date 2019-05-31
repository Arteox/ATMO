/*************************************************************************
						   Analyse  -  description
							 -------------------
	d�but                : 07/05/2019
	copyright            : (C) 2019 par Mengxing ZHANG, Louis UNG, Fabien GELUS et Baptiste PAULETTO
*************************************************************************/

//---------- Interface de la classe <Analyse> (fichier Analyse.h) ------
#if ! defined ( ANALYSE_H )
#define ANALYSE_H
 
//--------------------------------------------------- Interfaces utilis�es
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
// R�le de la classe <Analyse>
//
//
//------------------------------------------------------------------------ 

class Analyse
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques
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
	// entr�e : moyenne des mesures pour chaque type
	// sortie : indice de qualit?de l'air de 1 ?10  ou -1 si donn�es incoh�rentes
	// on choisit le plus grand des sous - indices calcul�s pour le dioxyde de soufre, le dioxyde d'azote, l'ozone et les particules fines;
	// Contrat :
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

	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes priv�es

	//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <Analyse>

#endif // ANALYSE_H
