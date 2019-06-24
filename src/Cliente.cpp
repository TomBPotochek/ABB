#include "Cliente.h"

Cliente::Cliente (unsigned long telefono){
    this->telefono = telefono;
}

unsigned long Cliente::obtenerTelefono (){
    return this->telefono;
}


void Cliente::asignarTelefono (unsigned long telefono){
    this->telefono = telefono;
}






