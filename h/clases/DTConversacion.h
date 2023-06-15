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
        string convId;
        bool active;
        list<DtMensaje> msgs;  
    public:
        // Constructor
        DtConversacion(string convId, bool active, list<DtMensaje> msgs);

        // Getters
        bool getActive();
        list<DtMensaje> getMsgs();
        string getConvId();
 
        // Destructor
        ~DtConversacion();
            
        //friend ostream &operator<<(ostream &o, DtConversacion &s);
};

#endif