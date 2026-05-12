#include "../include/CVector.h"
#include <iostream>

using namespace std;

int main() {
    CVector A, B;
    cout << "Nhap vector A\u1D40:\n";
    cin >> A;
    cout << A;

    cout << "Nhap vector B\u1D40:\n";
    cin >> B;
    cout << B;

    if (A.getSoChieu() == B.getSoChieu()) {
        cout << "A\u1D40 + B\u1D40 = " << A + B;
        cout << "A\u1D40 - B\u1D40 = " << A - B;
        cout << "A\u1D40 * B\u1D40 = " << A * B << endl;
    } else
        cout << "A\u1D40 va B\u1D40 khong cung kich thuoc!\n";

    return 0;
}
