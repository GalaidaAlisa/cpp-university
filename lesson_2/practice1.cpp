#include <iostream>

using namespace std;

void f(const char* name = "Ivanov", int year = 1, double grade = 4.0) {
    cout << "Name: " << name << ", year: " << year << ", grade: " << grade << endl;
} // +++ ++- +-- ---
void f(int year, double grade = 4.0) {
    const char* name = "Ivanov";
    cout << "Name: " << name << ", year: " << year << ", grade: " << grade << endl;
} // -++ -+-

void f(const char* name, double grade) {
    int year = 1;
    cout << "Name: " << name << ", year: " << year << ", grade: " << grade << endl;
} // +-+
void f(double grade) {
    const char* name = "Ivanov";
    int year = 1;
    cout << "Name: " << name << ", year: " << year << ", grade: " << grade << endl;
} // --+

struct Student {
    const char* name;
    int year;
    double grade;
};

int main() {
    Student array[8] = {
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
            f(array[i].name, array[i].year, array[i].grade);
        } else if (array[i].name && array[i].year) {
            f(array[i].name, array[i].year);
        } else if (array[i].name && array[i].grade) {
            f(array[i].name, array[i].grade);
        } else if (array[i].name) {
            f(array[i].name);
        } else if (array[i].year && array[i].grade) {
            f(array[i].year, array[i].grade);
        } else if (array[i].year) {
            f(array[i].year);
        } else if (array[i].grade) {
            f(array[i].grade);
        } else {
            f();
        }
    }
    return 0;
}
