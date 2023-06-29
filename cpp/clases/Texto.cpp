#include "../../h/clases/Texto.h"

Texto::Texto(string text, map<string, Usuario *> receptores, DtFecha fechaEnv, Usuario *emisor, int ultimoId)
{
  this->texto = text;
  this->fechaEnvio = fechaEnv;
  this->emisor = emisor;
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

Texto::~Texto() {}

DtMensaje *Texto::getDataMensaje()
{
  DtTexto *text = new DtTexto(this->texto, this->id, this->fechaEnvio, this->crearInfoMsg(), this->emisor->getDataUsuario());
  return text;
}
