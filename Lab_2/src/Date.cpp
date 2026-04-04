#include "../include/Date.hpp"
#include <iostream>

using namespace std;

void Date::Nhap() {
    int iNgay, iThang, iNam;
    cout << "Nhap ngay: ";
    cin >> iNgay;
    cout << "Nhap thang: ";
    cin >> iThang;
    cout << "Nhap nam: ";
    cin >> iNam;

    cout << iNgay << iThang << iNam << endl;
}
void Date::Xuat() {}

Date Date::NgayThangNamTiepTheo(const Date &d) {
    Date res;
    return res;
}
