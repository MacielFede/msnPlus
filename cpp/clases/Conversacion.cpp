#include "../../h/clases/Conversacion.h"

Conversacion::~Conversacion() {}

void Conversacion::setActivaFalse() {
  if (this->activa)
    this->activa = false;
}

string Conversacion::getIdConversacion() {
  return this->idConversacion;
}

bool Conversacion::getActiva() {
  return this->activa;
}
