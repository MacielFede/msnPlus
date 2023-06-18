#ifndef DTCONVERSACION_H
#define DTCONVERSACION_H

#include <iostream>
#include <cstdlib>
#include <list>
#include <string>
#include "DTMensaje.h"

using namespace std;

class DtConversacion
{
    private:
        string idConv;
        bool activa;
        list<DtMensaje> mensajes;  
    public:
        // Constructor
        DtConversacion(string idConv, bool activa, list<DtMensaje> mensajes);

        // Getters
        bool getActiva();
        list<DtMensaje> getMensajes();
        string getIdConv();
 
        // Destructor
        ~DtConversacion();
            
        //friend ostream &operator<<(ostream &o, DtConversacion &s);
};

#endif