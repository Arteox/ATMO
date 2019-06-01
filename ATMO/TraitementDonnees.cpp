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
#include <iomanip>
using namespace std;
#include <locale>
#include <codecvt>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

//------------------------------------------------------ Include personnel
#include "TraitementDonnees.h"
#include "Capteur.h"
#include "Mesure.h"
#include "TypeMesure.h"
#include "CoordonneesGPS.h"
#include "Zone.h"
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
//on renvoie tous les capteurs dans la zone indiquée
{
	collectionCapteurs capteurs;
	Zone zone(lat, longi, rayon);
	CoordonneesGPS cGPS;

	for (collectionCapteurs::iterator it = donneesCapteurs.begin(); it != donneesCapteurs.end(); ++it) {
		if (zone.estDansZone(it->getLat(), it->getLong())) {
			capteurs.push_back(*it);
		}
	}

	if (capteurs.size() == 0) {
		cout << "pas de capteurs aux alentours de ce point" << endl;
	}

	return capteurs;
}

collectionCapteurs TraitementDonnees::ParcoursCapteurs(double lat, double longi)
//on renvoie les 3 capteurs les plus proches dans un rayon de 10 km
{
	collectionCapteurs capteurs;
	Zone zoneDixKm(lat, longi, 10);
	CoordonneesGPS cGPS;
	
	for (collectionCapteurs::iterator it = donneesCapteurs.begin(); it != donneesCapteurs.end(); ++it) {
		if (zoneDixKm.estDansZone(it->getLat(), it->getLong())) {
			capteurs.push_back(*it);
		}
	}

	if (capteurs.size() <= 3) {
		if (capteurs.size() == 0) {
			cout << "pas de capteurs aux alentours de ce point" << endl;
		}

		return capteurs;
	}
	else {
		//on cherche les 3 capteurs les plus proches
		map<double, int> distanceIndex;
		for (collectionCapteurs::iterator it = capteurs.begin(); it != capteurs.end(); ++it) {
			double distance = cGPS.distanceEnKmEntreDeuxPoints(lat, longi, it->getLat(), it->getLong());
			distanceIndex.insert(make_pair(distance, it-capteurs.begin()));
		}

		//une fois les indices trouvees, on insere dans un nouveau vector de taille 3
		collectionCapteurs capteursProches;
		for (map<double, int>::iterator it = distanceIndex.begin(); capteursProches.size() < 3; ++it) {
			capteursProches.push_back(capteurs[it->second]);
		}
		return capteursProches;
	}
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
				double lat = stod(attributs[1].substr(0,dot1)+attributs[1].substr(dot1,6));

				size_t dot2 = attributs[2].find(".");
				double longi = stod(attributs[2].substr(0, dot2) + attributs[2].substr(dot2,6));

				string description = attributs[3];

				//on ajoute les mesures après car sinon il faudrait parcourir toutes les mesures pour chaque capteur
				Capteur c(sensorID, lat, longi, description);
				donneesCapteurs.push_back(c);
			}
		}
	}
	fic.close();

	//recherche des mesures associees au capteur
	//on parcourt qu'une seule fois la liste des mesures mais plusieurs fois celles des capteurs
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

collectionMesures TraitementDonnees::ParcoursMesures(collectionCapteurs capteurs, Date horodateDeb, Date horodateFin)
//Les mesures doivent appartenir aux capteurs en paramètre, et être réalisées entre les 2 dates indiquées, borne supérieure excluse
{
	collectionMesures mesuresFiltrees;

	for (collectionCapteurs::iterator itC = capteurs.begin(); itC != capteurs.end(); ++itC) {
		collectionMesures mesuresCapteur = itC->getMesures();
		for (collectionMesures::iterator it = mesuresCapteur.begin(); it != mesuresCapteur.end(); ++it) {
			if ((!(it->getDate() < horodateDeb)) && it->getDate() < horodateFin) {
				mesuresFiltrees.insert(*it);
			}
		}
	}

	return mesuresFiltrees;
}

collectionMesures TraitementDonnees::ParcoursMesures()
{
	return donneesMesures;
}

collectionTypesMesure TraitementDonnees::ParcoursTypeeMesure()
{
	return donneesTypesMesure;
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


