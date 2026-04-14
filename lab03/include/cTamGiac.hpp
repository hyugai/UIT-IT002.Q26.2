struct cDiem {
    cDiem();
    cDiem(double, double);
    cDiem(cDiem const &);
    ~cDiem();

    void Nhap();
    // void Xuat();
    cDiem TinhTien(double, double);
    cDiem Quay(double);
    cDiem ThuPhong(double);

  private:
    double x, y;
};

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
    cDiem ds[3];
};
