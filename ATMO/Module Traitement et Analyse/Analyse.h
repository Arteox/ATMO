/**
 * Project Diagrammes GL UML
 */


#ifndef _ANALYSE_H
#define _ANALYSE_H

class Analyse {
public: 
    
void CaracteristiquesZone(bool d, double lat, double long,double rayon,  Date horodateDeb,  Date horodateFin) : Map<TypeMesure, double>();
    
/**
 * @param Date horodateDeb
 * @param Date horodateFin
 */
List<List<Capteur>> ComportementSimilaire(void Date horodateDeb, void Date horodateFin);
    
/**
 * @param Date horodateDeb
 * @param Date horodateFin
 */
void Dysfonctionnement(void Date horodateDeb, void Date horodateFin);
    
void CaracteristiquesPoint ( double long, double lat, Date horodateDeb, Date horodateFin ) : Map<TypeMesure, double> ();
    
void QualiteAir(Map<TypeMesure, double>):Integer();
private: 
    List<Capteur> Capteurs;
};

#endif //_ANALYSE_H