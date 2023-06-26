#ifndef DTCONVERSACION_H
#define DTCONVERSACION_H

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class DtConversacion
{
protected:
    string idConv, nomUsuario;
    // Si la conversacion es un grupo nomUsuario = "-". No creo otro DT porque no puedo usar Dynamic_cast para saber el tipo de la conversacion
    bool activa;

public:
    // Constructor
    DtConversacion();
    DtConversacion(string idConv, bool activa, string nomUser);

    // Getters
    string getIdConv();
    string getNomUsuario();
    bool getActiva();

    // Destructor
    ~DtConversacion();

};

#endif