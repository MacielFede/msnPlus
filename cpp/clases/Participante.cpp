#include "../../h/clases/Participante.h"

Participante::Participante(Usuario* soy, DtFecha fecha, bool soyAdmin) 
{
    this->administrador = soyAdmin;
    this->fechaIngreso = fecha;
    this->usuario = soy;
}


Usuario* Participante::getUsuario()
{
    return this->usuario;
}

Participante::~Participante() {}

DtFecha Participante::getFechaIngreso() 
{
    return this->fechaIngreso;
}

bool Participante::getAdminStatus()
{
    return this->administrador;
}