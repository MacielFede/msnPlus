#include "../../h/dataTypes/DtMensaje.h"

// Constructor
DtMensaje::DtMensaje(string idMensaje, DtFecha fechaEnvio) 
{
    this->idMensaje = idMensaje;
    this->fechaEnvio = fechaEnvio;
}

// Getters
string DtMensaje::getIdMensaje() 
{
    return this->idMensaje;
}

DtFecha DtMensaje::getFechaEnvio()
{
    return this->fechaEnvio;
}

// Destructor
DtMensaje::~DtMensaje() {}