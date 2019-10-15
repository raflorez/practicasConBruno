#include <iostream>
#include <string.h>
#include <stdio.h>


using namespace std;

//Struct's
struct Subject{
    int id;
    char name[20];
};

//file = legajo Ahora writearé my code en inglush
struct Student{
    int cod_file;
    int cod_subject;
    char name[20];
};
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

void showStudent(Student);

template <typename T>
void show(Nodo<T>*, void (*)(T));

//inteface function
void show_students_i();
void load_students_i();
void show_subject_i();
void load_subject_i();

//tools
Student createStudent(int, char[20], int);

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
    cout<<"Choose a option \n 1_ Show student's \n 2_ Load student's\n 3_ Show subject's\n 4_ Load subject's \n";
    int op;
    cin>>op;
    switch(op){
        case 1:
            show_students_i();
            break;
        case 2:
            cout<<"\n  You choose \"Load student's\"";
            load_students_i();
            break;
        case 3:
            show_subject_i();
            break;
        case 4:
            load_subject_i();
            break;

        default:
            cout<<"Invalidate!!";
            break;


    }

}



template <typename T>
void push(Nodo<T>*& p, T v){

    Nodo<T>* q = new Nodo<T>();
    q->info = v;
    q->next= p;
    p = q;
    return;
}

void showStudent(Student student){
    cout << "His name is " <<student.name<< ", his file code is ";
    cout <<student.cod_file<<" and his subject is "<<student.cod_subject<<endl;

}
template <typename T>
void show(Nodo<T>* l, void (*show)(T)){
    Nodo<T>* aux = l;
    while( aux!=NULL ){
        show(aux->info);
        aux = aux->next;
    }
}

 Student createStudent(int cod_file, char name[20] , int cod_subject){
    Student s;
    s.cod_file = cod_file;
    strcpy_s(s.name, name);
    s.cod_subject = cod_subject;
    return s;
}
//Main
void show_students_i(){
    //TODO...
}
void load_students_i(){

    Nodo<Student>* students = NULL;

    cout<<"\n Say the number of register that you can put\n";
    int n, cf, cs = 0;
    char nm[20];
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cout<<"\n Okey. Now say FILE CODE of student"<<endl;
        cin>>cf;
        cout<<"\n Okey. Now say NAME of student"<<endl;
        cin.ignore();
        cin.getline(nm,20);
        cout<<"\n Okey. Now say SUBJECT CODE of student"<<endl;
        
        cin>>cs;
        push(students, createStudent(cf, nm, cs));
    }
    


    show(students, showStudent);

    /* Open file */
    FILE* f = fopen("..\\datastorage.dat", "wb+");

    /* Load Studedst*/
    load_file(f, students);
    fclose(f);

}
void show_subject_i(){
    //TODO...
}
void load_subject_i(){
    //TODO...
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

