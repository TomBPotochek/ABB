#ifndef FAMILIA_H
#define FAMILIA_H

#include <Cliente.h>
#include <iostream>
#include <Lista.h>

const double DESCUENTO_F = 0.35;

class Familia : public Cliente {

    private:

        Lista<string>* nombres;


    public:

        // PRE: nombres != 0
        // POST: Crea un objeto de clase Familia con los datos indicados.
        Familia (Lista<string>* nombres, unsigned long int telefono);

        // PRE: --
        // POST: Devuelve una lista con los nombres de la familia.
        Lista<string>* obtenerNombres ();

        // PRE: nombres != 0
        // POST: Modifica los nombres de los integrantes de la familia.
        void asignarNombres (Lista<string>* nombres);

        // PRE: --
        // POST: Devuelve el precio total a pagar aplicando un descuento a precioFijo
        //       El total a pagar es la sumatoria de los precios individuales
        double calcularPrecio (int precio);

        // PRE: --
        // POST: Lista los nombres de los integrantes de la familia y el telefono
        void imprimirDatos ();
};

#endif // FAMILIA_H
