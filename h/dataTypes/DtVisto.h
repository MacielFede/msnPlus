#ifndef DTVISTO_H
#define DTVISTO_H

#include <iostream>
#include <cstdlib>
#include <list>
#include <string>   
#include "DTFecha.h"

using namespace std;

class DtVisto
{
    private:
        string numTel;
        string nombre;
        DtFecha fechaVisto;
    public:
        // Constructor
        DtVisto(string numTel, string nombre, DtFecha fechaVisto);

        // Getters
        string getNumTel();
        string getNombre();
        DtFecha getFechaVisto();
 
        // Destructor
        ~DtVisto();
            
        //friend ostream &operator<<(ostream &o, DtVisto &s);
};

#endif