#include <iostream>
#include <string>

using namespace std;

enum Gen { M, W };

struct Date {
    int d;
    int m;
    int y;
};

struct Child {
    string name;
    Gen gen;
    int h;
    Date bdate;
};

void printChild(Child c) {
    cout << c.name << " | " << (c.gen == M ? "M" : "W") << " | " 
         << c.h << " | " << c.bdate.d << "." << c.bdate.m << "." << c.bdate.y << "\n";
}

void printArr(Child arr[], int size) {
    for(int i = 0; i < size; i++) {
        printChild(arr[i]);
    }
    cout << "\n";
}

void avgHeight12yoW(Child arr[], int size) {
    int sum = 0;
    int count = 0;
    for(int i = 0; i < size; i++) {
        if(arr[i].gen == W && (2026 - arr[i].bdate.y) == 12) {
            sum += arr[i].h;
            count++;
        }
    }
    if(count > 0) cout << "Avg height: " << (double)sum / count << "\n\n";
    else cout << "No 12yo girls\n\n";
}

bool isYounger(Date d1, Date d2) {
    if(d1.y != d2.y) return d1.y > d2.y;
    if(d1.m != d2.m) return d1.m > d2.m;
    return d1.d > d2.d;
}

void top3YoungestBoys(Child in[], int size, Child out[], int &outSize) {
    Child boys[20];
    int bCount = 0;
    for(int i = 0; i < size; i++) {
        if(in[i].gen == M) {
            boys[bCount] = in[i];
            bCount++;
        }
    }
    
    for(int i = 0; i < bCount - 1; i++) {
        for(int j = 0; j < bCount - i - 1; j++) {
            if(!isYounger(boys[j].bdate, boys[j+1].bdate)) {
                Child tmp = boys[j];
                boys[j] = boys[j+1];
                boys[j+1] = tmp;
            }
        }
    }
    
    outSize = (bCount < 3) ? bCount : 3;
    for(int i = 0; i < outSize; i++) {
        out[i] = boys[i];
    }
}

void sortByDate(Child arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(isYounger(arr[j].bdate, arr[j+1].bdate)) {
                Child tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

void findByName(Child arr[], int size, string target) {
    for(int i = 0; i < size; i++) {
        if(arr[i].name == target) {
            printChild(arr[i]);
        }
    }
    cout << "\n";
}

void updateChild(Child &c, int newHeight) {
    c.h = newHeight;
}

void filterByMonth(Child in[], int size, int targetMonth, Child out[], int &outSize) {
    outSize = 0;
    for(int i = 0; i < size; i++) {
        if(in[i].bdate.m == targetMonth) {
            out[outSize] = in[i];
            outSize++;
        }
    }
}

void wrapFilter(Child in[], int size, int targetMonth) {
    Child res[20];
    int resSize = 0;
    filterByMonth(in, size, targetMonth, res, resSize);
    printArr(res, resSize);
}

int main() {
    Child data[20] = {
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

    avgHeight12yoW(data, 20);

    Child youngestBoys[3];
    int boysSize = 0;
    top3YoungestBoys(data, 20, youngestBoys, boysSize);
    printArr(youngestBoys, boysSize);

    sortByDate(data, 20);
    printArr(data, 20);

    findByName(data, 20, "Смирнова");

    updateChild(data[0], 170);
    
    wrapFilter(data, 20, 4);

    return 0;
}