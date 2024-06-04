#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Lote 
{
 private:

    struct loteInfo {
        string nombreL;
        string numeroL;
    };

    vector <loteInfo> lotes;

 public:
    void printLotes () const {

        for ( const auto& lote : lotes ) {
            cout << "nombre: " << lote.nombreL << "- numero: " << lote.numeroL << endl;
        }
    }

    void addLote ( const string& nombreL, string& numeroL ) 
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

void menu_lotes ( Lote& lote ) 

{

    cout << "Este es la lista de lotes disponibles para ofertar" << endl;
    lote.printLotes ();

};

int main () {
 
 Lote lote;
 
 string nombre_p; 
 string nombreL;
 string numeroL;




    return 0;
};

