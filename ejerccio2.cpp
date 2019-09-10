#include <iostream>

using namespace std;


int main() {
int edad;
cout<<"De edad"<<endl;
cin>>edad;

if( edad <= 12){//Menor
cout<<"Es menor";
}else if(edad >= 13 && edad <= 18){//Cadete
cout<<"Es Cadete";
}else if(edad > 18 && edad <= 26){//Juvenil
cout<<"Es Juvenil";
}else{//Mayor
cout<<"Es mayor";
}
return 0;
}

