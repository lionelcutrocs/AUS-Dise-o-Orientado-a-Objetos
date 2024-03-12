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

    cout << "\n=== Bienvenido al gestor de Libros personal ===\n" << endl;

    cout << "-> Selecciona lo que necesites hacer." << endl;
    cout << "1. Agregar un nuevo Libro." << endl;
    cout << "2. Eliminar un libro." << endl;
    cout << "3. Mostrar la lista de libros." << endl;

    cout << "-> ";
    cin >> resp_menu;


    switch ( resp_menu )
    
    {
     case 1:
        

        cout << "Agregando nuevo Libro ..." << endl;
        cout << "Ingrese el titulo del libro." << endl;
        cout << "... ";
        string title;

        cin.ignore();
        getline (cin, title);

        cout << "Ingrese el autor del libro." << endl;
        cout << "... ";
        string author;
        getline (cin, author);

        biblio.addBook (title, author);
        cout << "Libro agregado correctamente." << endl;
        break;
    
    // default:
    //     break;
    }

    return 0;
}