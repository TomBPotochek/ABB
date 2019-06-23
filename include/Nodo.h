#ifndef NODO_H_
#define NODO_H_


template<class T> class Nodo {

    private:

        T dato;

        Nodo<T>* siguiente;

    public:


        // PRE: --
        // POST: el Nodo resulta inicializado con el dato dado
        //       y sin un Nodo siguiente.
        Nodo(T dato);

        //PRE: --
        // POST: devuelve el valor del dato.
        T obtenerDato();

        // PRE: --
        // POST: cambia el valor del dato.
        void cambiarDato(T nuevoDato);

        //PRE: --
        // POST: devuelve el siguiente Nodo.
        Nodo<T>* obtenerSiguiente();

        // PRE: --
        // POST: cambia el siguiente Nodo por nuevoSiguiente.
        void cambiarSiguiente(Nodo<T>* nuevoSiguiente);
};

template<class T> Nodo<T>::Nodo(T dato) {

    this->dato = dato;
    this->siguiente = 0;
}

template<class T> T Nodo<T>::obtenerDato() {

    return this->dato;
}

template<class T> void Nodo<T>::cambiarDato(T nuevoDato) {

    this->dato = nuevoDato;
}

template<class T> Nodo<T>* Nodo<T>::obtenerSiguiente() {

    return this->siguiente;
}

template<class T> void Nodo<T>::cambiarSiguiente(Nodo<T>* nuevoSiguiente) {

    this->siguiente = nuevoSiguiente;
}


#endif /* NODO_H_ */
