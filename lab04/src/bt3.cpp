#include "../include/cTime.h"
#include <iostream>

using namespace std;

int main() {
    CTime t;
    cin >> t;
    cout << t;

    int giayCount;
    cout << "Nhap so giay cong: ";
    cin >> giayCount;
    cout << t + giayCount;

    cout << "Nhap so giay tru: ";
    cin >> giayCount;
    cout << t - giayCount;

    return 0;
}
