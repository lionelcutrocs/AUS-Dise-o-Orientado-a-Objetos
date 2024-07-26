#include "subasta.h"

using namespace std;

    Lote::Lote() {
        leerLotesDeArchivo ( "lotes.txt" );
    };

    void Lote::leerLotesDeArchivo ( const string& nombreArchivo )
    {
        ifstream archivo(nombreArchivo);
        if (archivo.is_open()) {
            for (int i = 0; getline(archivo, linea); ++i) {
            if (!linea.empty()) {
                loteInfo nuevoLote;                                  // se crea un objeto loteInfo
                nuevoLote.nombreL = linea;                           // se asigna el nombre del lote desde la linea que se lee
                nuevoLote.ofertaActual = 0;                          // se accede a ofertaActual y se inicializa correctamente
                nuevoLote.nombreOferente = "";                       // se accede a nombreOferente y se inicializa correctamente
                lotes.push_back(nuevoLote);                          // se agrega un nuevo lote al vector
                }                                                    // este metodo logra asignar valores en cada miembro de forma directa
            }
            archivo.close();
        } else {
            cerr << "Error al abrir el archivo de lotes: " << nombreArchivo << endl;
        }
    }

    void Lote::printLotes() const 
    {
        for (const auto& lote : lotes) {
            cout << "\nLote: " << lote.nombreL << endl;
            cout << "Oferta actual: " << lote.ofertaActual << endl;
            if (!lote.nombreOferente.empty()) {
                cout << "Nombre del Oferente: " << lote.nombreOferente << endl;
            }
            cout << endl;
        }    
    }

    void Lote::realizarOferta ( int numeroLote, int montoOferta, const string& nombreOferente )
    {
        if (numeroLote <= 0 || numeroLote > static_cast<int>(lotes.size())) {
            cerr << "Numero de lote invalido." << endl;
            return;
        }
        
        loteInfo& lote = lotes[numeroLote - 1];
        
        // solo actualiza la oferta si el monto es mayor a 0
        if ( montoOferta > lote.ofertaActual)
        {
            lote.ofertaActual = montoOferta;
            lote.nombreOferente = nombreOferente;
        }
    }

    void Lote::guardarResultadosEnArchivo (const string& nombreArchivo) const
    {
     ofstream archivo(nombreArchivo);
     if (archivo.is_open()) {
        for (const auto& lote : lotes ) {
            archivo << "Lote: " << lote.nombreL << endl;
            archivo << "Oferta ganadora: " << lote.ofertaActual << endl; 
            if (!lote.nombreOferente.empty ()) {
                archivo << "Nombre del Oferente: " << lote.nombreOferente << endl;
            }
            archivo << endl;
            
        }
        archivo.close();
        cout << "Resultados guardados en -> " << nombreArchivo << endl;
    } else {
        cerr << "Error al guardar el archivo de resultados -> " << nombreArchivo << endl; 
    }     
}

    int Lote::getLotesSize() const {
        return static_cast<int>(lotes.size());
    }

    void ManipularArchivos::escribirEnArchivo(const string& nombreArchivo, const string& contenido) 
    {
        // Verificar si el archivo existe
        ofstream archivo(nombreArchivo, ios::app);
        if (!archivo.is_open()) {
            // Crear el archivo si no existe
            ofstream archivoNuevo(nombreArchivo);
            if (!archivoNuevo.is_open()) {
                throw runtime_error("Error al crear el archivo");
            } else {
                archivoNuevo << contenido << endl;
                archivoNuevo.close();
            } 
        } else {
            archivo << contenido << endl;
            archivo.close();
        }       
    }

// funcion del menu y gestion de ofertas
void menu_ingreso ( string& nombre_p ) 
{
    cout << "<=============================>" << endl;
    cout << "\nBienvenido a la Subasta" << endl;
    cout << "\nPor favor ingrese su nombre" << endl;
    cout << "-> ";
    getline ( cin, nombre_p );
};

void menu_lotes ( Lote& milote, int& resp_lote )
{
    cout << "\n**************************************************" << endl;
    cout << "\nEsta es la lista de lotes disponibles para ofertar" << endl;
    
    milote.printLotes ();

    cout << "**************************************************" << endl;
    cout << "\nSeleccione a continuacion el lote que quiere ofertar" << endl;
    cout << "-> ";

    while (!(cin >> resp_lote ) || resp_lote <= 0 || resp_lote > milote.getLotesSize())
    {
        cin.clear();
        cin.ignore( numeric_limits<streamsize>::max(), '\n');
        cout << "Por favor ingrese un numero de lote valido." << endl;
        cout << "-> ";
    }
    cin.ignore (numeric_limits<streamsize>::max(), '\n');
};

void solicitarOferta (Lote& milote, int& resp_lote, int& montoOferta, const string& nombreOferente ) 
{
    cout << "\nIngrese el monto de la oferta para el lote " << resp_lote << ":" << endl;
    cout << "-> ";
    while (!(cin >> montoOferta ) || montoOferta <= 0 )
    {
        cin.clear();
        cin.ignore (numeric_limits<streamsize>::max(), '\n');
        cout << "El monto de la oferta debe ser un numero positivo" << endl;
        cout << "-> ";
    }
    
    cin.ignore (numeric_limits<streamsize>::max(), '\n');
    milote.realizarOferta (resp_lote, montoOferta, nombreOferente );
    cout << "\n/// La oferta fue registrada correctamente ///" << endl;
}

int main () {
 
 Lote milote;                                       // instancia de la clase Lote para gestionar los lotes
 
 int resp_lote;                                     // variable para almacenar la seleccion del lote
 int montoOferta;                                   // variable para almacenar el monto de la oferta
 string nombreOferente;                             // variable para almacenar el nombre del participante
 string nombreL;                                
 char continuar;

    // menu principal de la subasta
    do {

     menu_ingreso ( nombreOferente );                     // se solicita el nombre del participante
     menu_lotes ( milote, resp_lote );                      // muestra la lista de lotes y solicita la seleccion deseada
     solicitarOferta ( milote, resp_lote, montoOferta, nombreOferente );   
    
     // se consulta al usuario si desea realizar otra oferta
     cout << "\nDesea realizar otra oferta? (s/n): ";
     cin >> continuar;
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    system("cls");

    } while ( continuar == 's' || continuar == 'S' );

 // guardar los resultados al finalizar la subasta
 milote.guardarResultadosEnArchivo( "resultados_subasta.txt" );
 cout << "\nGracias por participar en la subasta!" << endl;
 cin.get ();


    return 0;
};

