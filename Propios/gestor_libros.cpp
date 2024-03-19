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

    void printBook () const {

        for (const auto& libro : books ) {
            cout << "Libro: " << libro.title << " - Autor: " << libro.author << endl;
        }
    }

 private:
    struct bookInfo {
        string title;
        string author;
    };

    vector <bookInfo> books;
};

 void menu_operation ( string& resp_correcta, string& resp_backmenu,
                        string& author, string& title, Book& biblio, int& resp_menu, bool& repeat_menu ) 
{
    string flag;

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

         cin.ignore ();
         getline ( cin, author );

         biblio.addBook ( title, author );
        
         cout << "\nLibro agregado correctamente." << endl;

         cout << "\nQuiere realizar otra operacion mas? ( Si o No )" << endl;
         cout << "-> ";
         cin >> resp_backmenu;
         
        break;
        
        case 2:
         cout << "\nEliminando un libro guardado ..." << endl;
         cout << "Ingrese el titulo del libro." << endl;
         cout <<"-> ";

         cin.ignore ();
         getline ( cin, title );

         cout << "\nIngrese el autor del libro." << endl;
         cout << "-> ";
            
         getline ( cin, author );
            
         biblio.deleteBook ( title, author );
         cout << "\nLibro eliminado correctamente" << endl;

        break;

        case 3:
         cout << "\nEsta es la lista de libros actual." << endl;
         
         biblio.printBook();

         cout << "\nQuiere realizar otra operacion mas? ( Si o No )" << endl;
         cout << "-> ";
         cin >> resp_backmenu;

        break;

        case 4:
         cout << "Saliendo del programa ..." << endl;
        
        
        break;
    }
    // default:
    //    break;
};
 
 void menu_user ( int& resp_menu ) {

    cout << "\n=== Bienvenido al gestor de Libros personal ===\n" << endl;
    
    cout << "-----------------------------------------------" << endl;

    cout << "\n-> Selecciona lo que necesites hacer." << endl;
    cout << "\n1. Agregar un nuevo Libro." << endl;
    cout << "2. Eliminar un libro." << endl;
    cout << "3. Mostrar la lista de libros." << endl;
    cout << "4. Salir del programa." << endl;

    cout << "\n-> ";
    cin >> resp_menu;

 };

int main () {

 int resp_menu;                                             // variable para elegir opcion del menu
 bool repeat_menu = true;

 Book biblio;
 string title;
 string author;
 string resp_backmenu;
 string resp_correcta = "si, Si, SI";

    // menu_user ( resp_menu );

    // menu_operation ( resp_correcta, resp_backmenu, author, title, biblio, resp_menu, repeat_menu );
    
    while ( repeat_menu == true )
    {   
        menu_user ( resp_menu );

        menu_operation ( resp_correcta, resp_backmenu, author, title, biblio, resp_menu, repeat_menu );

        if ( resp_backmenu.compare (resp_correcta) )
        {
            menu_user ( resp_menu );
            
        } else {
            repeat_menu == false;
        }
    }
    




    return 0;
}