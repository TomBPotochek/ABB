#include <Individuo.h>


Individuo::Individuo (string nombre, double descuento){
    this->nombre = nombre;
    this->descuento = DESCUENTO;
}

string Individuo::obtenerNombre (){
    return this->nombre;
}


void Individuo::asignarNombre (string nombre){
    this->nombre = nombre;
}



double Individuo::calcularPrecio (int precio){
    double precioTotal = precio*descuento;
    return precioTotal;
}
