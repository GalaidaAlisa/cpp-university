#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>

using namespace std;

class Animal { // створюємо базовий клас Animal
protected:
    const char* name;
    int year_of_birth;
    bool status;
    
public:
    static int number_of_animals; 

    Animal(const char* n, int y, bool s) : name(n), year_of_birth(y), status(s) {
        number_of_animals++;
    }

    virtual char* type () = 0;

    const char* get_name() {
        return name;
    }

    int get_year() {
        return year_of_birth;
    }

    bool get_status() {
        return status;
    }

    void health() {
        if (this->get_status()) {
            cout << "On treatment" << endl;
        } else {
            cout << "Not on treatment" << endl;
        }
    }

    virtual void output() {
        cout << "    Name: " << this->get_name();
        cout << "\n    Year of birth: " << this->get_year();
        cout << "\n    Status of health: ";
        this->health();
    }
};


// створюємо 3 нащадкових класа (Cat, Dog, Rabbit) та перевизначаємо метод type()

class Cat: public Animal { 
public: 
    Cat(const char* n, int y, bool s) : Animal(n, y, s) {}

    char* type() override {
        return "cat";
    }

    void output() {
        cout << "Cat" << endl;
        Animal::output();
    }

};

class Dog: public Animal {
public: 
    Dog(const char* n, int y, bool s) : Animal(n, y, s) {}

    char* type() override {
        return "dog";
    }

    void output() {
        cout << "Dog" << endl;
        Animal::output();
    }

};

class Rabbit: public Animal {
public: 
    Rabbit(const char* n, int y, bool s) : Animal(n, y, s) {}

    char* type() override {
        return "rabbit";
    }

    void output() {
        cout << "Rabbit" << endl;
        Animal::output();
    }

};

// створюємо клас Shelter - клас саме притулка для тварин з методами додвання тварин та 
// можливістю забирати тварин з притулку

class Shelter {
private:
    static const int size = 50;
    Animal* arr[size];
public:
    Shelter() {
        for (int i = 0; i < size; i++) { 
            arr[i] = nullptr;
        }
        load_animals();
    }

    void add_animal(Animal* animal) {
        if (Animal::number_of_animals <= size) { 
            arr[Animal::number_of_animals - 1] = animal;
            cout << "Animal have successfully added." << endl;
        } else {
            cout << "Shelter doesn't have free place." << endl;
        }
    }

    void output_total() {
        cout << "\nList of animals: ";
        for (int i = 0; i < Animal::number_of_animals; i++) {
            cout << "\n" << i + 1 << ". " << arr[i]->get_name() << "(" << arr[i]->type() << ")";
        }
        cout << endl;
    }

    void output_animal(int number) {
        if ((number > 0) && (number <= Animal::number_of_animals)) {
            cout << "\n" << arr[number - 1]->get_name() << endl;;
            cout << "   " << arr[number - 1]->type() << endl;
            cout << "   " << arr[number - 1]->get_year() << endl;
            cout << "   ";
            arr[number - 1]->health();
            cout << endl;
        } else {
            cout << "Wrong number." << endl;
        }
    }

    void pick_animal(int number) {
        if ((number > 0) && (number <= Animal::number_of_animals)) {
            arr[number - 1] = arr[Animal::number_of_animals - 1];
            arr[Animal::number_of_animals - 1] = nullptr;
            cout << "Success" << endl;
            Animal::number_of_animals--;
        } else {
            cout << "Wrong number." << endl; 
        }
    }

    // створюємо метод збереження тварин в окремий текстовий файл

    void save_animals() {
        char* filename = "animals.txt";

        fstream file(filename);
        if (!file.is_open()) {
            cerr << "Error while opening file animals.txt!" << endl;
            return;
        }

        for (int i = 0; i < Animal::number_of_animals; i++) {
            file << arr[i]->get_name() << '|' << arr[i]->get_status() << '|' << arr[i]->get_year() << '|' << arr[i]->type() << endl;
        }

        file.close();
    }

    // створюємо метод, де можна буде взяти і створити тварину з інформацією з рядка 
    // нашого текстового файлу

    Animal* animal_from_line(char* line) {
        char* name;
        char* isSick;
        char* year_ch;
        int year;
        char* type;
        bool health;
        int places[3];
        int count = 0;
        Animal* animal;

        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] == '|') {
                places[count] = i;
                count++;
            }
        }
        name = new char[places[0] + 1];
        strncpy(name, line, places[0]);
        name[places[0]] = '\0';
        isSick = new char[2];
        strncpy(isSick, line + places[0] + 1, places[1] - places[0] - 1);
        isSick[1] = '\0';
        year_ch = new char[places[2] - places[1]];
        strncpy(year_ch, line + places[1] + 1, places[2] - places[1] - 1);
        year_ch[places[2] - places[1] - 1] = '\0';
        type = new char[strlen(line) - places[2]];
        strncpy(type, line + places[2] + 1, strlen(line) - places[2] - 1);
        type[strlen(line) - places[2] - 1] = '\0';

        
        if (!strcmp(isSick, "0")) {
            health = false;
        } else {
            health = true;
        }
        year = stoi(year_ch);
        if (!strcmp(type, "cat")) {
            animal = new Cat(name, year, health);
        }
        if (!strcmp(type, "dog")) {
            animal = new Dog(name, year, health);
        }
        if (!strcmp(type, "rabbit")) {
            animal = new Rabbit(name, year, health);
        }
        return animal;
    }

    // метод для змоги записати тварину з файлу до загального масиву

    void load_animals() {
        char* filename = "animals.txt";
        ifstream file(filename);
        Animal* animal;

        if (!file.is_open()) {
            cerr << "Error while opening file animals.txt!" << endl;
            return;
        }

        char line[200];
        while (file.getline(line, 200)) {
            animal = animal_from_line(line);
            arr[Animal::number_of_animals - 1] = animal;
        }

        file.close();
    }
};


int Animal::number_of_animals = 0; 
int main() {
    Shelter* shelter = new Shelter();
    bool flag = true;
    int choice;
    int number;
    char* name;
    int status_int;
    bool status;
    int year_of_birth;
    int type;
    while(flag) {
        cout << "\n1. Add animal" << endl;
        cout << "2. Pick up an animal" << endl;
        cout << "3. Output all animals" << endl;
        cout << "4. Output animal" << endl;
        cout << "5. Finish program" << endl;
        cin >> choice;
        switch(choice) {
            case 1:
                name = new char[50];
                cout << "Enter name of animal: ";
                cin >> name;
                cout << "Enter health status of animal (0 - healthy, other - sick): ";
                cin >> status_int;
                if (status_int) {
                    status = true;
                } else {
                    status = false;
                }
                cout << "Enter year of birth of animal: ";
                cin >> year_of_birth;
                cout << "Enter number (1 - cat, 2 - dog, 3 - rabbit): ";
                cin >> type;
                if (type == 1) {
                    Cat* cat = new Cat(name, year_of_birth, status);
                    shelter->add_animal(cat);
                } else if (type == 2) {
                    Dog* dog = new Dog(name, year_of_birth, status);
                    shelter->add_animal(dog);
                } else if (type == 3) {
                    Rabbit* rabbit = new Rabbit(name, year_of_birth, status);
                    shelter->add_animal(rabbit);
                } else {
                    cout << "Wrong input" << endl;
                }
                break;
            case 2: 
                cout << "Enter number of animal: ";
                cin >> number;
                shelter->pick_animal(number);
                break;
            case 3:
                shelter->output_total();
                break;
            case 4:
                cout << "Enter number of animal: ";
                cin >> number;
                shelter->output_animal(number);
                break;
            case 5:
                cout << "Thank you for using this program." << endl;
                flag = false;
                shelter->save_animals();
                break;
            default:
                cout << "\nInvalid choice" << endl;
        }
    }
    return 0;
}
