#ifndef CONSOLA_H
#define CONSOLA_H

#include <iostream>

class Consola {

    public:

        // PRE: --
        // POST: la consola queda lista para usar
        Consola();


        // POST: muestra por consola el menu de operaciones
        void imprimirMenu();

        // POST: Devuelve la opcion ingresada por el usuario loego de corroborar que sea correcta.
        int ingresarOpcion();
};

#endif // CONSOLA_H
