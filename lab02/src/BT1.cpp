#include "../include/NgayThangNam.hpp"
#include <iostream>
using namespace std;
int main() {
    NgayThangNam d;
    d.Nhap();
    /* Mốc thời gian hiện tại */
    cout << "\nNgay thang nam hien tai: ";
    d.Xuat();
    /* Ngày tiếp theo */
    NgayThangNam next_d{d.NgayThangNamTiepTheo()};
    cout << "Ngay thang nam tiep theo: ";
    next_d.Xuat();
    return 0;
}
