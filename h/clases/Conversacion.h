#ifndef CONVERSACION_H
#define CONVERSACION_H

#include <cstdlib>
#include <list>
#include <map>
#include <string>
#include "h/clases/Usuario.h"
#include "h/clases/Mensaje.h"
#include "h/dataTypes/DtContacto.h"
#include "h/dataTypes/DtUsuario.h"
#include "h/dataTypes/DtConversacion.h"
#include "h/dataTypes/DtMensaje.h"
#include "h/dataTypes/DtInfoMensaje.h"

using namespace std;

class Conversacion
{
private:
    bool activa;
    string idConversacion;
    map<string, Mensaje> mensajes;
public:
    virtual DtConversacion getDataConversacion() = 0;

    void setActivaFalse();

    list<DtMensaje> buscarMensajes();

    void eliminarMensaje(string idMensaje);
    
    DtInfoMensaje informacionMensaje(string idMensaje);

    void asignarAConversacion(Mensaje m);
};
#endif