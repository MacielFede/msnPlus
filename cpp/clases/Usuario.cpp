#include "../../h/clases/Usuario.h"

Usuario::~Usuario() {}

void Usuario::setDesc(string desc) {
  this->descripcion = desc;
}

void Usuario::setImagen(string url) {
  this->imagenPerfil = url;
}

void Usuario::setNombre(string nom) {
  this->nombre = nom;
}

DtUsuario Usuario::getDataUsuario() {
  // DtUsuario user = DtUsuario();
  // return DtUsuario()
}