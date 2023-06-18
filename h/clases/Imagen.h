#ifndef IMAGEN_H
#define IMAGEN_H

#include "Mensaje.h"

class Imagen : public Mensaje
{
private:
  string url, formatoImg, tamano, descripcion;
public:
  //Imagen(map<string, Usuario> &receptores, DtRelojito fechaSistema, Usuario &emisor, string URL, string formato, string tam, string desc);
  ~Imagen();

  string getUrl();
  string getFormato();
  string getTamano();
  string getDescripcion();


  DtMensaje getDataMensaje();
  DtInfoMensaje crearInfoMsg();
};

#endif