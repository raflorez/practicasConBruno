#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo{
    int info;
    Nodo* sgts;
};

Nodo* insertar_ordenado(Nodo*&, int);
void obtener_lista(Nodo*);

int main()
{
    //Hacker mood
    system("color 0a");

    //La lista es una asociación de nodos básicamente
    Nodo* lista = NULL;
    int x;

    //Se va pidiendo 3 elementos para agregar a la lista
    for (int i = 0; i < 3; i++){
        cout<<"inserte x\n";
        cin>>x;
        insertar_ordenado(lista, x);
    }

    cout<<"\nA continuación una lista ordenada\n";
    obtener_lista(lista);
    //

    return 0;

}

Nodo* insertar_ordenado(Nodo* &lista, int x){
    Nodo* p = new Nodo();
    p->info = x;

    if (lista == NULL  || x < lista->info){
        p->sgts = lista;

        lista = p;
    }else{
        Nodo* q = lista;

        while(q->sgts != NULL && x>q->sgts->info){
            q = q->sgts;
        }

        p->sgts = q->sgts;
        q->sgts = p;
    }

    return p;
}

void obtener_lista(Nodo* lista){
    /*
    SGTS: Siguiente

    el WHILE muestra la info de cada Nodo
    yendo desde el SGTS a SGTS hasta cuando
    vale NULL, porque significarìa que no
    habría siguiente y por lo tanto ahí
    terminarìa la lista.

    */
    Nodo* p = new Nodo();
    p = lista;

    cout<<p->info<<"\n";

    while(p->sgts != NULL){
        p = p->sgts;
        cout<<p->info<<"\n";
    }

    return;
}
