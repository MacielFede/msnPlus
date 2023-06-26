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

class Mensaje;

using namespace std;

class Conversacion
{
protected:
    bool activa;
    string idConversacion;
    map<int, Mensaje*> mensajes;
public:
    virtual DtConversacion getDataConversacion() = 0;
    virtual DtConversacion getDataConversacion(string telSesionAct) = 0;

    virtual list<DtMensaje*> buscarMensajes(string telSesion) = 0;

    list<DtVisto> informacionMensaje(int idMensaje);

    virtual void asignarAConversacion(Mensaje* m) = 0;

    void setActivaFalse();

    void eliminarMensaje(string idMensaje);

    bool getActiva();

    string getIdConversacion();

    ~Conversacion();
};
#endif
