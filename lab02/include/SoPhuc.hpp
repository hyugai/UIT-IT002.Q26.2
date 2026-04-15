struct SoPhuc {
    void Nhap();
    void Xuat();
    SoPhuc Tong(SoPhuc const &);
    SoPhuc Hieu(SoPhuc const &);
    SoPhuc Tich(SoPhuc const &);
    SoPhuc Thuong(SoPhuc const &);

  private:
    double iThuc, iAo;
};
