#include "../../h/controladores/CAutenticacion.h"

CAutenticacion *CAutenticacion::instancia = nullptr;
// Le doy valor a la instancia como null para que solo la primera vez creemos la instancia

CAutenticacion &CAutenticacion::getCAutenticacion()
{
    if (instancia == nullptr)
    {
        instancia = new CAutenticacion();
    }
    // Si la instancia ya fue creada retorno una referencia a la misma instancia
    return *instancia;
}

CAutenticacion::CAutenticacion() {}

CAutenticacion::~CAutenticacion()
{
    delete instancia;
}

CAutenticacion &CAutenticacion::operator=(const CAutenticacion &)
{
    return *this;
}