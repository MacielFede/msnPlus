#include "../../h/controladores/CContacto.h"


using namespace std;

CContacto* CContacto::instancia = nullptr;

// Le doy valor a la instancia como null para que solo la primera vez creemos la instancia

CContacto& CContacto::getCContacto()
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

CContacto& CContacto::operator=(const CContacto&)
{
    return *this;
}

list<DtContacto> CContacto::listarContactos()
{
    CAutenticacion &Caut = CAutenticacion::getCAutenticacion();

    Usuario *u = Caut.getSesionActiva();
    map<string, DtContacto> uContacts = u->listarContactos();

    list<DtContacto> dtContacts;

    for (const auto &[key, value] : uContacts)
    {
        dtContacts.push_back(value);
    }

    return dtContacts;
}

Usuario CContacto::ingresarNumeroContacto(string cNumTel) {}
void CContacto::agregarContacto(string cNumTel)
{
    if (esContacto(cNumTel)) return;

    //Fabrica& fabrica = Fabrica::getFabrica();
    //CAutenticacion Caut = fabrica.getCAut();

    CAutenticacion& Caut = CAutenticacion::getCAutenticacion();

    Usuario* u = Caut.getSesionActiva();
    Usuario* newContact = Caut.infoUsuario(cNumTel);

    u->agregarContacto(newContact);
}
bool CContacto::esContacto(string cNumTel)
{
    //Fabrica& fabrica = Fabrica::getFabrica();
    CAutenticacion& Caut = CAutenticacion::getCAutenticacion();
    Usuario* u = Caut.getSesionActiva();
    return u->listarContactos().count(cNumTel);
}
DtContacto CContacto::numToContacto(string cNumTel)
{
    //Usuario c;
    DtContacto dtC("ab", "ab", "ab");

    return dtC;
}