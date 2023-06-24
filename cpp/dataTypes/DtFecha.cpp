#include "../../h/dataTypes/DtFecha.h"

// Constructor por defecto
DtFecha::DtFecha()
{
    this->dia = 1;
    this->mes = 1;
    this->anio = 2000;
    this->horas = 0;
    this->minutos = 0;
}

// Constructor con parámetros
DtFecha::DtFecha(int dia, int mes, int anio, int horas, int minutos)
{
    /*try
    {
        if (dia > 31 || mes < 1 || anio > 12 || mes < 1 || anio < 1900 || horas < 0 || horas > 23 || minutos < 0 || minutos > 59)
        {
            throw invalid_argument("\nFecha inválida.");
        }*/
        this->dia = dia;
        this->mes = mes;
        this->anio = anio;
        this->horas = horas;
        this->minutos = minutos;
    /*}
    catch (invalid_argument &i)
    {
        cout << i.what() << endl;
    }*/
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

string imprNum(int num) {
    return (num < 10) ? ("0" +  to_string(num)) : to_string(num);
}

void DtFecha::imprimirFecha()
{
    cout << "[" << imprNum(this->dia) << "/" << imprNum(this->mes) << "/" << this->anio << "]" << endl;
}

void DtFecha::imprimirFechayHora() 
{
    cout << "[" << imprNum(this->dia) << "/" << imprNum(this->mes) << "/" << this->anio << " " << imprNum(this->horas) << ":" << imprNum(this->minutos) << "]" << endl;
}

// Destructor
DtFecha::~DtFecha() {}