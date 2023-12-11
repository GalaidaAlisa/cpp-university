/*
Розробити клас Figure. Успадкувати від нього класи
Rectangle (прямокутник), Circle (коло) Triangle (трикутник). Створити масив
різних фігур та забезпечити обчислення периметра та площі кожної фігури залежно
від її типу.
*/

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

// базова фігура - точка з координатами (x, y)
class Figure {
protected:
    float x, y;

public:
    Figure (float _x, float _y) : x(_x), y(_y) {}

    virtual void output() {
        cout << "point with coordinates (" << x << ", " << y << ")." << endl;
    }

    virtual float area() {
        return 0;
    }

    virtual void type() {
        cout << "POINT" << endl;
    }

    virtual float perimetr() {
        return 0;
    }
};

class Triangle: public Figure {
private:
    float side1;
    float side2;
    float side3;

public:
    Triangle(float _x, float _y, float s1, float s2, float s3) : Figure(_x, _y) {
        if (s1 <= 0 || s2 <= 0 || s3 <= 0 || s1 + s2 <= s3 || s1 + s3 <= s2 || s2 + s3 <= s1) {
            throw invalid_argument("Invalid dimensions for Triangle");
        }
        side1 = s1;
        side2 = s2;
        side3 = s3;
    }

    void output() override {
        cout << "Side1: " << side1 << ", side2: " << side2 << ", side3: " << side3 << "." << endl; 
        cout << "Left bottom vertix is: ";
        Figure::output();
    }

    void type() override {
        cout << "TRIANGLE" << endl;
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
    Rectangular(float _x, float _y, float s1, float s2) : Figure(_x, _y) {
        if (s1 <= 0 || s2 <= 0) {
            throw invalid_argument("Invalid dimensions for Rectangle");
        }
        side1 = s1;
        side2 = s2;
    }

    void output() override {
        cout << "Side1: " << side1 << ", side2: " << side2 << "." << endl; 
        cout << "Left bottom vertix is: ";
        Figure::output();
    }

    void type() override {
        cout << "RECTANGULAR" << endl;
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
    Circle(float _x, float _y, float r) : Figure(_x, _y) {
        if (r <= 0) {
            throw invalid_argument("Invalid radius for Circle");
        }
        radius = r;
    }

    void output() override {
        cout << "Radius: " << radius << "." << endl; 
        cout << "Center vertix is: ";
        Figure::output();
    }

    void type() override {
        cout << "CIRCLE" << endl;
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
    Figure* figure = new Figure(2, 3);
    figure->output();
    cout << endl;
    Rectangular* rectangular = new Rectangular(0, 0, 2, 5);
    Triangle* triangle = new Triangle(10, -10, 4, 7, 10);
    Circle* circle = new Circle(-7, 7, 5);
    array[0] = rectangular;
    array[1] = triangle;
    array[2] = circle;
    for (int i = 0; i < 3; i++) {
        cout << "Figure " << i + 1 << ": ";
        array[i]->type();
        array[i]->output();
        cout << "Area of figure: " << array[i]->area() << endl;
        cout << "Perimetr of figure: " << array[i]->perimetr() << endl;
        cout << endl;
    }

    return 0;
}
