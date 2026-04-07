struct GioPhutGiay {
    void Nhap();
    void Xuat();
    GioPhutGiay TinhCongThemMotGiay();

  private:
    int iGio, iPhut, iGiay;
};

bool KiemTraGio(const int &);
bool KiemTraPhutGiay(const int &);
