#include <iostream>
using namespace std;

struct Nodo{
    int info;
    Nodo* sgts;
};
void push(Nodo*&, int);
int pop(Nodo*&);
void encolar(Nodo*&, Nodo*&, int);
int desencolar(Nodo*&, Nodo*&);

int main()
{
    system("color 0a");
    Nodo* p = NULL;
    Nodo* fte = NULL;
    Nodo* fin = NULL;
    Nodo* pila = NULL;


    for (int i = 0; i < 10; i++){
        push(pila, i);
        
    }
    while (pila){
        cout <<pop(pila);
    }
    cout<<endl;

    for (int i = 0; i< 10; i++){
        encolar(fte, fin, i);
        
    }
    while(fte){
        cout << desencolar(fte, fin);
    }
}

void push(Nodo *&pila, int x){
    Nodo *p = new Nodo();
    p->info = x;
    p->sgts = pila;

    pila = p;

    return;
}

void encolar(Nodo* &fte, Nodo* &fin, int x){
    Nodo *p = new Nodo();
    p->info = x;
    p->sgts = NULL;

    if (fte == NULL) fte = p; else fin->sgts = p;
    fin = p;

    return;
}

int pop(Nodo* &pila){
    Nodo *p = pila;
    int x = p->info;
    pila = p->sgts;

    delete p;

    return x;
}

int desencolar(Nodo* &fte, Nodo*&fin){
    Nodo *p = fte;
    int x = p->info;
    fte = p->sgts;
    if (fte == NULL) fin = NULL;

    delete p;

    return x;
}
