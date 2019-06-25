#include "Empresa.h"

using namespace std;




int main() {

    Empresa empresa;
    empresa.cargarClientes("clientes.txt");
    empresa.menuOperativo();


    return 0;
}
