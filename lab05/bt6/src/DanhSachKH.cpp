#include "../include/DanhSachKH.h"

// Destructor
DanhSachKH::~DanhSachKH() {
    delete[] mpA;
    delete[] mpB;
    delete[] mpC;
}

/* *
 * @brief Overload operator
 * @param is
 * @param rhs
 * @return istream &
 * */
istream &operator>>(istream &is, DanhSachKH &rhs) {
    do {
        is >> rhs.mACount;
    } while (rhs.mACount <= 0 || rhs.mACount >= 1000);

    do {
        is >> rhs.mBCount;
    } while (rhs.mBCount <= 0 || rhs.mBCount >= 1000);

    do {
        is >> rhs.mCCount;
    } while (rhs.mCCount <= 0 || rhs.mCCount >= 1000);

    delete[] rhs.mpA;
    rhs.mpA = new KHLoaiA[rhs.mACount];
    for (int i{0}; i < rhs.mACount; ++i)
        is >> rhs.mpA[i];

    delete[] rhs.mpB;
    rhs.mpB = new KHLoaiB[rhs.mBCount];
    for (int i{0}; i < rhs.mBCount; ++i)
        is >> rhs.mpB[i];

    delete[] rhs.mpC;
    rhs.mpC = new KHLoaiC[rhs.mCCount];
    for (int i{0}; i < rhs.mCCount; ++i)
        is >> rhs.mpC[i];

    return is;
}

/* *
 * @brief Overload operator
 * @param os
 * @param rhs
 * @return ostream &
 * */
ostream &operator<<(ostream &os, DanhSachKH const &rhs) {
    os << rhs.mACount << ' ' << rhs.mBCount << ' ' << rhs.mCCount << endl;

    for (int i{0}; i < rhs.mACount; ++i)
        os << rhs.mpA[i];

    for (int i{0}; i < rhs.mBCount; ++i)
        os << rhs.mpB[i];

    for (int i{0}; i < rhs.mCCount; ++i)
        os << rhs.mpC[i];

    return os;
}

/* *
 * @brief Tính thành tiền cho khách hàng
 * @param void
 * @return void
 * */
void DanhSachKH::calcThanhTien() {
    for (int i{0}; i < mACount; ++i)
        mpA[i].calcThanhTien();

    for (int i{0}; i < mBCount; ++i)
        mpB[i].calcThanhTien();

    for (int i{0}; i < mCCount; ++i)
        mpC[i].calcThanhTien();
}
