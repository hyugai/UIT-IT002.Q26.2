#include <istream>
#include <ostream>

using namespace std;

class CTime {
    int mGio, mPhut, mGiay;

  public:
    CTime();
    CTime(int, int, int);
    CTime(CTime const &);

    friend istream &operator>>(istream &, CTime &);
    friend ostream &operator<<(ostream &, CTime const &);
    CTime operator+(int const &) const;
    CTime operator-(int const &) const;
    CTime &operator++();
    CTime operator++(int);
    CTime &operator--();
    CTime operator--(int);
};
