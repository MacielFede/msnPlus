#include "../../h/clases/Conversacion.h"
#include "../../h/clases/Texto.h"
#include "../../h/clases/Contacto.h"
#include "../../h/clases/Imagen.h"
#include "../../h/clases/Video.h"

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
  if (Texto* texto = dynamic_cast<Texto*>(mens)) {
    texto->getDataMensaje()->imprimir();
  }
  else if (Video* video = dynamic_cast<Video*>(mens)) {
    video->getDataMensaje()->imprimir();
  }
  else if (Imagen* imagen = dynamic_cast<Imagen*>(mens)) {
    imagen->getDataMensaje()->imprimir();
  }
  else if (Contacto* contacto = dynamic_cast<Contacto*>(mens)) {
    contacto->getDataMensaje()->imprimir();
  }
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