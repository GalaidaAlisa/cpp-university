/*
Реалізувати завдання 9, зробивши клас Figure абстрактним. Додати винятки в конструктори фігур (наприклад радіус коло повинен буди додатним, якщо ні - згенерувати виняток. В мейні перехопити і обробити)

Додати коментар, що краще, щоб клас Фігура був абстрактним чи ні.
Відповідь обґрунтуйте.
*/


#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

// базова фігура - точка з координатами (0, 0)
class Figure {
public:
    virtual void output() {
        cout << "The figure is: ";
    }

    virtual float area() = 0;

    virtual float perimetr() = 0;
};

class Triangle: public Figure {
private:
    float side1;
    float side2;
    float side3;
public:
    Triangle(float s1, float s2, float s3) {
        if (s1 <= 0 || s2 <= 0 || s3 <= 0 || s1 + s2 <= s3 || s1 + s3 <= s2 || s2 + s3 <= s1) {
            throw invalid_argument("Invalid dimensions for Triangle");
        }
        side1 = s1;
        side2 = s2;
        side3 = s3;
    }

    void output() {
        Figure::output();
        cout << "TRIAGLE" << endl;
        cout << "Side1: " << side1 << ", side2: " << side2 << ", side3: " << side3 << "." << endl; 
    }

    float area() override {
        float p;
        p = (side1 + side2 + side3) / 2;
        return p * (p - side1) * (p - side2) * (p - side3);
    }
    float perimetr() override {
        return side1 + side2 + side3;
    }
};


class Rectangular: public Figure {
private:
    float side1;
    float side2;
public:
    Rectangular(float s1, float s2) {
        if (s1 <= 0 || s2 <= 0) {
            throw invalid_argument("Invalid dimensions for Rectangle");
        }
        side1 = s1;
        side2 = s2;
    }

    void output() {
        Figure::output();
        cout << "RECTANGULAR" << endl;
        cout << "Side1: " << side1 << ", side2: " << side2 << "." << endl; 
    }

    float area() override {
        return side1 * side2;
    }
    float perimetr() override {
        return (side1 + side2) * 2;
    }
};


class Circle: public Figure {
private:
    float radius;
public:
    Circle(float r) {
        if (r <= 0) {
            throw invalid_argument("Invalid radius for Circle");
        }
        radius = r;
    }

    void output() {
        Figure::output();
        cout << "CIRCLE" << endl;
        cout << "Radius: " << radius << "." << endl; 
    }

    float area() override {
        return M_PI * radius * radius;
    }
    float perimetr() override {
        return 2 * M_PI * radius;
    }
};


int main() {
    Figure* array[3];
    Rectangular* rectangular = new Rectangular(2, 5);
    Triangle* triangle = new Triangle(4, 7, 10);
    Circle* circle = new Circle(5);
    array[0] = rectangular;
    array[1] = triangle;
    array[2] = circle;
    for (int i = 0; i < 3; i++) {
        cout << "Figure " << i + 1 << ":\n";
        array[i]->output();
        cout << "Area of figure: " << array[i]->area() << endl;
        cout << "Perimetr of figure: " << array[i]->perimetr() << endl;
        cout << endl;
    }

    return 0;
}
