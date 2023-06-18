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
    void archivarConversacion(string idConversacion);

    list<DtConversacion> listarConversacionesActivas();

    list<DtConversacion> listarConvArch();

    list<DtMensaje> selConversacion(string idConversacion);

    void eliminarMensaje(string idMensaje);

    list<DtContacto> listarContactos();

    void seleccionarContacto(string cNumTel);

    DtInfoMensaje informacionMensaje(string idMensaje);

    void enviarMensajeSimple(string msgTxt);

    void enviarImg(string url, string formato, string size, string desc);

    void enviarVideo(string url, string duracion);

    void enviarContacto(string cNumTel);

    void crearMensaje();
};

#endif