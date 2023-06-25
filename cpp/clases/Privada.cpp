#include "../../h/clases/Privada.h"

Privada::Privada() {}

Privada::~Privada() {}

DtConversacion Privada::getDataConversacion(string telSesionAct) {
  return DtConversacion(this->getIdConversacion(), this->getActiva(), this->getNomUsuario(telSesionAct));
}

string Privada::getNomUsuario(string usuarioActivo) {
  //Necesito retornar el nombre del otro participante de la conversacion privada
  map<string, Usuario*>::iterator iter = this->participantes.begin();
  if (iter->first == usuarioActivo)
    ++iter;
  return iter->second->getNombre();
}

list<DtMensaje> Privada::buscarMensajes() {}

DtInfoMensaje Privada::informacionMensaje(string idMensaje) {}

void Privada::asignarAConversacion(Mensaje* m) {}