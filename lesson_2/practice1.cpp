#include <iostream>

using namespace std;

struct Student {
    const char* name;
    int year;
    double grade;
};

Student f(const char* name = "Ivanov", int year = 1, double grade = 4.0); // +++ ++- +-- ---
Student f(int year, double grade = 4.0); // -++ -+-
Student f(const char* name, double grade); // +-+
Student f(double grade); // --+


Student f(const char* name = "Ivanov", int year = 1, double grade = 4.0) {
    Student student;
    student.name = name;
    student.year = year;
    student.grade = grade;
    return student;
} // +++ ++- +-- ---
Student f(int year, double grade = 4.0) {
    Student student;
    const char* name = "Ivanov";
    student.name = name;
    student.year = year;
    student.grade = grade;
    return student;
} // -++ -+-
Student f(const char* name, double grade) {
    Student student;
    int year = 1;
    student.name = name;
    student.year = year;
    student.grade = grade;
    return student;
} // +-+
Student f(double grade) {
    Student student;
    const char* name = "Ivanov";
    int year = 1;
    student.name = name;
    student.year = year;
    student.grade = grade;
    return student;
} // --+


int main() { 
    Student array[8] = {             // створюємо масив структур
        {"Smith", 2, 3.3}, // +++
        {"Johnson", 2, NULL}, // ++-
        {"Petrov", NULL, NULL}, // +--
        {nullptr, NULL, NULL}, // ---
        {nullptr, 3, 2.4}, // -++
        {nullptr, 4, NULL}, // -+-
        {"Kim", NULL, 4.1}, // +-+
        {nullptr, NULL, 4.3} // --+
    };

    for (int i = 0; i < 8; i++) {
        if (array[i].name && array[i].year && array[i].grade) {
            array[i] = f(array[i].name, array[i].year, array[i].grade);
        } else if (array[i].name && array[i].year) {
            array[i] = f(array[i].name, array[i].year);
        } else if (array[i].name && array[i].grade) {
            array[i] = f(array[i].name, array[i].grade);
        } else if (array[i].name) {
            array[i] = f(array[i].name);
        } else if (array[i].year && array[i].grade) {
            array[i] = f(array[i].year, array[i].grade);
        } else if (array[i].year) {
            array[i] = f(array[i].year);
        } else if (array[i].grade) {
            array[i] = f(array[i].grade);
        } else {
            array[i] = f();
        }
    }    
    for (int i = 0; i < 8; i++) {
        cout << "Name: " << array[i].name << ", year: " << array[i].year << ", grade: " << array[i].grade << "." << endl;
    }
    return 0;
}
