#include <iostream>
using namespace std;


void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int salaries[10];

    cout << "Enter salaries of 10 employees:\n";
    for (int i = 0; i < 10; i++) {
        cin >> salaries[i];
    }

    cout << "\nSalaries before sorting:\n";
    display(salaries, 10);

    bubbleSort(salaries, 10);

    cout << "\nSalaries after Bubble Sort (Ascending Order):\n";
    display(salaries, 10);

    return 0;
}

