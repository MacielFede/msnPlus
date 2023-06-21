#include "../../h/dataTypes/DtUsuario.h"

// Constructor
DtUsuario::DtUsuario(string numTel, string nombre, DtFecha fechaRegistro, string imagenPerfil, string descripcion, DtFecha ultimaConexion)
{
    this->numTel = numTel;
    this->nombre = nombre;
    this->fechaRegistro = fechaRegistro;
    this->imagenPerfil = imagenPerfil;
    this->descripcion = descripcion;
    this->ultimaConexion = ultimaConexion;
}

// Getters
string DtUsuario::getNumTel()
{
    return this->numTel;
}

string DtUsuario::getNombre()
{
    return this->nombre;
}

DtFecha DtUsuario::getFechaRegistro()
{
    return this->fechaRegistro;
}

string DtUsuario::getImagenPerfil()
{
    return this->imagenPerfil;
}

string DtUsuario::getDescripcion()
{
    return this->descripcion;
}

DtFecha DtUsuario::getUltimaConexion()
{
    return this->ultimaConexion;
}

// Destructor
DtUsuario::~DtUsuario() {}