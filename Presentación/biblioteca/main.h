#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

template <typename T>
struct nodo
{
    T info;
    nodo<T>* siguiente;
};

template <typename T>
int descendente(T a, T b){
    return a > b;
}
template <typename T>
int ascedente(T a, T b){
    return a < b;
}



void push(nodo<int>*&pila, int x );

int pop(nodo<int>*&pila);

void encolar(nodo<int>*&frente,nodo<int>*&fin, int x);

int desencolar(nodo<int>*&frente,nodo<int>*&fin);






void push(nodo<int>*&pila, int x)
{
	nodo<int>*p = new nodo<int>();
	p->info=x;
	p->siguiente=pila;
	pila=p;
	return;
}

int pop(nodo<int>*&pila)
{
	nodo<int>*p = pila;
	int x = p-> info;
	pila = p->siguiente;
	delete p;
	return x;
}

void encolar(nodo<int>*&frente,nodo<int>*&fin, int x)
{
	nodo<int>*p = new nodo<int>();
	p->info=x;
	p->siguiente=NULL;
	if (frente == NULL)
	{
		frente=p;
	}
	else fin->siguiente=p;
	fin=p;
	return;
}

int desencolar(nodo<int>*&frente,nodo<int>*&fin)
{
	nodo<int>*p = frente;
	int x = p-> info;
	frente = p->siguiente;
	if (frente == NULL)
	{
		fin=NULL;
	}
	delete p;
	return x;
}

void showInt(int x){
    cout<<x<<"-";
}
template <typename T>
void show(nodo<T>* l, void (*showType)(T)){ 
    nodo<T>* aux = l;
    while( aux!=NULL ){
        showType(aux->info);
        aux = aux->next;
    }
}

template <typename T>
nodo<T>* insertar_ordenado(nodo<T>* &lista, T x, int (*criterio)(T a, T b)){
    nodo<T>* p = new nodo<T>();
    p->info = x;

    if (lista == NULL  || criterio(x, lista->info)){
        p->next = lista;

        lista = p;
    }else{
        nodo<T>* q = lista;

        while(q->next != NULL && criterio(q->next->info,x)){
            q = q->next;
        }

        p->next = q->next;
        q->next = p;
    }

    return p;
}
