#ifndef DTMENSAJE_H
#define DTMENSAJE_H

#include <iostream>
#include <string>
#include "DtVisto.h"
#include "DtFecha.h"

using namespace std;

class DtMensaje
{
protected:
    int idMensaje;
    DtFecha fechaEnvio;
    list<DtVisto> infoMensaje;

public:
    // Constructor
    DtMensaje(int idMensaje, DtFecha fechaEnvio, list<DtVisto> receptores);
    DtMensaje();

    // Getters
    bool usuarioEsReceptor(string telefonoSesion);
    int getIdMensaje();
    DtFecha getFechaEnvio();
    list<DtVisto> getInfoMensaje();
    virtual void imprimir() = 0;

    // Destructor
    ~DtMensaje();

};

#endif