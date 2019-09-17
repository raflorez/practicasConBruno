#include <iostream>
#include <stdlib.h>
using namespace std;

struct Malo{
    string nombre;
    int vida = 2;
    string skin = "<x__x>\n \\_/";
    int posX = 20;
};

struct Player{
    string nombre;
    int vida = 10;
    string skin = "<UwU>";
    int posX;
};

void reload_window(Player, Malo);

void setPosX(int, string);


int main()
{
    system("color 0a");
    Player player;
    Malo malo;
    player.nombre = "Ramiro";
    bool isLost = 1;
    player.posX = 20;
    reload_window(player, malo);
    cout<<"\n";
    while(isLost){


        reload_window(player, malo);
        cout<<"\n";
        cin>>player.posX;
        cout<<"\nINTRODUZCA LA POSICION X DE SU PERSONAJE";
    }

}

void reload_window(Player p, Malo m){
    system("cls");
    setPosX(m.posX, m.skin);
    cout<<"\n\n\n";
     setPosX(p.posX, p.skin);
}

void setPosX(int x, string elem){
    for(int i = 0; i< x; i++){
        cout<<" ";
    }
    cout<<elem;
}
