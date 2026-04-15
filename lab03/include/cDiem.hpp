struct cDiem {
    cDiem();
    cDiem(double, double);
    cDiem(cDiem const &);
    ~cDiem();

    double getX() const;
    double getY() const;
    void Nhap();
    cDiem TinhTien(double, double);
    cDiem Quay(double);
    cDiem ThuPhong(double);

  private:
    double x, y;
};
