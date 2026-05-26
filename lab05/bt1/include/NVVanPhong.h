#include "NhanVien.h"

class NVVanPhong : public NhanVien {
    int mSoNgayLamViec;

  public:
    ~NVVanPhong();

    friend istream &operator>>(istream &, NVVanPhong &);
    friend ostream &operator<<(ostream &, NVVanPhong const &);
    void calcLuong() override;
};
