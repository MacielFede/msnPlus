#include "../../h/clases/Imagen.h"

Imagen::Imagen(map<string, Usuario *> receptores, DtFecha fechaEnv, Usuario *emisor, int ultimoId, string formato, string tam, string desc)
{

  this->descripcion = desc;
  this->formatoImg = formato;
  this->tamano = tam;
  this->emisor = emisor;
  this->fechaEnvio = fechaEnv;
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

Imagen::~Imagen() {}

DtMensaje *Imagen::getDataMensaje()
{
  DtImagen *image = new DtImagen(this->formatoImg, this->descripcion, this->tamano, this->id, this->fechaEnvio, this->crearInfoMsg(), this->emisor->getDataUsuario());
  return image;
}
