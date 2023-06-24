#include "../../h/clases/Conversacion.h"

Conversacion::~Conversacion() {}

void Conversacion::setActivaFalse() {
  if (this->activa)
    this->activa = false;
}
