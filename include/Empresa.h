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
        void cargarCliente(std::string linea);
        
        // PRE: el texto debe no tener caracteres no num�ricos
        // POST: convierte el n�mero de tel�fono de texto a num�rico
        unsigned long int procesarTelefono(string strTelefono);
        
        // PRE: --
        // POST: agrega al �rbol un cliente ingresado por el usuario, devuelve TRUE si tuvo �xito o FALSE si ya exist�a
        bool agregarCliente(Cliente* cliente);
        
        // PRE: --
        // POST: elimina del �rbol el cliente ingresado por el usuario, devuelve TRUE si tuvo �xito o FALSE si no exist�a
        bool bajarCliente(Cliente* cliente);
        
        // PRE: --
        // POST: imprime la informaci�n de todos los clientes
        void listarClientes();
		
		// PRE: --
        // POST: imprime la informaci�n del cliente que se pasa por par�metro
		void imprimirCliente(Cliente* cliente);
		
		// PRE: --
        // POST: devuelve el cliente buscado
        Cliente* buscarCliente(unsigned long int telefono);
        
        // PRE: --
        // POST: imprime el precio teniendo en cuenta el descuento del cliente
        void consultarPrecio(Cliente* cliente, double precio);
		
        // PRE: 1 <= opcion <= 6
        // POST: lleva a cabo la operación indicada por 'opcion'
        void realizarOperacion(int opcion);
        
        // PRE: --
        // POST: libera los recursos asociados
        ~Empresa();
};

#endif // EMPRESA_H
