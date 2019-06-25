#include "Cliente.h"

Cliente::Cliente (unsigned long int telefono) {
    this->telefono = telefono;
}

double Cliente::obtenerDescuento() {

    return this->descuento;
}

unsigned long Cliente::obtenerTelefono () {
    return this->telefono;
}
