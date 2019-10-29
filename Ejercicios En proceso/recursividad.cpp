#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


template <typename T>
struct Node
{
    T info;
    Node<T>* next;
};

template <typename T>
int ascedente(T a, T b){
    return a < b;
}


template <typename T>
int descendente(T a, T b){
    return a > b;
}

template <typename T >
Node<T>* insertar_ordenado_recursio(Node<T>* &lista, T x, int (*criterio)(T a, T b), bool esPrimerValor){

    if(esPrimerValor){
        Node<T>* p = new Node<T>();
        p->info = x;
        if(lista == NULL){
            lista = p;
        }else if(criterio(x, lista->info)){
            p->next = lista;
            lista = p;
        }else{

        }
    }

    return lista;
}
template <typename T >
void insertar_ordenado(Node<T>* &lista, T x, int (*criterio)(T a, T b)){

        Node<T>* p = new Node<T>();

    p->info = x;

    //Si la lista no contiene ningun valor O, si el primero cumple con el criterio de ordenaiento
    if (lista == NULL  || criterio(x, lista->info)){
        //se intecambia la posición con el nuevo nodo y el primero de la lista de la lista
        p->next = lista;
        lista = p;
    }else{
        //Si no se cumple con el criterio
        Node<T>* q = lista;
        //Hasta que no cumpla el criterio se irá desplazando hasta llegar al final
        while(q->next != NULL && !criterio(x, q->next->info)){
            q = q->next;
        }
        p->next = q->next;
        q->next = p;

    }

    return;
}

void showInt(int x){
    cout<<x<<"-";
}
template <typename T>
void show(Node<T>* l, void (*showType)(T)){ //para obtener el tamaño
    Node<T>* aux = l;
    while( aux!=NULL ){
        showType(aux->info);
        aux = aux->next;
    }
}


int main(){
    cout<<"voy a insertar un numero con criterio de ordne decente";

    Node<int>* nodosAutistas = NULL;
    insertar_ordenado(nodosAutistas, 2, descendente);
    insertar_ordenado(nodosAutistas, 5, descendente);
    insertar_ordenado(nodosAutistas, 1, descendente);
    insertar_ordenado(nodosAutistas, 6, descendente);
    insertar_ordenado(nodosAutistas, 5, descendente);
    insertar_ordenado(nodosAutistas, 1, descendente);
    insertar_ordenado(nodosAutistas, 6, descendente);
    Node<int>* aux = nodosAutistas;
    while( aux!=NULL ){
        cout<<aux->info<<"-";
        aux = aux->next;
    }
}

