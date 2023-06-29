#include "../../h/clases/Conversacion.h"
#include "../../h/clases/Mensaje.h"

Conversacion::~Conversacion() {}

void Conversacion::setActivaFalse() {
  if (this->activa)
    this->activa = false;
}

int Conversacion::getUltimoIdMensaje() {
  return ++this->ultimoIdMensaje;
}

string Conversacion::getIdConversacion() {
  return this->idConversacion;
}

bool Conversacion::getActiva() {
  return this->activa;
}

list<DtVisto> Conversacion::informacionMensaje(int idMensaje) {
  //Asumo que el mensaje existe y que el usuario es emisor
  Mensaje* mens = this->mensajes.find(idMensaje)->second;
  cout << "< ";
  mens->getDataMensaje()->imprimir();
  return mens->crearInfoMsg();
}