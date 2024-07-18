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
        string nombreOferente;
        int ofertaActual = 0;
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
            if (!lote.nombreOferente.empty()) {
                cout << "Oferta actual: " << lote.nombreOferente << endl;
            }
        }   cout << endl; 
    }

    void realizarOferta ( int numeroLote, int montoOferta, const string& nombreOferente ) {
        if (numeroLote <= 0 || numeroLote > lotes.size()) {
            cerr << "Numero de lote invalido." << endl;
            return;
        }

        lotes[numeroLote - 1].ofertaActual = montoOFerta;
        lotes[numeroLote - 1].nombreOferente = nombreOferente;
    }


    void guardarResultadosEnArchivo (const string& nombreArchivo) {
        ofstream archivo(nombreArchivo);
        if (archivo.is_open()) {
            for (const auto& lote : lotes ) {
                archivo << "Lote: " << lote.nombreL << endl;
                archivo << "Oferta ganadora: " << lote.ofertaActual << endl; 
                if (!lote.nombreOferente.empty ()) {
                    archivo << "Oferta ganador: " << lote.nombreOferente << endl;
                }
            }   archivo << endl;
            archivo.close();
            cout << "Resultados guardados en -> " << nombreArchivo << endl;
        } else {
            cerr << "Error al guardar el archivo de resultados -> " << nombreArchivo << endl; 
        }  
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

void realizarOferta (Lote& milote, string nombre_p ) 
{
    int numeroLore;
    int montoOferta;
}

int main () {
 
 Lote milote;                                   // instancia de la clase Lote para gestionar los lotes

 milote.leerLotesDeArchivo("Lotes.txt");        // leer lotes desde el archivo al iniciar el programa
 
 int resp_lote;                                 // variable para almacenar la seleccion del lote
 int montoOferta;                               // variable para almacenar el monto de la oferta
 string nombre_p;                               // variable para almacenar el nombre del participante
 string nombreL;                                
 char continuar;


    do {

     menu_ingreso ( nombre_p );
     menu_lotes ( milote, resp_lote );
    
        if ( resp_lote > 0 && resp_lote <= milote.getLotesSize()) {
            cout << "Ingrese el monto de su oferta para el lote " << resp_lote << ":" << endl;
            cout << "-> ";
            cin >> montoOferta;
        }

        if ( montoOferta > 0 ) {
            realizarOferta ( milote, resp_lote, montoOferta, nombre_p );
            cout << "Oferta registrada correctamente." << endl;
        } else {
            cout << "El monto de la oferta debe ser un numero positivo." << endl;
        } else {
            cout << "Opcion invalida. Intente de nuevo." << endl;
        };
        
     cout << "\nDesea realizar otra oferta? (s/n): "; << endl;
     cin >> continuar;
    
    } while ( continuar == 's' || continuar == 'S' );

 // guardar los resultados al finalizar la subasta
 milote.guardarResultadosEnArchivo( "resultados_subasta.txt" );
 cout << "\nGracias por participar en la subasta!" << endl;


    return 0;
};

