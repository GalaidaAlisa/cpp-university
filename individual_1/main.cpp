//main.cpp
#include <iostream>
#include <cstring>
#include "logic.cpp"

int Animal::number_of_animals = 0; 
int main() {
    Shelter* shelter = new Shelter();
    bool flag = true;
    Animal* animal;
    int choice;
    int picked_animal_choice;
    bool inHospital = false;
    int number;
    char* name;
    int status_int;
    bool isHealthy;
    int year_of_birth;
    int type;
    while(flag) {
        if (shelter->numberOfAnimals() == 0) {
            cout << "\n1. Add animal" << endl;
            cout << "2." << endl;
            cout << "3." << endl;
            cout << "4. Finish program" << endl;
        } else {
            cout << "\n1. Add animal" << endl;
            cout << "2. Output all animals" << endl;
            cout << "3. Output animal" << endl;
            cout << "4. Output all animals in hospital" << endl;
            cout << "5. Finish program" << endl;
        }
        cin >> choice;
        if (shelter->numberOfAnimals() == 0 && choice > 1 && choice < 5) {
            choice = -1;
        }
        switch(choice) {
            case 1:
                name = new char[50];
                cout << "Enter name of animal: ";
                cin >> name;
                cout << "Enter health status of animal (0 - sick, other - healthy): ";
                cin >> status_int;
                if (status_int) {
                    isHealthy = true;
                } else {
                    isHealthy = false;
                }
                cout << "Enter year of birth of animal: ";
                cin >> year_of_birth;
                cout << "Enter number (1 - cat, 2 - dog, 3 - rabbit): ";
                cin >> type;
                if (type == 1) {
                    Cat* cat = new Cat(name, year_of_birth, isHealthy, inHospital);
                    shelter->add_animal(cat);
                } else if (type == 2) {
                    Dog* dog = new Dog(name, year_of_birth, isHealthy, inHospital);
                    shelter->add_animal(dog);
                } else if (type == 3) {
                    Rabbit* rabbit = new Rabbit(name, year_of_birth, isHealthy, inHospital);
                    shelter->add_animal(rabbit);
                } else {
                    cout << "Wrong input" << endl;
                }
                break;
            case 2:
                shelter->output_total();
                break;
            case 3:
                cout << "Enter number of animal: ";
                cin >> number;
                animal = shelter->output_animal(number);
                if (animal) {
                    cout << "MENU FOR THIS ANIMAL" << endl;
                    if (animal->get_healthy_status()) {
                        cout << "1. Take animal home." << endl;
                        cout << "Other. Back to main menu." << endl;
                        cin >> picked_animal_choice;
                        if (picked_animal_choice == 1) {
                            shelter->pick_animal(number);
                        }
                    } else if (animal->is_in_hospital()) {
                        cout << "1. Take animal from hospital." << endl;
                        cout << "Other. Back to main menu." << endl;
                        cin >> picked_animal_choice;
                        if (picked_animal_choice == 1) {
                            if (shelter->take_animal_from_hospital(number)) {
                                cout << "Action success!" << endl;
                            } else {
                                cout << "Animal not in hospital." << endl;
                            }
                        }
                    } else {
                        cout << "1. Take animal home" << endl;
                        cout << "2. Put animal in hospital" << endl;
                        cout << "Other. Back to main menu." << endl;
                        cin >> picked_animal_choice;
                        if (picked_animal_choice == 1) {
                            if (shelter->pick_animal(number)) {
                                cout << "Action succes." << endl;
                            } else {
                                cout << "Wrong number." << endl; 
                            }
                        } else if (picked_animal_choice == 2) {
                            shelter->animal_to_treatment(number);
                        }
                    }
                }
                break;
            case 4:
                shelter->output_hospital();
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
