#include "../../h/dataTypes/DtConversacion.h"

// Constructor
DtConversacion::DtConversacion(string idConv, bool activa, list<DtMensaje> mensajes) 
{
    this->idConv = idConv;
    this->activa = activa;
    this->mensajes = mensajes;
}

// Getters
bool DtConversacion::getActiva() 
{
    return this->activa;
}

list<DtMensaje> DtConversacion::getMensajes() 
{
    return this->mensajes;
}

string DtConversacion::getIdConv() 
{
    return this->idConv;
}

// Destructor
DtConversacion::~DtConversacion() {}