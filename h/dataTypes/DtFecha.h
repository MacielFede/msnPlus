#ifndef DTFECHA_H
#define DTFECHA_H
#include <iostream>
using namespace std;

class DtFecha
{
private:
    // No tiro enie aca porque sino puede colapsar todo
    int dia, mes, anio, horas, minutos;

public:
    // Constructores
    DtFecha();
    DtFecha(int dia, int mes, int anio, int horas, int minutos);
    // Getters
    int getDia();
    int getMes();
    int getAnio();
    int getHoras();
    int getMinutos();

    // Métodos
    bool esValida();
    void imprimirFecha();
    void imprimirFechayHora();
    bool esMayor(DtFecha fecha);

    // Destructor
    ~DtFecha();
};

#endif
