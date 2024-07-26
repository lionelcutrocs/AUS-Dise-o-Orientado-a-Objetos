#ifndef SUBASTA_H
#define SUBASTA_H

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
    string linea;

 public:
 
 Lote();
 void leerLotesDeArchivo (const string& nombreArchivo );
 void printLotes () const;
 void realizarOferta ( int numeroLote, int montoOferta, const string& nomreOferente );
 void guardarResultadosEnArchivo ( const string& nombreArchivo ) const;
 int getLotesSize () const;
};

class ManipularArchivos
{
 public:
 void escribirEnArchivo (const string& nombreArchivo, const string& contenido);
};

void menu_ingreso ( string& nombre_p );
void menu_lotes ( Lote& milote, int& resp_lote );
void solicitarOferta (Lote& milote, int& resp_lote, int& montoOferta, const string& nombreOferente );

#endif