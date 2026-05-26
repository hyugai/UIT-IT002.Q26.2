#include "../include/DanhSachGD.h"
#include <iomanip>
#include <istream>
#include <iostream>
#include <ostream>

using namespace std;

DanhSachGD::~DanhSachGD() {
    delete[] mpDat;
    delete[] mpNhaPho;
    delete[] mpCanHoChungCu;
}

int DanhSachGD::getDatCount() const { return mDatCount; }
int DanhSachGD::getNhaPhoCount() const { return mNhaPhoCount; }
int DanhSachGD::getCanHoChungCuCount() const { return mCanHoChungCuCount; }

istream &operator>>(istream &is, DanhSachGD &rhs) {
    do {
        is >> rhs.mDatCount;
    } while (rhs.mDatCount <= 0);

    do {
        is >> rhs.mNhaPhoCount;
    } while (rhs.mNhaPhoCount <= 0);

    do {
        is >> rhs.mCanHoChungCuCount;
    } while (rhs.mCanHoChungCuCount <= 0);

    delete[] rhs.mpDat;
    delete[] rhs.mpNhaPho;
    delete[] rhs.mpCanHoChungCu;
    rhs.mpDat = new GDDat[rhs.mDatCount];
    rhs.mpNhaPho = new GDNhaPho[rhs.mNhaPhoCount];
    rhs.mpCanHoChungCu = new GDCanHoChungCu[rhs.mCanHoChungCuCount];

    for (int i{0}; i < rhs.mDatCount; ++i)
        is >> rhs.mpDat[i];

    for (int i{0}; i < rhs.mNhaPhoCount; ++i)
        is >> rhs.mpNhaPho[i];

    for (int i{0}; i < rhs.mCanHoChungCuCount; ++i)
        is >> rhs.mpCanHoChungCu[i];

    return is;
}

ostream &operator<<(ostream &os, DanhSachGD const &rhs) {
    os << "Danh dach giao dich Dat:\n";
    for (int i{0}; i < rhs.mDatCount; ++i)
        os << fixed << setprecision(2) << rhs.mpDat[i] << endl;

    os << "Danh dach giao dich Nha pho:\n";
    for (int i{0}; i < rhs.mNhaPhoCount; ++i)
        os << fixed << setprecision(2) << rhs.mpNhaPho[i] << endl;

    os << "Danh dach giao dich Can ho chung cu:\n";
    for (int i{0}; i < rhs.mCanHoChungCuCount; ++i)
        os << rhs.mpCanHoChungCu[i] << endl;

    return os;
}

void DanhSachGD::calcThanhTienGD() {
    for (int i{0}; i < mDatCount; ++i)
        mpDat[i].calcThanhTien();

    for (int i{0}; i < mNhaPhoCount; ++i)
        mpNhaPho[i].calcThanhTien();

    for (int i{0}; i < mCanHoChungCuCount; ++i)
        mpCanHoChungCu[i].calcThanhTien();
}

double DanhSachGD::calcAvgThanhTienCanHoChungCu() const {
    double res;

    for (int i{0}; i < mCanHoChungCuCount; ++i)
        res += mpCanHoChungCu[i].getThanhTien();

    return res / mCanHoChungCuCount;
}

GDNhaPho DanhSachGD::findMaxThanhTienNhaPho() const {
    GDNhaPho res{mpNhaPho[0]};

    for (int i{1}; i < mNhaPhoCount; ++i) {
        if (mpNhaPho[i].getThanhTien() > res.getThanhTien())
            res = mpNhaPho[i];
    }

    return res;
}

void DanhSachGD::findGD(int const &m, int const &y, ostream &os) const {
    for (int i{0}; i < mDatCount; ++i) {
        if (mpDat[i].getNgayGD().getThang() == m &&
            mpDat[i].getNgayGD().getNam() == y)
            os << mpDat[i] << endl << endl;
    }

    for (int i{0}; i < mNhaPhoCount; ++i) {
        if (mpNhaPho[i].getNgayGD().getThang() == m &&
            mpNhaPho[i].getNgayGD().getNam() == y)
            os << mpNhaPho[i] << endl << endl;
    }

    for (int i{0}; i < mCanHoChungCuCount; ++i) {
        if (mpCanHoChungCu[i].getNgayGD().getThang() == m &&
            mpCanHoChungCu[i].getNgayGD().getNam() == y)
            os << mpCanHoChungCu[i] << endl << endl;
    }
}
