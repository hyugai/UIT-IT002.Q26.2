#include <istream>
#include <ostream>
using namespace std;

class cSoPhuc {
    double mThuc, mAo;

  public:
    cSoPhuc(double, double = 0);

    friend istream &operator>>(istream &, cSoPhuc &);
    friend ostream &operator<<(ostream &, cSoPhuc const &);
    bool operator==(cSoPhuc const &) const;
    bool operator!=(cSoPhuc const &) const;
    cSoPhuc operator+(cSoPhuc const &) const;
    cSoPhuc operator-(cSoPhuc const &) const;
    cSoPhuc operator*(cSoPhuc const &) const;
    cSoPhuc operator/(cSoPhuc const &) const;
};
