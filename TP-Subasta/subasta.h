#ifndef SUBASTA_H
#define SUBASTA_H

#include <iostream>                         // biblioteca estandar de IO
#include <vector>                           // biblioteca para manejar vectores
#include <string>                           // biblioteca para manipular strings
#include <fstream>                          // biblioteca para trabajar con archivos
#include <filesystem>                       // biblioteca para trabajar con el sistema de archivos

using namespace std;

class Lote 
{
 private:                                   // estructura creada para almacenar estos datos de subasta
    struct loteInfo {
        string nombreL;                     // nombre del lote asignado
        string nombreOferente;              // nombre del participante
        int ofertaActual = 0;               // variable con la oferta actual
    };

    vector <loteInfo> lotes;
    string linea;

 public:
 
 Lote();
 // funcion para leer el archivo con los lotes
 void leerLotesDeArchivo (const string& nombreArchivo );
 
 // funcion para imprimir la lista de lotes desde el archivo
 void printLotes () const;
 
 // funcion para que el participante haga la oferta deseada
 void realizarOferta ( int numeroLote, int montoOferta, const string& nomreOferente );
 
 // funcion para guardar los resultados de la subasta creando un archivo
 void guardarResultadosEnArchivo ( const string& nombreArchivo ) const;
 int getLotesSize () const;
};

// funcion para el primer menu de usuario
void menu_ingreso ( string& nombre_p );

// funcion para la seleccion de lotes
void menu_lotes ( Lote& milote, int& resp_lote );

// funcion para solicitar el monto al usuario
void solicitarOferta (Lote& milote, int& resp_lote, int& montoOferta, const string& nombreOferente );

#endif