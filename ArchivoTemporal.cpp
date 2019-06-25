

#include "Lista.h"
#include <fstream>

void cargarArchivo(const char* nombreArchivo){
    ifstream archivo(nombreArchivo);
    this->clientes = new ABB<std::string, Cliente*>;
    
    if (archivo.is_open()) {
        while (!archivo.eof()){ //o tal vez tenga que ser "while(getline(linea))" ?
            linea = getline(archivo);
            this->cargarCliente(std::string linea);
            
        }        
    }

    archivo.close();
}


void cargarCliente(ABB<std::string, Cliente*>* clientes, std::string linea){
    unsigned int posComa = linea.find(",");
    unsigned long int = this->procesarTelefono(linea.substr(0,pos));

	linea = linea.substr(pos+1);
    posComa = linea.find(",");

    if (pos == string::npos) {
        Individuo* individuo = new Individuo(linea, telefono); //era asi para usar el constructor heredado de cliente?
        this->clientes->agregar(telefono, individuo);

    } else {
        Lista<string>* nombres = new Lista<string>;

        while (posComa != string::npos){
            nombre = linea.substr(0,pos);
            nombres->agregar(nombre);
            linea = linea.substr(pos+1);
            posComa = linea.find(",");
        }

        Familia* familia = new Familia(nombres, telefono);
        cliente->agregar(telefono, familia);
    }
}

unsigned long int procesarTelefono(string strTelefono) {

	unsigned long int telefono;
	stringstream ssTelefono(strTelefono);

	telefono << ssTelefono;

	return telefono;
}