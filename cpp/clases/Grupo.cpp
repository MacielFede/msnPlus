#include "../../h/clases/Grupo.h"

Grupo::Grupo() {}

Grupo::~Grupo() {}

DtConversacion Grupo::getDataConversacion() {
  return DtConversacion(this->getIdConversacion(), this->getActiva(), "-");
}

list<DtMensaje> Grupo::buscarMensajes() {}

DtInfoMensaje Grupo::informacionMensaje(string idMensaje) {}

void Grupo::asignarAConversacion(Mensaje* m) {}