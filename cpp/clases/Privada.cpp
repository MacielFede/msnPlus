#include "../../h/clases/Privada.h"
#include "../../h/clases/Mensaje.h"

Privada::Privada(Usuario * yo, Usuario * otro) {
  // Inserto ambos participantes y listo
  this->participantes.insert({yo->getTelefono(),yo});
  this->participantes.insert({otro->getTelefono(),otro});
  this->activa = true;
  this->privada = true;
}

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

list<DtMensaje*> Privada::buscarMensajes(string telSesion) {
  list<DtMensaje*> msj;
  map<int, Mensaje*>::iterator iter;
  for (iter = this->mensajes.begin(); iter != this->mensajes.end(); ++iter) {
    //Si el usuario no esta entre los receptores no mando el Dt
    if (iter->second->esReceptor(telSesion)) {
      //Seteo el visto si es que nu fue visto
      if (!iter->second->fueVisto(telSesion))
        iter->second->setVisto(telSesion);
      msj.push_back(iter->second->getDataMensaje());
    }
  }
  return msj;
}

void Privada::asignarAConversacion(Mensaje* m) {}