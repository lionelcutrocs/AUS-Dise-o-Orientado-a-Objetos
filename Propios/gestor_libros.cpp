#include <iostream>
#include <vector>
using namespace std;

class Book {
 
 public:
    void addBook (const string& title, const string& author) 
    {
        books.push_back ({ title, author });
    }
    

 private:
    struct bookInfo {
        string title;
        string author;
    };

    vector <bookInfo> books;
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
        

        cout << "Agregando nuevo Libro ..." << endl;
        cout << "Ingrese el titulo del libro." << endl;
        cout << "... ";
        
        string title, author;
        cin.ignore();
        getline (cin, title);

        cout << "Ingrese el autor del libro." << endl;
        cout << "... ";
        getline (cin, author);

        biblio.addBook (title, author);
        cout << "Libro agregado correctamente." << endl;
        break;
    
    default:
        break;
    }

    return 0;
}