#include "../include/PhanSo.hpp"
#include <cstdio>
#include <iostream>
#include <numeric>

using namespace std;

/*
 * @brief Nhập tử (iTu), mẫu (iMau) -> KIỂM TRA, NHẬP LẠI nếu không hợp lệ
 *
 * @return void
 * */
void PhanSo::Nhap() {
    cout << "Nhap tu: ";
    cin >> iTu;
    do {
        cout << "Nhap mau (khac 0): ";
        cin >> iMau;
    } while (iMau == 0);
}

/*
 * @brief Xuất ra màn hình theo định dạng: a/b
 *
 * @return void
 * */
void PhanSo::Xuat() {
    if (iMau == 1) {
        cout << iTu;
    } else {
        printf("%d/%d", iTu, iMau);
    }
    cout << endl;
}

/*
 * @brief Rút gọn phân số dùng UCLN, đảo dấu trừ lên tử nếu phân số âm, bỏ dấu
 * trừ nếu phân số dương
 *
 * @retutn void
 * */
void PhanSo::RutGon() {
    int iUCLN{gcd(iTu, iMau)};
    iTu /= iUCLN;
    iMau /= iUCLN;

    if (iTu * iMau < 0) {
        iTu *= (iTu > 0 ? -1 : 1);
    } else {
        iTu *= (iTu < 0 ? -1 : 1);
    }
    iMau *= (iMau < 0 ? -1 : 1);
}

/*
 * @brief Tính tổng 2 phân số
 *
 * @param ps
 *
 * @return Phân số mới
 * */
PhanSo PhanSo::Tong(PhanSo const &ps) {
    PhanSo kq;

    if (this->iMau == ps.iMau) {
        kq.iTu = this->iTu + ps.iTu;
        kq.iMau = this->iMau;
    } else {
        kq.iTu = this->iTu * ps.iMau + ps.iTu * this->iMau;
        kq.iMau = this->iMau * ps.iMau;
    }

    kq.RutGon();

    return kq;
}

/*
 * @brief Tính hiệu 2 phân số
 *
 * @param ps
 *
 * @return Phân số mới
 * */
PhanSo PhanSo::Hieu(PhanSo const &ps) {
    PhanSo kq;

    if (this->iMau == ps.iMau) {
        kq.iTu = this->iTu - ps.iTu;
        kq.iMau = this->iMau;
    } else {
        kq.iTu = this->iTu * ps.iMau - ps.iTu * this->iMau;
        kq.iMau = this->iMau * ps.iMau;
    }

    kq.RutGon();

    return kq;
}

/*
 * @brief Tính tích 2 phân số
 *
 * @param ps
 *
 * @return Phân số mới
 * */
PhanSo PhanSo::Tich(PhanSo const &ps) {
    PhanSo kq;

    kq.iTu = this->iTu * ps.iTu;
    kq.iMau = this->iMau * ps.iMau;

    kq.RutGon();

    return kq;
}

/*
 * @brief Tính thương 2 phân số
 *
 * @param ps
 *
 * @return Phân số mới; phân số mới bằng 0 nếu xảy ra phép chia cho 0
 * */
PhanSo PhanSo::Thuong(PhanSo const &ps) {
    PhanSo kq;

    if (ps.iTu != 0) {
        kq.iTu = this->iTu * ps.iMau;
        kq.iMau = this->iMau * ps.iTu;

        kq.RutGon();
    } else {
        cout << "Phép chia cho ";
        kq.iTu = 0;
        kq.iMau = 1;
    }

    return kq;
}

/*
 * @brief So sánh 2 phân số
 *
 * @param ps
 *
 * @return 1(Lớn hơn), -1(Nhỏ hơn), 0(Bằng nhau)
 * */
int PhanSo::SoSanh(PhanSo const &ps) {
    int kq{0};

    int delta{this->iTu * ps.iMau - ps.iTu * this->iMau};

    if (delta > 0) {
        kq = 1;
    } else if (delta < 0) {
        kq = -1;
    }

    return kq;
}
