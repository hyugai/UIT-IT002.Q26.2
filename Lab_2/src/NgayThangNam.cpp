#include "../include/NgayThangNam.hpp"
#include <cstdio>
#include <iostream>

using namespace std;

/*
 * @brief Nhập năm (iNam), tháng (iThang), ngày (iNgay) -> KIỂM TRA, NHẬP LẠI
 * nếu không hợp lệ
 * @return void
 * */
void NgayThangNam::Nhap() {
    do {
        cout << "Nhap nam (khac 0): ";
        cin >> iNam;
    } while (!KiemTraNam(iNam));

    do {
        cout << "Nhap thang (tu 1 den 12): ";
        cin >> iThang;
    } while (!KiemTraThang(iThang));

    do {
        printf("Nhap ngay duong va khong lon hon %d: ",
               GetSoNgay(iThang, iNam));
        cin >> iNgay;
    } while (!KiemTraNgay(iNgay, iThang, iNam));
}

/*
 * @brief Xuất ra màn hình theo định dạng: dd/mm/yyyy
 * @return void
 * */
void NgayThangNam::Xuat() { printf("%02d/%02d/%d\n", iNgay, iThang, iNam); }

/*
 * @brief Tính ngày tiếp theo bằng cách tăng ngày lên 1
 * return NgayThangNam
 * */
NgayThangNam NgayThangNam::NgayThangNamTiepTheo() {
    NgayThangNam kq;
    if (++iNgay > GetSoNgay(iThang, iNam)) {
        iNgay = 1;
        if (++iThang > 12) {
            iThang = 1;
            ++iNam;
        }
    }

    kq.iNgay = this->iNgay;
    kq.iThang = this->iThang;
    kq.iNam = this->iNam;

    return kq;
}

/*
 * @brief Xác định tổng số ngày trong tháng
 * @param iThang
 * @param iNam
 * @return 28(Tháng 2, Không nhuận), 29(Tháng 2, Nhuận),
 * 30(Tháng 4,6,9,11), 31(Còn lại)
 * */
int GetSoNgay(const int &iThang, const int &iNam) {
    int kq;

    switch (iThang) {
    case 4:
    case 6:
    case 9:
    case 11:
        kq = 30;
        break;
    case 2:
        kq = (KiemTraNamNhuan(iNam) ? 29 : 28);
        break;
    default:
        kq = 31;
        break;
    }

    return kq;
}

/*
 * @brief Kiểm tra năm nhuận
 * @param iNam
 * @return 1(Nhuận), 0(Không nhuận)
 * */
bool KiemTraNamNhuan(const int &iNam) {
    bool kq{false};

    if (iNam % 4 == 0 && iNam % 100 != 0 || iNam % 400 == 0) {
        kq = true;
    }

    return kq;
}

/*
 * @brief Kiểm tra năm thỏa mãn: dương
 * @param iNam
 * @return 1(Hợp lệ), 0(Không hợp lệ)
 * */
bool KiemTraNam(const int &iNam) {
    bool kq{true};

    if (iNam < 0) {
        kq = false;
    }

    return kq;
}

/*
 * @brief Kiểm tra tháng thỏa mãn: dương, không lớn hơn 12
 * @param iThang
 * @return 1(Hợp lệ), 0(Không hợp lệ)
 * */
bool KiemTraThang(const int &iThang) {
    bool kq{true};

    if (iThang < 1 || iThang > 12) {
        kq = false;
    }

    return kq;
}

/*
 * @brief Kiểm tra ngày thỏa mãn: dương, không lớn hơn tổng số ngày của tháng
 * @param iNgay
 * @param iThang
 * @param iNam
 * @return 1(Hợp lệ), 0(Không hợp lệ)
 * */
bool KiemTraNgay(const int &iNgay, const int &iThang, const int &iNam) {
    bool kq{true};

    if (iNgay > GetSoNgay(iThang, iNam) || iNgay < 1) {
        kq = false;
    }

    return kq;
}
