#ifndef INDIVIDUO_H
#define INDIVIDUO_H
#include <iostream>

//#define DESCUENTO_I = 0.10;

class Individuo : public Cliente {

    private:

        string nombre;
        double descuento;


    public:
        //Costructor
        //PRE: Se debe respetar el tipo de dato de los parametros.
        //POST: Crea un objeto de clase Individuo.
        Individuo (string nombre, double descuento):Cliente (unsigned long telefono);

        //PRE:--
        //POST: Devulve el nombre del individuo.
        string obtenerNombre ();

        //PRE: Se debe respetar el tipo de dato de los parametros
        //POST: Modifica el nombre del individuo.
        void asignarNombre (string nombre);

        //PRE: Se debe respetar el tipo de dato de los parametros
        //POST: Devuelve el precio total a pagar del individuo.
        double calcularPrecio (int precio);

};

#endif // INDIVIDUO_H
