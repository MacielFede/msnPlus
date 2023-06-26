#include "../../h/clases/Imagen.h"

Imagen::~Imagen() {}

DtMensaje* Imagen::getDataMensaje() {
  DtImagen* image = new DtImagen(this->formatoImg, this->descripcion, this->tamano, this->id, this->fechaEnvio, this->crearInfoMsg());
  return image;
}
