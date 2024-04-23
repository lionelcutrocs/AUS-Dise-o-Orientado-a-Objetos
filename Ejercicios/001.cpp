#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Alumno {

 int dni;
 string nombre;
 string mail;

 public:
    Alumno ( int d, string n, string m ) : dni {d}, nombre {n}, mail {m} {};            // constructor para inicializar datos del alumno
        string getNombre () { return nombre; };                                         // metodo para acceso a nombre
};

class Materia {

 string codigo;
 string nombre;
 int cuatrimestre;
 vector <Alumno> inscriptos;

 public:
    void enrolarAlumno (Alumno);
    void listarAlumno ();
    bool buscarAlumno (int);
    
};

int main () {










    return 0;
}