#ifndef VISTO_H
#define VISTO_H

#include "Usuario.h"
#include "../dataTypes/DtFecha.h"
#include "../dataTypes/DtVisto.h"

class Visto {
private:
  Usuario* receptor;
  bool visto;
  DtFecha fechaV;
public:
  Visto(Usuario* recep, DtFecha fecha);
  ~Visto();

  void setVisto();
  // Pre: Visto debe ser false. Post: Visto cambia a true
  bool getVisto();
  Usuario getReceptor();
  DtVisto getDataVisto();
};

#endif