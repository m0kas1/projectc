#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};


struct Child
{
    string surname;
    string name;
    char gender;
    double height;
    Date birthday;
};


bool compareByDate(const Child& a, const Child& b) {
    if (a.birthday.year != b.birthday.year) {
        return a.birthday.year < b.birthday.year; 
    }
    if (a.birthday.month != b.birthday.month) {
        return a.birthday.month < b.birthday.month;
    }

    return a.birthday.day < b.birthday.day;
}

int main() {
    setlocale(LC_ALL, "");
    
    Child children[20] = {
        {"Иванов", "Иван", 'M', 150.5, {15, 5, 2012}},
        {"Смирнова", "Анна", 'F', 152.0, {10, 8, 2014}},
        {"Петров", "Алексей", 'M', 148.0, {22, 11, 2015}},
        {"Сидорова", "Мария", 'F', 149.5, {5, 3, 2014}}, 
        {"Кузнецов", "Дмитрий", 'M', 155.0, {1, 1, 2011}},
        {"Попова", "Екатерина", 'F', 145.0, {12, 12, 2015}},
        {"Васильев", "Михаил", 'M', 160.2, {20, 5, 2010}},
        {"Соколова", "Елена", 'F', 151.3, {18, 7, 2014}},  
        {"Михайлов", "Артем", 'M', 142.0, {30, 9, 2016}},  
        {"Новикова", "Ольга", 'F', 158.0, {8, 4, 2011}},
        {"Федоров", "Максим", 'M', 140.5, {14, 2, 2017}}, 
        {"Морозова", "Наталья", 'F', 150.0, {25, 10, 2013}},
        {"Волков", "Даниил", 'M', 153.4, {3, 6, 2013}},
        {"Алексеева", "Дарья", 'F', 154.1, {17, 8, 2014}},
        {"Лебедев", "Илья", 'M', 139.0, {5, 12, 2017}},  
        {"Семенова", "Виктория", 'F', 148.8, {21, 1, 2015}},
        {"Егоров", "Никита", 'M', 156.7, {9, 11, 2012}},
        {"Павлова", "Алиса", 'F', 152.5, {28, 5, 2014}}, 
        {"Козлов", "Роман", 'M', 147.2, {11, 3, 2016}}, 
        {"Степанова", "Полина", 'F', 146.0, {19, 9, 2015}}
    };

    for (int i = 0; i < 20; i++) {
        cout << children[i].surname << " " << children[i].name << ", " << children[i].gender << ", " << children[i].height << " см, " << children[i].birthday.day << "." << children[i].birthday.month << "." << children[i].birthday.year << endl;
    }

    double sumhgtf = 0;
    int countf = 0;

    for (int i = 0; i < 20; i++) {
        if (children[i].birthday.year == 2014 && children[i].gender == 'F') {
            sumhgtf += children[i].height;
            countf++;                   
        }
    } 
    
    if (countf > 0) {
        double avghgtf = sumhgtf / countf;
        cout << "Средний рост 12-летних девочек: " << avghgtf << " см" << endl;
    } else {
        cout << "Девочек подходящего возраста не найдено." << endl;
    }

    sort(children, children + 20, compareByDate);

    cout << "\nДети, отсортированные по дате рождения:" << endl;
    for (int i = 0; i < 20; i++) {
        cout << children[i].surname << " " << children[i].name << ", " << children[i].gender << ", " << children[i].height << " см, " << children[i].birthday.day << "." << children[i].birthday.month << "." << children[i].birthday.year << endl;
    }

    string isur;
    cout << "\nEnter surname: ";
    cin >> isur;

    bool found = false;
    for (int i = 0; i < 20; i++) {
        if (children[i].surname == isur) {
            cout << children[i].surname << " " << children[i].name << ", " << children[i].gender << ", " << children[i].height << " см, " << children[i].birthday.day << "." << children[i].birthday.month << "." << children[i].birthday.year << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "ребенок с фамилией " << isur << " не найден." << endl;
    }

    int imonth;
    cout << "\nвведи месяц (1-12): ";
    cin >> imonth;

    Child monthchild[20]; // Отдельный массив для результатов
    int fcount = 0;       // Счетчик найденных детей

    for (int i = 0; i < 20; i++) {
        if (children[i].birthday.month == imonth) {
            monthchild[fcount] = children[i]; // Копируем данные в новый массив
            fcount++;
        }
    }

    cout << "\nдети, родившиеся в " << imonth << " месяце:" << endl;
    for (int i = 0; i < fcount; i++) {
        cout << monthchild[i].surname << " " << monthchild[i].name << ", " << monthchild[i].gender << ", " << monthchild[i].height << " см, " << monthchild[i].birthday.day << "." << monthchild[i].birthday.month << "." << monthchild[i].birthday.year << endl;
    }

    return 0;
}