#include <iostream>
#include <vector>
#include <string>
#include <fstream>

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

    void printLotes () const 
    {
        for ( const auto& lote : lotes ) {
            cout << "" << lote.nombreL << endl;
        }
    }

    void addLote ( const string& nombreL ) 
    {
        lotes.push_back ({nombreL});
    };
};

class ManipularArchivos
{
 public:
 void escribirEnArchivo(const std::string& nombreArchivo, const std::string& contenido) {
  // Verificar si el archivo existe
  if (!std::filesystem::exists(nombreArchivo)) {
    // Crear el archivo si no existe
    std::ofstream archivoNuevo(nombreArchivo);
    if (!archivoNuevo.is_open()) {
      throw std::runtime_error("Error al crear el archivo");
    }
  }

  // Abrir el archivo
  std::ofstream archivo(nombreArchivo, std::ios::app);
  if (archivo.is_open()) {
    // Escribir el contenido en el archivo
    archivo << contenido << std::endl;
    archivo.close();
  } else {
    throw std::runtime_error("Error al abrir el archivo");
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

