#include "Empresa.h"

Empresa::Empresa() {
    this->clientes = 0;
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
        Individuo* individuo = new Individuo(linea, telefono);
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
        nombre = linea.substr(0,posComa);
        nombres->agregar(nombre);

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

void Empresa::bajarCliente(unsigned long int telefono){

    if (!this->clientes->eliminar(telefono))
        this->consola.errorClienteNoEncontrado();
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

void Empresa::realizarOperacion(int opcion) {	//hay que modificarla segun los casos

    switch(opcion) {

        case 1: this->consultarPrecio(this->buscarCliente(this->consola.ingresarTelefono()), this->consola.ingresarPrecio()); break;
        case 2: this->agregarCliente(this->ingresarCliente()); break;
        case 3: this->bajarCliente(this->consola.ingresarTelefono()); break;
        case 4: this->listarClientes(); break;
        case 5: this->imprimirCliente(this->buscarCliente(this->consola.ingresarTelefono())); break;
    }
}

void Empresa::consultarPrecio(Cliente* cliente, double precio){

	double total = cliente->calcularPrecio(precio);

	this->consola.imprimirPrecio(total);
}

Cliente* Empresa::ingresarCliente(){

    while(this->clientes->buscar(this->semilla) != 0)
        this->semilla++;

    unsigned long int telefonoNuevo = this->semilla;

    std::string nombre = this->consola.ingresarNombre();
    this->consola.imprimirMensaje("Si ingresa más nombres, será contado como familia");
    bool opcion = this->consola.continuarIngresando();
    Cliente* clienteNuevo;

    if (opcion) {
        Lista<std::string>* nombres = new Lista<std::string>;
        nombres->agregar(nombre);
        while (opcion){
            nombre = this->consola.ingresarNombre();
            nombres->agregar(nombre);
            opcion = this->consola.continuarIngresando();
        }
        clienteNuevo = new Familia(nombres, telefonoNuevo);
    } else
        clienteNuevo = new Individuo(nombre, telefonoNuevo);

    return clienteNuevo;
}

Empresa::~Empresa() {
    delete this->clientes;
}
