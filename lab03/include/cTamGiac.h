#pragma once
#include "cDiem.h"
// #include <iostream>
// using namespace std;

#define MAX_SIDES 3
#define EPS 1e-8

enum class DangTamGiac {
    KhongPhaiTamGiac, // Không phải tam giác
    Thuong,           // Thường
    Can,              // Cân
    Vuong,            // Vuông
    VuongCan,         // Vuông Cân
    Deu               // Đều
};

class cTamGiac {
    DangTamGiac type{DangTamGiac::KhongPhaiTamGiac};

    cDiem *mpDiem{nullptr};
    double *mpCanh{nullptr};

  public:
    cTamGiac();
    cTamGiac(cTamGiac const &);
    ~cTamGiac();

    void nhap();
    void xuat() const;
    short countCapCanhBangNhau();
    bool isVuong();
    void getDangTamGiac();
    double getChuVi() const;
    double getDienTich() const;
    cTamGiac tinhTien() const;
    cTamGiac quay() const;
    cTamGiac phongTo() const;
    cTamGiac thuNho() const;
};

template <typename Vec> void bubbleSort(Vec &v, int const &n) {
    bool is_swapped{false};

    for (int i{0}; i < n - 1; i++) {
        for (int j{0}; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                double t{v[j]};
                v[j] = v[j + 1];
                v[j + 1] = t;

                is_swapped = true;
            }
        }

        if (!is_swapped)
            break;
    }
}

template <typename Func, typename ArrIn, typename ArrOut>
void calcToHop(Func fn, ArrIn &pIn, ArrOut &pOut, int const &n, int iOut = 0,
               int i = 0) {
    if (i == n - 1)
        return;

    for (int k{i + 1}; k < n; k++) {
        pOut[iOut++] = fn(pIn[i], pIn[k]);
    }

    calcToHop(fn, pIn, pOut, n, iOut, ++i);
}
