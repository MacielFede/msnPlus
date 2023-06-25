#include "../h/utils.h"

void menuFechayHora() {
    string comando;
    int valor, dia, mes, anio, horas, minutos;
    DtFecha fecha;
    Relojito& relojito = Relojito::getRelojito();
    do {
        cout << "\nComandos:\n";
        cout << "1 - Actualizar fecha y hora manualmente.\n";
        cout << "2 - Actualizar fecha y hora con la actual del sistema.\n";
        cout << "3 - Volver al menu anterior.\n\n";
        cout << "Que desea hacer? > ";
        fflush(stdin);
        getline(cin, comando);

        switch (comando[0])
        {
        case '1':
            do {
                cout << "\nIngresar día (1-31):\n";
                cin >> valor;
            } while (valor > 31 || valor < 1); // Se controla para que salga cuando se ingrese un día válido.
            dia = valor;
            do {
                cout << "\nIngresar mes (1-12):\n";
                cin >> valor;
            } while (valor > 12 || valor < 1); // Se controla para que salga cuando se ingrese un día válido.
            mes = valor;
            do {
                cout << "\nIngresar anio (>= 1900):\n";
                cin >> valor;
            } while (valor < 1900); // Se controla para que salga cuando se ingrese un día válido.
            anio = valor;
            do {
                cout << "\nIngresar horas (0-23):\n";
                cin >> valor;
            } while (valor > 23 || valor < 0); // Se controla para que salga cuando se ingrese un día válido.
            horas = valor;
            do {
                cout << "\nIngresar minutos (0-59):\n";
                cin >> valor;
            } while (valor > 59 || valor < 0); // Se controla para que salga cuando se ingrese un día válido.
            minutos = valor;
            fecha = DtFecha(dia, mes, anio, horas, minutos);
            relojito.actualizarFecha(fecha);
            cout << "Se actualizó la fecha y hora correctamente: ";
            relojito.getFechaActual().imprimirFechayHora();
            break;
        case '2':
            relojito.actualizarFecha();
            cout << "Se actualizó la fecha y hora correctamente: ";
            relojito.getFechaActual().imprimirFechayHora();
            break;
        case '3':
            cout << "Volviendo al menu anterior.\n";
            break;
        default:
            cout << "Ingresaste un comando inexistente.\n";
            break;
        }
    } while (comando[0] != '3');
}


void imprimirConversaciones(bool activas) {
    IConversacion& Cconv = Fabrica::getFabrica().getCConv();
    list<DtConversacion> convers = Cconv.listarConversaciones();
    list<DtConversacion>::iterator iter;
    cout << "\tId de conversacion\tNombre de contacto\n";
    if (activas) {
        int cantArchiv = 0;
        for (iter = convers.begin(); iter != convers.end(); ++iter) {
            if (iter->getActiva())
                cout << "\t" << iter->getIdConv() << "\t" << iter->getNomUsuario() << "\n";
            else
                cantArchiv++;
        }
        cout << "Archivadas: " << cantArchiv << endl;
    }
    else {
        int cantActivas = 0;
        for (iter = convers.begin(); iter != convers.end(); ++iter) {
            if (!iter->getActiva())
                cout << "\t" << iter->getIdConv() << "\t" << iter->getNomUsuario() << "\n";
            else
                cantActivas++;
        }
        cout << "Activas: " << cantActivas << endl;
    }
}