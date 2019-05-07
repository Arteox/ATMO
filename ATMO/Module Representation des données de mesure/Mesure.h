/**
 * Project Diagrammes GL UML
 */


#ifndef _MESURE_H
#define _MESURE_H

#include "Capteur.h"


class Mesure {
private: 
    t_time Horodate;
    double Value;
    Capteur SensorID;
};

#endif //_MESURE_H