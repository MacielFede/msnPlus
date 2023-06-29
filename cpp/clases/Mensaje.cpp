#include "../../h/clases/Mensaje.h"

Mensaje::Mensaje() {}

Mensaje::~Mensaje() {}

list<DtVisto> Mensaje::crearInfoMsg() {
  map<string, Visto*>::iterator iter;
  list<DtVisto> recept;
  for (iter = this->receptores.begin(); iter != this->receptores.end(); ++iter) {
    recept.push_back(iter->second->getDataVisto());
  }
  return recept;
}

bool Mensaje::esReceptor(string telefonoSesion) {
  return this->receptores.find(telefonoSesion) != this->receptores.end();
}

DtFecha Mensaje::getFechaEnvio() {
  return this->fechaEnvio;
}

bool Mensaje::fueVisto(string telefonoSesion) {
  return this->receptores.find(telefonoSesion)->second->getVisto();
}

void Mensaje::setVisto(string telefonoSesion) {
  this->receptores.find(telefonoSesion)->second->setVisto();
}

bool Mensaje::esEmisor(string telefonoSesion) {
  return this->emisor->getTelefono() == telefonoSesion;
}
