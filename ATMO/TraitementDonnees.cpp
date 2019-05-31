/*************************************************************************
TraitementDonnees  -  description
-------------------
début                : ${date}
copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <Capteur> (fichier Capteur.h) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
#include <locale>
#include <codecvt>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>

//------------------------------------------------------ Include personnel
#include "TraitementDonnees.h"
#include "Capteur.h"
#include "Mesure.h"
#include "TypeMesure.h"
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe
const string TraitementDonnees::fichierCapteurs = "DonneesCSV\\Sensors.csv";
const string TraitementDonnees::fichierTypesMesure = "DonneesCSV\\AttributeType.csv";
const string TraitementDonnees::fichierMesures = "DonneesCSV\\MesuresSample.csv";
//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

collectionCapteurs TraitementDonnees::ParcoursCapteurs(double lat, double longi, double rayon)
{
	
	return collectionCapteurs();
}

collectionCapteurs TraitementDonnees::ParcoursCapteurs(double lat, double longi)
{
	ifstream fic;
	string lectLigne;
	fic.open(fichierCapteurs);
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

void TraitementDonnees::lectureMesures()
{
	ifstream fic;
	string lectLigne;

	if (donneesTypesMesure.empty()) {
		lectureTypesMesure();
	}

	fic.open(fichierMesures);
	if (fic) {
		for (lectLigne; getline(fic, lectLigne); ) {
			istringstream iss(lectLigne);
			try {
				if (lectLigne != "Timestamp;SensorID;AttributeID;Value;") {
					string attribut;
					vector<string> attributs;
					while (getline(iss, attribut, ';'))
					{
						attributs.push_back(attribut);
					}

					string date_brute = attributs[0];
					Date date(date_brute);

					int sensorID = stoi(attributs[1].substr(6, 1));

					string type = attributs[2];
					TypeMesure typeMesure;

					collectionTypesMesure::iterator it;
					for (it = donneesTypesMesure.begin(); it != donneesTypesMesure.end(); ++it) {
						if (it->getAttributeId() == type) {
							typeMesure = *it;
							break;
						}
					}

					double valeur = stod(attributs[3]);

					Mesure mesure(date, valeur, typeMesure, sensorID);
					donneesMesures.insert(mesure);
				}
			}
			catch (const exception& e) {
				cerr << "out of memory maybe" << endl;
			}
		}
	}
	fic.close();
}

void TraitementDonnees::lectureCapteurs()
{
	if (donneesMesures.empty()) {
		lectureMesures();
	}

	ifstream fic;
	string lectLigne;
	fic.open(fichierCapteurs);
	if (fic) {
		for (lectLigne; getline(fic, lectLigne); ) {
			istringstream iss(lectLigne);			
			if (lectLigne != "SensorID;Latitude;Longitude;Description;"){
				string attribut;
				vector<string> attributs;
				while (getline(iss, attribut, ';'))
				{
					attributs.push_back(attribut);
				}
				int sensorID = stoi(attributs[0].substr(6,1));

				//6 chiffres apres la virgule pour les coordonnees GPS
				size_t dot1 = attributs[1].find(".");
				double lat = stod(attributs[1].substr(dot1,6));

				size_t dot2 = attributs[2].find(".");
				double longi = stod(attributs[2].substr(dot2,6));

				string description = attributs[3];

				//on ajoute les mesures après car sinon il faudrai parcourir toutes les mesures pour chaque capteur
				Capteur c(sensorID, lat, longi, description);
				donneesCapteurs.push_back(c);
			}
		}
	}
	fic.close();

	//recherche des mesures associees au capteur
	//on parcourt qu'une seule fois la liste des mesures mais plusieurs fois celles des capteurs
	cout << "taille donneesMesure : " << donneesMesures.size() << endl;
	for (collectionMesures::iterator itM = donneesMesures.begin(); itM != donneesMesures.end(); ++itM) {
		for (collectionCapteurs::iterator itC = donneesCapteurs.begin(); itC != donneesCapteurs.end(); ++itC) {
			if (itM->getSensorID() == itC->getId()) {
				collectionMesures m = itC->getMesures();
				m.insert(*itM);
				itC->setMesures(m);
			}
		}
	}
}

collectionCapteurs TraitementDonnees::ParcoursCapteurs()
{
	return donneesCapteurs;
}

collectionMesures TraitementDonnees::ParcoursMesures(collectionCapteurs, Date horodateDeb, Date horodateFin)
{
	return collectionMesures();
}

void TraitementDonnees::lectureTypesMesure()
{
	ifstream fic;
	string lectLigne;
	fic.open(fichierTypesMesure);
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
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

TraitementDonnees::TraitementDonnees(const TraitementDonnees & unTraitementDonnees)
{

}

TraitementDonnees::TraitementDonnees()
{
	lectureTypesMesure();
	lectureMesures();
	lectureCapteurs();

}

TraitementDonnees::~TraitementDonnees()
{
}

//------------------------------------------------------------------ PRIVE


//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées


