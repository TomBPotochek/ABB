#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>

class Cliente {

    private:

        string telefono;

    public:
        //Costructor
        //PRE: Se debe respetar el tipo de dato de los parametros.
        //POST: Crea un objeto de clase cliente.
        Cliente (string telefono);

        //PRE: --
        //POST: Devuelve el telefono del cliente.
        string obtenerTelefono ();

        //PRE: Se debe respetar el tipo de dato de los parametros.
        //POST: Modifica el telefono del cliente.
        void asignarTelefono (string dato);

        virtual imprimirIntegrantes () = 0;
        virtual double calcularPrecio (int precio) = 0;

};

#endif // CLIENTE_H
