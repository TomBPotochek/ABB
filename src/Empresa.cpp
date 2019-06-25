#include "Empresa.h"
#include "Lista.h"
#include "ABB.h"
#include <sstream>

Empresa::Empresa() {
    this->clientes = 0;
    this->consola = 0;
    this->semilla = 10086200;
}

void Empresa::cargarClientes(const char* nombreArchivo){
    ifstream archivo(nombreArchivo);
    this->clientes = new ABB<unsigned long int, Cliente*>;

    if (archivo.is_open()) {
    	string linea;
        while (!archivo.eof()){ //o tal vez tenga que ser "while(getline(linea))" ?
            getline(archivo, linea);
            this->cargarCliente(linea);
        }
    }
    archivo.close();
}

void Empresa::cargarCliente(std::string linea){
    unsigned int posComa = linea.find(",");
    unsigned long int telefono = this->procesarTelefono(linea.substr(0,posComa));

	linea = linea.substr(posComa+1);
    posComa = linea.find(",");

    if (posComa == string::npos) {
        Individuo* individuo = new Individuo(linea, telefono); //era asi para usar el constructor heredado de cliente?
        this->clientes->agregar(telefono, individuo);

    } else {
        Lista<string>* nombres = new Lista<string>;
        string nombre;

        while (posComa != string::npos){
            nombre = linea.substr(0,posComa);
            nombres->agregar(nombre);
            linea = linea.substr(posComa+1);
            posComa = linea.find(",");
        }

        Familia* familia = new Familia(nombres, telefono);
        this->clientes->agregar(telefono, familia);
    }
}

unsigned long int Empresa::procesarTelefono(string strTelefono) {

	unsigned long int telefono;
	stringstream ssTelefono(strTelefono);

	ssTelefono >> telefono;

	return telefono;
}

    
    if (archivo.is_open()) {
    	string linea;
        while (!archivo.eof()){ //o tal vez tenga que ser "while(getline(linea))" ?
            linea = getline(archivo);
         }        
    }
    archivo.close();
}

void Empresa::cargarCliente(std::string line  
void Empresa::imprimirCliente(Cliente* cliente){
	if (cliente != 0) {
		cliente->imprimirDatos();
	} else {
		cout << "Error: no existe un cliente con el telefono ingresado";
	}
}

Cliente* Empresa::buscarCliente(unsigned long int telefono){
	return this->clientes->buscar(telefono);
}

void Empresa::menuOperativo(){

	bool salida = false;

	while (!salida) {

		int opcion;

		this->consola.imprimirMenu();
		opcion = this->consola.ingresarOpcion();
		this->realizarOperacion(opcion); //verificar nombre.

		salida = (opcion == 6);
	}
}

void Empresa::realizarOperacion(int opcion) {	//hay que modificarla segun los casos

    switch(opcion) {

        case 1: this->consultarPrecio(this->buscarCliente(this->consola.ingresarTelefono()), this->consola.ingresarPrecio()); break;
        case 2: this->agregarCliente(this->consola.ingresarCliente()); break;
        case 3: this->bajarCliente(this->consola.ingresarTelefono()); break;
        case 4: this->listarClientes(); break;
        case 5: this->imprimirCliente(this->buscarCliente(this->consola.ingresarTelefono())); break;
    }
void Empresa::cargarCliente(std::string line#include "Empresa.h"
#include "Lista.h"
#include "ABB.h"
#include <sstream>

Empresa::Empresa() {
    this->clientes = 0;
    this->consola = 0;
    this->semilla = 10086200;
}

void Empresa::cargarClientes(const char* nombreArchivo){
    ifstream archivo(nombreArchivo);
    this->clientes = new ABB<unsigned long int, Cliente*>;

    if (archivo.is_open()) {
    	string linea;
        while (!archivo.eof()){ //o tal vez tenga que ser "while(getline(linea))" ?
            getline(archivo, linea);
            this->cargarCliente(linea);
        }
    }
    archivo.close();
}

void Empresa::cargarCliente(std::string linea){
    unsigned int posComa = linea.find(",");
    unsigned long int telefono = this->procesarTelefono(linea.substr(0,posComa));

	linea = linea.substr(posComa+1);
    posComa = linea.find(",");

    if (posComa == string::npos) {
        Individuo* individuo = new Individuo(linea, telefono); //era asi para usar el constructor heredado de cliente?
        this->clientes->agregar(telefono, individuo);

    } else {
        Lista<string>* nombres = new Lista<string>;
        string nombre;

        while (posComa != string::npos){
            nombre = linea.substr(0,posComa);
            nombres->agregar(nombre);
            linea = linea.substr(posComa+1);
            posComa = linea.find(",");
        }

        Familia* familia = new Familia(nombres, telefono);
        this->clientes->agregar(telefono, familia);
    }
}

unsigned long int Empresa::procesarTelefono(string strTelefono) {

	unsigned long int telefono;
	stringstream ssTelefono(strTelefono);

	ssTelefono >> telefono;

	return telefono;
}

bool Empresa::agregarCliente(Cliente* cliente){
	return this->clientes->agregar(cliente->obtenerTelefono(), cliente);
}

bool Empresa::bajarCliente(unsigned long int telefono){
	if( !this->clientes->eliminar(telefono))
        this->consola.mensaje("El cliente no existía");
    else
        this->consola.mensaje("Cliente borrado");
}

void Empresa::listarClientes(){
	this->clientes->recorrer(this->imprimirCliente);
}

void Empresa::imprimirCliente(Cliente* cliente){
	if (cliente != 0) {
		cliente->imprimirDatos();
	} else {
		cout << "Error: no existe un cliente con el telefono ingresado";
	}
}

Cliente* Empresa::buscarCliente(unsigned long int telefono){
	return this->clientes->buscar(telefono);
}

void Empresa::menuOperativo(){

	bool salida = false;

	while (!salida) {

		int opcion;

		this->consola.imprimirMenu();
		opcion = this->consola.ingresarOpcion();
		this->realizarOperacion(opcion); //verificar nombre.

		salida = (opcion == 6);
	}
}

void Empresa::realizarOperacion(int opcion) {

    switch(opcion) {

        case 1: this->consultarPrecio(this->buscarCliente(this->consola.ingresarTelefono()), this->consola.ingresarPrecio()); break;
        case 2: this->agregarCliente(this->consola.ingresarCliente()); break;
        case 3: this->bajarCliente(this->consola.ingresarTelefono()); break;
        case 4: this->listarClientes(); break;
        case 5: this->imprimirCliente(this->buscarCliente(this->consola.ingresarTelefono())); break;
    }
}

void Empresa::consultarPrecio(Cliente* cliente, double precio){
	this->consola.imprimirPrecio((1 - cliente->obtenerDescuento() ) * precio);
}

void Empresa::ingresarCliente(){
