/*************************************************************************
Parseur  -  description
-------------------
début                : ${date}
copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <Parseur> (fichier Parseur.h) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <list>
#include <sstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Parseur.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

list<double> Parseur::ParserCommande() // mettre ici le paramètre entrée
{
    //Initialisation des différentes variables utilisées.
	list<double> commandeParsee;
    string parametreCourant;
    unsigned nbParametres (0);
    bool aDesOptions = false;
    //L'utilisateur entre sa commande (à mettre dans le menu à terme)
    string entree;
    getline(cin,entree);
    //jusqu'ici
    istringstream fluxEntree (entree);
    getline(fluxEntree, parametreCourant,' ');
    if(!verificationParametre(parametreCourant)){
        //faire l'affichage menu de l'erreur cerr
    } else {
        commandeParsee.push_back(AttributionCommande(parametreCourant));
        nbParametres = NombreDeParametresCommande(parametreCourant);
        aDesOptions = PossedeDesOptionsCommande(parametreCourant);
        if(nbParametres > 1){
            if(!verificationParametre(parametreCourant)){
                //faire l'affichage menu de l'erreur cerr
            else if(aDesOptions){ // on récupère la dite option
                getline(fluxEntree, parametreCourant,' ');
                commandeParsee.push_back(AttributionOption(parametreCourant));
            } else {
                 for (unsigned i (0); i< nbParametres; i++){
                    getline(fluxEntree,parametreCourant,' ')
                    if(!verificationParametre(parametreCourant)){
                    //faire l'affichage menu de l'erreur cerr
                    } else {
                        commandeParsee.push_back(stod(parametreCourant));
                    }   
                }
                cout << "Resultat"<<endl;
                for(auto v : commandeParsee){
                    cout<< "Valeur : " << v <<endl;
                }
            }      
        }
    }
    return commandeParsee;
}

//------------------------------------------------- Surcharge d'opérateurs
Parseur & Parseur::operator=(const Parseur & unParseur) {
	return *this;
}


//-------------------------------------------- Constructeurs - destructeur

Parseur::Parseur(const Parseur & unParseur)
{
}

Parseur::Parseur()
{

}

Parseur::~Parseur()
{
}


//------------------------------------------------- Surcharge d'opérateurs


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées


