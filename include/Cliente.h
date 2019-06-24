#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>

class Cliente {

    private:

        unsigned long telefono;

    public:

        Cliente (unsigned long telefono);
        
        unsigned long obtenerTelefono ();
        void asignarTelefono (unsigned long dato);


        virtual double calcularPrecio (int precio) = 0;

};

#endif // CLIENTE_H
