#include <iostream>
#include <vector>
using namespace std;

class Book {
    public:

    void addBook () {

    }
    
};



int main () {

 int resp_menu;
 Book biblio;

    cout << "Bienvenido al gestor de Libros personal\n" << endl;

    cout << "1. Selecciona lo que necesites hacer.\n" << endl;
    cout << "2. Agregar un nuevo Libro.\n" << endl;
    cout << "3. Eliminar un libro.\n" << endl;
    cout << "4. Mostrar la lista de libros.\n" << endl;

    cout << "-> \n";
    cin >> resp_menu;


    switch ( resp_menu )
    
    {
     case 1:
        cout << "Agregando nuevo Libro ..." << biblio.addBook;
        break;
    
    default:
        break;
    }

    return 0;
}