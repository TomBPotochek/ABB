#include "Individuo.h"


Individuo::Individuo (string nombre,):Cliente(telefono) {
    this->nombre = nombre;
    this->descuento = DESCUENTO_I;
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
