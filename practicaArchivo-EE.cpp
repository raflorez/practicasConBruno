#include <iostream>
#include <string.h>
#include <stdio.h>


using namespace std;

struct Alumnos{
    Alumnos* sgts;
    int nro_legajo;
    int cod_materia;
    char nombre[20];
};


struct Materia{
    Materia* sgts;
    int cod_materia;
    char nombre[20];
};

//Prototipos

//main function
void mostrar_list_alumnos();
void cargar_alumnos();
void mostrar_materias();
void cargar_materias();

//de Carga
Alumnos* insertar_alumno(Alumnos* &lista, int, int, char[]);

int main()
{
    cout<<"Elija la opción \n 1_ mostrar listado de alumnos \n 2_ mostrar materias disponibles\n 3_ cargar alumnos\n 4_ cargar materias \n";
    int op;
    cin>>op;
    switch(op){
        case 1:
            mostrar_list_alumnos();
            break;
        case 2:
            cout<<"\n  Usted ha elegido cargar alumnos";
            cargar_alumnos();
            break;
        case 3:
            mostrar_materias();
            break;
        case 4:
            cargar_materias();
            break;

        default:
            cout<<"Seleccione una opción valida uwu";
            break;


    }
}

//Main
void mostrar_list_alumnos(){
    //TODO...
}
void cargar_alumnos(){
    Alumnos* lista = NULL;


    int nro_insert = 3;

    //parametros
    int nro_legajo;
    int cod_materia;
    char nombre[20];
    //Vas insertando numeros en la lista y se van a ordenar
    //for (int i = 0; i < nro_insert; i++){
        cout<<"\ninserte cod_materia \n";
        cin>>cod_materia;
        cout<<"\ninserte nro_legajo \n";
        cin>>nro_legajo;
        cout<<"\n inserte nombre";
        cin.getline(nombre,20);
        system("pause");
        //insertar_alumno(lista, nro_legajo, cod_materia, nombre);
    //}
    //Muestra el primer numero, tiene que ser el más chico porque fue ordenandose
    //cout<<lista->nombre;
}
void mostrar_materias(){
    //TODO...
}
void cargar_materias(){
    //TODO...
}

//Tools
Alumnos* insertar_alumno(Alumnos* &lista, int nro_legajo, int cod_materia, char nombre[]){
    Alumnos* p = new Alumnos();
    p->nro_legajo = nro_legajo;
    p->cod_materia = cod_materia;
    strcpy( p->nombre, nombre );
    if (lista == NULL  || nro_legajo < lista->nro_legajo){
        p->sgts = lista;
        lista = p;
    }else{
        Alumnos* q = lista;
        while(q->sgts != NULL && nro_legajo>q->sgts->nro_legajo){
            q = q->sgts;
        }
        p->sgts = q->sgts;
        q->sgts = p;
    }
    return p;
}
