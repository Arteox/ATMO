/**
 * Project Diagrammes GL UML
 */


#ifndef _CAPTEUR_H
#define _CAPTEUR_H

class Capteur {
private: 
    Integer ID;
    double Lat;
    double Long;
    String Description;
    List<Mesure> Mesures;
};

#endif //_CAPTEUR_H