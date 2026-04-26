#include "../include/cSoHang.h"
#include <cmath>
#include <iostream>

using namespace std;

//
cSoHang::cSoHang() {}

//
cSoHang::cSoHang(int bac, double heSo) : mBac(bac), mHeSo(heSo) {}

//
cSoHang::cSoHang(cSoHang const &givenSoHang)
    : mBac(givenSoHang.mBac), mHeSo(givenSoHang.mHeSo) {}

//
int cSoHang::getBac() const { return mBac; }
double cSoHang::getHeSo() const { return mHeSo; }

/* *
 * @brief Nhập bậc và hệ số cho số hạng
 * @return void
 * */
void cSoHang::nhap() {
    cout << "Nhap bac: ";
    cin >> mBac;

    cout << "Nhap he so: ";
    cin >> mHeSo;
}

/* *
 * @brief In ra màn hình số hạng
 * @return void
 * */
void cSoHang::xuat() const {
    if (fabs(mHeSo) == 1) // Hệ số bằng 1 thì không in ra 1
        cout << (mHeSo > 0 ? " + " : " - ");
    else if (mHeSo) // Hệ số khác 0
        cout << (mHeSo > 0 ? " + " : " - ") << fabs(mHeSo);

    if (mHeSo) { // Chỉ in ra số hạng nếu hệ số khác 0
        if (mBac == 1)
            cout << "x";
        else if (mBac)
            cout << "x^" << mBac;
        else if (mHeSo == 1)
            cout << fabs(mHeSo);
    }
}
/* *
 * @brief In ra màn hình số hạng đầu tiên
 * @return void
 * */
void cSoHang::xuatSoHangDauTien() const {
    if (fabs(mHeSo) == 1)
        cout << (mHeSo > 0 ? "" : " - ");
    else if (mHeSo)
        cout << mHeSo;
    else
        cout << 0;

    if (mBac == 1)
        cout << "x";
    else if (mBac)
        cout << "x^" << mBac;
}

/* *
 * @brief Tính số hạng khi biết x
 * @param x Giá trị của x
 * @return double Trả về giá trị của số hạng khi thay x vào
 * */
double cSoHang::calcSoHang(double const &x) const {
    return mHeSo * pow(x, mBac);
}
