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
struct Node
{
    T info;
    Node<T>* next;
};

//Prototype's

//List function
template <typename T>
void push(Node<T>*&, T v);

void showStudent(Student);

template <typename T>
void show(Node<T>*, void (*)(T));

//inteface function
void show_students_i();
void load_students_i();

//tools
Student createStudent(int, char[20], int);

//File functions
template <typename R>
int registers_amount( FILE*);

template <typename T>
void seek(FILE*, int);

template <typename T>
T read(FILE* f);

template <typename T>
void write(FILE*, T);

template <typename T>
void load_file(FILE*&, Node<T>*&);
int main()
{
    system("color 0a");
    cout<<" _____ _             _            _  __   __\n"
          "/  ___| |           | |          | | \\ \\ / /\n"
          "\\ `--.| |_ _   _  __| | ___ _ __ | |_ \\ V / \n"
          " `--. \\ __| | | |/ _` |/ _ \\ '_ \\| __|/   \\ \n"
          "/\\__/ / |_| |_| | (_| |  __/ | | | |_/ /^\\ \\\n"
          "\\____/ \\__|\\__,_|\\__,_|\\___|_| |_|\\__\\/   \\/\n"
          "                                            \n"
          "    Made by: Ramiro Flores <ramirosacruz@gmail.com>\n"<<endl;
    cout<<"Choose a option \n 1_ Show student's \n 2_ Load student's\n";
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
        default:
            cout<<"Invalidate!!";
            break;


    }

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
void show(Node<T>* l, void (*show)(T)){
    Node<T>* aux = l;
    while( aux!=NULL ){
        show(aux->info);
        aux = aux->next;
    }
}

/*
 * Tools function
 */

void showStudent(Student student){
    cout << "His name is " <<student.name<< ", his file code is ";
    cout <<student.cod_file<<" and his subject is "<<student.cod_subject<<endl;

}

 Student createStudent(int cod_file, char name[20] , int cod_subject){
    Student s;
    s.cod_file = cod_file;
    strcpy_s(s.name, name);
    s.cod_subject = cod_subject;
    return s;
}
/*
 * Interface function
 */
void show_students_i(){

    FILE* f = fopen("datastorage.dat", "rb+");
    int length = registers_amount<Student>(f);
    seek<Student>(f, 0);

    Node<Student>* students = NULL;
    for (int i = 0; i < length; i++) { //fix

        push(students, read<Student>(f));

    }

    show(students, showStudent);
    fclose(f);
    system("pause");
}
void load_students_i(){
    FILE* f = fopen("datastorage.dat", "wb+");

    Node<Student>* students = NULL;

    cout<<"\n Say the number of register that you can put\n";
    int n, cf, cs = 0;
    char nm[20];
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cout<<"\n COMPLETED "<<i+1<<"/"<<n<<endl;
        cout<<"\n Okey. Now say FILE CODE of student"<<endl;
        cin>>cf;

        cout<<"\n Okey. Now say NAME of student"<<endl;
        cin.ignore();
        cin.getline(nm,20);
        cout<<"\n Okey. Now say SUBJECT CODE of student"<<endl;

        cin>>cs;
        push(students, createStudent(cf, nm, cs));
    }

    /*Show preview*/
    show(students, showStudent);

    /* Load Students*/
    load_file(f, students);

    system("pause");
}

/*
 * /File function
 */

template <typename T>
void load_file(FILE*& f, Node<T>*& p){
    while( p!=NULL ){
        write(f,  p->info);
        p = p->next;
    }
}

template <typename T>
void seek(FILE* arch, int n)
{
    fseek(arch, n*sizeof(T),SEEK_SET);
}
template <typename R>
int registers_amount( FILE * f){
    R r;
    fseek(f, 0, SEEK_END);
    return ftell(f)/sizeof(r);
}

template <typename T>
T read(FILE* f)
{
    T buff;
    fread(&buff,sizeof(T),1,f);
    return buff;
}
template <typename T>
void write(FILE* f, T v)
{
    fwrite(&v,sizeof(T),1,f);
    return;
}