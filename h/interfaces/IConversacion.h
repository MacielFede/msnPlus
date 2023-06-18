#ifndef ICONVERSACION_H
#define ICONVERSACION_H

#include <cstdlib>
#include <list>
#include <string>
#include "h/clases/Usuario.h"
#include "h/dataTypes/DtContacto.h"
#include "h/dataTypes/DtUsuario.h"
#include "h/dataTypes/DtConversacion.h"
#include "h/dataTypes/DtMensaje.h"
#include "h/dataTypes/DtInfoMensaje.h"

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