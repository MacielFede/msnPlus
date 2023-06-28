#ifndef UTILS_H
#define UTILS_H
#include <string>
#include <algorithm>
#include "clases/Relojito.h"
// #include "fabrica/Fabrica.h"

void menuFechayHora();


string numFormat(string val);

void imprimirConversaciones(bool activas);

void getInt(string mensaje, int& numero);


#endif
