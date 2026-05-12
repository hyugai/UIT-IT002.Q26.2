#include <istream>
#include <ostream>

using namespace std;

class CDate {
    int mNgay, mThang, mNam;

    bool isNamNhuan(int const &nam) const {
        if (!(nam % 4) && (nam % 100) || !(nam % 400))
            return true;

        return false;
    }

    int countNgayTrongThang(int const &thang, int const &nam) const {
        if (thang == 4 || thang == 6 || thang == 9 || thang == 11)
            return 30;

        if (thang == 2)
            return (isNamNhuan(nam) ? 29 : 28);

        return 31;
    }

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
    CDate();
    CDate(int, int, int);
    CDate(CDate const &);

    friend istream &operator>>(istream &, CDate &);
    friend ostream &operator<<(ostream &, CDate const &);
    int operator>(CDate const &) const;
    CDate operator+(int const &) const;
    CDate operator-(int const &) const;
    CDate &operator++();
    CDate operator++(int);
    CDate &operator--();
    CDate operator--(int);
    int operator-(CDate const &) const;
};
