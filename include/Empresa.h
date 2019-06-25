#ifndef EMPRESA_H
#define EMPRESA_H

#include <fstream>
#include "Consola.h"
#include "ABB.h"
#include "Cliente.h"

using namespace std;


class Empresa {

    private:

        ABB<Cliente*>* clientes;

        Consola consola;

    public:

        // PRE: --
        // POST: la aplicaciÃ³n queda preparada para utilizar pero sin clientes
        Empresa();

        // PRE: el archivo con los clientes existe y tiene el formato adecuado
        // POST: crea un ABB de clientes
        void cargarClientes(const char* nombreArchivo);
        
        // PRE: se cargaron clientes con 'cargarClientes()'
        // POST: interactÃºa con el usuario mediante un menu para realizar operaciones
        void menuOperativo();
    	
    private:
    	
    	// PRE: --
        // POST: agrega al árbol un cliente leído del archivo
        void cargarCliente(ABB<std::string, Cliente*>* clientes, std::string linea);
        
        // PRE: el texto debe no tener caracteres no numéricos
        // POST: convierte el número de teléfono de texto a numérico
        unsigned long int procesarTelefono(string strTelefono);
        
        // PRE: --
        // POST: agrega al árbol un cliente ingresado por el usuario, devuelve TRUE si tuvo éxito o FALSE si ya existía
        bool agregarCliente(Cliente* cliente);
        
        // PRE: --
        // POST: elimina del árbol el cliente ingresado por el usuario, devuelve TRUE si tuvo éxito o FALSE si no existía
        bool bajarCliente(Cliente* cliente);
        
        // PRE: --
        // POST: imprime la información de todos los clientes
        void listarClientes();
		
		// PRE: --
        // POST: imprime la información del cliente que se pasa por parámetro
		void imprimirCliente(Cliente* cliente);
		
		// PRE: --
        // POST: devuelve el cliente buscado
        Cliente* buscarCliente(unsigned long int telefono);
        
        // PRE: --
        // POST: imprime el precio teniendo en cuenta el descuento del cliente
        void consultarPrecio(Cliente* cliente, double precio);
		
        // PRE: 1 <= opcion <= 6
        // POST: lleva a cabo la operaciÃ³n indicada por 'opcion'
        void realizarOperacion(int opcion);
        
        // PRE: --
        // POST: libera los recursos asociados
        ~Empresa();
};

#endif // EMPRESA_H
