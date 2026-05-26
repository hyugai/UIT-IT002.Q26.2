#include "../include/DanhSachNV.h"
#include <iomanip>
#include <ostream>

// Destructor
DanhSachNV::~DanhSachNV() {
    delete[] mpLapTrinh;
    delete[] mpKiemChung;
}

/* *
 * @brief Overload operator
 * @param is
 * @param rhs
 * @return istream &
 * */
istream &operator>>(istream &is, DanhSachNV &rhs) {
    is >> rhs.mLapTrinhCount >> rhs.mKiemChungCount;

    delete[] rhs.mpLapTrinh;
    rhs.mpLapTrinh = new NVLapTrinh[rhs.mLapTrinhCount];
    for (int i{0}; i < rhs.mLapTrinhCount; ++i)
        is >> rhs.mpLapTrinh[i];

    delete[] rhs.mpKiemChung;
    rhs.mpKiemChung = new NVKiemChung[rhs.mKiemChungCount];
    for (int i{0}; i < rhs.mKiemChungCount; ++i)
        is >> rhs.mpKiemChung[i];

    return is;
}

/* *
 * @brief Overload operator
 * @param os
 * @param rhs
 * @return ostream &
 * */
ostream &operator<<(ostream &os, DanhSachNV const &rhs) {
    os << "Danh sach lap trinh vien:\n";
    for (int i{0}; i < rhs.mLapTrinhCount; ++i)
        os << rhs.mpLapTrinh[i] << endl;

    os << "Danh sach kiem chung vien:\n";
    for (int i{0}; i < rhs.mKiemChungCount; ++i)
        os << rhs.mpKiemChung[i] << endl;

    return os;
}

/* *
 * @brief Tính lương cho các nhân viên
 * @param void
 * @return void
 * */
void DanhSachNV::calcLuong() {
    for (int i{0}; i < mLapTrinhCount; ++i)
        mpLapTrinh[i].calcLuong();

    for (int i{0}; i < mKiemChungCount; ++i)
        mpKiemChung[i].calcLuong();
}

/* *
 * @brief Tìm các nhân viên có mức lương thấp hơn mức lương trung bình
 * @param os
 * @return void
 * */
void DanhSachNV::findNVLuongThapHonTrungBinh(ostream &os) const {
    double avgLuong{0};
    for (int i{0}; i < mLapTrinhCount; ++i)
        avgLuong += mpLapTrinh[i].getLuong();

    for (int i{0}; i < mKiemChungCount; ++i)
        avgLuong += mpKiemChung[i].getLuong();

    avgLuong /= (mLapTrinhCount + mKiemChungCount);
    os << "Muc luong trung binh: " << fixed << setprecision(3) << avgLuong
       << endl;

    for (int i{0}; i < mLapTrinhCount; ++i) {
        if (mpLapTrinh[i].getLuong() < avgLuong)
            os << mpLapTrinh[i] << endl;
    }

    for (int i{0}; i < mKiemChungCount; ++i) {
        if (mpKiemChung[i].getLuong() < avgLuong)
            os << mpKiemChung[i] << endl;
    }
}

/* *
 * @brief Tìm nhân viên có lương cao nhất
 * @param os
 * @return void
 * */
void DanhSachNV::findNVMaxLuong(ostream &os) const {
    NVLapTrinh resLT{findNVLapTrinhMaxLuong()};

    NVKiemChung resKC{mpKiemChung[0]};
    for (int i{1}; i < mKiemChungCount; ++i) {
        if (mpKiemChung[i].getLuong() > resKC.getLuong())
            resKC = mpKiemChung[i];
    }

    if (resLT.getLuong() > resKC.getLuong())
        os << resLT;
    else
        os << resKC;
}

/* *
 * @brief Tìm nhân viên có lương thấp nhất
 * @param os
 * @return void
 * */
void DanhSachNV::findNVMinLuong(ostream &os) const {
    NVLapTrinh resLT{mpLapTrinh[0]};
    for (int i{1}; i < mLapTrinhCount; ++i) {
        if (mpLapTrinh[i].getLuong() < resLT.getLuong())
            resLT = mpLapTrinh[i];
    }

    NVKiemChung resKC{findNVKiemChungMinLuong()};

    if (resLT.getLuong() < resKC.getLuong())
        os << resLT;
    else
        os << resKC;
}

/* *
 * @brief Tìm lập trình viên có lương cao nhất
 * @param void
 * @return NVLapTrinh
 * */
NVLapTrinh DanhSachNV::findNVLapTrinhMaxLuong() const {
    NVLapTrinh res{mpLapTrinh[0]};

    for (int i{1}; i < mLapTrinhCount; ++i) {
        if (mpLapTrinh[i].getLuong() > res.getLuong())
            res = mpLapTrinh[i];
    }

    return res;
}

/* *
 * @brief Tìm kiểm chứng có lương cao nhất
 * @param void
 * @return NVKiemChung
 * */
NVKiemChung DanhSachNV::findNVKiemChungMinLuong() const {
    NVKiemChung res{mpKiemChung[0]};
    for (int i{1}; i < mKiemChungCount; ++i) {
        if (mpKiemChung[i].getLuong() < res.getLuong())
            res = mpKiemChung[i];
    }

    return res;
}
