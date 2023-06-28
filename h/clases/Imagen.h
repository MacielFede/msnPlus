#ifndef IMAGEN_H
#define IMAGEN_H

#include "Mensaje.h"
#include "../dataTypes/DtImagen.h"
class Imagen : public Mensaje
{
private:
  string formatoImg, tamano, descripcion;

public:
  Imagen(map<string, Usuario*> receptores, DtFecha fechaEnv, Usuario* emisor, int ultimoId, string formato, string tam, string desc);

  string getUrl();
  string getFormato();
  string getTamano();
  string getDescripcion();

  DtMensaje* getDataMensaje();

  ~Imagen();
};

#endif