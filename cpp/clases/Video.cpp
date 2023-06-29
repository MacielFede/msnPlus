#include "../../h/clases/Video.h"

Video::Video(map<string, Usuario *> receptores, DtFecha fechaEnv, Usuario *emisor, string URL, string dur, int ultimoId)
{

  this->duracion = dur;
  this->url = URL;
  this->emisor = emisor;
  this->fechaEnvio = fechaEnv;
  this->id = ultimoId;

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

Video::~Video() {}

DtMensaje *Video::getDataMensaje()
{
  DtVideo *vid = new DtVideo(this->duracion, this->id, this->fechaEnvio, this->crearInfoMsg(), this->emisor->getDataUsuario());
  return vid;
}
