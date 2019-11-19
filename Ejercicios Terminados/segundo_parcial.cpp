#include <iostream>

using namespace std;

struct Examen{
    int numero_legajo;
    char apellido_nombre[20];
    float puntaje;
};


struct Nodo{
    Curso info;
    Nodo* sgt;
};

struct Curso{
    Nodo* examenFte;
    Nodo* examenFin;
};
void saludar(){
    cout<<"hola"<<endl;
}

unsigned getCurso(unsigned un_indice){
    //TODO
}

void encolar_examenes(){
    //TODO
}

Examen desencolar(Nodo* &fte, Nodo*&fin){
    Nodo *p = fte;
    Examen x = p->info;
    fte = p->sgts;
    if (fte == NULL) fin = NULL;

    delete p;

    return x;
}

struct Personita{

};
/*
Personita r;
is_buena(r);
*/

//T = Examen JUSTIFICACIÒN
bool is_promocionado(Examen examen){
    if(examen.puntaje >= 8){
        return true
    }else{
        return false;
    }

}


/*
Cursos > Curso > Examenes
Cursos N : Vector
Curso ? : Estructura E. ->Cola
Examenes : Object -> Nro legajo, Nombre y apellido y puntajes
*/
void InformarPromocionados(Curso curso){
    //Variables auxiliares para no afectar a la del curso
   Nodo* fte = Curso->examenFte;
   Nodo* fin = Curso->examenFin;
   Examen examenActual;
    while(fte){
        examenActual = desencolar(fte, fin);
        if(is_promocionado(examenActual)){
            cout<<"Ha promocionado el alumno ";
            cout<<examenActual.apellido_nombre;
            cout<<"con nota de promoción ";
            cout><<examenActual.puntaje;
        }

    }
}
int main()
{
    cout << "Hello world!" << endl;
    int n;
    cin<<n<<;

    /*Aca es cuando incializamos*/
    Nodo cursos[n];

    /*Paso un tiempo y el que corrije quiere hacerloxd*/

    //Corrigiendo
    for(int i; i<n; i++){
        InformarPromocionados(cursos[i])
    }
    return 0;
}
