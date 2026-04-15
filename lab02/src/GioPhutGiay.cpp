#include "../include/GioPhutGiay.hpp"
#include <cstdio>
#include <iostream>

using namespace std;

/*
 * @brief Nhập giờ (iGio), phút (iPhut), giây (iGiay) -> KIỂM TRA, NHẬP LẠI nếu
 * không hợp lệ
 * @return void
 * */
void GioPhutGiay::Nhap() {
    do {
        cout << "Nhap gio (tu 0 den 23): ";
        cin >> iGio;
    } while (!KiemTraGio(iGio));

    do {
        cout << "Nhap phut (tu 0 den 59): ";
        cin >> iPhut;
    } while (!KiemTraPhutGiay(iPhut));

    do {
        cout << "Nhap giay (tu 0 den 59): ";
        cin >> iGiay;
    } while (!KiemTraPhutGiay(iGiay));
}
/*
 * @brief Xuất ra màn hình theo định dạng: hh:mm:ss
 * @return void
 * */
void GioPhutGiay::Xuat() { printf("%02d:%02d:%02d\n", iGio, iPhut, iGiay); }
/*
 * @brief Tính mốc thời gian ở 1 giây tiếp theo
 * @return Mốc thời gian mới
 * */
GioPhutGiay GioPhutGiay::TinhCongThemMotGiay() {
    GioPhutGiay kq;

    if (++iGiay == 60) {
        iGiay = 0;
        if (++iPhut == 60) {
            iPhut = 0;
            if (++iGio == 24) {
                iGio = 0;
            }
        }
    }
    kq.iGio = this->iGio;
    kq.iPhut = this->iPhut;
    kq.iGiay = this->iGiay;

    return kq;
}

/*
 * @brief Kiểm tra giờ thỏa mãn: dương, không lớn hơn 23
 * @param t
 * @return 1(Hợp lệ), 0(Không hợp lệ)
 * */
bool KiemTraGio(const int &t) {
    bool kq{true};

    if (t < 0 || t > 23) {
        kq = false;
    }

    return kq;
}
/*
 * @brief Kiểm tra phút/giây thỏa mãn: dương, không lớn hơn 59
 * @param t
 * @return 1(Hợp lệ), 0(Không hợp lệ)
 * */
bool KiemTraPhutGiay(const int &t) {
    bool kq{true};

    if (t < 0 || t > 59) {
        kq = false;
    }

    return kq;
}
