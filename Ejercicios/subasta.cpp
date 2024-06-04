#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Lote 
{
 private:

    struct loteInfo {
        string nombreL;
        int numeroL;
    };

    vector <loteInfo> lotes;

 public:
    void printLotes () const 
    {
        for ( const auto& lote : lotes ) {
            cout << " " << lote.numeroL << " -> " << lote.nombreL << endl;
        }
    }

    void addLote ( const string& nombreL, int numeroL ) 
    {
        lotes.push_back ({nombreL,numeroL});
    };
};

void menu_ingreso ( string& nombre_p ) 

{

    cout << "Bienvenido a la Subasta" << endl;
    cout << "Por favor ingrese su nombre" << endl;
    cout << "-> ";
    getline ( cin, nombre_p );


};

void menu_lotes ( Lote& milote ) 

{

    cout << "Este es la lista de lotes disponibles para ofertar" << endl;
    milote.printLotes ();

};

int main () {
 
 Lote milote;
 
 string nombre_p; 
 string nombreL;

    milote.addLote ( "Computadora", 1 );
    milote.addLote ( "Celular", 2 );
    milote.addLote ( "Jarron Chino", 3);

    cout << "Lista de lotes: " << endl;
    milote.printLotes();

    return 0;
};

