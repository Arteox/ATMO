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
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <io.h>
#include <fcntl.h>
#include <cstdlib>
#include <locale>
#include <codecvt>
#include <windows.h>
#include <tchar.h>

//------------------------------------------------------ Include personnel
#include "TraitementDonnees.h"
#include "Capteur.h"
#include "Mesure.h"
#include "TypeMesure.h"
#include "CoordonneesGPS.h"
#include "Zone.h"
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe


//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques

collectionCapteurs TraitementDonnees::ParcoursCapteurs(double lat, double longi, double rayon)
//on renvoie tous les capteurs dans la zone indiqu�e
{
	collectionCapteurs capteurs;
	Zone zone(lat, longi, rayon);
	CoordonneesGPS cGPS;

	for (collectionCapteurs::iterator it = donneesCapteurs.begin(); it != donneesCapteurs.end(); ++it) {
		if (zone.estDansZone(it->getLat(), it->getLong())) {
			capteurs.push_back(*it);
		}
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
	if (!donneesMesures.empty()) {
		donneesMesures.clear();
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
	if (!donneesCapteurs.empty()) {
		donneesCapteurs.clear();
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
				int sensorID = stoi(attributs[0].substr(6,2));

				//6 chiffres apres la virgule pour les coordonnees GPS
				size_t dot1 = attributs[1].find(".");
				double lat = stod(attributs[1].substr(0,dot1)+attributs[1].substr(dot1,6));

				size_t dot2 = attributs[2].find(".");
				double longi = stod(attributs[2].substr(0, dot2) + attributs[2].substr(dot2,6));

				string description = attributs[3];

				//on ajoute les mesures apr�s car sinon il faudrait parcourir toutes les mesures pour chaque capteur
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

void TraitementDonnees::setFichierCapteurs(const char * capteurCSV)
{
	const char * relativePath = capteurCSV;
	char  absolutePath[4096] = "";
	GetFullPathNameA(relativePath, 4096, absolutePath, NULL);
	
	fichierCapteurs = absolutePath;

	lectureCapteurs();
}

void TraitementDonnees::setFichierTypesMesure(const char * typemesureCSV)
{
	const char * relativePath = typemesureCSV;
	char  absolutePath[4096] = "";
	GetFullPathNameA(relativePath, 4096, absolutePath, NULL);

	fichierTypesMesure = absolutePath;
	lectureTypesMesure();
}

void TraitementDonnees::setFichierMesures(const char * mesuresCSV)
{
	const char * relativePath = mesuresCSV;
	char  absolutePath[4096] = "";
	GetFullPathNameA(relativePath, 4096, absolutePath, NULL);
	fichierMesures = absolutePath;
	lectureMesures();
}

collectionMesures TraitementDonnees::ParcoursMesures(const collectionCapteurs& capteurs, const Date& horodateDeb, const Date& horodateFin)
//Les mesures doivent appartenir aux capteurs en param�tre, et �tre r�alis�es entre les 2 dates indiqu�es, borne sup�rieure excluse
//Les capteurs devraient d�j?avoir des mesures associ�es ?elles-m�mes lors de l'appel de cette m�thode 
{
	collectionMesures mesuresFiltrees;

	for (collectionCapteurs::const_iterator itC = capteurs.begin(); itC != capteurs.end(); ++itC) {
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

collectionTypesMesure TraitementDonnees::ParcoursTypeMesure()
{
	return donneesTypesMesure;
}

void TraitementDonnees::lectureTypesMesure()
{
	wifstream fic;
	wstring lectLigne;
	fic.open(fichierTypesMesure);
	if (!donneesTypesMesure.empty()) {
		donneesTypesMesure.clear();
	}
	if (fic) {
		for (lectLigne; getline(fic, lectLigne); ) {
			wistringstream iss(lectLigne);
			if (lectLigne != L"AttributeID;Unit;Description;") {
				wstring attribut;
				vector<wstring> attributs;
				while (getline(iss, attribut, L';'))
				{
					attributs.push_back(attribut);
				}

				wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
				string narrow = converter.to_bytes(L"hello");

				string attributID = converter.to_bytes(attributs[0]);
				wstring unite;
				if (attributs[1].size() > 5) {
					//il y a un caractere en plus si on a un caractere special dans l'unite
					unite = attributs[1].substr(1);
				}
				else {
					unite = attributs[1];
				}

				string description = converter.to_bytes(attributs[2]);
				TypeMesure type(attributID, unite, description);
				donneesTypesMesure.push_back(type);
			}
		}
	}
	fic.close();
}

//------------------------------------------------- Surcharge d'op�rateurs

//-------------------------------------------- Constructeurs - destructeur

TraitementDonnees::TraitementDonnees(const TraitementDonnees & unTraitementDonnees)
{

}

TraitementDonnees::TraitementDonnees()
{
	
	
	const char * relativePathCapteurs = "..\\ATMO\\DonneesCSV\\Sensors.csv";
	const char * relativePathTypesMesure = "..\\ATMO\\DonneesCSV\\AttributeType.csv";
	const char * relativePathMesures = "..\\ATMO\\DonneesCSV\\MesuresSample.csv";
	char  absolutePathCapteurs[4096] = "";
	char  absolutePathTypesMesure[4096] ="";
	char  absolutePathMesures[4096] ="";
	GetFullPathNameA(relativePathCapteurs, 4096, absolutePathCapteurs, NULL);
	GetFullPathNameA(relativePathTypesMesure, 4096, absolutePathTypesMesure, NULL);
	GetFullPathNameA(relativePathMesures, 4096, absolutePathMesures, NULL);

	fichierCapteurs = absolutePathCapteurs;
	fichierTypesMesure = absolutePathTypesMesure;
	fichierMesures = absolutePathMesures;

	lectureTypesMesure();
	lectureMesures();
	lectureCapteurs();
}

TraitementDonnees::~TraitementDonnees()
{
}

//------------------------------------------------------------------ PRIVE


//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es


