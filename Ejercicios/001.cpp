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

 int dni;
 string nombre;
 string mail;

    cout << "\nBienvenido al sistema de incripcion para Alumnos." << endl;
    cin.ignore();

    cout << "\nIngrese su nombre ..." << endl;
    getline (cin, nombre );

    cout << "<-------------------------->" << endl;

    cout << "Ingrese su DNI." << endl;
    cin >> dni;

    cout << "<-------------------------->" << endl;

    cout << "Ingrese su mail." << endl;
    cin.ignore();
    getline ( cin, mail );

    Alumno alumno1 ( dni, nombre, mail );                               // creo el objeto para guardar los datos

    cin.ignore();

    cout << "\n¡Incripcion existosa! Los siguientes datos fueron guardados" << endl;
    cout << "Nombre -> " << alumno1.getNombre() << endl;
    cout << "DNI -> " << dni << endl;
    cout << "Mail -> " << mail << endl;



    return 0;
}