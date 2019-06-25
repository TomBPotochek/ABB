#include "Familia.h"
//#include "Consola.h"
#include "Lista.h"


Familia::Familia (Lista<string>* nombres,):Cliente (telefono) {
    this->nombres = nombres;
    this->descuento = DESCUENTO_F;
}

Lista<string>* Familia::obtenerNombre(){
    return this->nombres;
}

void Familia::imprimirDatos(){
    cout << telefono << endl;
    nombres->iniciarCursor();
    while (nombres->avanzarCursor())
        cout << nombres->obtenerCursor() << endl;
}


void Familia::asignarNombre (Lista<string>* nombres){
    this->nombres = nombres;
}



double Familia::calcularPrecio (int precio){
    double precioTotal = nombres->tamanio*precio*(1-descuento);
    return precioTotal;
}

