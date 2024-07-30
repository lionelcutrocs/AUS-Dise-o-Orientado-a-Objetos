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
    {   // se verifica que el numero del lote sea valido
        if (numeroLote <= 0 || numeroLote > static_cast<int>(lotes.size())) {       
            cerr << "Numero de lote invalido." << endl;
            return;
        }
        
        loteInfo& lote = lotes[numeroLote - 1];                 // se obtiene referencia al objeto y 
        //                                                         se accede al lote seleccionado
        
        if ( montoOferta > lote.ofertaActual)                   // se comparan los montos de las ofertas
        {                                                       // si es mayor, se actualiza la informacion
            lote.ofertaActual = montoOferta;                    // se actualiza la nueva oferta como la actual
            lote.nombreOferente = nombreOferente;               // se asigna el nombre del nuevo oferente
        }
    }

    void Lote::guardarResultadosEnArchivo (const string& nombreArchivo) const
    {
     ofstream archivo(nombreArchivo);                           // se crea obj tipo ofstream y se vincula al archivo especificado en "nombreArchivo"
     if (archivo.is_open()) {                                   // se verifica que la apertura sea correcta para escribirlo
        for (const auto& lote : lotes )                         // se recorre cada elem del vector
        {
            archivo << "Lote: " << lote.nombreL << endl;                            // escritura
            archivo << "Oferta ganadora: " << lote.ofertaActual << endl;            // escritura
            if (!lote.nombreOferente.empty ()) {                                    // se verifica que este vacio la variable
                archivo << "Nombre del Oferente: " << lote.nombreOferente << endl;  // si no lo esta, se escribe
            }
            archivo << endl;
            
        }
            archivo.close();                                                        // cierre del archivo
            cout << "Resultados guardados en -> " << nombreArchivo << endl;
        } else {
            cerr << "Error al guardar el archivo de resultados -> " << nombreArchivo << endl; 
        }     
    }   

    int Lote::getLotesSize() const {                    // se obtiene el tamaño del vector para ver los lotes
        return static_cast<int>(lotes.size());          // se convierte el resultado para asegurar 
    }                                                   // que sea un entero


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


