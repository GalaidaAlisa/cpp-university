class Animal { // створюємо базовий клас Animal
protected:
    const char* name;
    int year_of_birth;
    bool is_healthy;
    bool in_hospital;
    
public:
    static int number_of_animals; 

    Animal(const char* n, int y, bool s, bool inh);
    virtual const char* type () = 0;
    const char* get_name() const;
    int get_year() const;
    bool get_healthy_status() const;
    bool is_in_hospital() const;
    void chande_healthy_status();
    void change_is_hospitalStatus();
    void health() const;
    virtual void output() const;
};

// створюємо 3 нащадкових класа (Cat, Dog, Rabbit) та перевизначаємо метод type()

class Cat: public Animal { 
public: 
    Cat(const char* n, int y, bool s, bool inh);

    const char* type() override;
    void output();
};

class Dog: public Animal {
public: 
    Dog(const char* n, int y, bool s, bool inh);

    const char* type() override;
    void output();
};

class Rabbit: public Animal {
public: 
    Rabbit(const char* n, int y, bool s, bool inh);

    const char* type() override;
    void output();
};

class Hospital {
private:
    static const int size = 10;
    Animal* arr[size];
public:
    Hospital();
    int numberOfAnimals();
    bool add_animal(Animal* animal);
    void output_total();
    bool pick_animal(Animal* animal);
    void save_animals();
    Animal* animal_from_line(char* line);
    void load_animals();
};

class Shelter {
private:
    static const int size = 50;
    Animal* arr[size];
    Hospital* hospital;
public:
    Shelter();
    int numberOfAnimals();
    void add_animal(Animal* animal);
    void output_total();
    Animal* output_animal(int number);
    bool pick_animal(int number);
    bool take_animal_from_hospital(int number);
    // створюємо метод збереження тварин в окремий текстовий файл
    void save_animals();
    void animal_to_treatment(int number);
    void output_hospital();
    // створюємо метод, де можна буде взяти і створити тварину з інформацією з рядка 
    // нашого текстового файлу
    Animal* animal_from_line(char* line);
    // метод для змоги записати тварину з файлу до загального масиву
    void load_animals();
};
