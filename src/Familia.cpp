#include "Familia.h"
//#include "Consola.h"
#include "Lista.h"


Familia::Familia (Lista<string>* nombres, double descuento):Cliente (std::string telefono) {
    this->nombres = nombres;
    this->descuento = descuento;
}

Lista<string>* Familia::obtenerNombre(){
    return this->nombres;
}

void Familia::imprimirIntegrantes(){
    nombres->iniciarCursor();
    while (nombres->avanzarCursor())
        cout << nombres->obtenerCursor(); 
}


void Familia::asignarNombre (Lista<string>* nombres){
    this->nombres = nombres;
}



double Familia::calcularPrecio (int precio){
    double precioTotal = nombres->tamanio*precio*(1-descuento);
    return precioTotal;
}

