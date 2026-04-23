#pragma once

class cDiem {
    double mX, mY;

  public:
    cDiem();
    cDiem(double, double);
    cDiem(cDiem const &);

    double getX() const;
    double getY() const;
    void setX(double const &);
    void setY(double const &);

    void nhap();
    static double calcKhoangCachToiDiem(cDiem const &, cDiem const &);
    cDiem tinhTien(cDiem const &) const;
    cDiem quay(double) const;
    cDiem thuPhong(double) const;

    bool operator==(cDiem const &) const;
    friend cDiem operator-(cDiem const &, cDiem const &);
};
