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

template <typename T>
Node<T>* insertar_ordenado(Node<T>* &lista, T x, int (*criterio)(T a, T b)){
    Node<T>* p = new Node<T>();
    p->info = x;

    if (lista == NULL  || criterio(x, lista->info)){
        p->next = lista;

        lista = p;
    }else{
        Node<T>* q = lista;

        while(q->next != NULL && criterio(q->next->info,x)){
            q = q->next;
        }

        p->next = q->next;
        q->next = p;
    }

    return p;
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
    insertar_ordenado(nodosAutistas, 2, ascedente);
    insertar_ordenado(nodosAutistas, 3, ascedente);
    insertar_ordenado(nodosAutistas, 1, ascedente);

    Node<int>* aux = nodosAutistas;
    while( aux!=NULL ){
        cout<<aux->info<<"-";
        aux = aux->next;
    }
}



