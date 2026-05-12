#include "../include/cDate.h"
#include <cstdio>
#include <iostream>
#include <istream>
#include <ostream>

using namespace std;

CDate::CDate() {};
CDate::CDate(int ngay, int thang, int nam)
    : mNgay(ngay), mThang(thang), mNam(nam) {};
CDate::CDate(CDate const &d)
    : mNgay(d.mNgay), mThang(d.mThang), mNam(d.mNam) {};

/* *
 * @brief
 * @param
 * @return
 * */
istream &operator>>(istream &is, CDate &rhs) {
    do {
        cout << "Nhap ngay, thang, nam: ";
        is >> rhs.mNgay >> rhs.mThang >> rhs.mNam;
    } while (!rhs.isNgayHopLe());

    return is;
}

/* *
 * @brief
 * @param
 * @return
 * */
ostream &operator<<(ostream &os, CDate const &rhs) {
    printf("%02d-%02d-%d\n", rhs.mNgay, rhs.mThang, rhs.mNam);

    return os;
}

/* *
 * @brief
 * @param
 * @return
 * */
CDate CDate::operator+(int const &n) const {
    int ngay{mNgay + n}, thang{mThang}, nam{mNam};

    while (ngay > countNgayTrongThang(thang, nam)) {
        ngay -= countNgayTrongThang(thang, nam);

        if (++thang > 12) {
            thang = 1;

            ++nam;
        }
    }

    return CDate{ngay, thang, nam};
}

/* *
 * @brief
 * @param
 * @return
 * */
CDate CDate::operator-(int const &n) const {
    int ngay{mNgay - n}, thang{mThang}, nam{mNam};

    while (ngay < 1) {
        if (--thang < 1) {
            thang = 12;

            --nam;
        }

        ngay += countNgayTrongThang(thang, nam);

        // if (mNam < 0)
        //     break;
    }

    return CDate{ngay, thang, nam};
}

/* *
 * @brief
 * @param
 * @return
 * */
CDate &CDate::operator++() {
    if (++mNgay > countNgayTrongThang(mThang, mNam)) {
        mNgay = 1;

        if (++mThang > 12) {
            mThang = 1;

            ++mNam;
        }
    }

    return *this;
}

/* *
 * @brief
 * @param
 * @return
 * */
CDate CDate::operator++(int) {
    CDate t{*this};

    ++(*this);

    return t;
}

/* *
 * @brief
 * @param
 * @return
 * */
CDate &CDate::operator--() {
    if (--mNgay < 1) {

        if (--mThang < 1) {
            mThang = 12;

            --mNam;
        }

        mNgay = countNgayTrongThang(mThang, mNam);
    }

    return *this;
}

/* *
 * @brief
 * @param
 * @return
 * */
CDate CDate::operator--(int) {
    CDate t{*this};

    --(*this);

    return t;
}

/* *
 * @brief
 * @param
 * @return
 * */
int CDate::operator-(CDate const &rhs) const {
    int daysCount{0};

    for (int i{mNam}, j{rhs.mNam}; i <= j; i++)
        daysCount += (isNamNhuan(i) ? 366 : 365);

    int lowerDaysCount{mNgay};
    for (int i{1}; i < mThang; i++)
        lowerDaysCount += countNgayTrongThang(i, mNam);

    int upperDaysCount{countNgayTrongThang(rhs.mThang, rhs.mNam) - rhs.mNgay};
    for (int i{12}; i > rhs.mThang; i--)
        upperDaysCount += countNgayTrongThang(i, rhs.mNam);

    return (daysCount - lowerDaysCount - upperDaysCount);
}

/* *
 * @brief
 * @param
 * @return
 * */
int CDate::operator>(CDate const &rhs) const {
    if (mNam != rhs.mNam)
        return (mNam < rhs.mNam ? 1 : -1);

    if (mThang != rhs.mThang)
        return (mThang < rhs.mThang ? 1 : -1);

    if (mNgay != rhs.mNgay)
        return (mNgay < rhs.mNgay ? 1 : -1);

    return 0;
}
