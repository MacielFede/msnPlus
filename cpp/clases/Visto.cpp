#include "../../h/clases/Visto.h"
#include "../../h/clases/Relojito.h"

Visto::Visto(Usuario* recep) {
  this->receptor = recep;
  this->visto = false;
}

Visto::~Visto() {}

void Visto::setVisto() {
  if (!this->visto) {
    this->visto = true;
    this->fechaV = DtFecha(Relojito::getRelojito().getFechaActual());
  }
}

bool Visto::getVisto() {
  return this->visto;
}

DtVisto Visto::getDataVisto() {
  return DtVisto(this->receptor->getTelefono(), this->receptor->getNombre(), this->fechaV, this->visto);
}