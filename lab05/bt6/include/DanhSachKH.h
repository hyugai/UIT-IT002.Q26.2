#pragma once
#include "KHLoaiA.h"
#include "KHLoaiB.h"
#include "KHLoaiC.h"
#include <istream>
#include <ostream>

using namespace std;

class DanhSachKH {
    int mACount, mBCount, mCCount;
    KHLoaiA *mpA{nullptr};
    KHLoaiB *mpB{nullptr};
    KHLoaiC *mpC{nullptr};

  public:
    ~DanhSachKH();
    friend istream &operator>>(istream &, DanhSachKH &);
    friend ostream &operator<<(ostream &, DanhSachKH const &);
    void calcThanhTien();
};
