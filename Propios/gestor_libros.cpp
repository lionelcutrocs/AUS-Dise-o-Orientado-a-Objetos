#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Book {
 
 public:
    void addBook ( const string& title, const string& author ) 
    {
        books.push_back ({ title, author });
    }
    
    void deleteBook ( const string& title, const string& author )
    {
        books.erase ( remove_if ( books.begin (), books.end (), [&] (const bookInfo& books ) 
        {
            return books.title == title && books.author == author;
        }), 
        
        books.end () );
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
 string title;
 string author;

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
        cout << "\nAgregando nuevo Libro ..." << endl;
        cout << "Ingrese el titulo del libro." << endl;
        cout << "... ";

        cin.ignore();
        getline ( cin, title );

        cout << "Ingrese el autor del libro." << endl;
        cout << "-> ";
        getline ( cin, author );

        biblio.addBook ( title, author );
        cout << "Libro agregado correctamente." << endl;
    break;
     
     case 2:

        cout << "\nEliminando un libro guardado ..." << endl;
        cout << "Ingrese el titulo del libro." << endl;
        cout <<"... ";

        cin.ignore ();
        getline ( cin, title );

        cout << "ingrese el autor del libro." << endl;
        cout << "-> ";
        
        getline ( cin, author );
        
        biblio.deleteBook ( title, author );
        cout << "Libro eliminado correctamente" << endl;

    break;

// default:
//    break;
}


    return 0;
}