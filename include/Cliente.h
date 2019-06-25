#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <string>

using namespace std;

class Cliente {

    protected:

        unsigned long int telefono;
        double descuento;

    public:
        //Costructor
        //PRE: Se debe respetar el tipo de dato de los parametros.
        //POST: Crea un objeto de clase cliente.
        Cliente (unsigned long int telefono);

        // PRE: --
        // POST: devuelve el descuento a aplicarse de acuerdo al tipo de cliente
        double obtenerDescuento();

        //PRE: --
        //POST: Devuelve el telefono del cliente.
        unsigned long int obtenerTelefono ();

        virtual void imprimirDatos () = 0;

        virtual double calcularPrecio (int precio) = 0;

};

#endif // CLIENTE_H
