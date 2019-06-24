#ifndef Lista_H_
#define Lista_H_

#include "Nodo.h"

template<class T> class Lista {

    private:

        Nodo<T>* primero;

        unsigned int tamanio;

        Nodo<T>* cursor;

    public:

        // PRE: --
        // POST: Lista vacía.
                Lista();





        // PRE: --
        // POST: devuelve la cantidad de elementos que tiene la Lista.
        unsigned int contarElementos();

        // PRE: --
        // POST: agrega el elemento al final de la Lista, en la posición:
        //       contarElementos() + 1.
        void agregar(T elemento);

        //
        // PRE : posicion pertenece al intervalo: [1, contarElementos() + 1]
        // POST: agrega el elemento en la posiciOn indicada,
        //       desplazando los elementos siguientes.
        void agregar(T elemento, unsigned int posicion);


        //
        // PRE : posicion pertenece al intervalo: [1, contarElementos()]
        // POST: devuelve el elemento en la posición indicada.
        T obtener(unsigned int posicion);

        //
        // PRE: posiciOn pertenece al intervalo: [1, contarElementos()]
        // POST: cambia el elemento en la posición indicada por el
        //       elemento dado.
        void asignar(T elemento, unsigned int posicion);

        //
        // PRE: posición pertenece al intervalo: [1, contarElementos()]
        // POST: remueve de la Lista el elemento en la posición indicada,
        //       desplezando los elementos siguientes para ocupar
        //       la posición removida.
        void remover(unsigned int posicion);


        // PRE: --
        // POST: deja el cursor de la Lista preparado para hacer un nuevo
        //       recorrido sobre sus elementos.
        void iniciarCursor();

        //
        // PRE: se ha iniciado un recorrido (invocando el metodo
        //       iniciarCursor()) y desde entonces no se han agregado o
        //       removido elementos de la Lista.
        // POST: mueve el cursor y lo posiciona en el siguiente elemento
        //       del recorrido.
        //       El valor de retorno indica si el cursor queda posicionado
        //       sobre un elemento o no (en caso de que la Lista esta vacia o
        //       no existan mas elementos por recorrer.)
        bool avanzarCursor();

        //
        // PRE: el cursor esta posicionado sobre un elemento de la Lista,
        //       (fue invocado el metodo avanzarCursor() y devolvia true)
        // POST: devuelve el elemento en la posicion del cursor.
        T obtenerCursor();

        // PRE: --
        // POST: libera los recursos asociados a la Lista.
        ~Lista();

    private:

        // PRE: posición pertenece al intervalo: [1, contarElementos()]
        // POST: devuelve el nodo en la posición indicada.
        Nodo<T>* obtenerNodo(unsigned int posicion); // NOTA: primitiva PRIVADA
};

template<class T> Lista<T>::Lista() {

    this->primero = 0;
    this->tamanio = 0;
    this->cursor = 0;
}




template<class T> unsigned int Lista<T>::contarElementos() {

    return this->tamanio;
}

template<class T> void Lista<T>::agregar(T elemento) {

    this->agregar(elemento, this->tamanio + 1);
}

template<class T> void Lista<T>::agregar(T elemento, unsigned int posicion) {

    if ((posicion > 0) && (posicion <= this->tamanio + 1)) {

        Nodo<T>* nuevo = new Nodo<T>(elemento);

        if (posicion == 1) {

            nuevo->cambiarSiguiente(this->primero);
            this->primero = nuevo;

        } else {

            Nodo<T>* anterior = this->obtenerNodo(posicion - 1);
            nuevo->cambiarSiguiente(anterior->obtenerSiguiente());
            anterior->cambiarSiguiente(nuevo);
        }

        this->tamanio++;

        /* cualquier recorrido actual queda invalidado */
        this->iniciarCursor();
    }

}

template<class T> T Lista<T>::obtener(unsigned int posicion) {

    T elemento;

    if ((posicion > 0) && (posicion <= this->tamanio)) {

        elemento = this->obtenerNodo(posicion)->obtenerDato();
    }

    return elemento;
}

template<class T> void Lista<T>::asignar(T elemento, unsigned int posicion) {

    if ((posicion > 0) && (posicion <= this->tamanio)) {

        this->obtenerNodo(posicion)->cambiarDato(elemento);
    }
}

template<class T> void Lista<T>::remover(unsigned int posicion) {

    if ((posicion > 0) && (posicion <= this->tamanio)) {

        Nodo<T>* removido;

        if (posicion == 1) {

            removido = this->primero;
            this->primero = removido->obtenerSiguiente();

        } else {

            Nodo<T>* anterior = this->obtenerNodo(posicion - 1);
            removido = anterior->obtenerSiguiente();
            anterior->cambiarSiguiente(removido->obtenerSiguiente());
        }

        delete removido;
        this->tamanio--;

        /* cualquier recorrido actual queda invalidado */
        this->iniciarCursor();
    }
}

template<class T> void Lista<T>::iniciarCursor() {

    this->cursor = 0;
}

template<class T> bool Lista<T>::avanzarCursor() {

    if (this->cursor == 0) {

        this->cursor = this->primero;

    } else {

        this->cursor = this->cursor->obtenerSiguiente();
    }

    /* pudo avanzar si el cursor ahora apunta a un nodo */
    return (this->cursor != 0);
}

template<class T> T Lista<T>::obtenerCursor() {

    T elemento;

    if (this->cursor != 0) {

        elemento = this->cursor->obtenerDato();
    }

    return elemento;
}

template<class T> Lista<T>::~Lista() {

    while (this->primero != 0) {

        Nodo<T>* aBorrar = this->primero;
        this->primero = this->primero->obtenerSiguiente();

        delete aBorrar;
    }
}

template<class T> Nodo<T>* Lista<T>::obtenerNodo(unsigned int posicion) {

    Nodo<T>* actual = this->primero;
    for (unsigned int i = 1; i < posicion; i++) {

        actual = actual->obtenerSiguiente();
    }

    return actual;
}

#endif /* Lista_H_ */
