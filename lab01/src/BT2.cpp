#include "../include/fraction.hpp"
#include <iostream>

using namespace std;

int main() {
    MyFraction f1, f2;
    cout << "Nhap phan so dau tien" << endl;
    cin >> f1;
    cout << "Nhap phan so thu hai" << endl;
    cin >> f2;

    cout << "Phan so lon hon: ";
    if (f1 > f2) {
        cout << f1;
    } else {
        cout << f2;
    }

    return 0;
}
