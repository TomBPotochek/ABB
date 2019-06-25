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
        // POST: la aplicación queda preparada para utilizar pero sin clientes
        Empresa();

        // PRE: el archivo con los clientes existe y tiene el formato adecuado
        // POST: crea un ABB de clientes
        void cargarClientes(const char* nombreArchivo);
        
        // PRE: se cargaron clientes con 'cargarClientes()'
        // POST: interactúa con el usuario mediante un menu para realizar operaciones
        void menuOperativo();
    	
    private:
    	
    	// PRE: --
        // POST: libera los recursos asociados
        void cargarCliente(ABB<std::string, Cliente*>* clientes, std::string linea);
        
        // PRE: --
        // POST: libera los recursos asociados
        unsigned long int procesarTelefono(string strTelefono);
        
        // PRE: --
        // POST: libera los recursos asociados
        bool agregarCliente(Cliente* cliente);
        
        // PRE: --
        // POST: libera los recursos asociados
        bool bajarCliente(Cliente* cliente);
        
        // PRE: --
        // POST: libera los recursos asociados
        void listarClientes();
		
		// PRE: --
        // POST: libera los recursos asociados
		void imprimirCliente(Cliente* cliente);
		
		// PRE: --
        // POST: libera los recursos asociados
        Cliente* buscarCliente(unsigned long int telefono);
        
        // PRE: --
        // POST: libera los recursos asociados
        void consultarPrecio(Cliente* cliente, double precio);
		
        // PRE: 1 <= opcion <= 6
        // POST: lleva a cabo la operación indicada por 'opcion'
        void realizarOperacion(int opcion);
        
        // PRE: --
        // POST: libera los recursos asociados
        ~Empresa();
};

#endif // EMPRESA_H
