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
    int capacity;
    map<string, pair<T, typename list<string>::iterator>> cache_data; // <Clave, <Obj, Iterator a LRU>>
    list<string> lru_list; // Lista para manejar el LRU
    string filename = "cache_file.txt";

    bool write_file(const string& key, const T& obj);
    bool read_file(const string& key, T &obj);
    void update_lru(const string &key);

public:
    CacheManager(int cap);
    ~CacheManager();

    void insert(const string& key, const T& obj);
    T get(const string& key);
    void show_cache();
};

template <class T>
CacheManager<T>::CacheManager(int cap) : capacity(cap) {}

template <class T>
CacheManager<T>::~CacheManager() {}

template <class T>
bool CacheManager<T>::write_file(const string& key, const T& obj) {
    ofstream ofs(filename, ios::app);
    if (!ofs.is_open()) return false;

    ofs << key << " " << obj.id << " " << obj.value << " " << obj.data << endl;
    ofs.close();
    return true;
}

template <class T>
bool CacheManager<T>::read_file(const string& key, T &obj) {
    ifstream ifs(filename);
    if (!ifs.is_open()) return false;

    string file_key;
    while (ifs >> file_key) {
        if (file_key == key) {
            int id, value;
            string data;
            ifs >> id >> value;
            getline(ifs, data); // lee el resto de la línea como datos

            obj = T(id, value, data);
            ifs.close();
            return true;
        }
        ifs.ignore(numeric_limits<streamsize>::max(), '\n'); // ignora hasta el final de la línea
    }
    ifs.close();
    return false;
}

template <class T>
void CacheManager<T>::update_lru(const string &key) {
    if (cache_data.find(key) != cache_data.end()) {
        lru_list.erase(cache_data[key].second);
    } else if (lru_list.size() >= static_cast<size_t>(capacity)) {
        string lru_key = lru_list.back();
        lru_list.pop_back();
        cache_data.erase(lru_key);
    }

    lru_list.push_front(key);
    cache_data[key].second = lru_list.begin();
}



template <class T>
void CacheManager<T>::insert(const string& key, const T& obj) {
    update_lru(key);
    cache_data[key] = make_pair(obj, lru_list.begin());
    write_file(key, obj);
}

template <class T>
T CacheManager<T>::get(const string& key) {
    if (cache_data.find(key) != cache_data.end()) {
        update_lru(key);
        return cache_data[key].first;
    }

    T obj;
    if (!read_file(key, obj)) {
        throw runtime_error("Key not found in cache or file.");
    }

    insert(key, obj);
    return obj;
}

template <class T>
void CacheManager<T>::show_cache() {
    for (const auto &item : cache_data) {
        cout << item.first << " - " << item.second.first.id << ", " << item.second.first.value << ", " << item.second.first.data << endl;
    }
}

#endif
