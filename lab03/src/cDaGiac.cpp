#include "../include/cDaGiac.h"
#include "../include/cDuongThang.h"
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

// Defaulted Constructor
cDaGiac::cDaGiac() {};

// Parameterized Constructor
cDaGiac::cDaGiac(int soDiem, cDiem *pDiem) : mSoDiem(soDiem), mpDiem(pDiem) {
    if (!pDiem)
        mpDiem = new cDiem[soDiem];
}

// Destructor
cDaGiac::~cDaGiac() { delete[] mpDiem; }

/* *
 * @brief Nhập vào các điểm thoả mãn đa giác lồi
 * @return void
 * @note Nhập các điểm nối tiếp nhau tạo thành một đa giác lồi
 * */
void cDaGiac::nhap() {
    do {
        cout << "Nhap so diem cho da giac loi (lon hon 2): ";
        cin >> mSoDiem;
    } while (mSoDiem < 3);

    delete[] mpDiem;
    mpDiem = new cDiem[mSoDiem];

    for (int i{0}; i < mSoDiem; i++) {
        do {
            cout << "Nhap diem thu " << i + 1 << endl;
            mpDiem[i].nhap();
        } while (!isDiemHopLe(mpDiem, i));
    }
}

/* *
 * @brief Xuất ra màn hình thông tin của đa giác
 * @return void
 * */
void cDaGiac::xuat() const {
    cout << "Chu Vi: " << setprecision(3) << getChuVi() << endl;
    cout << "Dien Tich: " << setprecision(3) << getDienTich() << endl;
}

/* *
 * @brief Tính chu vi của đa giác
 * @return double Trả về chu vi của đa giác
 * */
double cDaGiac::getChuVi() const {
    double kq{0};

    for (int i{0}; i < mSoDiem - 1; i++) {
        kq += cDiem::calcKhoangCachToiDiem(mpDiem[i], mpDiem[i + 1]);
    }

    kq += cDiem::calcKhoangCachToiDiem(mpDiem[0], mpDiem[mSoDiem - 1]);

    return kq;
}

/* *
 * @brief Tính diện tích của đa giác
 * @return double Trả về diện tích của đa giác
 * */
double cDaGiac::getDienTich() const {
    double kq{0};

    for (int i{0}; i < mSoDiem; i++) {
        int j{(i + 1) % mSoDiem};

        kq += mpDiem[i].getX() * mpDiem[j].getY();
        kq -= mpDiem[j].getX() * mpDiem[i].getY();
    }

    kq = fabs(kq) / 2.0;

    return kq;
}

/* *
 * @brief Tịnh tiến đa giác theo vector v
 * @return cDaGiac Trả về đa giác mới sau khi tịnh tiến
 * */
cDaGiac cDaGiac::tinhTien() const {
    cDiem v;
    cout << "Nhap vector tinh tien:\n";
    v.nhap();

    cDaGiac kq{mSoDiem};
    for (int i{0}; i < mSoDiem; i++) {
        kq.mpDiem[i] = mpDiem[i].tinhTien(v);
    }

    return kq;
}

/* *
 * @brief Quay đa giác 1 góc radian (tâm O)
 * @return cDaGiac Trả về đa giác mới sau khi quay
 * */
cDaGiac cDaGiac::quay() const {
    double rad;
    cout << "Nhap goc quay (radian): ";
    cin >> rad;

    cDaGiac kq{mSoDiem};
    for (int i{0}; i < mSoDiem; i++) {
        kq.mpDiem[i] = mpDiem[i].quay(rad);
    }

    return kq;
}

/* *
 * @brief Phóng to đa giác theo hệ số k
 * @return cDaGiac Trả về đa giác mới sau khi phóng to
 * */
cDaGiac cDaGiac::phongTo() const {
    double k;
    do {
        cout << "Nhap he so phong to (lon hon 1): ";
        cin >> k;
    } while (k <= 1);

    cDaGiac kq{mSoDiem};
    for (int i{0}; i < mSoDiem; i++) {
        kq.mpDiem[i] = mpDiem[i].thuPhong(k);
    }

    return kq;
}

/* *
 * @brief Thu nhỏ đa giác theo hệ số k
 * @return cDaGiac Trả về đa giác mới sau khi thu nhỏ
 * */
cDaGiac cDaGiac::thuNho() const {
    double k;
    do {
        cout << "Nhap he so thu nho (duong, nho hon 1): ";
        cin >> k;
    } while (k <= 0 || k >= 1);

    cDaGiac kq{mSoDiem};
    for (int i{0}; i < mSoDiem; i++) {
        kq.mpDiem[i] = mpDiem[i].thuPhong(k);
    }

    return kq;
}

cDiem const *cDaGiac::getpDiem() const { return mpDiem; }

/* *
 * @brief Kiểm tra điểm nhập vào có tạo ra đa giác lồi không
 * @param pDiem Mảng chứa điểm
 * @param i Index của điểm mới nhất
 * @return bool true(Hợp lệ), false(Ngược lại)
 * */
bool isDiemHopLe(cDiem const *pDiem, int const &i) {
    if (i < 2)
        return true;

    if (i == 2) {
        cDuongThang line{pDiem[0], pDiem[1]};
        if (!line.calcViTriDiem(pDiem[2]))
            return false;
    }

    cDuongThang line0{pDiem[0], pDiem[i - 1]},
        line1{pDiem[i - 2], pDiem[i - 1]};

    if ((line0.calcViTriDiem(pDiem[i]) < 0) &&
        (line1.calcViTriDiem(pDiem[i]) < 0))
        return true;

    return false;
}
