#include "../../h/dataTypes/DTContacto.h"

// Constructor
DtContacto::DtContacto(string numTel, string nombre, string imagenPerfil) 
{
    this->numTel = numTel;
    this->nombre = nombre;
    this->imagenPerfil = imagenPerfil;
}

// Getters
string DtContacto::getNumTel() 
{
    return this->numTel;
}

string DtContacto::getNombre() 
{
    return this->nombre;
}

string DtContacto::getImagenPerfil() 
{
    return this-> imagenPerfil;
}

// Destructor
DtContacto::~DtContacto() {}