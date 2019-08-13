#include <iostream>

using namespace std;

struct Sttr{
    int id;
    char content[20];
};

struct Ventas{
    int id_model;
    int id_vendedor;
    int fecha;
    char cliente[20];

};

void cargarVendedores(FILE*, Sttr[]);
void cargarModelos(FILE*, Sttr[]);
void emitirListado(FILE*, Sttr[], Sttr[]);
int main() {
    //Declaramos los structs
    Sttr vendedor[10];
    Sttr modelos[15];
    Ventas ventas[99];

    //Abrimos los flujos
    FILE* arch_vendedor = fopen("vendedores.dat", "rb");
    FILE* arch_modelos= fopen("modelos.dat", "rb");
    FILE* arch_ventas= fopen("ventas.dat", "rb");

    cargarVendedores(arch_vendedor, vendedor);
    cargarModelos(arch_modelos, modelos);
    emitirListado(arch_ventas, vendedor, modelos);

    return 0;
}

void cargarVendedores(FILE* archivo, Sttr vendedores[]){
    Sttr rr;

    while( fread(&rr, sizeof(vendedores), 1, archivo)){
        vendedores[rr.id-1] = rr;
    }

    return;
}

void cargarModelos(FILE* archivo, Sttr modelos[]){
    cargarVendedores(archivo, modelos);
    return;
}
void emitirListado(FILE* vtas, Sttr vendedores[], Sttr modelos[]){
    Ventas rr;
    int ant = 0;
    while( fread(&rr, sizeof(rr), 1, vtas)){
        if(rr.fecha != ant){
            cout << rr.fecha;
            ant = rr.fecha;
        }
        cout << rr.cliente;
        cout << vendedores[rr.id_vendedor - 1].content;
        cout << modelos[rr.id_model - 1].content;


    }
}