#include <iostream>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
struct Fruta{
	char nombre[20];
	int nv_de_sabor;
};


struct Verdura{
	char nombre[20];
	int nv_de_sabor;
};

struct Caramelos{
	char nombre[20];
	int nv_de_sabor;
};

template <typename F>
struct Bolsa{
	char descripcion[50];
	F productos[2];
};

template <typename F>
void mostrar_productos(F[], int);

int main(int argc, char** argv) {
	
	cout<<"estoy en el supermercado"<<endl;
	
	
	//agarrar frutas
	Fruta primer_fruta;
	strcpy(primer_fruta.nombre, "manzana");
	primer_fruta.nv_de_sabor = 10;
	
	Fruta segunda_fruta;
	strcpy(segunda_fruta.nombre, "banana");
	segunda_fruta.nv_de_sabor = 20;
	
	//agarrar caramelelos
	Caramelos primer_caramelo;
	strcpy(primer_caramelo.nombre, "fish");
	primer_caramelo.nv_de_sabor = 10;
	
	Caramelos segundo_caramelo;
	strcpy(segundo_caramelo.nombre, "chupetin");
	segundo_caramelo.nv_de_sabor = 10;
	
	//las pongo en la bolsa de frutas
	Bolsa<Fruta> miBolsa_de_frutas;
 	strcpy(miBolsa_de_frutas.descripcion, "es una bolsa que tiene frutas!");
	miBolsa_de_frutas.productos[0] = primer_fruta;
	miBolsa_de_frutas.productos[1] = segunda_fruta;
	
	//las pongo en la bolsa de caramelos
	Bolsa<Caramelos> miBolsa_de_caramelos;
	strcpy(miBolsa_de_caramelos.descripcion, "es una bolsa que tiene caramelos!");
	miBolsa_de_caramelos.productos[0] = primer_caramelo;
	miBolsa_de_caramelos.productos[1] = segundo_caramelo;
	
	//mostrar en caja que productos tnego 
	mostrar_productos(miBolsa_de_frutas.productos,2);
	mostrar_productos(miBolsa_de_caramelos.productos,2);
	return 0;
}

template <typename F>
void mostrar_productos(F productos[], int cant_prod){
	for(int i = 0; i < cant_prod; i++){
		cout<<"producto ingresada "<<productos[i].nombre<<" y su valor de sabor es "<<productos[i].nv_de_sabor<<endl;
	}
	
	return; //no devuelve nada
}


