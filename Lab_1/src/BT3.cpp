#include "../include/fraction.hpp"
#include <iostream>

using namespace std;

int main() {
    MyFraction f1, f2;
    cout << "Enter 1st fraction: " << endl;
    cin >> f1;
    cout << "Enter 2nd fraction:" << endl;
    cin >> f2;

    cout << "Add: " << f1 + f2 << endl;
    cout << "Sub: " << f1 - f2 << endl;
    cout << "Mul: " << f1 * f2 << endl;
    cout << "Div: " << f1 / f2 << endl;

    return 0;
}
