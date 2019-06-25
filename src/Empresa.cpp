#include "Empresa.h"
#include "Lista.h"
#include "ABB.h"

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
            linea = getline(archivo);
            this->cargarCliente(linea);
        }        
    }
    archivo.close();
}

void Empresa::cargarCliente(std::string linea){
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

unsigned long int Empresa::procesarTelefono(string strTelefono) {

	unsigned long int telefono;
	stringstream ssTelefono(strTelefono);

	telefono << ssTelefono;

	return telefono;
}

bool Empresa::agregarCliente(Cliente* cliente){
	return this->clientes->agregar(cliente->obtenerTelefono(), cliente);
}

bool Empresa::bajarCliente(Cliente* cliente){
	return this->clientes->eliminar(TClave clave);
}

void Empresa::listarClientes(){
	this->clientes->recorrer(this->imprimirCliente);
}

void Empresa::imprimirCliente(Cliente* cliente){
	if cliente != 0 {
		cliente->imprimirDatos();
	} else {
		this->consola.errorClienteNoEncontrado();
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
        case 3: this->bajarCliente(this->buscarCliente(this->consola.ingresarTelefono())); break;
        case 4: this->listarClientes(); break;
        case 5: this->imprimirCliente(this->buscarCliente(this->consola.ingresarTelefono())); break;
    }
}

void Empresa::consultarPrecio(Cliente* cliente, double precio){
	this->consola.imprimirPrecio((1 - cliente->obtenerDescuento() ) * precio);
}

void Empresa::ingresarCliente(){
    unsigned long int telefonoNuevo = this->semilla;
    while(this->clientes->buscar(telefonoNuevo) != 0)
        telefonoNuevo++;
    
    this->consola.mensaje("Ingrese nombre: ");
    std::string nombre = this->consola.ingresarNombre();
    this->consola.mensaje("Si ingresa más nombres, será contado como familia");
    bool opcion = this->consola.continuarIngresando();
    if (opcion) {
        Lista<std::string>* nombres = new Lista<std::string>;
        nombres->agregar(nombre);
        while (opcion){
            this->consola.mensaje("Ingrese nombre: ");
            nombre = this->consola.ingresarNombre();
            nombres->agregar(nombre);
            opcion = this->consola.continuarIngresando();
        }
        Familia* clienteNuevo = new Familia(nombres, telefonoNuevo);
    } else 
        Individuo* clienteNuevo = new Individuo(nombre, telefonoNuevo);
           
    this->clientes->agregar(telefonoNuevo, clienteNuevo);   
}

Empresa::~Empresa() {
    delete this->clientes;
}
