#include <iostream>

using namespace std;

template <typename T>
struct Nodo{
	T info;
	Nodo<T> sgt;	
}
template <typename T>
struct Pizza{
	T precio;
	int tamanio;
	int tipo;
	
};


template <typename T>
struct Pedido{
	int horario;
	char nombre_c[30];
	Pizza pizzas[30];
	int cantidad[30];
};

