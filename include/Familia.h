#ifndef FAMILIA_H
#define FAMILIA_H
#include <iostream>

#define DESCUENTO = 0.35;

class Familia : public Cliente {

    private:

        "lista" nombre; //esto en realidad deberia ser una lista de nombres
        double descuento;


    public:

        Familia (string nombre, double descuento);


        string obtenerNombre ();
        void asignarNombre (string nombre);


        double calcularPrecio (int precio);

};

#endif // FAMILIA_H
