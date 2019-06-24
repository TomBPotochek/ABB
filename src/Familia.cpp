#include <Familia.h>
/* Deberia estar con Arbols

Familia::Familia (string nombre, double descuento){
    this->nombre = nombre;
    this->descuento = DESCUENTO;
}

string Familia::obtenerNombre (){
    return this->nombre;
}


void Familia::asignarNombre (string nombre){
    this->nombre = nombre;
}

*/

double Familia::calcularPrecio (int precio){
    double precioTotal = precio*descuento;
    return precioTotal;
}

