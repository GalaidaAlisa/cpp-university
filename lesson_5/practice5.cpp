#include <iostream>
#include <cstring>

using namespace std;

class Student {
public:
    static int number_of_students;

    Student(const char* input_name, int input_year, float input_mark) : year(input_year), mark(input_mark) {
        name = new char[strlen(input_name)];
        strcpy(name, input_name);
        number_of_students++;
    }

    void output() {
        cout << "Student " << name << " is studying on the " << year << " course and has mark " << mark << '.' << endl;
    }

    char* get_name() const {
        return name;
    }

    int get_year() const {
        return year;
    }

    float get_mark() const {
        return mark;
    }

    void set_name(const char* name) {
        this->name = new char[strlen(name)];
        strcpy(this->name, name);
    }

    void set_year(int year) {
        if (year > 0 && year < 5) {
            this->year = year;
        } else {
            cout << "Wrong data." << endl;
        }
    }

    void set_mark(float mark) {
        if (mark >= 0 && mark <= 5) {
            this->mark = mark;
        } else {
            cout << "Wrong data." << endl;
        }
    }

    bool test() {
        if (mark > 2) {
            return true;
        }
        return false;
    }

    ~Student() {
        delete name;
        number_of_students--;
    }
private:
    char* name;
    int year;
    float mark;
};

Student* the_best_student(Student* students[], int length) {
    Student* best_student;
    float grade = -1;
    for (int i = 0; i < length; i++) {
        if (students[i]->get_mark() > grade) {
            grade = students[i]->get_mark();
            best_student = students[i];
        }
    }
    return best_student;
}


int Student::number_of_students = 0;

int main() {
    Student* first = new Student("Tom", 4, 3.2);
    Student* second = new Student("Sam", 2, 4.5);
    Student* students[2] = {first, second};
    int lenght = students[0]->number_of_students;
    cout << "The best student is: " << endl;
    the_best_student(students, lenght)->output();
    cout << endl;

    students[0]->set_mark(4.9);
    students[0]->output();
    cout << "The best student is: " << endl;
    the_best_student(students, lenght)->output();
    return 0;
}
