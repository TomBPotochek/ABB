#ifndef INDIVIDUO_H
#define INDIVIDUO_H
#include <iostream>
#include <Cliente.h>

const double DESCUENTO_I = 0.10;

class Individuo : public Cliente {

    private:

        string nombre;


    public:

        // PRE: --
        // POST: Crea un objeto de clase Individuo con los datos indicados.
        Individuo (string nombre, unsigned long int telefono);

        // PRE: --
        // POST: Devulve el nombre del individuo.
        string obtenerNombre ();

        // PRE: --
        // POST: Modifica el nombre del individuo.
        void asignarNombre (string nombre);

        // PRE: --
        // POST: Devuelve el precio total a pagar aplicando un descuento a precioFijo.
        double calcularPrecio (int precioFijo);

		// PRE: --
		// POST: imprime nombre y telefono del individuo
        void imprimirDatos ();

};

#endif // INDIVIDUO_H
