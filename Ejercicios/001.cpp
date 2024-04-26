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

void menu_operation ( string& nombre, string& mail, string& nombreMateria, string& codigo, int& dni, int& cuatrimestre, int& resp_menu, Materia& materia ) 

{
    if ( resp_menu == 1)
    {
         cout << "\nEnrolamiento del Alumno." << endl;
         cout << "--------------------" << endl;
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

    } else if (resp_menu == 2)
    
    {    
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
    }

};

int main () {

 int dni;
 int cuatrimestre;
 int resp_menu;
 string nombre;
 string mail;
 Materia materia;
 string codigo;
 string nombreMateria;

    cout << "\nBienvenido al sistema de inscripcion para Alumnos." << endl;
    cout << "\nPrecione Enter para comenzar:" << endl;
    cin.ignore();                                                       // pausa del programa para precionar enter y continuar

    cout << "\n<---------------------------------------------------------->" << endl;

    cout << "\nIngrese la opcion deseada" << endl;
    cout << "\n1.Enrolar alumno." << endl;
    cout << "2.Registrar materia." << endl;
    cout << "\n-> "; 

    cin >> resp_menu;
    cin.ignore();

    if (resp_menu == 1)
    {
        menu_operation ( nombre, mail, nombreMateria, codigo, dni, cuatrimestre, resp_menu, materia);

    } else if ( resp_menu == 2 )
        
    {
        menu_operation ( nombre, mail, nombreMateria, codigo, dni, cuatrimestre, resp_menu, materia);
    }    

    return 0;
}