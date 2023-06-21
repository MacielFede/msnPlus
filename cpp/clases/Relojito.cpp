#include "../../h/clases/Relojito.h"
#include <chrono>
#include <ctime>

// Se asigna valor null para que se cree la instancia solo la primera vez
Relojito *Relojito::instancia = nullptr;

Relojito &Relojito::getRelojito()
{
    if (instancia == nullptr)
    {
        instancia = new Relojito();
    }

    // Si la instancia ya fue creada, se retorna una referencia a la misma
    return *instancia;
}

DtFecha Relojito::fechaSistema()
{
    // Obtener el tiempo actual del sistema
    auto actual = chrono::system_clock::now();

    // Convertir el tiempo actual a un formato de tiempo legible
    time_t tiempoActual = chrono::system_clock::to_time_t(actual);

    // Obtener una estructura de tiempo local a partir de tiempoActual
    tm *tiempoLocal = localtime(&tiempoActual);

    // Obtener los componentes individuales
    int dia = tiempoLocal->tm_mday;         // Día del mes (1-31)
    int mes = tiempoLocal->tm_mon + 1;      // Mes (0-11, se agrega 1 para que sea 1-12)
    int anio = tiempoLocal->tm_year + 1900; // Año (se agrega 1900)
    int horas = tiempoLocal->tm_hour;       // Hora (0-23)
    int minutos = tiempoLocal->tm_min;      // Minutos (0-59)
    DtFecha fecha = DtFecha(dia, mes, anio, horas, minutos);
    return fecha;
}

Relojito::Relojito()
{
    DtFecha fechaSistema = this->fechaSistema();
    this->dia = fechaSistema.getDia();
    this->mes = fechaSistema.getMes();
    this->anio = fechaSistema.getAnio();
    this->horas = fechaSistema.getHoras();
    this->minutos = fechaSistema.getMinutos();
}

DtFecha Relojito::getFechaActual()
{
    DtFecha fecha = DtFecha(this->dia, this->mes, this->anio, this->horas, this->minutos);
    return fecha;
}

// Método para actualizar fecha con parámetro
void Relojito::actualizarFecha(DtFecha fechaNueva)
{
    this->dia = fechaNueva.getDia();
    this->mes = fechaNueva.getMes();
    this->anio = fechaNueva.getAnio();
    this->horas = fechaNueva.getHoras();
    this->minutos = fechaNueva.getMinutos();
}

// Método para actualizar la fecha con la actual del sistema
void Relojito::actualizarFecha()
{
    DtFecha fechaSistema = this->fechaSistema();
    this->dia = fechaSistema.getDia();
    this->mes = fechaSistema.getMes();
    this->anio = fechaSistema.getAnio();
    this->horas = fechaSistema.getHoras();
    this->minutos = fechaSistema.getMinutos();
}

Relojito::~Relojito() {}