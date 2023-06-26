#include "../../h/dataTypes/DtMensaje.h"

// Constructor
DtMensaje::DtMensaje() {}
DtMensaje::DtMensaje(int idMensaje, DtFecha fechaEnvio, list<DtVisto> receptores, DtUsuario emisor)
{
    this->idMensaje = idMensaje;
    this->fechaEnvio = fechaEnvio;
    this->infoMensaje = receptores;
    this->emisor = emisor;
}

// Getters
int DtMensaje::getIdMensaje()
{
    return this->idMensaje;
}

DtFecha DtMensaje::getFechaEnvio()
{
    return this->fechaEnvio;
}

// Destructor
DtMensaje::~DtMensaje() {}


bool DtMensaje::usuarioEsReceptor(string telefonoSesion) {
    list<DtVisto>::iterator iter;
    for (iter = this->infoMensaje.begin(); iter != this->infoMensaje.end(); ++iter) {
        if (telefonoSesion == iter->getNumTel()) return true;
    }
    return false;
}

void imprimir() {}

bool DtMensaje::usuarioEsEmisor(string telefonoSesion) {
    return this->emisor.getNumTel() == telefonoSesion;
}