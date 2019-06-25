#ifndef FAMILIA_H
#define FAMILIA_H

#include <iostream>

const double DESCUENTO_F = 0.35;

class Familia : public Cliente {

    private:

        Lista<string>* nombres;


    public:

        //Costructor
        //PRE: Se debe respetar el tipo de dato de los parametros.
        //POST: Crea un objeto de clase Familia.
        Familia (Lista<string>* nombres,):Cliente (telefono);

        //PRE:--
        //POST: Dvuelve los nombres de la familia.
        Lista<string>* obtenerNombre ();

        //PRE: Se debe respetar el tipo de dato de los parametros.
        //POST: Modifica los nombres de los integrantes de la familia.
        void asignarNombre (Lista<string>* nombres);

        //PRE: Se debe respetar el tipo de dato de los parametros.
        //POST: Devuelve el precio total a pagar por la familia.
        double calcularPrecio (int precio);

        //PRE:--
        //POST: Lista los nombres de los integrantes de la familia.
        void imprimirDatos ();


};

#endif // FAMILIA_H
