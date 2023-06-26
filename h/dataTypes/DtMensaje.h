#ifndef DTMENSAJE_H
#define DTMENSAJE_H

#include <iostream>
#include <string>
#include "DtVisto.h"
#include "DtFecha.h"
#include "DtUsuario.h"

using namespace std;

class DtMensaje
{
protected:
    int idMensaje;
    DtFecha fechaEnvio;
    list<DtVisto> infoMensaje;
    DtUsuario emisor;

public:
    // Constructor
    DtMensaje(int idMensaje, DtFecha fechaEnvio, list<DtVisto> receptores, DtUsuario emisor);
    DtMensaje();

    // Getters
    bool usuarioEsReceptor(string telefonoSesion);
    int getIdMensaje();
    DtFecha getFechaEnvio();
    list<DtVisto> getInfoMensaje();
    virtual void imprimir() = 0;
    bool usuarioEsEmisor(string telefonoSesion);

    // Destructor
    ~DtMensaje();

};

#endif