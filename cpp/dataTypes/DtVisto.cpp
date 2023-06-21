#include "../../h/dataTypes/DtVisto.h"

// Constructor
DtVisto::DtVisto(string numTel, string nombre, DtFecha fechaVisto)
{
    this->numTel = numTel;
    this->nombre = nombre;
    this->fechaVisto = fechaVisto;
}

// Getters
string DtVisto::getNumTel()
{
    return this->numTel;
}

string DtVisto::getNombre()
{
    return this->nombre;
}

DtFecha DtVisto::getFechaVisto()
{
    return this->fechaVisto;
}

// Destructor
DtVisto::~DtVisto() {}