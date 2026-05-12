#include "../include/cDate.h"
#include <iostream>

int main() {
    CDate d1, d2;
    cout << "Nhap ngay thu nhat: ";
    cin >> d1;
    cout << d1;

    int n;
    cout << "Them n ngay: ";
    cin >> n;
    cout << d1 + n;

    cout << "Bot n ngay: ";
    cin >> n;
    cout << d2 - n;

    cout << "Nhap ngay thu nhat: ";
    cin >> d2;
    cout << d2;
    cout << "Khoang cach giua 2 ngay: ";
    switch (d1 > d2) {
    case -1:
        cout << d2 - d1;
        break;
    case 0:
        cout << 0;
        break;
    case 1:
        cout << d1 - d2;
        break;
    }
    cout << endl;

    return 0;
}
