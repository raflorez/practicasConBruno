#include <iostream>
#include <stdlib.h>//libreria texto

using namespace std;
struct Dato;
int ordenarXMayor(int, int, int);
Dato ordenarDatos(Dato[], int);


int main(){
struct Dato{
int col1;
int col2;
};

Dato dato[4];
//Pido los datos x pantalla
Dato dguardado[4];
for(int i=0; i<4; i++){
cout<<"ingre la primer columna: "<<endl;
cin>>dato[i].col1;
cout<<"ingre la segunda columna: "<<endl;
cin>>dato[i].col2;

}


//Grabo lo que ped{i
FILE* f = fopen("fsociaty.dat","w");
fwrite(&dato, sizeof(dato),1, f);

fclose(f);

//Leer mi archivo
FILE* fcomprobar = fopen("fsociaty.dat","r");
fread(dguardado, sizeof(dguardado),4, fcomprobar);

fclose(fcomprobar);



int len = 4;
int auxcol1;
int auxcol2;
for (int i =2; i<len; i++){
for( int j = 0; j<len-1; j++){
if( dguardado[j].col1 > dguardado[j+1].col1){
auxcol1 = dguardado[j].col1;
auxcol2 = dguardado[j].col2;
dguardado[j].col1 = dguardado[j+1].col1;
dguardado[j].col2 = dguardado[j+1].col2;
dguardado[j+1].col1 = auxcol1;
dguardado[j+1].col2 = auxcol2;
}
}
}
for(int i=0; i<4; i++){
cout<<"|";
cout<<dguardado[i].col1;
cout<<"|";
cout<<dguardado[i].col2;
cout<<"|";
cout<<endl;
}

}


 
