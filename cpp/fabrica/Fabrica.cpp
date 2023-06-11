#include "../../h/fabrica/Fabrica.h"

Fabrica *Fabrica::instancia = nullptr;
// Le doy valor a la instancia como null para que solo la primera vez creemos la instancia

Fabrica &Fabrica::getFabrica()
{
    if (instancia == nullptr)
    {
        instancia = new Fabrica();
    }
    // Si la instancia ya fue creada retorno una referencia a la misma instancia
    return *instancia;
}

Fabrica::Fabrica(){}

Fabrica::~Fabrica(){
  delete instancia;
}

// Definicion del constructor de copia y del operator override para que no se copie la instancia
Fabrica::Fabrica(const Fabrica &) {

}

Fabrica &Fabrica::operator=(const Fabrica &){
    return *this;
}

CConversacion Fabrica::getCConversacion(){
  return this->cconver.getCConversacion();
}