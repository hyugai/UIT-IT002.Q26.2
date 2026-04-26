#include "cDiem.h"

class cDaGiac {
    cDiem *mpDiem;

  public:
    void nhap();
    void xuat() const;
    cDaGiac tinhTien() const;
    cDaGiac quay() const;
    cDaGiac phongTo() const;
    cDaGiac thuNho() const;
};
