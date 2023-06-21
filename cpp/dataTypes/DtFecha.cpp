#include "../../h/dataTypes/DtFecha.h"

// Constructor por defecto
DtFecha::DtFecha()
{
    this->dia = 1;
    this->mes = 1;
    this->anio = 2000;
    this->horas = 0;
    thos->minutos = 0;
}

// Constructor con parámetros
DtFecha::DtFecha(int dia, int mes, int anio, int horas, int minutos)
{
    try
    {
        if (dia > 31 || mes < 1 || anio > 12 || mes < 1 || anio < 1900 || horas < 0 || horas > 23 || minutos < 0 || minutos > 59)
        {
            throw invalid_argument("\nFecha inválida.");
        }
        this->dia = dia;
        this->mes = mes;
        this->anio = anio;
    }
    catch (invalid_argument &i)
    {
        cout << i.what() << endl;
    }
}

// Getters
int DtFecha::getDia()
{
    return this->dia;
}

int DtFecha::getMes()
{
    return this->mes;
}

int DtFecha::getAnio()
{
    return this->anio;
}

int DtFecha::getHoras()
{
    return this->horas;
}

int DtFecha::getMinutos()
{
    return this->minutos;
}

// Métodos
bool DtFecha::esValida()
{
    return !(this->dia > 31 || this->mes < 1 || this->anio > 12 || this->mes < 1 || this->anio < 1900 || this->horas < 0 || this->horas > 23 || this->minutos < 0 || this->minutos > 59);
}

void DtFecha::imprimirFecha()
{
    cout << "[" << this->dia << "/" << this->mes << "/" << this->anio << "]" << endl;
}

void DtFecha::imprimirFechayHora() 
{
    cout << "[" << this->dia << "/" << this->mes << "/" << this->anio << this->horas << ":" << this->minutos << "]" << endl;
}

// Destructor
DtFecha::~DtFecha() {}
