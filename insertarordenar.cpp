#include <iostream>

using namespace std;


struct Nodo{
    int info;
    Nodo* sgts;
};

Nodo* insertarOrdenado(Nodo*&, int);
int main()
{

    Nodo* lista = NULL;
    int x;
    //Vas insertando numeros en la lista y se van a ordenar
    for (int i = 0; i < 39; i++){
        cout<<"inserte x\n";
        cin>>x;
        insertarOrdenado(lista, x);
    }
    //Muestra el primer numero, tiene que ser el más chico porque fue ordenandose
    cout<<lista->info;
    
    return 0;

}
Nodo* insertarOrdenado(Nodo* &lista, int x){
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
