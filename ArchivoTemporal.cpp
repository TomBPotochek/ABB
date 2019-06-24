

#include "Lista.h"
#include <fstream>

ABB<unsigned long, Cliente*>* cargarArchivo(const char* nombreArchivo){
    ifstream archivo(nombreArchivo);
    ABB<std::string, Cliente*>* clientes = new ABB<std::string, Cliente*>;
    
    if (archivo.is_open()) {
        while (!archivo.eof()){ //o tal vez tenga que ser "while(getline(linea))" ?
            linea = getline(archivo);
            this->cargarCliente(ABB<std::string, Cliente*>* clientes, std::string linea);
            
        }        
    }
    
    archivo.close();
    return clientes;
   
}


void cargarCliente(ABB<std::string, Cliente*>* clientes, std::string linea){
    unsigned pos = linea.find(',');
    string telefono = linea.substr(0,pos); linea = linea.substr(pos+1);
    
    pos = linea.find(',');
    if (pos == string::npos) {
        Individuo* individuo = new Individuo(linea, DESCUENTO_I, telefono); //era asi para usar el constructor heredado de cliente?
        cliente->agregar(std::string telefono, Individuo* individuo);
    } else {
        Lista<string>* nombres = new Lista<string>;
        while (pos != string::npos){
            nombre = linea.substr(0,pos);
            nombres->agregar(std::string nombre);
            linea = linea.substr(pos+1);
            pos = linea.find(',');
        }
        Familia* familia = new Familia(nombres, DESCUENTO_F, telefono); //igual que con Individuo (?
        cliente->agregar(std::string telefono, Familia* familia);
    }
}
    
    
    
    
    
    
}
