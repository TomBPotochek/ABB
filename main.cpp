#include "Empresa.h"

using namespace std;

int main() {
    
    Empresa empresa;
    empresa.cargarClientes("Clientes.csv");
    empresa.menuOperativo();
    
    return 0
}
