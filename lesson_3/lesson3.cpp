#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "");
    double x, y;
    bool f;

    cout << "Enter (x and y): ";
    cin >> x >> y;

    bool insq = (x >= 0 && x <= 1 && y >= 0 && y <= 1);

    bool intg = (x >= 2 && y >= 0 && y <= -x + 4);

    f = insq || intg;

    cout << "res: " << f << endl;
    return 0;
}