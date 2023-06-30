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
    map<string,bool> activa;
    string idConversacion;
    map<int, Mensaje*> mensajes;
    bool privada;
public:
    virtual DtConversacion getDataConversacion(string telSesionAct, string telefonoOtro) = 0;

    virtual list<DtMensaje*> buscarMensajes(string telSesion) = 0;

    virtual map<string, Usuario *> getParticipantes() = 0;

    list<DtVisto> informacionMensaje(int idMensaje);

    virtual list<DtVisto> infoMensajeCtm(int idMensaje) = 0;

    virtual void asignarAConversacion(Mensaje* m) = 0;

    virtual void setActivaFalse(string idUsuario) = 0;

    virtual void eliminarMensaje(int idMensaje, string telSesion) = 0;

    int getUltimoIdMensaje();

    virtual bool getActiva(string idUsuario) = 0;

    string getIdConversacion();

    ~Conversacion();
};
#endif
