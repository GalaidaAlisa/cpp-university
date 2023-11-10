#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Vector {
public:
    Vector(int n) : dim(n) {
        coord = new float[dim];
        for (int i = 0; i < dim; i++) {
            coord[i] = 0;
        }
    }

    Vector(Vector& other) : dim(other.dim) {
        coord = new float[dim];
        for (int i = 0; i < dim; i++) {
            coord[i] = other.coord[i];
        }
    }
    
    void set_coord(float value, int index) {
        if ((index >= 0) && (index < dim)) {
            coord[index] = value;
        } else {
            cout << "Wrong index." << endl;
        }
    }

    float get_coord(int index) {
        if ((index >= 0) && (index < dim)) {
            return coord[index];
        } 
    }

    int get_dim() {
        return dim;
    }

    float lenght() {
        int suma = 0;
        for (int i = 0; i < dim; i++) {
            suma += coord[i] * coord[i];
        }
        return sqrt(suma);
    }

    void output() {
        cout << "Dimension is: " << dim << ", coordinates: (";
        for (int i = 0; i < dim; i++) {
            cout << coord[i];
            if (i != dim - 1) {
                cout << ", ";
            }
        }
        cout << "), lenght: " << this->lenght() << '.' << endl;
    }

    Vector* dob(Vector* v, float k) {
    Vector* v_mod = new Vector(v->get_dim());
    for (int i = 0; i < v->get_dim(); i++) {
        v_mod->set_coord(v->get_coord(i) * k, i);
    }
    return v_mod;
    }

    ~Vector() {
        delete coord;
    }

private:
    int dim;
    float* coord;
};


float len(Vector* vector) {
    int suma = 0;
    for (int i = 0; i < vector->get_dim(); i++) {
        suma += vector->get_coord(i) * vector->get_coord(i);
    }
    return sqrt(suma);
}

Vector* suma(Vector* vector1, Vector* vector2) {
    if (vector1->get_dim() != vector2->get_dim()) {
        return nullptr;
    }
    Vector* v = new Vector(vector1->get_dim());
    for (int i = 0; i < v->get_dim(); i++) {
        v->set_coord(vector1->get_coord(i) + vector2->get_coord(i), i);
    }
    return v;
}

float scalar_product(Vector* vector1, Vector* vector2) {
    if (vector1->get_dim() != vector2->get_dim()) {
        return NULL;
    }
    int suma = 0;
    for (int i = 0; i < vector1->get_dim(); i++) {
        suma = suma + (vector1->get_coord(i) * vector2->get_coord(i));
    }
    return suma;
}

Vector* the_longest(Vector* arr[], int number_of_elem) {
    int max_len = 0;
    Vector* max_vector;
    for (int i = 0; i < number_of_elem; i++) {
        if (arr[i]->lenght() > max_len) {
            max_len = arr[i]->lenght();
            max_vector = arr[i];
        }
    }
    return max_vector;
}


int main() {
    Vector v1(3);
    v1.set_coord(1, 0);
    v1.set_coord(5, 1);
    v1.set_coord(-7, 2);
    v1.output();
    cout << endl;

    Vector* v2 = new Vector(4);
    v2->set_coord(3, 0);
    v2->set_coord(8, 1);
    v2->set_coord(-12, 2);
    v2->set_coord(4, 3);
    v2->output();
    cout << "Lenght by function: " << len(v2) << endl;
    cout << endl;

    Vector* v3 = new Vector(2);
    v3->set_coord(5, 0);
    v3->set_coord(-24, 1);

    Vector* v4 = new Vector(3);
    v4->set_coord(1, 0);
    v4->set_coord(13, 1);
    v4->set_coord(-15, 2);

    Vector* v5 = new Vector(3);
    v5->set_coord(2, 0);
    v5->set_coord(-17, 1);
    v5->set_coord(9, 2);

    Vector* result = suma(v4, v5);
    cout << "Sum of vectors v4 and v5:\n";
    result->output();
    cout << endl;

    cout << "Scalar product of vectors v4 and v5: " << scalar_product(v4, v5) << endl;
    cout << endl;

    Vector* vectors[4] = {v2, v3, v4, v5};
    cout << "The longest vector:\n";
    the_longest(vectors, 4)->output();
    return 0;
}
