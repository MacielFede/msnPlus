#ifndef CONVERSACION_H
#define CONVERSACION_H

// #include "Usuario.h"
#include <cstdlib>
#include <list>
#include <map>
#include <string>
// #include "Mensaje.h"
#include "../dataTypes/DtContacto.h"
#include "../dataTypes/DtUsuario.h"
#include "../dataTypes/DtConversacion.h"
#include "../dataTypes/DtMensaje.h"

class Usuario;
class Mensaje;

using namespace std;

class Conversacion
{
protected:
    int ultimoIdMensaje;
    bool activa;
    string idConversacion;
    map<int, Mensaje*> mensajes;
public:
    virtual DtConversacion getDataConversacion(string telSesionAct) = 0;

    virtual list<DtMensaje*> buscarMensajes(string telSesion) = 0;

    virtual map<string, Usuario *> getParticipantes() = 0;

    list<DtVisto> informacionMensaje(int idMensaje);

    virtual void asignarAConversacion(Mensaje* m) = 0;

    void setActivaFalse();

    void eliminarMensaje(string idMensaje);

    int getUltimoIdMensaje();

    bool getActiva();

    string getIdConversacion();

    ~Conversacion();
};
#endif
