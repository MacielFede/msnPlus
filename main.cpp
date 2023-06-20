#include <string>
#include "h/fabrica/Fabrica.h"
#include "h/interfaces/IAutenticacion.h"
#include "h/interfaces/IConversacion.h"
#include "h/interfaces/IContacto.h"
#include "h/clases/Relojito.h"

int main()
{
    string comando;
    Relojito& relojito = Relojito::getRelojito();
    Fabrica& fabrica = Fabrica::getFabrica();
    IConversacion Cconv = fabrica.getCConv();
    IAutenticacion Caut = fabrica.getCAut();
    IContacto Ccont = fabrica.getCCont();

    cout << "\nBienvenido a su mejor chat. Recuerde, para ejecutar los comandos debe ingresar siempre el numero del mismo.\n\n";
#pragma region AbrirApp
    // TODO: ACA HACER ABRIR APP

#pragma endregion

#pragma region MenuPrincipal

    do {
        cout << "\nComandos:\n";
        cout << "1 - Mostrar Conversaciones.\n";
        cout << "2 - Crear grupo.\n";
        cout << "3 - Enviar mensaje.\n";
        cout << "4 - Ver contactos.\n";
        cout << "5 - Modificar perfil.\n";
        cout << "6 - Ver fecha y hora actual.\n";
        cout << "7 - Actualizar fecha y hora actual.\n";
        cout << "8 - Cerrar app.\n\n";
        cout << "Que desea hacer? ";

        fflush(stdin);
        // fflush() limpia el buffer del sistema, como estamos usando el buffer de la libreria std siempre puede quedarnos basura en el buffer
        getline(cin, comando);
        // getLine() lee 1 linea (osea hasta encontrar un \n) y guarda todo en la variable string que le pasemos
        // cin es el buffer de la libreria std (character in)
        switch (comando[0])
        {
        case '1':
#pragma region MostrarConvers
            //TODO: Mostrar conversaciones
            //**** Habria que en vez de poner 2 opciones de ver mensaje y eliminar mensaje, poner 1 sola que diga Abrir conversacion,
            //**** Ahi adentro estara despues de mostrar los mensajes de la conversacion, las opciones de mostrar mas info de un mensaje o eliminar un mensaje
#pragma endregion
            break;

        case '2':
#pragma region Crear grupo
            //TODO: Crear grupo
#pragma endregion
            break;

        case '3':
#pragma region EnviarMensaje
            //TODO: Enviar mensaje
#pragma endregion
            break;

        case '4':
#pragma region VerContactos
            //TODO: Ver contactos
#pragma endregion
            break;

        case '5':
#pragma region ModificarPerfil
            //TODO: Modificar Perfil
#pragma endregion
            break;

        case '6':
#pragma region VerReloj
            //TODO: Relojito
#pragma endregion
            break;

        case '7':
#pragma region ActualizarReloj
            //TODO: Relojito
#pragma endregion
            break;

        case '8':
            cout << "\nNos vemos pronto!\n";
            break;

        default:
            cout << "Ingresaste un comando inexistente.\n";
            break;
        }
    } while (comando[0] != '8');

#pragma endregion

    //TODO: Eliminar todo
    return 0;
}