#ifndef DTIMAGEN_H
#define DTIMAGEN_H

#include <iostream>
#include <string>
#include "DtMensaje.h"

using namespace std;

class DtImagen : public DtMensaje
{
private:
  string formatoImg, tamano, descripcion;
public:
  // Constructor
  DtImagen();
  DtImagen(string formatoImg, string descripcion, string tamano, int idMen, DtFecha fechaEnv, list<DtVisto> infoMens);

  // Destructor
  ~DtImagen();
  void imprimir();

};

#endif