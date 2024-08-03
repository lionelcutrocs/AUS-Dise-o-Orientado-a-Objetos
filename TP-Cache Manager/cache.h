#ifndef CACHE_H
#define CACHE_H

#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <string>
#include <list>
#include <stdexcept>
#include <limits>

using namespace std;

template <class T>
class CacheManager {

private:
    int capacidad;                                                        // la capacidad de la cache

    // estructura que almacena los datos en la cache, T = obj almacenado y Iterator = iterador a la lista LRU
    map<string, pair<T, typename list<string>::iterator>> cache_data;
    list<string> lru_lista;                                                // lista para mantener el orden del uso reciente LRU de claves
    string nom_archivo = "cache_file.txt";                                // destino del resultado de la cache

    // metodos privados

    bool escribir_arch(const string& clave, const T& obj);                // funcion para escribir el obj en archivo
    bool leer_arch(const string& clave, T &obj);                          // funcion para leer el obj en archivo
    void actualizar_lru(const string &clave);                             // funcion para actualizar la lista LRU con la clave dada

public:
    CacheManager(int cap);                                                // constructor
    ~CacheManager();                                                      // destructor

    void insert(const string& clave, const T& obj);                       // incerta un objeto en la cache
    T get(const string& clave);                                           // obtengo un objeto en la cache
    void ver_cache();                                                     // muestra el contenido de la cache 
};

template <class T>
CacheManager<T>::CacheManager(int cap) : capacidad(cap) {}                // inicializa la capacidad de la cache

template <class T>
CacheManager<T>::~CacheManager() {}

template <class T>
bool CacheManager<T>::escribir_arch(const string& clave, const T& obj) {
    ofstream ofs(nom_archivo, ios::app);                                  // apertura del archivo
    if (!ofs.is_open()) return false;                                     // false por operacion sin exito

    ofs << clave << " " << obj.id << " " << obj.valor << " " << obj.data << endl;
    ofs.close();
    return true;                                                          // true por operacion exitosa
}

template <class T>



bool CacheManager<T>::leer_arch(const string& clave, T &obj) 
{
    // definiciones locales
    string clave_arch;                                       // es la clave que se lee del archivo
    string data;
    int id, valor;

    ifstream ifs(nom_archivo);                             // apertura del archivo indicado por nom_archivo
    if (!ifs.is_open()) return false;                      // devuelve un false si no logra abrirse

    while (ifs >> clave_arch) {                              // se lee la primera palabra "clave" y se almacena en clave_arch
        if (clave_arch == clave) {                           // se compara la clave leida en archivo con la clave que se busca
 //                                                             si hay coincidencia se leen los datos de esa clave

            ifs >> id >> valor;
            getline(ifs, data);                            // lee el resto de la linea y se almacena en data

            obj = T(id, valor, data);                      // se crea un nuevo objeto usando los datos leidos y se asignan a "obj"
            ifs.close();
            return true;                                   // devuelve true = se encontro y leyo la clave
        }   
        // se asegura de ignorar hasta el final sin importar la longitud
        ifs.ignore(numeric_limits<streamsize>::max(), '\n'); // si clave_arch no coincide con clave -> ignora el resto de linea actual y pasa a la siguiente
    }
    ifs.close();
    return false;
}

template <class T>
void CacheManager<T>::actualizar_lru(const string &clave) {
    if (cache_data.find(clave) != cache_data.end()) {                   // se verifica si existe la clave en "cache_data"
        lru_lista.erase(cache_data[clave].second);                       // si no, se borra el iterador asociado a "lru_lista"
    } else if (lru_lista.size() >= static_cast<size_t>(capacidad)) {
        string lru_key = lru_lista.back();
        lru_lista.pop_back();
        cache_data.erase(lru_key);
    }

    lru_lista.push_front(clave);
    cache_data[clave].second = lru_lista.begin();
}



template <class T>
void CacheManager<T>::insert(const string& clave, const T& obj) {
    actualizar_lru(clave);
    cache_data[clave] = make_pair(obj, lru_lista.begin());
    escribir_arch(clave, obj);
}

template <class T>
T CacheManager<T>::get(const string& clave) {
    if (cache_data.find(clave) != cache_data.end()) {
        actualizar_lru(clave);
        return cache_data[clave].first;
    }

    T obj;
    if (!leer_arch(clave, obj)) {
        throw runtime_error("clave not found in cache or file.");
    }

    insert(clave, obj);
    return obj;
}

template <class T>
void CacheManager<T>::ver_cache() {
    for (const auto &item : cache_data) {
        cout << item.first << " - " << item.second.first.id << ", " << item.second.first.valor << ", " << item.second.first.data << endl;
    }
}

#endif
