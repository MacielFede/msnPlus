#include "../../h/clases/Conversacion.h"
#include "../../h/clases/Mensaje.h"

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

list<DtVisto> Conversacion::informacionMensaje(int idMensaje) {
  //Asumo que el mensaje existe y que el usuario es emisor
  Mensaje* mens = this->mensajes.find(idMensaje)->second;
  cout << "< ";
  mens->getDataMensaje()->imprimir();
  return mens->crearInfoMsg();
}

void Conversacion::eliminarMensaje(int idMensaje, string telSesion) {
  map<int, Mensaje*>::iterator iterMsj = mensajes.find(idMensaje);
  if (iterMsj != mensajes.end()) {
    if (iterMsj->second->esReceptor(telSesion))
      iterMsj->second->eliminarReceptor(telSesion);
    else if (iterMsj->second->esReceptor(telSesion) && iterMsj->second->esEmisor(telSesion)) {
      delete iterMsj->second;
      mensajes.erase(idMensaje);
    }
    else
      cout << "Ya eliminaste el mensaje indicado.\n";
  }
  else
    cout << "El mensaje indicado no existe.\n";
}