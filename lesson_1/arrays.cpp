#include <iostream>

using namespace std;
void input_array(int* array, int l) {
    for (int i = 0; i < l; i++){
        cout << "Enter element " << i + 1 << ": ";
        cin >> array[i];
    }
}

void output_array(int* array, int l) {
    for (int i = 0; i < l; i++){
        cout << array[i] << ' ';
    }
}

float suma_of_items(int* arr, int l) {
    float suma = 0;
    for (int i = 0; i < l; i++) {
        suma += arr[i];
    }
    return suma;
}

int product_of_items(int* arr, int l) {
    int dob = 1;
    for (int i = 0; i < l; i++) {
        dob *= arr[i];
    }
    return dob;
}

int main() {
    int l, dob;
    float suma, ser_sum;
    cout << "Enter lenght of array: ";
    cin >> l;
    int* arr = new int[l];

    input_array(arr, l);
    output_array(arr, l);
    suma = suma_of_items(arr, l);
    dob = product_of_items(arr, l);

    ser_sum = suma / l;
    cout << endl << "Suma: " << suma << endl;
    cout << "Product: " << dob << endl;
    cout << "Serednya suma: " << ser_sum << endl;
    delete[] arr;
    return 0;
}