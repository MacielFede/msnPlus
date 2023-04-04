#ifndef SOCIO_H
#define SOCIO_H

#include <iostream>
#include <string>
using namespace std;

class Socio
{
private:
  string ci, nombre;

public:
  Socio(string ci, string nombre);
  Socio();
  //Constructor
  string getCI();
  string getNombre();
  //Getters
  void setCI(string nuevaCi);
  void setNombre(string nuevoNombre);
  //Setters
  ~Socio();
  //Destructor
};

#endif