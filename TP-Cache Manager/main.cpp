#include "cache.h"

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

const string Student::class_name = "StudentClass";

int main() {
    CacheManager<Student> my_cache(3);

    my_cache.insert("0", Student(0, 22, "student1"));
    my_cache.insert("1", Student(1, 23, "student2"));
    my_cache.insert("2", Student(2, 25, "student3"));
    my_cache.insert("3", Student(3, 29, "student4"));

    my_cache.show_cache();

    cout << "---------------------- UPDATE ----------------------" << endl;
    my_cache.insert("2", Student(22, 222, "EZE"));
    my_cache.show_cache();

    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;

    try {
        Student return_obj = my_cache.get("0"); // not in cache but in filesystem
        return_obj.print();
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;

    my_cache.insert("2", Student(2, 25, "EZE"));
    my_cache.show_cache();

    my_cache.insert("9", Student(1, 5, "Nine"));
    my_cache.insert("9", Student(1, 5, "Nine"));
    my_cache.insert("9", Student(1, 5, "Nine"));
    my_cache.show_cache();

    return 0;
}
