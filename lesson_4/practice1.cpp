#include <iostream> 
#include <math.h>

using namespace std;

class Rectangular {
    public:
        Rectangular(int w, int l): width(w), length(l) {}
    void output() {
        cout << "Rectangular with width " << this->width << " and lenght " << this->length << "." << endl;
    }
    int get_width() {
        return this->width;
    }
    int get_length() {
        return this->length;
    }
    void set_width(int new_width) {
        this->width = new_width;
    }
    void set_length(int new_length) {
        this->length = new_length;
    }
    int perimetr() {
        return (this->width + this->length) * 2;
    }
    int area() {
        return (this->width * this->length);
    }
    float diagonal() {
        return sqrt(this->width * this->width + this->length * this->length);
    }
    private:
        int width;
        int length;
};


int main () {
    Rectangular rectangular(5, 10);
    rectangular.output();
    cout << rectangular.get_width();
    cout << ", ";
    cout << rectangular.get_length() << endl;
    cout << "Perimetr: " << rectangular.perimetr() << endl;
    cout << "Area: " << rectangular.area() << endl;
    cout << "Diagonal: " << rectangular.diagonal() << endl;
    int new_width = 3;
    int new_length = 8;
    rectangular.set_width(new_width);
    rectangular.set_length(new_length);
    rectangular.output();
    cout << "Perimetr: " << rectangular.perimetr() << endl;
    cout << "Area: " << rectangular.area() << endl;
    cout << "Diagonal: " << rectangular.diagonal() << endl << endl;

    cout << "Test for pointer:" << endl;
    Rectangular* pointer_on_r = &rectangular;
    pointer_on_r->output();
    cout << "Perimetr: " << pointer_on_r->perimetr() << endl;
    cout << "Area: " << pointer_on_r->area() << endl;
    cout << "Diagonal: " << pointer_on_r->diagonal() << endl << endl;

    cout << "Test fot array:" << endl;
    Rectangular first(4, 10);
    Rectangular second(1, 50);
    Rectangular array[2] = {first, second};
    for (int i = 0; i < 2; i++) {
        cout << "Element " << i + 1 << ":" << endl;
        array[i].output();
        cout << "Perimetr: " << array[i].perimetr() << endl;
        cout << "Area: " << array[i].area() << endl;
        cout << "Diagonal: " << array[i].diagonal() << endl << endl;
    }
    return 0;
}
