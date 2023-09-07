#include <iostream>

using namespace std;

bool is_diff(int**arr, int row, int col_ind) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i][col_ind] == arr[j][col_ind]) {
                return false;
            }
        }
    }
    return true;   
}

int main() {
    int row, col, count = 0;
    cout << "Enter number of rows: ";
    cin >> row;
    cout << "Enter number of columns: ";
    cin >> col;
    int** arr = new int*[row];
    for (int i = 0; i < row; i++) {
        arr[i] = new int[col];
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            arr[i][j] = rand() % 10;
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "Numbers of column: ";
    for (int col_ind = 0; col_ind < col; col_ind++) {
        if (is_diff(arr, row, col_ind) == true) {
            count++;
            cout << col_ind + 1 << ' ';
        }
    }
    cout << endl << "Number of columns: " << count;
    for (int i = 0; i < row; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}
