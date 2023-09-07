#include <iostream>

using namespace std;

void Triangle_left_up(int** arr, int amount) {
    for (int i = 0; i < amount; i++) {
        for (int j = 0; j < amount; j++) {
            if (i + j < amount - 1) {
                cout << arr[i][j] << ' ';
            }
        }
        cout << endl;
    }
}

void Triangle_right_up(int** arr, int amount) {
    for (int i = 0; i < amount; i++) {
        for (int j = 0; j < amount; j++) {
            if (i - j < 0) {
                cout << arr[i][j] << ' ';
            }
            else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

void Triangle_right_down(int** arr, int amount) {
    for (int i = 0; i < amount; i++) {
        for (int j = 0; j < amount; j++) {
            if (i + j > amount - 1) {
                cout << arr[i][j] << ' ';
            }
            else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

void Triangle_left_down(int** arr, int amount) {
    for (int i = 0; i < amount; i++) {
        for (int j = 0; j < amount; j++) {
            if (i - j > 0) {
                cout << arr[i][j] << ' ';
            }
        }
        cout << endl;
    }
}

int main() {
    int amount;
    cout << "Enter number of rows/columns: ";
    cin >> amount;
    int** arr = new int*[amount];
    for (int i = 0; i < amount; i++) {
        arr[i] = new int[amount];
    }
    for (int i = 0; i < amount; i++) {
        for (int j = 0; j < amount; j++) {
            arr[i][j] = 0;
        }
    }
    
    Triangle_left_up(arr, amount);
    Triangle_right_up(arr, amount);
    Triangle_right_down(arr, amount);
    Triangle_left_down(arr, amount);

    for (int i = 0; i < amount; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}