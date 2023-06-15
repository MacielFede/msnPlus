#ifndef DTMENSAJE_H
#define DTMENSAJE_H

#include <iostream>
#include <string>   
#include "DTInfoMensaje.h"
#include "DTVisto.h"
#include "DTDateTime.h"

using namespace std;

class DtMensaje
{
    private:
        string msgId;
        DateTime sentDate;
        DtInfoMensaje* msgInfo;
    public:
        // Constructor
        DtMensaje(string msgId, DateTime sentDate);

        // Getters
        string getId();
        DateTime getSentDate();
        DtInfoMensaje* getMsgInfo();
 
        // Destructor
        ~DtMensaje();
            
        //friend ostream &operator<<(ostream &o, DtMensaje &s);
};

#endif