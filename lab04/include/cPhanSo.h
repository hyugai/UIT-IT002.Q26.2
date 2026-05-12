#include <istream>
#include <numeric>
#include <ostream>
using namespace std;

class cPhanSo {
    int mTu, mMau;

    void simplyPhanSo() {
        if (!mTu) {
            mTu = 0;
            mMau = 1;
            return;
        }

        int UCLN{gcd(mTu, mMau)};
        mTu /= UCLN;
        mMau /= UCLN;

        if (mTu * mMau < 0)
            mTu *= (mTu > 0 ? -1 : 1);
        else
            mTu *= (mTu > 0 ? 1 : -1);

        mMau *= (mMau < 0 ? -1 : 1);
    }

  public:
    cPhanSo();
    cPhanSo(int, int = 1);

    friend istream &operator>>(istream &, cPhanSo &);
    friend ostream &operator<<(ostream &, cPhanSo const &);
    bool operator==(cPhanSo const &) const;
    bool operator>(cPhanSo const &) const;
    bool operator<(cPhanSo const &) const;
    cPhanSo operator+(cPhanSo const &) const;
    cPhanSo operator-(cPhanSo const &) const;
    cPhanSo operator*(cPhanSo const &) const;
    cPhanSo operator/(cPhanSo const &) const;
};
