#include "../../h/controladores/CConversacion.h"

CConversacion* CConversacion::instancia = nullptr;
// Le doy valor a la instancia como null para que solo la primera vez creemos la instancia

CConversacion& CConversacion::getCConversacion()
{
    if (instancia == nullptr)
    {
        instancia = new CConversacion();
    }
    // Si la instancia ya fue creada retorno una referencia a la misma instancia
    return *instancia;
}

CConversacion::CConversacion() {}

CConversacion::~CConversacion() {
    delete instancia;
}


CConversacion& CConversacion::operator=(const CConversacion&) {
    return *this;
}