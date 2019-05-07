/**
 * Project Diagrammes GL UML
 */


#ifndef _TRAITEMENTDONNEES_H
#define _TRAITEMENTDONNEES_H

class TraitementDonnees {
public: 
    
/**
 * @param double lat
 * @param double long
 * @param double rayon
 */
List<Capteur> ParcoursCapteurs(void double lat, void double long, void double rayon);
    
/**
 * @param double lat
 * @param double long
 */
List<Capteur> ParcoursCapteurs(void double lat, void double long);
    
void ParcoursMesures(List<Capteur>, List<TypeMesure>, Date horodateDeb, Date horodateFin): List<Mesure>();
    
List<TypeMesure> ParcoursTypesMesure();
private: 
    String FichierTypesMesure;
    String FichierCapteurs;
    String FichierMesures;
};

#endif //_TRAITEMENTDONNEES_H