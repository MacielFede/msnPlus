#include "../../h/dataTypes/DtConversacion.h"

// Constructor
DtConversacion::DtConversacion()
{
}



DtConversacion::DtConversacion(string idConv, bool activa, string nomUser)
{
    this->idConv = idConv;
    this->activa = activa;
    this->nomUsuario = nomUser;
    this->privada = true;
}

DtConversacion::DtConversacion(string idConv, bool activa, string nomUser, bool privada)
{
    this->idConv = idConv;
    this->activa = activa;
    this->nomUsuario = nomUser;
    this->privada = privada;
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

bool DtConversacion::getPrivada()
{
    return this->privada;
}

// Destructor
DtConversacion::~DtConversacion() {}