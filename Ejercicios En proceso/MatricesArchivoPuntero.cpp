#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


template <typename T>
struct Node
{
    T info;
    Node<T>* next;
};


struct Data{
    int col;
    int row;
    int value;
};

/*
 * Prototypes function
 */
//Tools
int lengthInt(int);
Data createData(int, int, int);
void show_matrix3x2(Node<int>*[3][2]);

//List
template <typename T>
void push(Node<T>*&, T v);


template <typename T>
void show(Node<T>*, void (*)(T));

void showInt(int);
//inteface function
void show_matrix_i();
void load_matrix_i();


//File functions

int registers_amount( FILE*);
int get_position_p( FILE * f);
int seek( FILE*, int);

template <typename R>
int read( FILE*, R*);

template <typename T>
void write(FILE*, T);


/* -------------------------------------------------*/


/*
 * Main function
 */
int main()
{

    //declared variables
    int op;
    system("color 09");
    cout<<" __    __     ______     ______   ______     ______     __  __    \n"
          "/\\ \"-./  \\   /\\  __ \\   /\\__  _\\ /\\  == \\   /\\  __ \\   /\\_\\_\\_\\   \n"
          "\\ \\ \\-./\\ \\  \\ \\  __ \\  \\/_/\\ \\/ \\ \\  __<   \\ \\  __ \\  \\/_/\\_\\/_  \n"
          " \\ \\_\\ \\ \\_\\  \\ \\_\\ \\_\\    \\ \\_\\  \\ \\_\\ \\_\\  \\ \\_\\ \\_\\   /\\_\\/\\_\\ \n"
          "  \\/_/  \\/_/   \\/_/\\/_/     \\/_/   \\/_/ /_/   \\/_/\\/_/   \\/_/\\/_/ \n"
          "                                                                  "<<endl;
    cout<<"Made by: Ramiro Flores <ramirosacruz@gmail.com>\n"<<endl;
    cout<<"Choose a option \n 1_ Show matrix's \n 2_ Load matrix's\n";

    cin>>op;
    switch(op){
        case 1:
            //show_matrix_i();
            break;
        case 2:
            cout<<"\n  You choose \"Load student's\"";
            load_matrix_i();
            break;
        default:
            cout<<"Invalidate!!";
            break;


    }


    return 0;



}

/*
 * Interface function
 */
void show_matrix_i(){
    cout<<"\n Reading file...";

    //Open the file
    FILE* f = fopen("data.dat", "rb");

    //Initial Matriz where store the datastore of the file
    Node<int>* matriz[3][2];

    //Read the matriz
    read(f, matriz);
    /*
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            show(matriz[i][j], showInt);
        }
    }
     */
    fclose(f);


}

void load_matrix_i(){

    FILE* f = fopen("data.dat", "wb");
    Node<int>* matrix[3][2];
    int op = 0;
    int n = 0;
    int value = 0;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j <2; j++){

            cout<<"\n Ok! :)"<<endl;

            cout<<"X: "<<i+1<<" y Y: "<<j+1;

            cout<<"\nDo you want insert int? 1(YES) OR 0(NO)"<<endl;
            cin>>op;

            if(op) {
                cout<<"How much you want?"<<endl;
                cin>>n;
                cout<<n<<endl;
                for(int m = 0 ;m < n; m++){
                    cout<<"("<<m+1<<"/"<<n<<") The value was insert in list of the matrix in the coord X:"<<i+1<<" and Y:"<<j+1<<endl;;
                    cin>>value;
                    push(matrix[i][j], value);
                    write(f, createData(j+1,i+1,value));
                }
                cout<<"Finish X:"<<i+1<<" and Y:"<<j+1;
            }else{
                cout<<"Okey... :c ";
            }
        }
    }

    show_matrix3x2(matrix);

}

/*
 * Tools function
 */

int lengthInt(int x){
    int n = x;
    int i = 0;
    while(n>0){
        n /= 10;
        i++;
    }
    return i;

}
Data createData(int col, int row, int value){
    Data d;
    d.col = col;
    d.row = row;
    d.value = value;

    return d;
}

void show_matrix3x2(Node<int>* matrix[3][2]){

    int size_col;
    for(int i = 0; i < 3; i++){
        cout<<"|--------------------------------------|"<<endl;
        cout<<"|";
        for(int j = 0; j < 2; j++){
            show(matrix[i][j], showInt);cout<<"|";
        }
        cout<<endl;

    }

    /*


        cout<<"THIS IS THE MATRIX"<<endl;
     //12 char b cel
    cout<<"|--------------------------------------|"<<endl;
    cout<<"|            |            |            |"<<endl;
    cout<<"|------------|------------|------------|"<<endl;
    cout<<"|            |            |            |"<<endl;
    cout<<"|------------|------------|------------|"<<endl;

*/
}


/*
 * Files function
 */

template <typename R>
int registers_amount( FILE * f){
    R r;
    fseek(f, 0, SEEK_END);
    return ftell(f)/sizeof(r);
}
template <typename R>
int get_position_p( FILE * f){
    R r;
    return ftell(f)/sizeof(r);
}

template <typename R>
int seek( FILE * f, int pos){
    R r;
    return fseek(f, pos * sizeof(r), SEEK_SET);
}

template <typename R>
int read( FILE * f, R *r){
    return fread(&r, sizeof(r) , 1, f);
}

template <typename T>
void write(FILE* f, T v)
{
    fwrite(&v,sizeof(T),1,f);
    return;
}



/*
 * List function
 */

template <typename T>
void push(Node<T>*& p, T v){

    Node<T>* q = new Node<T>();
    q->info = v;
    q->next= p;
    p = q;
    return;
}

template <typename T>
void show(Node<T>* l, void (*showType)(T)){ //para obtener el tamaño
    Node<T>* aux = l;
    while( aux!=NULL ){
        showType(aux->info);
        aux = aux->next;
    }
}

void showInt(int x){
    cout<<x<<"-";
}

template <typename T>
Node<T>* insertar_ordenado(Node<T>* &lista, T x, T (*criterio)(T a, T b)){
    Node<T>* p = new Node<T>();
    p->info = x;

    if (lista == NULL  || criterio(x, lista->info)){
        p->sgts = lista;

        lista = p;
    }else{
        Node<T>* q = lista;

        while(q->sgts != NULL && criterio(q->sgts->inf, x)){
            q = q->sgts;
        }

        p->sgts = q->sgts;
        q->sgts = p;
    }

    return p;
}

template <typename T>
bool ascedente(T a, T b){
    return a < b;
}


template <typename T>
bool descendente(T a, T b){
    return a > b;
}



