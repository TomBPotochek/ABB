#include "Familia.h"
//#include "Consola.h"
#include "Lista.h"


Familia::Familia (Lista<string>* nombres, unsigned long int telefono): Cliente (telefono) {
    this->nombres = nombres;
    this->descuento = DESCUENTO_F;
}

Lista<string>* Familia::obtenerNombres(){
    return this->nombres;
}

void Familia::imprimirDatos(){
    cout << endl << telefono << "  ";
    nombres->iniciarCursor();
    while (nombres->avanzarCursor())
        cout << nombres->obtenerCursor() << " ";
}


void Familia::asignarNombres (Lista<string>* nombres){
    this->nombres = nombres;
}



double Familia::calcularPrecio (int precio){

    double precioTotal = this->nombres->contarElementos()*precio*(1-descuento);
    return precioTotal;
}

