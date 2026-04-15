#include "cDiem.hpp"
#include <string>

using namespace std;

enum class LoaiTamGiac { Thuong, Vuong, Can, VuongCan, Deu };

struct cTamGiac {
    cTamGiac();
    cTamGiac(cDiem const &, cDiem const &, cDiem const &);
    cTamGiac(cTamGiac const &o);
    ~cTamGiac();
    void Nhap();
    void Xuat();
    cDiem TinhTien(double, double);
    cDiem Quay(double);
    cDiem PhongTo(double);
    cDiem ThuNho(double);

  private:
    cDiem *ds;
};

LoaiTamGiac getTriangleType(cDiem const *);
double calDist(cDiem const &, cDiem const &);
bool isValidTriangle(cDiem const *);
bool isEquilateralTriangle(cDiem const *);
bool isIsoscelesTriangle(cDiem const *);
bool isRighTriangle(cDiem const *);
// bool isIsoscelesRighTriangle();
