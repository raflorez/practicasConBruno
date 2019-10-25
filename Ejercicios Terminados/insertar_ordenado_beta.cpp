#include <iostream>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Persona{
	char nombre [20];
	char apellido [20];
};

template <typename T>
struct Node {
	T info;
	Node<T>* next;
};

using namespace std;


template <typename T>
void show(Node<T>*);

template <typename T>
void insertar_ordenado(Node<T>*&, T );
//MAIN
int main() {
	

	
	
	Node<int>* lista = NULL;
	

	
	insertar_ordenado(lista,1);
	insertar_ordenado(lista,5);	
		insertar_ordenado(lista,2);	
	show(lista); 
}

 template <typename T>
void insertar_ordenado(Node<T>* &lista, T x){
    Node<T>* p = new Node<T>;
    p->info = x;

    if (lista == NULL  || x < lista->info){
        p->next = lista;

        lista = p;
    }else{
        Node<T>* q = lista;

        while(q->next != NULL && x>q->next->info){
            q = q->next;
        }

        p->next = q->next;
        q->next = p;
    }
}

template <typename T>
void show(Node<T>* p){
	Node<T>* aux = p;
	
	while(aux != NULL){
		cout<<"el nodo contiene el entero"<<aux->info<<endl;
		aux = aux->next;
	}
	
	cout<<endl<<" ya se recorrio toda la lista";
	
	
	
}
