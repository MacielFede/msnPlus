#include "../../h/dataTypes/DtInfoMensaje.h"

// Constructor
DtInfoMensaje::DtInfoMensaje(string numTel, string nombre, list<DtVisto> vistoPor) 
{
    this->numTel = numTel;
    this->nombre = nombre;
    this->vistoPor = vistoPor;
}

// Getters
string DtInfoMensaje::getNumTel() 
{
    return this->numTel;
}

string DtInfoMensaje::getNombre()
{
    return this->nombre;
}

list<DtVisto> DtInfoMensaje::getVistoPor() 
{
    return this->vistoPor;
}

// Destructor
DtInfoMensaje::~DtInfoMensaje {}