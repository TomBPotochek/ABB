#ifndef EMPRESA_H
#define EMPRESA_H

#include <fstream>
#include <sstream>
#include "Consola.h"
#include "ABB.h"
#include "Cliente.h"
#include "Individuo.h"
#include "Familia.h"


using namespace std;


class Empresa {

    private:

        ABB<unsigned long int, Cliente*>* clientes;

        Consola consola;

        unsigned long int semilla;

    public:

        // PRE: --
        // POST: la aplicacion queda preparada para utilizar pero sin clientes
        Empresa();

        // PRE: el archivo con los clientes existe y tiene el formato adecuado
        // POST: crea un ABB de clientes
        void cargarClientes(const char* nombreArchivo);

        // PRE: se cargaron clientes con 'cargarClientes()'
        // POST: interactua con el usuario mediante un menu para realizar operaciones
        void menuOperativo();

        // PRE: --
        // POST: libera los recursos asociados
        ~Empresa();

    private:

    	// PRE: --
        // POST: agrega al �rbol un cliente le�do del archivo
        void cargarCliente(std::string linea);

        // PRE: el texto debe no tener caracteres no num�ricos
        // POST: convierte el n�mero de tel�fono de texto a num�rico
        unsigned long int procesarTelefono(string strTelefono);


        Cliente* ingresarCliente();
        // PRE: --
        // POST: agrega al arbol un cliente ingresado por el usuario, devuelve TRUE si tuvo exito o FALSE si ya existia
        bool agregarCliente(Cliente* cliente);

        // PRE: --
        // POST: elimina del arbol el cliente con telefono indicado
        void bajarCliente(unsigned long int telefono);

        // PRE: --
        // POST: imprime la informacion de todos los clientes
        void listarClientes();

		// PRE: --
        // POST: imprime la informacion del cliente que se pasa por parametro
		static void imprimirCliente(Cliente* cliente);

		// PRE: --
        // POST: devuelve el cliente buscado
        Cliente* buscarCliente(unsigned long int telefono);

        // PRE: --
        // POST: imprime el precio teniendo en cuenta el descuento del cliente
        void consultarPrecio(Cliente* cliente, double precio);

        // PRE: 1 <= opcion <= 6
        // POST: lleva a cabo la operacion indicada por 'opcion'
        void realizarOperacion(int opcion);
};

#endif // EMPRESA_H
