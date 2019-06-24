#ifndef FAMILIA_H
#define FAMILIA_H

//#define DESCUENTO_F = 0.35;

class Familia : public Cliente {

    private:

        Lista<string>* nombres;
        double descuento;


    public:

        Familia (Lista<string>* nombres, double descuento):Cliente (unsigned long telefono);

        Lista<string>* obtenerNombre ();
        
        void asignarNombre (Lista<string>* nombres);

        double calcularPrecio (int precio);
        
        void listarNombres();


};

#endif // FAMILIA_H
