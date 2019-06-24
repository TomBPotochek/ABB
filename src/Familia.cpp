#include <Familia.h>


Familia::Familia (Lista<string>* nombres, double descuento):Cliente (unsigned long telefono) {
    this->nombres = nombres;
    this->descuento = DESCUENTO_F;
}

string Familia::obtenerNombre(){
    return this->nombres;
}


void Familia::asignarNombre (Lista<string>* nombres){
    this->nombres = nombres;
}



double Familia::calcularPrecio (int precio){
    double precioTotal = precio*descuento;
    return precioTotal;
}

