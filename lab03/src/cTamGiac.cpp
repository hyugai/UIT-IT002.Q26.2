#include "../include/cTamGiac.h"
#include "../include/cDuongThang.h"
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

// Defaulted Constructor: Khởi tạo tam giác với 3 điểm "trống"
cTamGiac::cTamGiac() {
    mpDiem = new cDiem[MAX_SIDES];
    mpCanh = new double[MAX_SIDES];
}

// Copy Constructor: Khởi tạo 1 tam giác là bản sao của 1 tam giác khác
cTamGiac::cTamGiac(cTamGiac const &tri) {
    mpDiem = new cDiem[MAX_SIDES];

    for (int i{0}; i < MAX_SIDES; i++)
        mpDiem[i] = tri.mpDiem[i];
}

// Destructor
cTamGiac::~cTamGiac() {
    delete[] mpDiem;
    delete[] mpCanh;
}

/* *
 * @brief Yêu cầu nhập vào 3 điểm đến khi thỏa mãn
 * @return void
 * */
void cTamGiac::nhap() {
    cout << "Nhap diem thu 1:\n";
    mpDiem[0].nhap();

    do {
        cout << "Nhap diem thu 2:\n";
        mpDiem[1].nhap();
    } while (mpDiem[0].isDiemTrung(mpDiem[1]));

    do {
        cout << "Nhap diem thu 3:\n";
        mpDiem[2].nhap();
        getDangTamGiac();
    } while (type == DangTamGiac::KhongPhaiTamGiac);
}

/* *
 * @brief Xuất ra màn hình loại tam giác, độ dài 3 cạnh
 * @return void
 * */
void cTamGiac::xuat() const {
    switch (type) {
    case DangTamGiac::Thuong:
        cout << "\nTam giac thuong\n";
        break;
    case DangTamGiac::Deu:
        cout << "\nTam giac deu\n";
        break;
    case DangTamGiac::Vuong:
        cout << "\nTam giac vuong\n";
        break;
    case DangTamGiac::Can:
        cout << "\nTam giac can\n";
        break;
    case DangTamGiac::VuongCan:
        cout << "\nTam giac vuong can\n";
        break;
    case DangTamGiac::KhongPhaiTamGiac:
        cout << "\nKhong phai tam giac\n";
        break;
    }
    cout << "Do dai 3 canh: ";
    for (int i{0}; i < MAX_SIDES; i++) {
        cout << setprecision(3) << mpCanh[i]
             << (i < MAX_SIDES - 1 ? ", " : " ");
    }
    cout << endl;

    cout << "Chu vi: " << setprecision(4) << getChuVi() << endl;
    cout << "Dien tich: " << setprecision(4) << getDienTich() << endl;
}

/* *
 * @brief Đếm số cặp cạnh bằng nhau
 * @return short Số cặp cạnh bằng nhau
 * */
short cTamGiac::countCapCanhBangNhau() {
    calcToHop(cDiem::calcKhoangCachToiDiem, mpDiem, mpCanh, MAX_SIDES);
    bubbleSort(mpCanh, MAX_SIDES);

    short isCapCanhBangNhau[MAX_SIDES];
    calcToHop([&](auto a, auto b) { return fabs(a - b) < EPS ? 1 : 0; }, mpCanh,
              isCapCanhBangNhau, MAX_SIDES);

    isCapCanhBangNhau[0] += isCapCanhBangNhau[1] + isCapCanhBangNhau[2];

    return isCapCanhBangNhau[0];
}

/* *
 * @brief Kiểm tra và xác định loại tam giác
 * @return void
 * */
void cTamGiac::getDangTamGiac() {
    if (!cDuongThang{mpDiem[0], mpDiem[1]}.calcViTriDiem(mpDiem[2])) {
        type = DangTamGiac::KhongPhaiTamGiac;
        return;
    }

    short capCanhBangNhauCount{countCapCanhBangNhau()};
    if (capCanhBangNhauCount == 3) {
        type = DangTamGiac::Deu;
        return;
    }

    // Kiểm tra tam giác vuông
    double val{fabs(pow(mpCanh[0], 2) + pow(mpCanh[1], 2) - pow(mpCanh[2], 2))};
    if (val < EPS ? true : false) {
        type =
            (capCanhBangNhauCount ? DangTamGiac::VuongCan : DangTamGiac::Vuong);
        return;
    }

    type = capCanhBangNhauCount ? DangTamGiac::Can : DangTamGiac::Thuong;
}

/* *
 * @brief Tính chu vi tam giác
 * @return void
 * */
double cTamGiac::getChuVi() const { return mpCanh[0] + mpCanh[1] + mpCanh[2]; }

/* *
 * @brief Tính diện tích tam giác bằng công thức Heron
 * @return void
 * */
double cTamGiac::getDienTich() const {
    double half_p{getChuVi() / 2.0};
    double s = sqrt(half_p * (half_p - mpCanh[0]) * (half_p - mpCanh[1]) *
                    (half_p - mpCanh[2]));

    return s;
}

/* *
 * @brief Tịnh tiến tam giác theo 1 vector v
 * @return cTamGiac Trả về một tam giác mới sau khi tịnh tiến
 * */
cTamGiac cTamGiac::tinhTien() const {
    cout << "Nhap vector tinh tien:\n";
    cDiem v;
    v.nhap();

    cTamGiac new_tri;
    for (size_t i{0}; i < MAX_SIDES; i++)
        new_tri.mpDiem[i] = mpDiem[i].tinhTien(v);

    return new_tri;
}

/* *
 * @brief Quay tam giác theo một góc radian
 * @return cTamGiac Trả về một tam giác mới sau khi quay
 * */
cTamGiac cTamGiac::quay() const {
    double rad;
    cout << "Nhap goc quay (radian): ";
    cin >> rad;

    cTamGiac new_tri;
    for (size_t i{0}; i < MAX_SIDES; i++)
        new_tri.mpDiem[i] = mpDiem[i].quay(rad);

    return new_tri;
}

/* *
 * @brief Phong to tam giac k lan
 * @return cTamGiac Trả về một tam giác mới sau khi phong to
 * */
cTamGiac cTamGiac::phongTo() const {
    double k;
    do {
        cout << "Nhap he so phong to (lon hon 1): ";
        cin >> k;
    } while (k <= 1);

    cTamGiac new_tri;
    for (size_t i{0}; i < MAX_SIDES; i++)
        new_tri.mpDiem[i] = mpDiem[i].thuPhong(k);

    return new_tri;
}

/* *
 * @brief Thu nho tam giac k lan
 * @return cTamGiac Trả về một tam giác mới sau khi thu nho
 * */
cTamGiac cTamGiac::thuNho() const {
    double k;
    do {
        cout << "Nhap he so phong to (so thuc duong nho hon 1): ";
        cin >> k;
    } while (k >= 1 || k <= 0);

    cTamGiac new_tri;
    for (short i{0}; i < MAX_SIDES; i++)
        new_tri.mpDiem[i] = mpDiem[i].thuPhong(k);

    return new_tri;
}
