#include "../../h/clases/Video.h"

Video::~Video() {}

DtMensaje* Video::getDataMensaje() {
  DtVideo* vid = new DtVideo(this->duracion, this->id, this->fechaEnvio, this->crearInfoMsg(), this->emisor->getDataUsuario());
  return vid;
}
