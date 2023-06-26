#ifndef DTVIDEO_H
#define DTVIDEO_H

#include <iostream>
#include <string>
#include "DtMensaje.h"

using namespace std;

class DtVideo : public DtMensaje
{
private:
  string duracion;
public:
  // Constructor
  DtVideo(string duracion, int idMen, DtFecha fechaEnv, list<DtVisto> infoMens, DtUsuario emisor);

  // Getters
  string getNumTel();
  string getNombre();
  // Destructor
  ~DtVideo();
  void imprimir();
  // friend ostream &operator<<(ostream &o, DtContacto &s);
};

#endif