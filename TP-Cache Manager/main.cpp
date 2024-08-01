#include "cache.h"
#include <cstdlib> // Para std::system

using namespace std;

class Student {
private:
    int id;
    int value;
    string data; // Cambiado a std::string

    // Declara a CacheManager como una clase amiga
    template <class T>
    friend class CacheManager;

public:
    static const string class_name;

    Student() : id(0), value(0), data("") {}

    Student(int _key, int _value, const string& _data) : id(_key), value(_value), data(_data) {}

    void print() const {
        cout << "Student Object: " << id << "," << value << "," << data << endl;
    }

    ~Student() {}
};

void clear_screen() {
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}

void pause_for_user() {
    cout << "->";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {

    cout << "Comienzo de la Cache Manager" << endl;

    CacheManager<Student> my_cache(3);

    cout << "\n==============================" << endl;
    cout << "Insertando estudiante 0" << endl;
    my_cache.insert("0", Student(0, 22, "student1"));
    my_cache.show_cache();
    cout << "\n==============================" << endl;
    pause_for_user();

    cout << "==============================" << endl;
    cout << "Insertando estudiante 1" << endl;
    my_cache.insert("1", Student(1, 23, "student2"));
    my_cache.show_cache();
    cout << "\n==============================" << endl;
    pause_for_user();

    cout << "Insertando estudiante 2" << endl;
    my_cache.insert("2", Student(2, 25, "student3"));
    my_cache.show_cache();
    cout << "\n==============================" << endl;
    pause_for_user();

    cout << "Insertando estudiante 3" << endl;
    my_cache.insert("3", Student(3, 29, "student4"));
    my_cache.show_cache();
    cout << "\n==============================" << endl;
    pause_for_user();


    cout << "\n---------------------- UPDATE ----------------------" << endl;
    cout << "\nActualizando estudiante 2" << endl;
    my_cache.insert("2", Student(22, 222, "EZE"));
    my_cache.show_cache();
    cout << "\n--------------------------------------------------" << endl;
    pause_for_user();


    cout << "\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;

    try {
        cout << "\nRecuperando estudiante 0 (desde el archivo si no esta en cache)" << endl;
        Student return_obj = my_cache.get("0");
        return_obj.print();
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
    cout << "\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
    pause_for_user();


    cout << "\nReinsertando estudiante 2" << endl;
    my_cache.insert("2", Student(2, 25, "EZE"));
    my_cache.show_cache();
    cout << "\n--------------------------------------------------" << endl;
    pause_for_user();


    cout << "\nInsertando estudiante 9" << endl;
    my_cache.insert("9", Student(1, 5, "Nine"));
    my_cache.show_cache();
    cout << "--------------------------------------------------" << endl;
    pause_for_user();


    cout << "Insertando estudiante 9 nuevamente" << endl;
    my_cache.insert("9", Student(1, 5, "Nine"));
    my_cache.show_cache();
    cout << "--------------------------------------------------" << endl;
    pause_for_user();


    cout << "Insertando estudiante 9 una vez mas" << endl;
    my_cache.insert("9", Student(1, 5, "Nine"));
    my_cache.show_cache();
    cout << "--------------------------------------------------" << endl;
    pause_for_user();

    return 0;
}