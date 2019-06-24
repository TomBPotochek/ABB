#include "Cliente.h"

Cliente::Cliente (string telefono){
    this->telefono = telefono;
}

unsigned long Cliente::obtenerTelefono (){
    return this->telefono;
}


void Cliente::asignarTelefono (string telefono){
    this->telefono = telefono;
}






