#ifndef VISTO_H
#define VISTO_H

//#include "Usuario.h"

class Visto {
private:
  //Usuario * receptor;
  bool visto;
public:
  Visto();
  ~Visto();

  void setVisto();
  // Pre: Visto debe ser false. Post: Visto cambia a true
  bool getVisto();
  //Usuario getReceptor();
};

#endif