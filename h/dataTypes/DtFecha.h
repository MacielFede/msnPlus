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

    bool operator==(const DtFecha& fecha);
    friend ostream& operator<<(ostream& o, DtFecha& f);
    // Destructor
    ~DtFecha();

    // Métodos
    bool esValida();
};

#endif
