#include<iostream>
#include<stdio.h>

using namespace std;

float compararTresNumeros(float, float,float);

int main(){
//Los datos de cada atleta. Nuestro obj: saber primer, segundo, tercero

//Pedir los nombres son 20

//Valores guardados
string sNombrePrimer;
string sNombreSegundo;
string sNombreTercer;

float fPrimero = 0.0;
float fSegundo = 0.0;
float fTercero = 0.0;

//Son los valores aux
float salto1 = 0.0;
float salto2 = 0.0;
float salto3 = 0.0;
string sNombreActual;
float fSaltoMayorActual = 0.0;

for(int i = 0; i<3; i++){
//Pedimos los datos 1 por 1
cout<<"atleta nro"<<i<<endl;
cout<<"Inserte el nombre del atleta\n";
cin>>sNombreActual;
cout<<"\nInserte primer salto";
cin>>salto1;
cout<<"\nInserte segundo salto";
cin>>salto2;
cout<<"\nInserte tercero salto";
cin>>salto3;

//Necesito saber cual de los saltos fue el mejor para compararlo con otros atletas
fSaltoMayorActual = compararTresNumeros(salto1,salto2,salto3);

if(fSaltoMayorActual > fPrimero){
//Ahora ese atleta es el primer puesto
sNombreTercer = sNombreSegundo;

sNombreSegundo = sNombrePrimer;

sNombrePrimer = sNombreActual;

fTercero = fSegundo;

fSegundo = fPrimero;

fPrimero = fSaltoMayorActual;

}else if(fSaltoMayorActual > fSegundo){
//Ahora ese atleta es el segundo puesto
sNombreTercer = sNombreSegundo;

sNombreSegundo = sNombreActual;
fSegundo = fTercero;
fSegundo = fSaltoMayorActual;
}else if (fSaltoMayorActual > fTercero){
//Ahora ese atleta es el tercer puesto
sNombreTercer = sNombreActual;
fTercero = fSaltoMayorActual;
}




}
//Concatenar
cout<<"el primer puesto es para: "<<sNombrePrimer<<" con un salto de"<<fPrimero<<endl;
cout<<"El Segundo puesto es para: "<<sNombreSegundo<<" con un salto de"<<fSegundo<<endl;
cout<<"el tercer puesto es para: "<<sNombreTercer<<" con un salto de"<<fTercero<<endl;
return 0;
}

float compararTresNumeros(float x, float y,float t){
float mayor = 0.0;

if( x > y &&  x> t ) {
mayor = x;
}else if(y > t) {
mayor = y;
}else {
mayor= t;
}
cout<<"mayor es "<<mayor;
return mayor;


}

