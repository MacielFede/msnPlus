#include "../../h/dataTypes/DtConversacion.h"

// Constructor
DtConversacion::DtConversacion(string idConv, bool activa, string nomUser)
{
    this->idConv = idConv;
    this->activa = activa;
    this->nomUsuario = nomUser;
}

// Getters
string DtConversacion::getNomUsuario()
{
    return this->nomUsuario;
}

bool DtConversacion::getActiva()
{
    return this->activa;
}

string DtConversacion::getIdConv()
{
    return this->idConv;
}

// Destructor
DtConversacion::~DtConversacion() {}