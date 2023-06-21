#include "../../h/controladores/CConversacion.h"

CConversacion* CConversacion::instancia = nullptr;
// Le doy valor a la instancia como null para que solo la primera vez creemos la instancia

CConversacion& CConversacion::getCConversacion()
{
    if (instancia == nullptr)
    {
        instancia = new CConversacion();
    }
    // Si la instancia ya fue creada retorno una referencia a la misma instancia
    return *instancia;
}

CConversacion::CConversacion() {}

CConversacion::~CConversacion() {
    delete instancia;
}


CConversacion& CConversacion::operator=(const CConversacion&) {
    return *this;
}

void CConversacion::archivarConversacion(string idConversacion) {}

list<DtConversacion> CConversacion::listarConversacionesActivas() {}

list<DtConversacion> CConversacion::listarConvArch() {}

list<DtMensaje> CConversacion::selConversacion(string idConversacion) {}

void CConversacion::eliminarMensaje(string idMensaje) {}

list<DtContacto> CConversacion::listarContactos() {}

void CConversacion::seleccionarContacto(string cNumTel) {}

DtInfoMensaje CConversacion::informacionMensaje(string idMensaje) {}

void CConversacion::enviarMensajeSimple(string msgTxt) {}

void CConversacion::enviarImg(string url, string formato, string size, string desc) {}

void CConversacion::enviarVideo(string url, string duracion) {}

void CConversacion::enviarContacto(string cNumTel) {}

void CConversacion::crearMensaje() {}