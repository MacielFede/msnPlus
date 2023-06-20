#ifndef CONVERSACION_H
#define CONVERSACION_H

#include <cstdlib>
#include <list>
#include <map>
#include <string>
#include "Usuario.h"
// #include "Mensaje.h"
#include "../dataTypes/DtContacto.h"
#include "../dataTypes/DtUsuario.h"
#include "../dataTypes/DtConversacion.h"
#include "../dataTypes/DtMensaje.h"
#include "../dataTypes/DtInfoMensaje.h"

class Mensaje;

using namespace std;

class Conversacion
{
private:
    bool activa;
    string idConversacion;
    map<string, Mensaje*> mensajes;
public:
    virtual DtConversacion getDataConversacion() = 0;

    void setActivaFalse();

    list<DtMensaje> buscarMensajes();

    void eliminarMensaje(string idMensaje);
    
    DtInfoMensaje informacionMensaje(string idMensaje);

    void asignarAConversacion(Mensaje* m);

    ~Conversacion();
};
#endif