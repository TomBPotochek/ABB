#ifndef INDIVIDUO_H
#define INDIVIDUO_H
#include <iostream>

#define DESCUENTO = 0.10;

class Individuo : public Cliente {

    private:

        string nombre;
        double descuento;


    public:

        Individuo (string nombre, double descuento);


        string obtenerNombre ();
        void asignarNombre (string nombre);


        double calcularPrecio (int precio);

};

#endif // INDIVIDUO_H
