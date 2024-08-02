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
    int capacidad;                                                      // la capacidad de la cache

    // estructura que almacena los datos en la cache, T = obj almacenado y Iterator = iterador a la lista LRU
    map<string, pair<T, typename list<string>::iterator>> cache_data;
    list<string> lru_list;                                              // lista para mantener el orden del uso reciente LRU de claves
    string nom_archivo = "cache_file.txt";                              // destino del resultado de la cache

    // metodos privados

    bool escribir_arch(const string& key, const T& obj);                // funcion para escribir el obj en archivo
    bool leer_arch(const string& key, T &obj);                          // funcion para leer el obj en archivo
    void actualizar_lru(const string &key);                             // funcion para actualizar la lista LRU con la clave dada

public:
    CacheManager(int cap);                                              // constructor
    ~CacheManager();                                                    // destructor

    void insert(const string& key, const T& obj);                       // incerta un objeto en la cache
    T get(const string& key);                                           // obtengo un objeto en la cache
    void ver_cache();                                                   // muestra el contenido de la cache 
};

template <class T>
CacheManager<T>::CacheManager(int cap) : capacidad(cap) {}              // inicializa la capacidad de la cache

template <class T>
CacheManager<T>::~CacheManager() {}

template <class T>
bool CacheManager<T>::escribir_arch(const string& key, const T& obj) {
    ofstream ofs(nom_archivo, ios::app);                                // apertura del archivo
    if (!ofs.is_open()) return false;                                   // false por operacion sin exito

    ofs << key << " " << obj.id << " " << obj.value << " " << obj.data << endl;
    ofs.close();
    return true;                                                        // true por operacion exitosa
}

template <class T>



bool CacheManager<T>::leer_arch(const string& key, T &obj) 
{
    // definiciones locales
    string file_key;                                       // es la clave que se lee del archivo
    string data;
    int id, value;

    ifstream ifs(nom_archivo);                             // apertura del archivo indicado por nom_archivo
    if (!ifs.is_open()) return false;                      // devuelve un false si no logra abrirse

    while (ifs >> file_key) {                              // se lee la primera palabra "clave" y se almacena en file_key
        if (file_key == key) {                             // se compara la clave leida en archivo con la clave que se busca
 //                                                             si hay coincidencia se leen los datos de esa clave

            ifs >> id >> value;
            getline(ifs, data);                            // lee el resto de la linea y se almacena en data

            obj = T(id, value, data);                      // se crea un nuevo objeto usando los datos leidos y se asignan a "obj"
            ifs.close();
            return true;                                   // devuelve true = se encontro y leyo la clave
        }   
        // se asegura de ignorar hasta el final sin importar la longitud
        ifs.ignore(numeric_limits<streamsize>::max(), '\n'); // si file_key no coincide con key -> ignora el resto de linea actual y pasa a la siguiente
    }
    ifs.close();
    return false;
}

template <class T>
void CacheManager<T>::actualizar_lru(const string &key) {
    if (cache_data.find(key) != cache_data.end()) {
        lru_list.erase(cache_data[key].second);
    } else if (lru_list.size() >= static_cast<size_t>(capacidad)) {
        string lru_key = lru_list.back();
        lru_list.pop_back();
        cache_data.erase(lru_key);
    }

    lru_list.push_front(key);
    cache_data[key].second = lru_list.begin();
}



template <class T>
void CacheManager<T>::insert(const string& key, const T& obj) {
    actualizar_lru(key);
    cache_data[key] = make_pair(obj, lru_list.begin());
    escribir_arch(key, obj);
}

template <class T>
T CacheManager<T>::get(const string& key) {
    if (cache_data.find(key) != cache_data.end()) {
        actualizar_lru(key);
        return cache_data[key].first;
    }

    T obj;
    if (!leer_arch(key, obj)) {
        throw runtime_error("Key not found in cache or file.");
    }

    insert(key, obj);
    return obj;
}

template <class T>
void CacheManager<T>::ver_cache() {
    for (const auto &item : cache_data) {
        cout << item.first << " - " << item.second.first.id << ", " << item.second.first.value << ", " << item.second.first.data << endl;
    }
}

#endif
