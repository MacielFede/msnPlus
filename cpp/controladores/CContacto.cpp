#include "../../h/controladores/CContacto.h"


using namespace std;

CContacto* CContacto::instancia = nullptr;

// Le doy valor a la instancia como null para que solo la primera vez creemos la instancia

CContacto &CContacto::getCContacto()
{
    if (instancia == nullptr)
    {
        instancia = new CContacto();
    }
    // Si la instancia ya fue creada retorno una referencia a la misma instancia
    return *instancia;
}

CContacto::CContacto() {}

CContacto::~CContacto()
{
}

void CContacto::liberarInstancia()
{
    if (instancia != nullptr)
    {
        delete instancia;
        instancia = nullptr;
    }
}

CContacto &CContacto::operator=(const CContacto &)
{
    return *this;
}


list<DtContacto> CContacto::listarContactos(){}
Usuario CContacto::ingresarNumeroContacto(string cNumTel){}
void CContacto::agregarContacto(string cNumTel){}