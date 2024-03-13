#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

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

 void menu_operation () {




 };


int main () {

 int resp_menu;
 bool repeat_menu = true;

 Book biblio;
 string title;
 string author;
 string resp_backmenu;
 string resp_correcta = "si, Si, SI";

    cout << "\n=== Bienvenido al gestor de Libros personal ===\n" << endl;

    cout << "Presione ENTER para continuar" << endl;

    cin.get();

    cout << "-> Selecciona lo que necesites hacer." << endl;
    cout << "\n1. Agregar un nuevo Libro." << endl;
    cout << "2. Eliminar un libro." << endl;
    cout << "3. Mostrar la lista de libros." << endl;
    cout << "4. Salir del programa." << endl;

    cout << "\n-> ";
    cin >> resp_menu;

    while ( repeat_menu )
    {

        switch ( resp_menu )
        
        {
        case 1:
            cout << "\nAgregando nuevo Libro ..." << endl;
            cout << "Ingrese el titulo del libro." << endl;
            cout << "... ";

            cin.ignore();
            getline ( cin, title );

            cout << "\nIngrese el autor del libro." << endl;
            cout << "... ";
            getline ( cin, author );

            biblio.addBook ( title, author );
            cout << "Libro agregado correctamente." << endl;

            cout << "Quiere realizar otra operacion mas? ( Si o No )" << endl;
            cout << "-> ";
            cin >> resp_backmenu;

            if ( resp_backmenu.compare (resp_correcta) )
            {
                repeat_menu = false;
            }
        break;
        
        case 2:
            cout << "\nEliminando un libro guardado ..." << endl;
            cout << "Ingrese el titulo del libro." << endl;
            cout <<"-> ";

            cin.ignore ();
            getline ( cin, title );

            cout << "Ingrese el autor del libro." << endl;
            cout << "-> ";
            
            getline ( cin, author );
            
            biblio.deleteBook ( title, author );
            cout << "Libro eliminado correctamente" << endl;

        break;

        case 4:
            cout << "Saliendo del programa ..." << endl;
            repeat_menu = false;
        break;

    // default:
    //    break;
    }

    // cout << "Quiere realizar otra operacion mas? ( Si o No )" << endl;
    // cout << "-> ";
    // cin >> resp_backmenu;

    //     if ( resp_backmenu.compare (resp_correcta) )
    //     {
    //         // bandera al swicht
    //     }
    }   


    return 0;
}