#ifndef ABB_H_
#define ABB_H_

#include "NodoABB.h"

template<class TClave, class TDato>

class ABB {

    private:

        NodoABB<TClave, TDato>* raiz;

        unsigned int tamanio;

    public:

        // PRE: --
        // POST: ABB vacío.
		ABB();

        // PRE: --
        // POST: devuelve la cantidad de elementos que tiene el ABB.
        unsigned int contarElementos();

        // PRE : --
        // POST: agrega al ABB el elemento ordenado de acuerdo a clave e indica si se pudo agregar.
        //       Si la clave ya existía el árbol queda inalterado.
        bool agregar(TClave clave, TDato dato);

        // PRE : --
        // POST: devuelve el elemento con clave indicada. Si no se encuentra devuelve 0
        TDato buscar(TClave clave);

        // PRE: --
        // POST: remueve del ABB el elemento con clave indicada. Devuelve un booleano dependiendo de si se eliminó.
        bool eliminar(TClave clave);

        // PRE: visitar es una funcion que devuelve void y recibe un dato de tipo TDato
        // POST: realiza un recorrido inorder, invocando a visitar para cada elemento.
        //       Si el ABB se encuentra vacio no hace nada
        void recorrer(void (*visitar)(TDato));

        // PRE: --
        // POST: libera los recursos asociados al ABB.
        ~ABB();

    private:

        // PRE: visitar es una funcion que devuelve void y recibe un dato de tipo TDato. raiz es la raiz del arbol.
        // POST: realiza un recorrido inorder comenzando por raiz, invocando a visitar para cada elemento.
        //       Si el ABB se encuentra vacio no hace nada
        // NOTA: metodo recursivo
        void inorder(NodoABB<TClave, TDato>* raiz, void (*visitar)(TDato));

        // PRE: raiz es la raiz del arbol
        // POST: elimina todos los nodos del arbol, realizando un recorrido postorder
        // NOTA: metodo recursivo
        void liberarPostorder(NodoABB<TClave, TDato>* raiz);

        // PRE: raiz es la raiz del arbol
        // POST: agrega en la posicion correspondiente el dato y devuelve la raiz del arbol modificado (o no)
        //       El tamaño del arbol queda incrementado si la clave no esta repetida
        // NOTA: metodo recursivo
        NodoABB<TClave, TDato>* agregarRecursivo(NodoABB<TClave, TDato>* raiz, TClave clave, TDato dato);

        // PRE: raiz es la raiz del arbol
        // POST: elimina el nodo de clave indicada y devuelve la raiz del arbol modificado (o no)
        //       El tamaño del arbol queda reducido si la clave existía
        // NOTA: metodo recursivo
        NodoABB<TClave, TDato>* eliminarRecursivo(NodoABB<TClave, TDato>* raiz, TClave clave);

        // PRE: raiz es la raiz del arbol
        // POST: devuelve el nodo de clave indicada. De no existir devuelve 0.
        // NOTA: metodo recursivo
        NodoABB<TClave, TDato>* buscarRecursivo(NodoABB<TClave, TDato>* raiz, TClave clave);

        // PRE: nodo != 0
        // POST: elimina el nodo indicado y devuelve un puntero al nodo que reemplaza su posicion (eventualmente 0)
        // NOTA: metodo recursivo
        NodoABB<TClave, TDato>* eliminarNodo(NodoABB<TClave, TDato>* nodo);
};

template<class TClave, class TDato>
ABB<TClave, TDato>::ABB() {

    this->raiz = 0;
	this->tamanio = 0;
}


template<class TClave, class TDato>
unsigned int ABB<TClave, TDato>::contarElementos() {

    return this->tamanio;
}

template<class TClave, class TDato>
TDato ABB<TClave, TDato>::buscar(TClave clave) {

    NodoABB<TClave, TDato>* nodo = this->buscarRecursivo(this->raiz, clave);

    return (nodo != 0) ? nodo->obtenerDato() : 0;
}

template<class TClave, class TDato>
bool ABB<TClave, TDato>::agregar(TClave clave, TDato dato) {

	unsigned int tamanioAnterior = this->tamanio;
    this->raiz = this->agregarRecursivo(this->raiz, clave, dato);

	return (this->tamanio > tamanioAnterior);
}

template<class TClave, class TDato>
bool ABB<TClave, TDato>::eliminar(TClave clave) {

	unsigned int tamanioAnterior = this->tamanio;
	this->raiz = this->eliminarRecursivo(this->raiz, clave);

	return (this->tamanio < tamanioAnterior);
}

template<class TClave, class TDato>
void ABB<TClave, TDato>::recorrer(void (*visitar)(TDato)) {

	this->inorder(this->raiz, visitar);
}

template<class TClave, class TDato>
ABB<TClave, TDato>::~ABB() {

	this->liberarPostorder(this->raiz);
}

template<class TClave, class TDato>
void ABB<TClave, TDato>::inorder(NodoABB<TClave, TDato>* raiz, void (*visitar)(TDato)) {

	if (raiz != 0) {

		this->inorder(raiz->obtenerIzquierdo(), visitar);
		visitar(raiz->obtenerDato());
		this->inorder(raiz->obtenerDerecho(), visitar);
	}
}

template<class TClave, class TDato>
void ABB<TClave, TDato>::liberarPostorder(NodoABB<TClave, TDato>* raiz) {

	if (raiz != 0) {

		this->liberarPostorder(raiz->obtenerIzquierdo());
		this->liberarPostorder(raiz->obtenerDerecho());
		delete raiz;
	}
}

template<class TClave, class TDato>
NodoABB<TClave, TDato>* ABB<TClave, TDato>::buscarRecursivo(NodoABB<TClave, TDato>* raiz, TClave clave) {

    if (raiz == 0 || raiz->obtenerClave() == clave)
       return raiz;

    if (clave > raiz->obtenerClave())
       return buscarRecursivo(raiz->obtenerDerecho(), clave);

    return buscarRecursivo(raiz->obtenerIzquierdo(), clave);
}

template<class TClave, class TDato>
NodoABB<TClave, TDato>* ABB<TClave, TDato>::agregarRecursivo(NodoABB<TClave, TDato>* raiz, TClave clave, TDato dato) {

	if (raiz == 0) {
		this->tamanio++;
		return new NodoABB<TClave, TDato>(clave, dato);

	} else {
		TClave claveRaiz = raiz->obtenerClave();

		if (clave < claveRaiz)
			raiz->cambiarIzquierdo(this->agregarRecursivo(raiz->obtenerIzquierdo(), clave, dato));

		else if (clave > claveRaiz)
			raiz->cambiarDerecho(this->agregarRecursivo(raiz->obtenerDerecho(), clave, dato));
	}

	return raiz;
}

template<class TClave, class TDato>
NodoABB<TClave, TDato>* ABB<TClave, TDato>::eliminarRecursivo(NodoABB<TClave, TDato>* raiz, TClave clave) {

    if (raiz == 0)
        return raiz;

    TClave claveRaiz = raiz->obtenerClave();

    if (clave < claveRaiz)
        raiz->cambiarIzquierdo(this->eliminarRecursivo(raiz->obtenerIzquierdo(), clave));

    else if (clave > claveRaiz)
        raiz->cambiarDerecho(this->eliminarRecursivo(raiz->obtenerDerecho(), clave));

    else
        return this->eliminarNodo(raiz);

    return raiz;
}

template<class TClave, class TDato>
NodoABB<TClave, TDato>* ABB<TClave, TDato>::eliminarNodo(NodoABB<TClave, TDato>* nodo) {

	NodoABB<TClave, TDato>* aBorrar = nodo;
	NodoABB<TClave, TDato>* izq = nodo->obtenerIzquierdo();
	NodoABB<TClave, TDato>* der = nodo->obtenerDerecho();

	if (izq == 0 || der == 0) {

        delete aBorrar;
        this->tamanio--;

        return (izq == 0) ? der : izq;
	}

    NodoABB<TClave, TDato>* menorDeMayores = der;

	while (menorDeMayores->obtenerIzquierdo() != 0)
        menorDeMayores = menorDeMayores->obtenerIzquierdo();

    TClave claveMenorDeMayores = menorDeMayores->obtenerClave();
    nodo->cambiarClave(claveMenorDeMayores);
    nodo->cambiarDato(menorDeMayores->obtenerDato());
    nodo->cambiarDerecho(this->eliminarNodo(menorDeMayores));

    return nodo;
}

#endif /* ABB_H_ */
