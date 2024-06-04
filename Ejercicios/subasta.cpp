#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Lote 
{
 private:

    struct loteInfo {
        string nombreL;
        
    };

    vector <loteInfo> lotes;

 public:
    void printLotes () const 
    {
        for ( const auto& lote : lotes ) {
            cout << "-> " << lote.nombreL << endl;
        }
    }

    void addLote ( const string& nombreL ) 
    {
        lotes.push_back ({nombreL});
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

    cout << "Esta es la lista de lotes disponibles para ofertar" << endl;
    milote.printLotes ();

};

int main () {
 
 Lote milote;
 
 string nombre_p; 
 string nombreL;

    milote.addLote ( "Computadora" );
    milote.addLote ( "Celular" );
    milote.addLote ( "Jarron Chino" );

    milote.printLotes();

    return 0;
};

