#include "../include/CMatrix.h"
#include <exception>
#include <iostream>

using namespace std;

int main() {
    CMatrix A, B;

    cout << "Nhap ma tran A:\n";
    cin >> A;
    cout << A;

    cout << "Nhap ma tran B:\n";
    cin >> B;
    cout << B;

    cout << "Tong 2 ma tran A+B:\n";
    try {
        cout << A + B;
    } catch (exception const &e) {
        cout << e.what() << endl;
    }

    cout << "Hieu 2 ma tran A-B:\n";
    try {
        cout << A - B;
    } catch (exception const &e) {
        cout << e.what() << endl;
    }

    cout << "Tich 2 ma tran AxB:\n";
    try {
        cout << A * B;
    } catch (exception const &e) {
        cout << e.what() << endl;
    }

    cout << "Nhap vector V:\n";
    CVector v;
    cin >> v;

    cout << "Tich ma tran va vecto AxV:\n";
    try {
        cout << A * v;
    } catch (exception const &e) {
        cout << e.what() << endl;
    }

    return 0;
}
