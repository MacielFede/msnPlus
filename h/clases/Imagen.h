#ifndef IMAGEN_H
#define IMAGEN_H

#include "Mensaje.h"
#include "../dataTypes/DtImagen.h"
class Imagen : public Mensaje
{
private:
  string formatoImg, tamano, descripcion, url;

public:
  Imagen(map<string, Usuario*> receptores, DtFecha fechaEnv, Usuario* emisor, int ultimoId, string formato, string tam, string desc, string url);

  string getUrl();
  string getFormato();
  string getTamano();
  string getDescripcion();

  DtMensaje* getDataMensaje();

  ~Imagen();
};

#endif