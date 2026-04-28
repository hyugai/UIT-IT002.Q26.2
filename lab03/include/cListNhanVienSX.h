#pragma once
#include "cNhanVienSX.h"

class cListNhanVienSX {
    int mSoNhanVien;
    cNhanVienSX *mpNhanVienSX{nullptr};

    /*
     * @brief Kiểm tra ID có bị trùng không
     * @return bool true(Trùng), false(Không trùng)
     * */
    bool isTrungId(int i) {
        for (int j{0}; j < i; j++) {
            if (mpNhanVienSX[j].getId() == mpNhanVienSX[i].getId()) {
                return true;
            }
        }

        return false;
    }

  public:
    ~cListNhanVienSX();

    void nhap();
    void xuat() const;
    cNhanVienSX findNhanVienLuongThapNhat() const;
    double calcTongLuong() const;
    cNhanVienSX findNhanVienCaoTuoiNhat() const;
    void sortNhanVienTheoLuong();
};
