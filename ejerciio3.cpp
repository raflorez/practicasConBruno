#include <iostream>

using namespace std;


int main() {
//Cargar un vector de 6nro
//Recorrerlo
//Mostrar por posicion mayor

int vector[6];
int mayor[2] = {0,0}; // posicion, numero
for (int i = 0; i < 6; i++){
cout<<"Inserte el valor "<<i<<endl;
cin>>vector[i];

if(vector[i] > mayor[1]){
vector[i] = mayor[1];
mayor[0] = i;
}

}
cout<<"\n La posicion del numero mas alto es"<<mayor[0]<<endl;

return 0;
}
