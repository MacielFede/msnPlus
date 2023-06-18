#include "../../h/controladores/CContacto.h"

CContacto* CContacto::instancia = nullptr;
// Le doy valor a la instancia como null para que solo la primera vez creemos la instancia

CContacto& CContacto::getCContacto()
{
    if (instancia == nullptr)
    {
        instancia = new CContacto();
    }
    // Si la instancia ya fue creada retorno una referencia a la misma instancia
    return *instancia;
}

CContacto::CContacto() {}

CContacto::~CContacto() {
    delete instancia;
}

// Definicion del constructor de copia y del operator override para que no se copie la instancia
CContacto::CContacto(const CContacto&) {}

CContacto& CContacto::operator=(const CContacto&) {
    return *this;
}