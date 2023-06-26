#include "../../h/dataTypes/DtMensaje.h"

// Constructor
DtMensaje::DtMensaje() {}
DtMensaje::DtMensaje(int idMensaje, DtFecha fechaEnvio, list<DtVisto> receptores)
{
    this->idMensaje = idMensaje;
    this->fechaEnvio = fechaEnvio;
    this->infoMensaje = receptores;
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