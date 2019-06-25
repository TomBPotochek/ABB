#include "Individuo.h"


Individuo::Individuo (string nombre, double descuento):Cliente(telefono) {
    this->nombre = nombre;
    this->descuento = descuento;
}

string Individuo::obtenerNombre (){
    return this->nombre;
}


void Individuo::asignarNombre (string nombre){
    this->nombre = nombre;
}



double Individuo::calcularPrecio (int precio){
    double precioTotal = precio*(1-descuento);
    return precioTotal;
}


void Individuos::imprimirDatos (){
    cout << this->telefono << endl;
    cout << this->nombre << endl;
}
