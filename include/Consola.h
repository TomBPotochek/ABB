#ifndef CONSOLA_H
#define CONSOLA_H

#include <iostream>
#include <string>

using namespace std;

class Consola {

    public:

        // PRE: --
        // POST: la consola queda lista para usar
        Consola();


		// PRE: --
        // POST: muestra por consola el menu de operaciones
        void imprimirMenu();

		// PRE: --
        // POST: Devuelve la opcion ingresada por el usuario luego de corroborar que sea correcta.
        int ingresarOpcion();

		// PRE: --
		// POST: Devuelve un nombre ingresado por el usuario
		string ingresarNombre();

		// PRE: --
		// POST: Muestra por consola un mensaje generico
		void imprimirMensaje(string mensaje);

		// PRE: --
		// POST: Devuelve un numero de telefono ingresado por el usuario
		unsigned long int ingresarTelefono();

		// PRE: --
		// POST: Indica si el usuario desea continuar ingresando nombres
		bool continuarIngresando();

		// PRE: --
		// POST: muestra por consola un mensaje que indica que no existe el cliente con numero ingresando
		void errorClienteNoEncontrado();

		// PRE: --
		// POST: Devuelve un precio ingresado por el usuario
		double ingresarPrecio();

		// PRE: --
		// POST: muestra por consola un precio
		void imprimirPrecio(float precio);
};

#endif // CONSOLA_H
