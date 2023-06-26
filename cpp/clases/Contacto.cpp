#include "../../h/clases/Contacto.h"

Contacto::~Contacto() {}

DtMensaje* Contacto::getDataMensaje() {
  DtContactoMsj* cont = new DtContactoMsj(this->contacto.getNumTel(), this->contacto.getNombre(), this->id, this->fechaEnvio, this->crearInfoMsg(), this->emisor->getDataUsuario());
  return cont;
}

