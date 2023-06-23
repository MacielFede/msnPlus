#include "../../h/clases/Participante.h"

Participante::Participante(Usuario * soy, DtFecha fecha, bool soyAdmin){
    this->administrador = soyAdmin;
    this->fechaIngreso = fecha;
    this->usuario = soy;
}

Participante::~Participante(){}