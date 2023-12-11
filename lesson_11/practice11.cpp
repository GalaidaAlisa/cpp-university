/*
Реалізувати клас Window за допомогою класу Rectangle двома способами (закрите спадкування, композиція). Забезпечити інтерфейс для переміщення вікна в задану точку, обчислення площі та інших характеристик.
*/


#include <iostream>

using namespace std;

class Rectangle {
protected:
    int width;
    int height;

public:
    Rectangle(int w, int h) : width(w), height(h) {}

    int get_height() {
        return height;
    }

    int get_width() {
        return width;
    }

    int area() {
        return width * height;
    }

    int perimeter() {
        return 2 * (width + height);
    }

    void change_size(int width, int height) {
        this->width = width;
        this->height = height;
    }
};

// Closed Inheritance
class window_inheritance : private Rectangle {
private:
    int x;
    int y;

public:
    window_inheritance(int w, int h, int initialX, int initialY) : Rectangle(w, h), x(initialX), y(initialY) {}

    void move(int newX, int newY) {
        x = newX;
        y = newY;
    }
    // bottom left x
    int getBLX() {
        return x;
    }
    // bottom left y
    int getBLY() {
        return y;
    }
    // top left x
    int getTLX() {
        return x;
    }
    // bottom left y
    int getTLY() {
        return y + height;
    }
    // top right x
    int getTRX() {
        return x + width;
    }
    // top right y
    int getTRY() {
        return y + height;
    }
    // bottom right x 
    int getBRX() {
        return x + width;
    }
    // bottom right y
    int getBRY() {
        return y;
    }

    void zoom_window(int new_width, int new_height) {
        change_size(new_width, new_height);
    }

    void display_info() {
        cout << "Window position: (" << x << ", " << y << ")\n";
        cout << "Window width: " << width << "\n";
        cout << "Window height: " << height << "\n";
        cout << "Window area: " << area() << "\n";
        cout << "Window perimeter: " << perimeter() << "\n";
        cout << "Coordinates of vertices:";
        cout << "\n\tBottom left: (" << getBLX() << ", " << getBLY() << ')';
        cout << "\n\tTop left: (" << getTLX() << ", " << getTLY() << ')';
        cout << "\n\tTop right: (" << getTRX() << ", " << getTRY() << ')';
        cout << "\n\tBottom right: (" << getBRX() << ", " << getBRY() << ')';
    }
};

// Composition
class window_composition {
private:
    Rectangle rectangle;
    int x;
    int y;

public:
    window_composition(int w, int h, int _x, int _y) : rectangle(w, h), x(_x), y(_y) {}

    void move(int _x, int _y) {
        x = _x;
        y = _y;
    }

    int area() {
        return rectangle.area();
    }

    int perimeter() {
        return rectangle.perimeter();
    }

    int height() {
        return rectangle.get_height();
    }

    int width() {
        return rectangle.get_width();
    }

    void change_size(int width, int height) {
        rectangle.change_size(width, height);
    }

    // bottom left x
    int getBLX() {
        return x;
    }
    // bottom left y
    int getBLY() {
        return y;
    }
    // top left x
    int getTLX() {
        return x;
    }
    // top left y
    int getTLY() {
        return y + height();
    }
    // top right x
    int getTRX() {
        return x + width();
    }
    // top right y
    int getTRY() {
        return y + height();
    }
    // bottom right x 
    int getBRX() {
        return x + width();
    }
    // bottom right y
    int getBRY() {
        return y;
    }

    void display_info() {
        cout << "Window position: (" << x << ", " << y << ")\n";
        cout << "Window width: " << width() << "\n";
        cout << "Window height: " << height() << "\n";
        cout << "Window area: " << area() << "\n";
        cout << "Window perimeter " << perimeter() << "\n";
        cout << "Coordinates of vertices:";
        cout << "\n\tBottom left: (" << getBLX() << ", " << getBLY() << ')';
        cout << "\n\tTop left: (" << getTLX() << ", " << getTLY() << ')';
        cout << "\n\tTop right: (" << getTRX() << ", " << getTRY() << ')';
        cout << "\n\tBottom right: (" << getBRX() << ", " << getBRY() << ')';
    }
};

int main() {
    cout << endl << "INHERITANCE" << endl;
    window_inheritance window_inh(10, 20, 5, 5);
    cout << "\nBefore moving:\n";
    window_inh.display_info();
    window_inh.move(10, 15);
    cout << "\n\nAfter moving:\n";
    window_inh.display_info();
    window_inh.zoom_window(20, 30);
    cout << "\n\nAfter size changing:\n";
    window_inh.display_info();

    cout << endl << endl << "COMPOSITION" << endl;
    window_composition window_com(10, 20, 5, 5);
    cout << "\nBefore moving:\n";
    window_com.display_info();
    window_com.move(10, 15);
    cout << "\n\nAfter moving:\n";
    window_com.display_info();
    window_com.change_size(20, 30);
    cout << "\n\nAfter size changing:\n";
    window_com.display_info();
    
    return 0;
}