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

string numFormat(string val)
{
    val.erase(remove(val.begin(),
                          val.end(),
                          ' '),
              val.end());

    return val;
}

void getInt(string mensaje, int& numero) {
    string input;
    bool numConvertido = false;
    cout << mensaje;
    do {
        try {
            getline(cin, input);
            stoi(input);
            numero = stoi(input);
            //stoi() agarra el string pasado y lo intenta convertir en un int. Si hay un error corta la funcion, 
            // al estar dentro de un try-catch una vez lanzado el error se corta la ejecucion
            if (numero < 1) { cout << "-Debes ingresar un numero valido-\n"; }
            else { numConvertido = true; }
        }
        catch (const exception& error) {
            cout << "\n-Debes ingresar un numero valido-\n";
        }
    } while (!numConvertido);
    fflush(stdin);
    numero = stoi(input);
}