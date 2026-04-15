#include "../include/SoPhuc.hpp"
#include <cmath>
#include <iostream>

using namespace std;

/*
 * @brief Nhập vào phần thực (iThuc) và ảo (iAo) của số phức
 * @return void
 * */
void SoPhuc::Nhap() {
    cout << "Nhap phan thuc: ";
    cin >> iThuc;
    cout << "Nhap phan ao: ";
    cin >> iAo;
}
/*
 * @brief Xuất ra màn hình theo định dạng: a + bi
 * return void
 * */
void SoPhuc::Xuat() {
    if (iThuc != 0) {
        cout << iThuc;
    }
    if (iAo != 0) {
        if (iThuc != 0) {
            cout << " + ";
        }
        cout << "(" << iAo << ")" << "i";
    }
    if (!iThuc && !iAo) {
        cout << 0;
    }
    cout << endl;
}
/*
 * @brief Tính tổng 2 số phức
 * @param sp
 * @return Số phức mới
 * */
SoPhuc SoPhuc::Tong(SoPhuc const &sp) {
    SoPhuc kq;
    kq.iThuc = this->iThuc + sp.iThuc;
    kq.iAo = this->iAo + sp.iAo;
    return kq;
}
/*
 * @brief Tính hiệu 2 số phức
 * @param sp
 * @return Số phức mới
 * */
SoPhuc SoPhuc::Hieu(SoPhuc const &sp) {
    SoPhuc kq;
    kq.iThuc = this->iThuc - sp.iThuc;
    kq.iAo = this->iAo - sp.iAo;
    return kq;
}
/*
 * @brief Tính tích 2 số phức
 * @param sp
 * @return Số phức mới
 * */
SoPhuc SoPhuc::Tich(SoPhuc const &sp) {
    SoPhuc kq;
    kq.iThuc = this->iThuc * sp.iThuc - this->iAo * sp.iAo;
    kq.iAo = this->iThuc * sp.iAo + this->iAo * sp.iThuc;
    return kq;
}
/*
 * @brief Tính thương 2 số phức
 * @param sp
 * @return Số phức mới
 * */
SoPhuc SoPhuc::Thuong(SoPhuc const &sp) {
    SoPhuc kq;
    double dMau{(pow(sp.iThuc, 2) + pow(sp.iAo, 2))};
    if (dMau != 0) {
        kq.iThuc = (this->iThuc * sp.iThuc + this->iAo * sp.iAo) / dMau;
        kq.iAo = (this->iAo * sp.iThuc - this->iThuc * sp.iAo) / dMau;
    } else {
        cout << "Phép chia cho ";
        kq.iThuc = 0;
        kq.iAo = 0;
    }
    return kq;
}
