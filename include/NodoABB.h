#ifndef NODO_ABB_H_
#define NODO_ABB_H_

template<class TClave, class TDato>
class NodoABB {

    private:

        TDato dato;
		TClave clave;

        NodoABB<TClave, TDato>* izquierdo;
        NodoABB<TClave, TDato>* derecho;


    public:

        // PRE: --
        // POST: el NodoABB resulta inicializado con clave y dato indicados, y sin nodos izquierdo y derecho.
        NodoABB(TClave clave, TDato dato);

		// PRE: --
        // POST: devuelve el valor de la clave.
		TClave obtenerClave();

        // PRE: --
        // POST: devuelve el valor del dato.
        TDato obtenerDato();

        // PRE: --
        // POST: cambia el valor del dato.
        void cambiarDato(TDato nuevoDato);

        // PRE: --
        // POST: cambia el valor de la clave
        void cambiarClave(TClave nuevaClave);

        // PRE: --
        // POST: devuelve el NodoABB izquierdo.
        NodoABB<TClave, TDato>* obtenerIzquierdo();

		// PRE: --
        // POST: devuelve el NodoABB derecho.
        NodoABB<TClave, TDato>* obtenerDerecho();

        // PRE: --
        // POST: cambia el NodoABB izquierdo por nuevoIzquierdo.
        void cambiarIzquierdo(NodoABB<TClave, TDato>* nuevoIzquierdo);

		// PRE: --
        // POST: cambia el NodoABB derecho por nuevoDerecho.
        void cambiarDerecho(NodoABB<TClave, TDato>* nuevoDerecho);
};

template<class TClave, class TDato>
NodoABB<TClave, TDato>::NodoABB(TClave clave, TDato dato) {

	this->clave = clave;
    this->dato = dato;
    this->izquierdo = 0;
	this->derecho = 0;
}

template<class TClave, class TDato>
TClave NodoABB<TClave, TDato>::obtenerClave() {

    return this->clave;
}

template<class TClave, class TDato>
TDato NodoABB<TClave, TDato>::obtenerDato() {

    return this->dato;
}

template<class TClave, class TDato>
void NodoABB<TClave, TDato>::cambiarDato(TDato nuevoDato) {

    this->dato = nuevoDato;
}

template<class TClave, class TDato>
void NodoABB<TClave, TDato>::cambiarClave(TClave nuevaClave) {

    this->clave = nuevaClave;
}

template<class TClave, class TDato>
NodoABB<TClave, TDato>* NodoABB<TClave, TDato>::obtenerIzquierdo() {

    return this->izquierdo;
}

template<class TClave, class TDato>
NodoABB<TClave, TDato>* NodoABB<TClave, TDato>::obtenerDerecho() {

    return this->derecho;
}

template<class TClave, class TDato>
void NodoABB<TClave, TDato>::cambiarIzquierdo(NodoABB<TClave, TDato>* nuevoIzquierdo) {

    this->izquierdo = nuevoIzquierdo;
}

template<class TClave, class TDato>
void NodoABB<TClave, TDato>::cambiarDerecho(NodoABB<TClave, TDato>* nuevoDerecho) {

    this->derecho = nuevoDerecho;
}

#endif /* NODO_ABB_H_ */
