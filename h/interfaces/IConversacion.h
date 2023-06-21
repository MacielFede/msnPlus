#ifndef ICONVERSACION_H
#define ICONVERSACION_H

#include <cstdlib>
#include <list>
#include <string>
#include "../clases/Usuario.h"
#include "../dataTypes/DtContacto.h"
#include "../dataTypes/DtUsuario.h"
#include "../dataTypes/DtConversacion.h"
#include "../dataTypes/DtMensaje.h"
#include "../dataTypes/DtInfoMensaje.h"

using namespace std;

class IConversacion
{
private:

public:
    virtual void archivarConversacion(string idConversacion) = 0;

    virtual list<DtConversacion> listarConversacionesActivas() = 0;

    virtual list<DtConversacion> listarConvArch() = 0;

    virtual list<DtMensaje> selConversacion(string idConversacion) = 0;

    virtual void eliminarMensaje(string idMensaje) = 0;

    virtual list<DtContacto> listarContactos() = 0;

    virtual void seleccionarContacto(string cNumTel) = 0;

    virtual DtInfoMensaje informacionMensaje(string idMensaje) = 0;

    virtual void enviarMensajeSimple(string msgTxt) = 0;

    virtual void enviarImg(string url, string formato, string size, string desc) = 0;

    virtual void enviarVideo(string url, string duracion) = 0;

    virtual void enviarContacto(string cNumTel) = 0;

    virtual void crearMensaje() = 0;
};

#endif