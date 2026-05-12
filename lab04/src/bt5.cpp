#include "../include/cDaThuc.h"
#include <iostream>

using namespace std;

int main() {
    cDaThuc A, B;

    cout << "Nhap da thuc A:\n";
    cin >> A;
    cout << A;

    cout << "Nhap da thuc B:\n";
    cin >> B;
    cout << B;

    cout << "A + B =" << A + B;
    cout << "A - B =" << A - B;

    return 0;
}
