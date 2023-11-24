#include "header.h"
#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>

using namespace std;

Animal::Animal(const char* n, int y, bool s, bool inh) : name(n), year_of_birth(y), is_healthy(s), in_hospital(inh) {
    number_of_animals++;
}

const char* Animal::get_name() const {
    return name;
}

int Animal::get_year() const {
    return year_of_birth;
}

bool Animal::get_healthy_status() const {
    return is_healthy;
}

void Animal::health() const {
    if (this->get_healthy_status()) {
        cout << "Healthy" << endl;
    } else {
        if (is_in_hospital()) {
            cout << "Sick, on treatment" << endl;
        } else {
            cout << "Sick, not on treatment" << endl;
        }
    }
}

void Animal::chande_healthy_status() {
    if (is_healthy) {
        is_healthy = false;
    } else {
        is_healthy = true;
    }
}

void Animal::change_is_hospitalStatus() {
    if (in_hospital) {
        in_hospital = false;
    } else {
        in_hospital = true;
    }
}

bool Animal::is_in_hospital() const {
    return in_hospital;
}

void Animal::output() const {
    cout << "    Name: " << this->get_name();
    cout << "\n    Year of birth: " << this->get_year();
    cout << "\n    Status of health: ";
    this->health();
}

Cat::Cat(const char* n, int y, bool s, bool inh) : Animal(n, y, s, inh) {}

const char* Cat::type() {
    return "cat";
}

void Cat::output() {
    cout << "Cat" << endl;
    Animal::output();
}

Dog::Dog(const char* n, int y, bool s, bool inh) : Animal(n, y, s, inh) {}

const char* Dog::type() {
    return "dog";
}

void Dog::output() {
    cout << "Dog" << endl;
    Animal::output();
}

Rabbit::Rabbit(const char* n, int y, bool s, bool inh) : Animal(n, y, s, inh) {}

const char* Rabbit::type() {
    return "rabbit";
}

void Rabbit::output() {
    cout << "Rabbit" << endl;
    Animal::output();
}

// створюємо клас Shelter - клас саме притулка для тварин з методами додвання тварин та 
// можливістю забирати тварин з притулку

Shelter::Shelter() {
    for (int i = 0; i < size; i++) { 
        arr[i] = nullptr;
    }
    hospital = new Hospital();
    load_animals();
}

void Shelter::add_animal(Animal* animal) {
    if (numberOfAnimals() < size) {
        arr[numberOfAnimals()] = animal;
        cout << "Animal have successfully added." << endl;
    } else {
        cout << "Shelter doesn't have free place." << endl;
    }
}

void Shelter::output_total() {
    cout << "\nList of animals in shelter: ";;
    if (!numberOfAnimals()) {
        cout << "\nThere no animals";
    }
    for (int i = 0; i < numberOfAnimals(); i++) {
        cout << "\n" << i + 1 << ". " << arr[i]->get_name() << "(" << arr[i]->type() << ")";
    }
    cout << endl;
}

Animal* Shelter::output_animal(int number) {
    if ((number > 0) && (number <= numberOfAnimals())) {
        cout << "\n" << arr[number - 1]->get_name() << endl;;
        cout << "   " << arr[number - 1]->type() << endl;
        cout << "   " << arr[number - 1]->get_year() << endl;
        cout << "   ";
        arr[number - 1]->health();
        cout << endl;
        return arr[number - 1];
    }
    cout << "Wrong number." << endl;
    return nullptr;
}

bool Shelter::pick_animal(int number) {
    if (number <= 0 || number > numberOfAnimals()) {
        return false;
    }
    arr[number - 1] = arr[numberOfAnimals() - 1];
    arr[numberOfAnimals() - 1] = nullptr;
    return true;
}

bool Shelter::take_animal_from_hospital(int number) {
    if (number <= 0 || number > numberOfAnimals()) {
        return false;
    }
    if (!arr[number - 1]->is_in_hospital()) {
        return false;
    }
    hospital->pick_animal(arr[number - 1]);
    arr[number - 1]->chande_healthy_status();
    arr[number - 1]->change_is_hospitalStatus();
}

void Shelter::output_hospital() {
    hospital->output_total();
};

// створюємо метод збереження тварин в окремий текстовий файл

void Shelter::save_animals() {
    hospital->save_animals();
    const char* filename = "animals.txt";

    if (!numberOfAnimals()) {
        ofstream file(filename, ios::trunc);
        return;
    }

    fstream file(filename);
    if (!file.is_open()) {
        cerr << "Error while opening file animals.txt!" << endl;
        return;
    }

    for (int i = 0; i < numberOfAnimals(); i++) {
        file << arr[i]->get_name() << '|' << arr[i]->get_healthy_status() << '|' << arr[i]->is_in_hospital() << '|' << arr[i]->get_year() << '|' << arr[i]->type() << endl;
    }

    file.close();
}

// створюємо метод, де можна буде взяти і створити тварину з інформацією з рядка 
// нашого текстового файлу

Animal* Shelter::animal_from_line(char* line) {
    char* name;
    char* isSick;
    char* inh;
    char* year_ch;
    int year;
    char* type;
    bool health;
    bool inHospital;
    int places[4];
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
    inh = new char[2];
    strncpy(inh, line + places[1] + 1, places[2] - places[1] - 1);
    inh[1] = '\0';
    year_ch = new char[places[3] - places[2]];
    strncpy(year_ch, line + places[2] + 1, places[3] - places[2] - 1);
    year_ch[places[3] - places[2] - 1] = '\0';
    type = new char[strlen(line) - places[2]];
    strncpy(type, line + places[3] + 1, strlen(line) - places[3] - 1);
    type[strlen(line) - places[3] - 1] = '\0';

    if (!strcmp(isSick, "0")) {
        health = false;
    } else {
        health = true;
    }
    if (!strcmp(inh, "0")) {
        inHospital = false;
    } else {
        inHospital = true;
    }
    year = stoi(year_ch);
    if (!strcmp(type, "cat")) {
        animal = new Cat(name, year, health, inHospital);
    }
    if (!strcmp(type, "dog")) {
        animal = new Dog(name, year, health, inHospital);
    }
    if (!strcmp(type, "rabbit")) {
        animal = new Rabbit(name, year, health, inHospital);
    }
    return animal;
}

// метод для змоги записати тварину з файлу до загального масиву

void Shelter::load_animals() {
    const char* filename = "animals.txt";
    ifstream file(filename);
    Animal* animal;

    if (!file.is_open()) {
        cerr << "Error while opening file animals.txt!" << endl;
        return;
    }

    char line[200];
    while (file.getline(line, 200)) {
        animal = animal_from_line(line);
        arr[numberOfAnimals()] = animal;
    }

    file.close();
}

int Shelter::numberOfAnimals() {
    int number = 0;
    while (arr[number] && number < size) {
        number++;
    }
    return number;
}

void Shelter::animal_to_treatment(int number) {
    if (number <= 0 || number > size) {
        cout << "Wrong number" << endl;
        return;
    }
    if (arr[number - 1]->get_healthy_status()) {
        cout << "This animal is healthy." << endl;
        return;
    }
    if (arr[number - 1]->is_in_hospital()) {
        cout << "This animal already in hospital" << endl;
        return;
    }
    if (hospital->add_animal(arr[number - 1])) {
        cout << "Operation success." << endl;
        arr[number - 1]->change_is_hospitalStatus();
        return;
    }
    cout << "Too many animals in hospital." << endl;
}

Hospital::Hospital() {
    for (int i = 0; i < size; i++) { 
        arr[i] = nullptr;
    }
    load_animals();
}

int Hospital::numberOfAnimals() {
    int number = 0;
    while (arr[number] && number < size) {
        number++;
    }
    return number;
}

bool Hospital::add_animal(Animal* animal) {
    if (numberOfAnimals() <= size) { 
        arr[numberOfAnimals()] = animal;
        return true;
    }
    return false;
}

bool Hospital::pick_animal(Animal* animal) {
    int index = -1;
    for (int i = 0; i < numberOfAnimals(); i++) {
        if (!strcmp(arr[i]->get_name(), animal->get_name()) && !strcmp(arr[i]->type(), animal->type()) && arr[i]->get_year() == animal->get_year()) {
            index = i;
            break;
        }
    }
    if (index < 0) {
        return false;
    }
    arr[index] = arr[numberOfAnimals() - 1];
    arr[numberOfAnimals() - 1] = nullptr;
    return true;
}

void Hospital::output_total() {
    cout << "\nList of animals in hospital: ";
    if (!numberOfAnimals()) {
        cout << "\nThere no animals";
    }
    for (int i = 0; i < numberOfAnimals(); i++) {
        cout << "\n" << i + 1 << ". " << arr[i]->get_name() << "(" << arr[i]->type() << ")";
    }
    cout << endl;
}

void Hospital::save_animals() {
    const char* filename = "animals_hospital.txt";

    if (!numberOfAnimals()) {
        ofstream file(filename, ios::trunc);
        return;
    }

    fstream file(filename);
    if (!file.is_open()) {
        cerr << "Error while opening file animals_hospital.txt!" << endl;
        return;
    }

    for (int i = 0; i < numberOfAnimals(); i++) {
        file << arr[i]->get_name() << '|' << arr[i]->get_healthy_status() << '|' << arr[i]->is_in_hospital() << '|' << arr[i]->get_year() << '|' << arr[i]->type() << endl;
    }

    file.close();
}

Animal* Hospital::animal_from_line(char* line) {
    char* name;
    char* isSick;
    char* inh;
    char* year_ch;
    int year;
    char* type;
    bool health;
    bool inHospital;
    int places[4];
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
    inh = new char[2];
    strncpy(inh, line + places[1] + 1, places[2] - places[1] - 1);
    inh[1] = '\0';
    year_ch = new char[places[3] - places[2]];
    strncpy(year_ch, line + places[2] + 1, places[3] - places[2] - 1);
    year_ch[places[3] - places[2] - 1] = '\0';
    type = new char[strlen(line) - places[2]];
    strncpy(type, line + places[3] + 1, strlen(line) - places[3] - 1);
    type[strlen(line) - places[3] - 1] = '\0';

    if (!strcmp(isSick, "0")) {
        health = false;
    } else {
        health = true;
    }
    if (!strcmp(inh, "0")) {
        inHospital = false;
    } else {
        inHospital = true;
    }
    year = stoi(year_ch);
    if (!strcmp(type, "cat")) {
        animal = new Cat(name, year, health, inHospital);
    }
    if (!strcmp(type, "dog")) {
        animal = new Dog(name, year, health, inHospital);
    }
    if (!strcmp(type, "rabbit")) {
        animal = new Rabbit(name, year, health, inHospital);
    }
    return animal;
}

// метод для змоги записати тварину з файлу до загального масиву

void Hospital::load_animals() {
    const char* filename = "animals_hospital.txt";
    ifstream file(filename);
    Animal* animal;

    if (!file.is_open()) {
        cerr << "Error while opening file animals_hospital.txt!" << endl;
        return;
    }

    char line[200];
    while (file.getline(line, 200)) {
        animal = animal_from_line(line);
        arr[numberOfAnimals()] = animal;
    }

    file.close();
}
