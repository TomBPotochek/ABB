#include "Cliente.h"

Cliente::Cliente (std::string telefono){
    this->telefono = telefono;
}

unsigned long Cliente::obtenerTelefono (){
    return this->telefono;
}


void Cliente::asignarTelefono (std::string telefono){
    this->telefono = telefono;
}






