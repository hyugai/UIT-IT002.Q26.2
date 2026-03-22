#include "../include/fraction.hpp"
#include <iostream>

using namespace std;

int main() {
    MyFraction f1, f2;
    cout << "Enter 1st fraction: " << endl;
    cin >> f1;
    cout << "Enter 2nd fraction:" << endl;
    cin >> f2;

    cout << "Greater fraction: ";
    if (f1 > f2) {
        cout << f1;
    } else {
        cout << f2;
    }

    return 0;
}
