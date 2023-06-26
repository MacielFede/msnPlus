#include "../../h/clases/Texto.h"

Texto::~Texto() {}


DtMensaje* Texto::getDataMensaje() {
  DtTexto* text = new DtTexto(this->texto, this->id, this->fechaEnvio, this->crearInfoMsg(), this->emisor->getDataUsuario());
  return text;
}
