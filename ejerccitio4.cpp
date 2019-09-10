#include<iostream>

using namespace std;

int main (){
int vector[6];
int mayor=0;
int posicion=0;
for(int i=0;i<6;i++)
{
cin>>vector[i];

}
for(int i=0;i<6;i++)
{
if (vector[i]>mayor)
{
mayor = vector[i];
posicion = i+1;
}

}
cout<<endl;
cout<<posicion;


}
