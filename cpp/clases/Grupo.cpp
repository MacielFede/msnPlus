#include "../../h/clases/Grupo.h"
#include "../../h/clases/Mensaje.h"

Grupo::Grupo() {}

Grupo::~Grupo() {}

DtConversacion Grupo::getDataConversacion() {
  return DtConversacion(this->getIdConversacion(), this->getActiva(), "-");
}

list<DtMensaje*> Grupo::buscarMensajes(string telSesion) {
  list<DtMensaje*> msj;
  map<int, Mensaje*>::iterator iter;
  for (iter = this->mensajes.begin(); iter != this->mensajes.end(); ++iter) {
    //Si el usuario no esta entre los receptores o entro al grupo despues de que se envio el mensaje no mando el Dt
    if (iter->second->esReceptor(telSesion) && iter->second->getFechaEnvio().esMayor(this->participantes.find(telSesion)->second->getFechaIngreso())) {
      //Seteo el visto si es que nu fue visto
      if (!iter->second->fueVisto(telSesion))
        iter->second->setVisto(telSesion);
      msj.push_back(iter->second->getDataMensaje());
    }
  }
  return msj;
}

list<DtVisto> Grupo::informacionMensaje(string idMensaje) {}

void Grupo::asignarAConversacion(Mensaje* m) {}