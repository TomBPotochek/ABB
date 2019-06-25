#include "Consola.h"

using namespace std;


void Consola::imprimirMenu(){

    cout << endl << endl << "MENU PRINCIPAL" << endl << " Elija una opcion:" << endl << endl
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
        opcionValida = (opcion > 0 && opcion < 7);

        if (!opcionValida)
            cout << endl << "Ingrese una opcion valida.";
    }

    return opcion;
}


string Consola::ingresarNombre() {

	string nombre;

	cout << "Ingrese el nombre de la persona";
	cin >> nombre;

	return nombre;
}

void Consola::imprimirMensaje(string mensaje) {

	cout << endl << mensaje << endl;
}

unsigned long int Consola::ingresarTelefono(){

	unsigned long int telefono;

	cout << endl << "Ingrese el numero del cliente" << endl;
	cin >> telefono;

	return telefono;
}

bool Consola::continuarIngresando() {

	char opcion;

	cout << endl << "Desea continuar ingresando nombres? s/n" << endl;
	cin >> opcion;

	return (opcion == 's');
}

void Consola::errorClienteNoEncontrado() {

	cout << endl << "Error: no existe un cliente con el telefono ingresado";
}

double Consola::ingresarPrecio(){

	double precio;

	cout << endl << "Ingrese el precio fijo del producto" << endl;
	cin >> precio;

	return precio;
}

void Consola::imprimirPrecio(float precio){

	cout << endl << "Precio a pagar: " << precio << endl;
}
