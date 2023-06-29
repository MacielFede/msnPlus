#include "../../h/clases/Contacto.h"

Contacto::Contacto(map<string, Usuario *> receptores, DtFecha fechaEnv, Usuario *emisor, int ultimoId, DtUsuario contact)
{
  this->contacto = contact;
  this->emisor = emisor;
  this->fechaEnvio = fechaEnv;
  // this->id = ++ultimoId;

  // Utilizar un iterador para recorrer el map de usuarios
  for (auto it = receptores.begin(); it != receptores.end(); ++it)
  {
    Usuario *receptor = it->second;

    // Crear una instancia de la clase Visto para cada usuario
    Visto *visto = new Visto(receptor);

    // Agrego el usuario al arreglo de receptores del mensaje
    this->receptores.insert({receptor->getTelefono(), visto});
  }
}

Contacto::~Contacto() {}

DtMensaje *Contacto::getDataMensaje()
{
  DtContactoMsj *cont = new DtContactoMsj(this->contacto.getNumTel(), this->contacto.getNombre(), this->id, this->fechaEnvio, this->crearInfoMsg(), this->emisor->getDataUsuario());
  return cont;
}
