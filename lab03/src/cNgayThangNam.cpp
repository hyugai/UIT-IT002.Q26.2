#include "../include/cNgayThangNam.h"
#include <cstdio>
#include <iostream>

using namespace std;

/* *
 * @brief Nhập ngày tháng năm
 * @return void
 * */
void cNgayThangNam::nhap() {
    do {
        cout << "Nhap nam (lon hon 0): ";
        cin >> mNam;
    } while (mNam <= 0);

    do {
        cout << "Nhap thang (duong, nho hon 13): ";
        cin >> mThang;
    } while (mThang < 1 || mThang > 12);

    do {
        cout << "Nhap ngay: ";
        cin >> mNgay;
    } while (mNgay < 0 || mNgay > countSoNgayTrongThang());
}

/* *
 * @brief Xuất ra màn hình ngày tháng năm theo định dạng dd-mm-yyyy
 * @return void
 * */
void cNgayThangNam::xuat() const { printf("%2d-%2d-%4d", mNgay, mThang, mNam); }

/* *
 * @brief Đếm số ngày tối đa trong tháng
 * @return int Trả về số ngày tối đa trong tháng
 * */
int cNgayThangNam::countSoNgayTrongThang() const {
    switch (mThang) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    default:
        return (isNamNhuan() ? 29 : 28);
    }
}

/* *
 * @brief Kiểm tra năm nhuận nếu chia hết cho 400 HOẶC chia hết cho 4 nhưng
 * không chia hết cho 100
 *
 * @return bool true(Là năm nhuận), false(Ngược lại)
 * */
bool cNgayThangNam::isNamNhuan() const {
    if (!(mNam % 400) || (!(mNam % 4) && mNam % 100))
        return true;
    else
        return false;
}

/* *
 * @brief So sánh năm sinh
 * @param cNgayThangNam Năm cần so sánh
 * @return int -1(Nhỏ hơn), 0(Bằng tuổi), 1(Lớn hơn)
 * */
int cNgayThangNam::compareTuoi(cNgayThangNam const &date) const {
    if (mNam < date.mNam)
        return 1;
    else if (mNam > date.mNam)
        return -1;

    if (mThang < date.mThang)
        return 1;
    else if (mThang > date.mThang)
        return -1;

    if (mNgay < date.mNgay)
        return 1;
    else if (mNgay > date.mNgay)
        return -1;

    return 0;
}
