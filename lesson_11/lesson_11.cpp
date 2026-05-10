#include <iostream>
#include <numeric>
#include <stdexcept>

class Fraction {
private:
    int num;
    int den;

    void reduce() {
        if (den < 0) {
            num = -num;
            den = -den;
        }
        int g = std::gcd(std::abs(num), den);
        if (g != 0) {
            num /= g;
            den /= g;
        }
    }

public:
    Fraction(int n = 0, int d = 1) : num(n), den(d) {
        if (d == 0) throw std::invalid_argument("Знаменатель не может быть равен 0");
        reduce();
    }

    ~Fraction() {}

    Fraction operator+(const Fraction& other) const {
        return Fraction(num * other.den + other.num * den, den * other.den);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(num * other.den - other.num * den, den * other.den);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(num * other.num, den * other.den);
    }
 
    Fraction operator/(const Fraction& other) const {
        if (other.num == 0) throw std::invalid_argument("Деление на ноль");
        return Fraction(num * other.den, den * other.num);
    }

    void print() const {
        if (den == 1) std::cout << num;
        else std::cout << num << "/" << den << std::endl;
    }
};

int main() {
    Fraction a(3, 4), b(5, 6);
    a.print();
    b.print();
    (a + b).print();
}