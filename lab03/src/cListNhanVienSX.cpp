#include "../include/cListNhanVienSX.h"
#include <iostream>

using namespace std;

// Destructor
cListNhanVienSX::~cListNhanVienSX() { delete[] mpNhanVienSX; }

/* *
 * @brief Nhập vào danh sách n nhân viên
 * @return void
 * */
void cListNhanVienSX::nhap() {
    do {
        cout << "Nhap so luong nhan vien (lon hon 0): ";
        cin >> mSoNhanVien;
    } while (mSoNhanVien < 1);

    delete[] mpNhanVienSX;

    mpNhanVienSX = new cNhanVienSX[mSoNhanVien];

    for (int i{0}; i < mSoNhanVien; i++) {
        mpNhanVienSX[i].nhap();
        cout << endl;
    }
}

/* *
 * @brief In ra màn hình danh sách nhân viên
 * @return void
 * */
void cListNhanVienSX::xuat() const {
    cout << "id,ho_ten,ngay_sinh,so_san_pham_gia_cong,gia_mot_san_pham\n";
    for (int i{0}; i < mSoNhanVien; i++) {
        mpNhanVienSX[i].xuat();
    }
}

/* *
 * @brief Tìm nhân viên lương thấp nhất
 * @return cNhanVienSX Trả về nhân viên có lương thấp nhất
 * */
cNhanVienSX cListNhanVienSX::findNhanVienLuongThapNhat() const {
    cNhanVienSX kq{mpNhanVienSX[0]};

    for (int i{0}; i < mSoNhanVien; i++) {
        if (mpNhanVienSX[i].calcLuong() < kq.calcLuong()) {
            kq = mpNhanVienSX[i];
        }
    }

    return kq;
}

/* *
 * @brief Tính tổng lương công ty phải phát cho nhân viên
 * @return double Trả về tổng lương cần phát
 * */
double cListNhanVienSX::calcTongLuong() const {
    double kq{0};

    for (int i{0}; i < mSoNhanVien; i++)
        kq += mpNhanVienSX[i].calcLuong();

    return 0;
}

/* *
 * @brief Tìm nhân viên có số tuổi cao nhất
 * @return cNhanVienSX Trả về nhân viên có số tuổi cao nhất
 * */
cNhanVienSX cListNhanVienSX::findNhanVienCaoTuoiNhat() const {
    cNhanVienSX kq{mpNhanVienSX[0]};

    for (int i{1}; i < mSoNhanVien; i++) {
        if (mpNhanVienSX[i].getNgaySinh().compareTuoi(kq.getNgaySinh()) > 0) {
            kq = mpNhanVienSX[i];
        }
    }

    return kq;
}

/* *
 * @brief Sắp xếp nhân viên theo lương tăng dần
 * @return void
 * */
void cListNhanVienSX::sortNhanVienTheoLuong() {
    for (int i{0}; i < mSoNhanVien - 1; i++) {
        for (int j{0}; j < mSoNhanVien - i - 1; j++) {
            cNhanVienSX t{mpNhanVienSX[j]};
            if (mpNhanVienSX[j].calcLuong() > mpNhanVienSX[j + 1].calcLuong()) {
                mpNhanVienSX[j] = mpNhanVienSX[j + 1];
                mpNhanVienSX[j + 1] = t;
            }
        }
    }
}
