#include "Consola.h"

using namespace std;

Consola::Consola()
{
    //ctor
}

void Consola::imprimirMenu(){

    cout << endl << "MENU PRINCIPAL" << endl << " Elija una opcion:" << endl << endl
         << "1. Consultar precio" << endl
         << "2. Agregar un nuevo cliente" << endl
         << "3. Dar de baja un cliente" << endl
         << "4. Listar clientes" << endl
         << "5. Buscar cliente" << endl
         << "6. Salir" << endl << endl;

}

int Consola::ingresarOpcion() {

    int opcion;
    bool opcionValida = false;

    while (!opcionValida) {
        cin >> opcion;
        opcionValida = (opcion > 0 && opcion < 5);

        if (!opcionValida)
            cout << endl << "Ingrese una opcion valida.";
    }

    return opcion;
}

*Cliente Consola::ingresarCliente() {
	
}

unsigned long int Consola::ingresarTelefono(){

}

void errorClienteNoEncontrado() {
	
}

float ingresarPrecio(){
	
}

void imprimirPrecio(float precio){
	
}
