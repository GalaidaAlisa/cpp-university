#include <iostream>

using namespace std;

bool is_diff(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int size;
    cout << "Enter number of elements: ";
    cin >> size;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10;
    }
    return 0;
}
