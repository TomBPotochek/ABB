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

        static Consola consola;

        unsigned long int semilla;

    public:

        // PRE: --
        // POST: la instancia queda lista para utilizar pero sin clientes cargados
        Empresa();

        // PRE: el archivo con los clientes existe y tiene el formato adecuado
        // POST: carga los clientes del archivo
        void cargarClientes(const char* nombreArchivo);

        // PRE: --
        // POST: interactua con el usuario mediante un menu para realizar operaciones
        void menuOperativo();

        // PRE: --
        // POST: libera los recursos asociados
        ~Empresa();

    private:

    	// PRE: linea tiene un cliente con el formato adecuado
        // POST: carga el cliente con los datos de linea
        void cargarCliente(std::string linea);

        // PRE: strTelefono debe tener caracteres numericos
        // POST: devuelve el numero de telefono en formato numerico
        unsigned long int procesarTelefono(string strTelefono);

		// PRE: --
        // POST: devuelve un puntero a cliente con datos ingresados por el usuario
        Cliente* ingresarCliente();

        // PRE: cliente != 0 y el numero de telefono es unico
        // POST: agrega al arbol el cliente
        void agregarCliente(Cliente* cliente);

        // PRE: --
        // POST: elimina del arbol el cliente con telefono indicado. Muestra por consola el resultado de la operacion
        void bajarCliente(unsigned long int telefono);

        // PRE: Hay clientes en el arbol
        // POST: imprime la informacion de todos los clientes existentes
        void listarClientes();

		// PRE: cliente != 0
        // POST: imprime la informacion del cliente indicado
        // NOTA: el metodo es estatico para poder utilizarlo como callback al recorrer el arbol
		static void imprimirCliente(Cliente* cliente);

		// PRE: --
        // POST: devuelve el cliente buscado. Si no se encuentra devuelve 0.
        Cliente* buscarCliente(unsigned long int telefono);

        // PRE: cliente != 0
        // POST: consulta el precio de acuerdo al tipo de cliente y lo muestra por consola
        void consultarPrecio(Cliente* cliente, double precio);

        // PRE: 1 <= opcion <= 6
        // POST: lleva a cabo la operacion indicada por 'opcion'
        void realizarOperacion(int opcion);

        // PRE: se debe utilizar al destruirse la instancia de Empresa y recorriendo el arbol de clientes
        // POST: libera la memoria ocupada por unCliente
        // NOTA: el metodo es estatico para poder utilizarlo como callback al recorrer el arbol
        static void liberarCliente(Cliente* unCliente);
};

#endif // EMPRESA_H
