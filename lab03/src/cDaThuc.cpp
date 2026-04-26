#include "../include/cDaThuc.h"
#include <iostream>

using namespace std;

// Defaulted Constructor: Khởi tạo đa thức với bậc bằng 0
cDaThuc::cDaThuc() {
    mBac = 0;

    if (mpSoHang)
        delete[] mpSoHang;
    mpSoHang = new cSoHang[1];
    mpSoHang[0] = cSoHang{mBac, 0};
}

// Parameterized Constructor: Khởi tạo đa thức với bậc n
cDaThuc::cDaThuc(int n) : mBac(n) {
    if (mpSoHang)
        delete[] mpSoHang;
    mpSoHang = new cSoHang[mBac + 1];

    for (int i{0}; i <= mBac; i++) {
        double t;
        cout << "Nhap he so cho so hang bac " << i << ": ";
        cin >> t;
        mpSoHang[i] = cSoHang{i, t};
    }
}

// Destructor
cDaThuc::~cDaThuc() {
    if (mpSoHang)
        delete[] mpSoHang;
}

/* *
 * @brief Thiết lập lại đa thức với số bậc mới
 * @return void
 * */
void cDaThuc::setBac(int const &n) {
    mBac = n;

    if (mpSoHang)
        delete[] mpSoHang;
    mpSoHang = new cSoHang[mBac + 1];
}

/* *
 * @brief Nhập đa thức bậc n
 * @return void
 * */
void cDaThuc::nhap() {
    do {
        cout << "Nhan bac cao nhat cua da thuc (so khong am): ";
        cin >> mBac;
    } while (mBac < 0);

    if (mpSoHang)
        delete[] mpSoHang;
    mpSoHang = new cSoHang[mBac + 1];

    for (int i{0}; i <= mBac; i++) {
        double t;
        cout << "Nhap he so cho so hang bac " << i << ": ";
        cin >> t;
        mpSoHang[i] = cSoHang{i, t};
    }
}

/* *
 * @brief In ra màn hình đa thức bậc n
 * @return void
 * */
void cDaThuc::xuat() const {
    mpSoHang[mBac].xuatSoHangDauTien();
    for (int i{mBac - 1}; i >= 0; i--) {
        mpSoHang[i].xuat();
    }
    cout << endl;
}

/* *
 * @brief Cộng 2 đa thức
 * @return cDaThuc Kết quả của phép cộng 2 đa thức
 * */
cDaThuc cDaThuc::addDaThuc(cDaThuc const &rhs) const {
    cDaThuc kq;

    int maxBac{mBac > rhs.mBac ? mBac : rhs.mBac};
    kq.setBac(maxBac);

    for (int i{0}; i <= maxBac; i++) {
        double heSo1{mBac >= i ? mpSoHang[i].getHeSo() : 0};
        double heSo2{rhs.mBac >= i ? rhs.mpSoHang[i].getHeSo() : 0};

        kq.mpSoHang[i] = cSoHang{i, heSo1 + heSo2};
    }

    return kq;
}

/* *
 * @brief Trừ 2 đa thức
 * @return cDaThuc Kết quả của phép trừ 2 đa thức
 * */
cDaThuc cDaThuc::subDaThuc(cDaThuc const &rhs) const {
    cDaThuc kq;

    int maxBac{mBac > rhs.mBac ? mBac : rhs.mBac};
    kq.setBac(maxBac);

    for (int i{0}; i <= maxBac; i++) {
        double heSoLhs{mBac >= i ? mpSoHang[i].getHeSo() : 0};
        double heSoRhs{rhs.mBac >= i ? rhs.mpSoHang[i].getHeSo() : 0};

        kq.mpSoHang[i] = cSoHang{i, heSoLhs - heSoRhs};
    }

    return kq;
}

/* *
 * @brief Tính giá trị của đa thức khi biết số hạng x
 * @param x Giá trị của x
 * @return double Trả về giá trị của đa thức khi thay x vào
 * */
double cDaThuc::calcDaThuc(double const &x) const {
    double kq{0};
    for (int i{0}; i <= mBac; i++) {
        kq += mpSoHang[i].calcSoHang(x);
    }

    return kq;
}
