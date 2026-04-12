#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "");
    
    int n;
    cout << "введите размер массива: ";
    cin >> n;

    double* mas1 = new double[n];
    double sum1 = 0;

    cout << "введите элементы массива:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> mas1[i];
        sum1 = sum1 + mas1[i];
    }

    double srednee1 = sum1 / n;
    int count_ne_nuli = 0;

    for (int i = 0; i < n; i++) {
        if (mas1[i] != 0) {
            count_ne_nuli = count_ne_nuli + 1;
        }
    }

    double* mas2 = new double[count_ne_nuli];
    int j = 0;
    double sum2 = 0;

    for (int i = 0; i < n; i++) {
        if (mas1[i] != 0) {
            mas2[j] = mas1[i];
            sum2 = sum2 + mas2[j];
            j = j + 1;
        } else {
            mas1[i] = srednee1; 
        }
    }

    double srednee2 = 0;
    if (count_ne_nuli > 0) {
        srednee2 = sum2 / count_ne_nuli;
    }

    cout << "\nпервый массив после замены: ";
    for (int i = 0; i < n; i++) {
        cout << mas1[i] << " ";
    }

    cout << "\nвторой массив (без нулей): ";
    for (int i = 0; i < count_ne_nuli; i++) {
        cout << mas2[i] << " ";
    }

    cout << "\nсреднее первого массива: " << srednee1;
    cout << "\nсреднее второго массива: " << srednee2 << endl;

    if (srednee1 > srednee2) {
        cout << "среднее первого массива больше." << endl;
    } else if (srednee1 < srednee2) {
        cout << "среднее второго массива больше." << endl;
    } else {
        cout << "средние значения равны." << endl;
    }

    delete[] mas1;
    delete[] mas2;

    return 0;
}