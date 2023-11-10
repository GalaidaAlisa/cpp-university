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

    float scholarship() {
        if ((mark > 3) && (mark <= 4)) {
            return 2000;
        } else if (mark > 4) {
            return 2500;
        } else {
            return 0;
        }
    } 

    void output_scholarship() {
        int amount = this->scholarship();
        if (amount != 0) {
            cout << this->get_name() << " receives " << amount << " hryvnias." << endl;
        } else {
            cout << this->get_name() << " doesn't receive a scholarship." << endl;
        }
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
    Student* first = new Student("Tom", 4, 2.2);
    first->output();

    Student* second = new Student("Sam", 2, 4.5);
    second->output();

    Student* third = new Student("John", 1, 3.3);
    third->output();

    Student* fourth = new Student("Smith", 3, 2.5);
    fourth->output();

    Student* students[4] = {first, second, third, fourth};
    int lenght = students[0]->number_of_students;
    cout << endl << "The best student is: " << endl;
    the_best_student(students, lenght)->output();
    cout << endl;

    students[0]->set_mark(4.9);
    students[0]->output();
    cout << "The best student is: " << endl;
    the_best_student(students, lenght)->output();

    cout << "\nScholarship:\n";
    first->output_scholarship();
    second->output_scholarship();
    third->output_scholarship();
    fourth->output_scholarship();

    return 0;
}
