#include "SVCaoDang.h"
#include "SVDaiHoc.h"
#include <istream>
#include <ostream>

class DanhSachSV {
    int mCaoDangCount, mDaiHocCount;
    SVCaoDang *mpCaoDang{nullptr};
    SVDaiHoc *mpDaiHoc{nullptr};

  public:
    ~DanhSachSV();
    friend istream &operator>>(istream &, DanhSachSV &);
    friend ostream &operator<<(ostream &, DanhSachSV const &);
    void findSVTotNghiep(ostream &) const;
    void findSVKhongTotNghiep(ostream &) const;
    SVDaiHoc findMaxDTBDaiHoc() const;
    SVCaoDang findMaxDTBCaoDang() const;
    int countDHKhongTotNghiep() const;
    int countCDKhongTotNghiep() const;
};
