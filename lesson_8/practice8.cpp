/*
Розробити клас, похідний класу Point. Протестувати раннє
та пізніше (поліморфне) зв'язування.
*/

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Point {
protected:
    float x;
    float y;
public:
    Point(float a, float b) : x(a), y(b) {}

    float get_coordX() {
        return x;
    }

    float get_coordY() {
        return y;
    }

    void set_coordX(float a) {
        x = a;
    }

    void set_coordY(float a) {
        y = a;
    }

    virtual void output() {
        cout << "Coord x: " << x << ", coord y: " << y << "." << endl;
    }

    float distance_to_O() {
        return sqrt(x * x + y * y);
    }

};

class ColorPoint: public Point {
private:
    char* color;
public:
    ColorPoint(float x, float y, char* c) : Point(x, y) {
        color = new char[strlen(c + 1)];
        strcpy(color, c);
    }

    void get_color() {
        cout << color << endl;
    }

    void set_color(char* new_color) {
        color = new char[strlen(new_color + 1)];
        strcpy(color, new_color);
    }

    void output() {
        Point::output();
        cout << "Color: " << color << '.' << endl;
    }

    ~ColorPoint() {
        delete color;
    }
};

int main() {
// раннє зв'язування
    cout << "EARLY binding.\n" << endl;
    Point point(3, 4);
    cout << "TEST FOR POINT: " << endl;
    cout << "Distance to 0: " << point.distance_to_O() << endl;
    point.output();

    ColorPoint colorpoint(2, 5, "yellow");
    cout << "\nTEST FOR COLORED POINT: " << endl;
    colorpoint.set_color("blue");
    cout << "Distance to 0: " << colorpoint.distance_to_O() << endl;
    colorpoint.output();

// пізнє зв'язування
    cout << "\nLATE binding." << endl;
    Point* new_point = &point; // створили покажчик на тип даних point
    cout << "Distance to 0: " << new_point->distance_to_O() << endl;
    new_point->output();

    Point* new_color_point = &colorpoint; // створили покажчик на тип даних colorpoint
    cout << "Distance to 0: " << new_color_point->distance_to_O() << endl;
    new_color_point->output();

    return 0;
}
