#include "subasta.h"

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
