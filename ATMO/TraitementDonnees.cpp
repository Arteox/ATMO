/*************************************************************************
TraitementDonnees  -  description
-------------------
d�but                : ${date}
copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <Capteur> (fichier Capteur.h) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <iostream>
using namespace std;
#include <locale>
#include <codecvt>

//------------------------------------------------------ Include personnel
#include "TraitementDonnees.h"
#include "Capteur.h"
#include "Mesure.h"
#include "TypeMesure.h"
#include <fstream>
#include <sstream>
#include <vector>
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe
const string TraitementDonnees::FichierCapteurs = "DonneesCSV\\Sensors.csv";
const string TraitementDonnees::FichierTypesMesure = "DonneesCSV\\AttributeType.csv";
const string TraitementDonnees::FichierMesures = "DonneesCSV\\MesuresSample.csv";
//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques

collectionCapteurs TraitementDonnees::ParcoursCapteurs(double lat, double longi, double rayon)
{
	
	return collectionCapteurs();
}

collectionCapteurs TraitementDonnees::ParcoursCapteurs(double lat, double longi)
{
	ifstream fic;
	string lectLigne;
	fic.open(FichierCapteurs);
	if (fic) {
		for (lectLigne; getline(fic, lectLigne); ) {
			istringstream iss(lectLigne);			
			if (lectLigne != "SensorID;Latitude;Longitude;Description;"){
				cout << lectLigne << endl;
				string attribut;
				vector<string> attributs;
				while (getline(iss, attribut, ';'))
				{
					attributs.push_back(attribut);
				}
				int sensorID = stoi(attributs[0]);
				double lat = stod(attributs[1]);
				double longi = stod(attributs[2]);
				string description = attributs[3];
				//Capteur c(sensorID, lat, longi, description);
				//donneesCapteurs.push_back(c);

			}
		}
	}
	fic.close();
	return collectionCapteurs();
}

collectionMesures TraitementDonnees::ParcoursMesures(collectionCapteurs, Date horodateDeb, Date horodateFin)
{
	return multiset<Mesure>();
}

collectionTypesMesure TraitementDonnees::ParcoursTypesMesure()
{
	ifstream fic;
	string lectLigne;
	fic.open(FichierTypesMesure);
	if (fic) {
		for (lectLigne; getline(fic, lectLigne); ) {
			istringstream iss(lectLigne);
			if (lectLigne != "AttributeID;Unit;Description;") {
				string attribut;
				vector<string> attributs;
				while (getline(iss, attribut, ';'))
				{
					attributs.push_back(attribut);
				}
				string attributID = attributs[0];

				wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;
				wstring unite = converter.from_bytes(attributs[1]); //encodage de la lettre grecque mu ne marche pas

				string description = attributs[2];
				TypeMesure type(attributID, unite, description);
				donneesTypesMesure.push_back(type);
			}
		}
	}
	fic.close();

	return donneesTypesMesure;
}

//------------------------------------------------- Surcharge d'op�rateurs

//-------------------------------------------- Constructeurs - destructeur

TraitementDonnees::TraitementDonnees(const TraitementDonnees & unTraitementDonnees)
{

}

TraitementDonnees::~TraitementDonnees()
{
}

//------------------------------------------------------------------ PRIVE
TraitementDonnees::TraitementDonnees()
{
	
}

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es


