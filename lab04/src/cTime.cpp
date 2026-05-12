#include "../include/cTime.h"
#include <cstdio>
#include <iostream>
#include <istream>
#include <ostream>

using namespace std;

CTime::CTime() {};
CTime::CTime(int gio, int phut, int giay)
    : mGio(gio), mPhut(phut), mGiay(giay) {};
CTime::CTime(CTime const &t) : mGio(t.mGio), mPhut(t.mPhut), mGiay(t.mGiay) {}

/* *
 * @brief
 * @param
 * @return
 * */
istream &operator>>(istream &is, CTime &rhs) {
    do {
        cout << "Nhap gio, phut, giay: ";
        is >> rhs.mGio >> rhs.mPhut >> rhs.mGiay;
    } while (!((rhs.mGio >= 0 && rhs.mGio < 24) &&
               (rhs.mPhut >= 0 && rhs.mPhut < 60) &&
               (rhs.mGiay >= 0 && rhs.mGiay < 60)));

    return is;
}

/* *
 * @brief
 * @param
 * @return
 * */
ostream &operator<<(ostream &os, CTime const &rhs) {
    printf("%02d:%02d:%02d\n", rhs.mGio, rhs.mPhut, rhs.mGiay);

    return os;
}

/* *
 * @brief
 * @param
 * @return
 * */
CTime CTime::operator+(int const &giayCount) const {
    int gio{mGio + giayCount / 3600}, phut{mPhut + giayCount % 3600 / 60},
        giay{mGiay + giayCount % 3600 % 60};

    if (giay >= 60) {
        giay %= 60;
        ++phut;
    }

    if (phut >= 60) {
        phut %= 60;
        ++gio;
    }

    gio %= 24;

    return CTime{gio, phut, giay};
}

/* *
 * @brief
 * @param
 * @return
 * */
CTime CTime::operator-(int const &giayCount) const {
    int gio{mGio - giayCount / 3600}, phut{mPhut - giayCount % 3600 / 60},
        giay{mGiay - giayCount % 3600 % 60};

    while (giay < 0) {
        giay += 60;
        --phut;
    }

    while (phut < 0) {
        phut += 60;
        --gio;
    }

    while (gio < 0) {
        gio += 24;
    }

    return CTime{gio, phut, giay};
}

/* *
 * @brief
 * @param
 * @return
 * */
CTime &CTime::operator++() {
    if (++mGiay >= 60) {
        mGiay %= 60;

        if (++mPhut >= 60) {
            mPhut %= 60;

            if (++mGio == 24)
                mGio = 0;
        }
    }

    return *this;
}

/* *
 * @brief
 * @param
 * @return
 * */
CTime CTime::operator++(int) {
    CTime t{*this};

    ++(*this);

    return t;
}

/* *
 * @brief
 * @param
 * @return
 * */
CTime &CTime::operator--() {
    if (--mGiay < 0) {
        mGiay += 60;

        if (--mPhut < 0) {
            mPhut += 60;

            if (--mGio < 0)
                mGio += 24;
        }
    }

    return *this;
}

/* *
 * @brief
 * @param
 * @return
 * */
CTime CTime::operator--(int) {
    CTime t{*this};

    --(*this);

    return t;
}
