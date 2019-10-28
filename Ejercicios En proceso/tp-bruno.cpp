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
T ascedente(T a, T b){
    return a - b;
}


template <typename T>
T descendente(T a, T b){
    return a + b;
}

template <typename T>
Node<T>* insertar_ordenado(Node<T>* &lista, T x, int (*criterio)(T a, T b)){
        //crear el nodo
    Node<T>* nuevo = new Node<T>();
        nuevo->info = x;
        nuevo->next = NULL;
        //si esta vacia o va delante del primero
        if (lista==NULL || criterio(lista->info,x)>0 ){
            lista = nuevo;
            return nuevo;
        }
        //si no salió, no esta vacía y va entre dos o al final
        Node<T>* aux = lista;
        while( aux->next != NULL && criterio(aux->next->info,x)<0) {
            aux = aux->next;
        }
        // enlaza los punteros
        nuevo -> next = aux->next,
        aux -> next = nuevo;
        return nuevo;

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

    show(nodosAutistas, showInt);
}

