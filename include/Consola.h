#ifndef CONSOLA_H
#define CONSOLA_H
#include "Arbol.h"
#include "Pelicula.h"
#include <iostream>

class Consola {

    public:

        // PRE: --
        // POST: la consola queda Arbol para usar
        Consola();

        // PRE: --
        // POST: muestra por consola el menu de operaciones
        void imprimirMenu();

        // PRE: --
        // POST: devuelve un entero del 1 al 4 que representa la accion ingresada por el usuario
        int ingresarOpcion();

        // PRE: Arbol != 0. Utilizar este metodo para vistas y no vistas
        // POST: muestra por consola las peliculas.
        void imprimirPeliculas(Arbol<Pelicula*>* Arbol);

        // PRE: recomendadas != 0 y porcentajesAfinidad != 0. Los datos de las dos Arbols deben corresponderse segun el orden
        // POST: muestra por consola las peliculas de 'recomendadas' con sus respectivas afinidades
        void imprimirRecomendadas(Arbol<Pelicula*>* recomendadas, Arbol<double>* porcentajesAfinidad);


    private:

        // PRE: 'unaPelicula' != 0
        // POST: muestra por consola los datos de la pelicula
        void imprimirPelicula(Pelicula* unaPelicula);

        // PRE: 'actores' != 0
        // POST: muestra por consola los actores indicados
        void imprimirActores(Arbol<string>* actores);

};

#endif // CONSOLA_H
