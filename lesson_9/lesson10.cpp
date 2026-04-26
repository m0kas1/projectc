#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

enum Gen { M, W };

struct Date {
    int d;
    int m;
    int y;
};

struct Child {
    char name[50];
    Gen gen;
    int h;
    Date bdate;
};

void pArr(Child arr[], int sz) {
    for(int i = 0; i < sz; i++) {
        cout << arr[i].name << " | " << (arr[i].gen == M ? "M" : "W") << " | " 
             << arr[i].h << " | " << arr[i].bdate.d << "." << arr[i].bdate.m << "." << arr[i].bdate.y << "\n";
    }
    cout << "\n";
}

void mkTxt() {
    ofstream f(".\\data.txt");
    f << "Иванов 1\n";
    f << "Смирнова 0\n";
    f << "Кузнецов 1\n";
    f.close();
}

void updTxt(Child arr[], int sz) {
    ifstream f(".\\data.txt");
    if(!f.is_open()) return;
    
    char n[50];
    int g;
    
    while(f >> n >> g) {
        for(int i = 0; i < sz; i++) {
            if(strcmp(arr[i].name, n) == 0) {
                arr[i].gen = (g == 0) ? M : W;
                break;
            }
        }
    }
    f.close();
}

void wrBin(Child arr[], int sz) {
    ofstream f(".\\data.bin", ios::binary);
    if(f.is_open()) {
        f.write((char*)arr, sz * sizeof(Child));
        f.close();
    }
}

void rdBin(Child arr[], int &sz) {
    ifstream f(".\\data.bin", ios::binary);
    if(f.is_open()) {
        f.seekg(0, ios::end);
        int b = f.tellg();
        sz = b / sizeof(Child);
        f.seekg(0, ios::beg);
        
        f.read((char*)arr, b);
        f.close();
    }
}

int main() {
    Child d[20] = {
        {"Иванов", M, 145, {15, 4, 2014}},
        {"Смирнова", W, 150, {10, 5, 2014}},
        {"Кузнецов", M, 160, {12, 1, 2013}},
        {"Попова", W, 148, {22, 11, 2014}},
        {"Васильев", M, 130, {5, 6, 2015}},
        {"Петрова", W, 152, {14, 8, 2014}},
        {"Соколов", M, 155, {19, 2, 2014}},
        {"Михайлова", W, 140, {30, 10, 2015}},
        {"Новиков", M, 142, {8, 3, 2014}},
        {"Федорова", W, 151, {2, 7, 2014}},
        {"Морозов", M, 138, {11, 12, 2015}},
        {"Волкова", W, 146, {25, 9, 2014}},
        {"Алексеев", M, 165, {4, 4, 2012}},
        {"Лебедева", W, 135, {17, 1, 2016}},
        {"Семенов", M, 150, {21, 5, 2014}},
        {"Егорова", W, 149, {9, 2, 2014}},
        {"Павлов", M, 158, {28, 8, 2013}},
        {"Козлова", W, 147, {16, 6, 2014}},
        {"Степанов", M, 132, {3, 11, 2016}},
        {"Николаева", W, 154, {1, 3, 2014}}
    };

    mkTxt();
    updTxt(d, 20);
    wrBin(d, 20);
    
    Child d2[20];
    int sz2 = 0;
    rdBin(d2, sz2);
    
    pArr(d2, sz2);

    return 0;
}