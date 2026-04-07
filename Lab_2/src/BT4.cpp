#include "../include/GioPhutGiay.hpp"
#include <iostream>

using namespace std;

int main() {
    /* Nhập thời gian */
    GioPhutGiay t;
    t.Nhap();

    /* Xuất ra thời gian hiện tại*/
    cout << "\nThoi gian hien tai: ";
    t.Xuat();

    /* Xuất ra thời gian sau 1s*/
    GioPhutGiay t_next{t.TinhCongThemMotGiay()};
    cout << "Sau 1s: ";
    t_next.Xuat();

    return 0;
}
