#pragma once

#include <istream>
#include <ostream>

using namespace std;

class Date {
    int mNgay, mThang, mNam;

    /* *
     * @brief
     * @param
     * @return
     * */
    bool isNamNhuan(int const &nam) const {
        if (!(nam % 4) && (nam % 100) || !(nam % 400))
            return true;

        return false;
    }

    /* *
     * @brief
     * @param
     * @return
     * */
    int countNgayTrongThang(int const &thang, int const &nam) const {
        if (thang == 4 || thang == 6 || thang == 9 || thang == 11)
            return 30;

        if (thang == 2)
            return (isNamNhuan(nam) ? 29 : 28);

        return 31;
    }

    /* *
     * @brief
     * @param
     * @return
     * */
    bool isNgayHopLe() const {
        if (mNam < 1)
            return false;

        if (mThang < 1 || mThang > 12)
            return false;

        if (mNgay < 1 || mNgay > countNgayTrongThang(mThang, mNam))
            return false;

        return true;
    }

  public:
    friend istream &operator>>(istream &, Date &);
    friend ostream &operator<<(ostream &, Date const &);
    bool operator>(Date const &) const;
    int getThang() const;
    int getNam() const;
};
