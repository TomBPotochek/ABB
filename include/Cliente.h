#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>

class Cliente {

    private:

        string telefono;
        double descuento;

    public:
        //Costructor
        //PRE: Se debe respetar el tipo de dato de los parametros.
        //POST: Crea un objeto de clase cliente.
        Cliente (unsigned long int telefono);

        //PRE: --
        //POST: Devuelve el telefono del cliente.
        unsigned long int obtenerTelefono ();

        //PRE: Se debe respetar el tipo de dato de los parametros.
        //POST: Modifica el telefono del cliente.
        void asignarTelefono (string dato);

        virtual imprimirIntegrantes () = 0;
        virtual double calcularPrecio (int precio) = 0;

};

#endif // CLIENTE_H
