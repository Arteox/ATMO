/*************************************************************************
						   Analyse  -  description
							 -------------------
	d�but                : ${date}
	copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Analyse> (fichier Analyse.h) ------
#if ! defined ( ANALYSE_H )
#define ANALYSE_H

//--------------------------------------------------- Interfaces utilis�es
#include <time.h>;
#include <map>;
#include <list>;
#include "TypeMesure.h";
#include "Capteur.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 
typedef time_t Date;
typedef std::list<std::list<Capteur>> doubleCollectionCapteurs;
typedef std::list<Capteur> collectionCapteurs;
typedef std::map<TypeMesure, double> conteneurMoyMesures;
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
	static conteneurMoyMesures caracteristiquesZone(bool d, double lat, double long, double rayon, Date horodateDeb, Date horodateFin);
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
