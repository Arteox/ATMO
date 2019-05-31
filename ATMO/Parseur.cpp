/*************************************************************************
Parseur  -  description
-------------------
d�but                : ${date}
copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <Parseur> (fichier Parseur.h) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <iostream>
#include <list>
#include <sstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Parseur.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques

list<double> Parseur::ParserCommande() // mettre ici le param�tre entr�e
{
    //Initialisation des diff�rentes variables utilis�es.
	list<double> commandeParsee;
    string parametreCourant;
    unsigned nbParametres (0);
    bool aDesOptions = false;
    //L'utilisateur entre sa commande (� mettre dans le menu � terme)
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
            else if(aDesOptions){ // on r�cup�re la dite option
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

//------------------------------------------------- Surcharge d'op�rateurs
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


//------------------------------------------------- Surcharge d'op�rateurs


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es


