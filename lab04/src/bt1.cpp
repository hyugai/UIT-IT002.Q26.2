#include "../include/cSoPhuc.h"
#include <exception>
#include <iostream>

using namespace std;

int main() {
    double thuc, ao;

    cout << "Khoi tao so phuc dac biet (so thuc): ";
    cin >> thuc;
    cSoPhuc A{thuc};
    cout << A;

    cout << "Khoi tao so phuc:" << endl;
    cout << "Nhap phan thuc, ao: ";
    cin >> thuc >> ao;
    cSoPhuc B{thuc, ao};
    cout << B;

    cout << "Nhap so phuc A:\n";
    cin >> A;
    cout << A;
    cout << "Nhap so phuc B:\n";
    cin >> B;
    cout << B;

    cout << "So sanh: ";
    if (A == B)
        cout << "A bang B\n";
    if (A != B)
        cout << "A khac B\n";

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
