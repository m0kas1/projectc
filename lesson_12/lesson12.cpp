#include <iostream>
#include <string>

using namespace std;

class Ship {
protected:
    string name;
public:
    static int count;
    Ship(string n)  {
        this->name = n;
        count++;
    }

    virtual void show() {
        cout << "Корабль: " << name << endl;
    }
};

class Parahod : public Ship {
    int power;
public:
    Parahod(string n, int p) : Ship(n) {
        this->power = p;
    }
    
    void show() override { // Рекомендуется добавлять override
        Ship::show();
        cout << "Пароход: " << name << ", Мощность: " << power << " л.с." << endl;
    }
};

class Parusnik : public Ship {
protected:
    int sailsArea;
public:
    Parusnik(string n, int sa) : Ship(n) {
        this->sailsArea = sa;
    }
    
    void show() override {
        Ship::show();
        cout << "Парусник: " << name << ", Площадь парусов: " << sailsArea << " кв.м" << endl;
    }
};

class Corvette : public Parusnik {
    int guns;
public:
    Corvette(string n, int sa, int g) : Parusnik(n, sa) {
        this->guns = g;
    }
    
    void show() override {
        Ship::show();
        cout << "Корвет: " << name << ", Площадь парусов: " << sailsArea 
             << " кв.м, Орудий: " << guns << " шт." << endl;
    }
};



int Ship::count = 0;
int main() {
    setlocale(LC_ALL, "");

    Parahod s1("Святой Николай", 1500);
    Parusnik s2("Надежда", 2500);
    Corvette s3("Свирепый", 1800, 24);
    Ship s4("Базовое судно");

    /* s4.show();
    s1.show();
    s2.show();
    s3.show(); */

    Ship* flot[] = { &s1, &s2, &s3, &s4 };

    for (int i = 0; i < size(flot); i++) {
        flot[i]->show();
        cout << endl;
    }

    cout << "Всего кораблей: " << Ship::count << endl;

    return 0;
}