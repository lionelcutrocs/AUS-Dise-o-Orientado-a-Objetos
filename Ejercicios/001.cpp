#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

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

 int cuatrimestre;
 string nombreMateria;
 string codigo;

 vector <Alumno> inscriptos;

 public:

    void enrolarAlumno (Alumno nuevoAlumno ) 
        {
         inscriptos.push_back ( nuevoAlumno );
        }

    void listarAlumno ();
    bool buscarAlumno (int);
    
};

void limpiarConsola () {
    system("cls");
};

int main () {

 int dni;
 int cuatrimestre;
 string nombre;
 string mail;
 Materia materia;
 string codigo;
 string nombreMateria;

    cout << "\nBienvenido al sistema de inscripcion para Alumnos." << endl;
    cout << "\nPrecione Enter para comenzar:" << endl;
    cin.ignore();                                                       // pausa del programa para precionar enter y continuar

    cout << "Ingrese su nombre." << endl;
    cout << "-> ";
    getline (cin, nombre );

    cout << "\n<-------------------------->" << endl;

    cout << "\nIngrese su DNI." << endl;
    cout << "-> ";
    cin >> dni;

    cout << "\n<-------------------------->" << endl;

    cout << "\nIngrese su mail." << endl;
    cout << "-> ";
    cin.ignore();
    getline ( cin, mail );

    Alumno alumno1 ( dni, nombre, mail );                               // creo el objeto para guardar los datos
    materia.enrolarAlumno ( alumno1 );                                  // llamo a la funcion para guardar el objeto en el vector

    cout << "\nPrecione Enter para guardar:" << endl;
    cin.ignore();                                                       // pausa del programa para precionar enter y continuar

    cout << "Inscripcion existosa! Los siguientes datos fueron guardados" << endl;
    cout << "\nNombre -> " << alumno1.getNombre() << endl;
    cout << "DNI -> " << dni << endl;
    cout << "Mail -> " << mail << endl;

    cout << "\n<---------------------------------------------------------->" << endl;

    cout << "\nPrecione Enter para continuar:" << endl;
    cin.ignore();   

    cout << "Cargue los datos de la Materia:" << endl;
    cout << "\nNombre de la materia:" << endl;
    cout << "-> ";
    getline ( cin, nombreMateria );

    cout << "\nCargue el numero de cuatrimestre correspondiente" << endl;
    cout << "-> ";
    cin >> cuatrimestre;

    cout << "\nCargue el codigo de materia" << endl;
    cout << "-> ";
    cin.ignore();
    getline ( cin, codigo );

    cout << "\nPrecione Enter para guardar:" << endl;
    cin.ignore();

    cout << "Inscripcion existosa! Los siguientes datos fueron guardados" << endl;
    cout << "\nNombre de materia -> " << nombreMateria << endl;
    cout << "Numero de cuatrimestre -> " << cuatrimestre << endl;
    cout << "Codigo de materia -> " << codigo << endl;

    return 0;
}