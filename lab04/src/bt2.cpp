#include "../include/cPhanSo.h"
#include <iostream>

using namespace std;

int main() {
    int tu, mau;

    cout << "Khoi tao phan so dac biet: ";
    cin >> tu;
    cPhanSo A{tu};
    cout << A;

    cout << "Khoi tao phan so thuong: ";
    cin >> tu >> mau;
    cPhanSo B{tu, mau};
    cout << B;

    cout << "Nhap phan so A:\n";
    cin >> A;
    cout << A;
    cout << "Nhap phan so B:\n";
    cin >> B;
    cout << B;

    cout << "So sanh: ";
    if (A == B)
        cout << "A bang B\n";
    if (A > B)
        cout << "A lon hon B\n";
    if (A < B)
        cout << "A nho hon B\n";

    cout << "A+B: " << A + B;
    cout << "A-B: " << A - B;
    cout << "A*B: " << A * B;
    try {
        cout << "A/B: " << A / B;
    } catch (const exception &e) {
        cout << "(Error!) " << e.what() << endl;
    }

    return 0;
}
