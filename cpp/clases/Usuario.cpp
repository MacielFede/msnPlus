#include "../../h/clases/Usuario.h"

Usuario::~Usuario() {}

void Usuario::agregarContacto(Usuario* c)
{
    //contactos.insert({c->getDataUsuario().getNumTel(), c});
}

DtUsuario Usuario::setDesc(string desc) {
  this->descripcion = desc;
  return this->getDataUsuario();
}

DtUsuario Usuario::setImagen(string url) {
  this->imagenPerfil = url;
  return this->getDataUsuario();
}

DtUsuario Usuario::setNombre(string nom) {
  this->nombre = nom;
  return this->getDataUsuario();
}

DtUsuario Usuario::getDataUsuario() {
  return DtUsuario(this->telefono, this->nombre, this->fechaRegistro, this->imagenPerfil, this->descripcion, this->ultimaConexion);
}