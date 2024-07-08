#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>

using namespace std;


class Lote 
{
 private:

    struct loteInfo {
        string nombreL;
    };

    vector <loteInfo> lotes;

 public:


    Lote () {
        lotes.push_back ({"1- Computadora"});
        lotes.push_back ({"2- Celular"});
        lotes.push_back ({"3- Jaron Chino"});
    };

    void leerLotesDeArchivo ( const string& nombreArchivo)
    {
        ifstream archivo (nombreArchivo);
        if (archivo.is_open()) {
            string linea;
            while (getline (archivo, linea)) {
                if (!linea.empty()) {
                    lotes.push_back({linea, 0, ""});
                }
            }
            archivo.close();
        } else {
            cerr << "Error al abrir el archivo de lotes: " << nombreArchivo << endl;
        }
    }

    void printLotes () const {
        for (const auto& lote : lotes) {
            cout << "Lote: " << lote.nombreL << endl;
            cout << "Oferta actual: " << lote.ofertaActual << endl;
            if (!lote.nombreOferta.empty()) {
                cout << "Oferta actual: " << lote.nombreOferta << endl;
            }
        }   cout << endl; 
    }

};




class ManipularArchivos
{
 public:
 void escribirEnArchivo(const string& nombreArchivo, const string& contenido) {
  // Verificar si el archivo existe
  if (!filesystem::exists(nombreArchivo)) {
    // Crear el archivo si no existe
    ofstream archivoNuevo(nombreArchivo);
    if (!archivoNuevo.is_open()) {
      throw runtime_error("Error al crear el archivo");
    }
  }

  // Abrir el archivo
  ofstream archivo(nombreArchivo, ios::app);
  if (archivo.is_open()) {
    // Escribir el contenido en el archivo
    archivo << contenido << endl;
    archivo.close();
  } else {
    throw runtime_error("Error al abrir el archivo");
  }
}

};

void menu_ingreso ( string& nombre_p ) 

{

    cout << "Bienvenido a la Subasta" << endl;
    cout << "Por favor ingrese su nombre" << endl;
    cout << "-> ";
    getline ( cin, nombre_p );


};

void menu_lotes ( Lote& milote, int& resp_lote ) 

{

    cout << "Esta es la lista de lotes disponibles para ofertar" << endl;
    
    milote.printLotes ();

    cout << "\nSeleccione a continuacion el lote que quiere ofertar" << endl;
    cout << "-> ";
    cin >> resp_lote;

    switch ( resp_lote )
    {
    case 1:
        cout << "\nHa seleccionado el lote 1 -> Computadora" << endl;
    
    break;
    
    case 2:
        cout << "\nHa seleccionado el lote 2 -> Celular" << endl;
    
    break;

    case 3:
        cout << "\nHa seleccionado el lote 3 -> Jarron Chino" << endl;

    break;
    }

};

int main () {
 
 Lote milote;
 
 int resp_lote;
 int resp_usr;
 string nombre_p; 
 string nombreL;

    // milote.addLote ( "\n1- Computadora" );
    // milote.addLote ( "2- Celular" );
    // milote.addLote ( "3- Jarron Chino" );

    menu_lotes ( milote, resp_lote);


    return 0;
};

