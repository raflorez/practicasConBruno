#include <iostream>
#include <string.h>
#include <stdio.h>


using namespace std;

 
template <typename T>
struct Nodo
{
    T info;
    Nodo<T>* next;
};

//Prototype's

//tools
template <typename T>
void push(Nodo<T>*&, T v);

void showInt(int);

template <typename T>
void show(Nodo<T>*, void (*)(T));

//inteface function
void show_matrix_i();
void load_matrix_i();

//tools
 
//File functions

int registers_amount( FILE*);
int get_position_p( FILE * f);
int seek( FILE*, int);

template <typename R>
int read( FILE*, R*);

template <typename R>
int write( FILE*, R);

template <typename T>
void load_file(FILE*&,  Nodo<T>*&);


int main()
{
	//declared variables
	system("color 01");
	int op;

    cout<<"que desea hacer?"<<endl;
    
    cout<<"\n 1_Leer archivo"<<endl;
    cout<<"\n 2_Cargar archivo"<<endl;
    
    cin>>op;
    
    if(op == 1){
    	show_matrix_i();
	}else{
		load_matrix_i();
	}	
	
	return 0;
		
		

}


void show_matrix_i(){
	cout<<"\n Reading file...";
 	
 	//Open the file
	FILE* f = fopen("data.dat", "rb");
	
	//Initial Matriz where store the datastore of the file
	Nodo<int>* matriz[3][2];
	
	//Read the matriz
	read(f, matriz);
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 2; j++){
			show(matriz[i][j], showInt);
		}
	}
	fclose(f);
	
	
}


void load_matrix_i(){
	
	FILE* f = fopen("data.dat", "wb");
	Nodo<int>* matrix[3][2];
	int x = 0;
	int op = 0;
	int n = 0;
	int value = 0;
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j <2; j++){
			
			cout<<"\n Ok! :)"<<endl;
			 
			cout<<"X: "<<i<<" y Y: "<<j;
			
			cout<<"\nDo you want insert int? 1(YES) OR 0(NO)"<<endl;
			cin>>op;
			
			if(op) {
				cout<<"How much you want?"<<endl;
				cin>>n;
				cout<<n<<endl;#include <iostream>
#include <string.h>
#include <stdio.h>


using namespace std;

 
template <typename T>
struct Nodo
{
    T info;
    Nodo<T>* next;
};

//Prototype's

//tools
template <typename T>
void push(Nodo<T>*&, T v);

template <typename R>
void showInt(Nodo<R>*);

template <typename T>
void show(Nodo<T>*, void (*)(T*));

//inteface function
void show_matrix_i();
void load_matrix_i();

//tools
 
//File functions

int registers_amount( FILE*);
int get_position_p( FILE * f);
int seek( FILE*, int);

template <typename R>
int read( FILE*, R);

template <typename R>
int write( FILE*, R);

template <typename T>
void load_file(FILE*&,  Nodo<T>*&);


int main()
{
	//declared variables
	int op;
	
    cout<<"que desea hacer?"<<endl;
    
    cout<<"\n 1_Leer archivo"<<endl;
    cout<<"\n 2_Cargar archivo"<<endl;
    
    cin>>op;
    
    if(op == 1){
    	show_matrix_i();
	}else{
		load_matrix_i();
	}	
	
	return 0;
		
		

}


void show_matrix_i(){
	cout<<"\n Reading file...";
 	
 	//Open the file
	FILE* f = fopen("data.dat", "rb");
	
	//Initial Matriz where store the datastore of the file
	Nodo<int>* matriz[3][2];
	
	
	//Read the file and set matriz
	
	int value;
	
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 2; j++){
			read(f, value);
			cout<<value;
			
			push(matriz[i][j], value );
		}
	}

	fclose(f);
	
	//Read value of matriz
	
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 2; j++){
		 	show(matriz[i][j], showInt);
		}
	}	
	
}


void load_matrix_i(){
	
	FILE* f = fopen("data.dat", "wb");
	Nodo<int>* matrix[3][2];
	int x = 0;
	int op = 0;
	int n = 0;
	int value = 0;
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j <2; j++){
			
			cout<<"\n Ok! :)"<<endl;
			 
			cout<<"X: "<<i<<" y Y: "<<j;
			
			cout<<"\nDo you want insert int? 1(YES) OR 0(NO)"<<endl;
			cin>>op;
			
			if(op) {
				cout<<"How much you want?"<<endl;
				cin>>n;
				cout<<n<<endl;
				for(int m = 0 ;m < n; m++){
					cout<<"("<<m+1<<"/"<<n<<") The value was insert in list of the matrix in the coord Y:"<<i+1<<" and X:"<<j+1<<endl;;
					cin>>value;
					cout<<value;
					push(matrix[i][j], value);
					write(f, matrix[i][j]);
					cout<<"\nINSERT WAS: "<<(matrix[i][j])->info;
				}
				cout<<"Finish X:"<<j+1<<" and Y:"<<i+1;
			}else{
				cout<<"Okey... :c ";
			}
		}
	}
	
	
	
	
	
	
	
}

//List fucntion
template <typename T>
void push(Nodo<T>*& p, T v){

    Nodo<T>* q = new Nodo<T>();
    q->info = v;
    q->next= p;
    p = q;
    return;
}


template <typename R> 
void showInt(Node<T>* t){
    cout<<"the value is :"<<t->info;
}


template <typename T>
void show(Nodo<T>* l, void (*showValue)(T)){
    Nodo<T>* aux = l;
    while( aux!=NULL ){
        showValue(aux->info);
        aux = aux->next;
    }
}



//Files functions

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
int read( FILE * f, R r){
    return fread(&r, sizeof(r) , 1, f);
}

template <typename R>
int write( FILE * f, R r) {

    return fwrite(&r, sizeof(R), 1, f);
}

//Main function

template <typename T>
void load_file(FILE*& f, Nodo<T>*& p){

    while( p!=NULL ){
        write(f,  p->info);
        p = p->next;
    }
}

template <typename T>
Nodo<T>* insertar_ordenado(Nodo<T>* &lista, T x, T (*criterio)(T a, T b)){
    Nodo<T>* p = new Nodo<T>();
    p->info = x;
	
    if (lista == NULL  || criterio(x, lista->info)){
        p->sgts = lista;
		
        lista = p;
    }else{
        Nodo<T>* q = lista;

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
				for(int m = 0 ;m < n; m++){
					cout<<"("<<m+1<<"/"<<n<<") The value was insert in list of the matrix in the coord Y:"<<i+1<<" and X:"<<j+1<<endl;;
					cin>>value;
					push(matrix[i][j], value);
				}
				cout<<"Finish X:"<<j+1<<" and Y:"<<i+1;
			}else{
				cout<<"Okey... :c ";
			}
		}
	}
	
	write(f, matrix);
	
	
	
	
	
}

//List fucntion
template <typename T>
void push(Nodo<T>*& p, T v){

    Nodo<T>* q = new Nodo<T>();
    q->info = v;
    q->next= p;
    p = q;
    return;
}


template <typename T>
void showInt(int x){
    cout<<"the value is :"<<x;
}


template <typename T>
void show(Nodo<T>* l, void (*show)(T)){
    Nodo<T>* aux = l;
    while( aux!=NULL ){
        show(aux->info);
        aux = aux->next;
    }
}



//Files functions

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

template <typename R>
int write( FILE * f, R r) {

    return fwrite(&r, sizeof(R), 1, f);
}

//Main function

template <typename T>
void load_file(FILE*& f, Nodo<T>*& p){

    while( p!=NULL ){
        write(f,  p->info);
        p = p->next;
    }
}

template <typename T>
Nodo<T>* insertar_ordenado(Nodo<T>* &lista, T x, T (*criterio)(T a, T b)){
    Nodo<T>* p = new Nodo<T>();
    p->info = x;
	
    if (lista == NULL  || criterio(x, lista->info)){
        p->sgts = lista;
		
        lista = p;
    }else{
        Nodo<T>* q = lista;

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
