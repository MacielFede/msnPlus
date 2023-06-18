#ifndef DTMENSAJE_H
#define DTMENSAJE_H

#include <iostream>
#include <string>   
#include "DTInfoMensaje.h"
#include "DTVisto.h"
#include "DTFecha.h"

using namespace std;

class DtMensaje
{
    private:
        string idMensaje;
        DtFecha fechaEnvio;
        DtInfoMensaje* infoMensaje;
    public:
        // Constructor
        DtMensaje(string idMensaje, DtFecha fechaEnvio);

        // Getters
        string getIdMensaje();
        DtFecha getfechaEnvio();
        DtInfoMensaje* getInfoMensaje();
 
        // Destructor
        ~DtMensaje();
            
        //friend ostream &operator<<(ostream &o, DtMensaje &s);
};

#endif