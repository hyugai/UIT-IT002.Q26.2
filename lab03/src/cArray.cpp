#include "../include/cArray.h"
#include <iostream>
#include <random>

using namespace std;

// Defaulted Constructor
cArray::cArray() {}

// Paramterized Constructor
cArray::cArray(int n, int min, int max) : mN(n), mMin(min), mMax(max) {
    generateMangNgauNhienNPhanTu();
}

// Destructor
cArray::~cArray() {
    if (mpPhanTu)
        delete[] mpPhanTu;
}

/* *
 * @brief Tạo mảng số nguyên ngẫu nhiên với n phần tử từ -100 đến 100
 * @return void
 * */
void cArray::generateMangNgauNhienNPhanTu() {
    if (mpPhanTu)
        delete[] mpPhanTu;
    mpPhanTu = new int[mN];

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(mMin, mMax);

    for (int i{0}; i < mN; i++) {
        mpPhanTu[i] = dis(gen);
    }
}

/* *
 * @brief Nhập số lượng n phần tử
 * @return void
 * */
void cArray::nhap() {
    cout << "Nhap gia tri nho nhat co the xuat hien trong mang: ";
    cin >> mMin;
    do {
        cout << "Nhap gia tri lon nhat co the xuat hien trong mang (lon hon "
             << mMin << "): ";
        cin >> mMax;
    } while (mMax <= mMin);

    do {
        cout << "Nhap n phan tu (n > 0): ";
        cin >> mN;
    } while (mN <= 0);

    generateMangNgauNhienNPhanTu();
}

/* *
 * @brief Xuất mảng số nguyên n phần tử
 * @return void
 * */
void cArray::xuat() const {
    for (int i{0}; i < mN; i++) {
        cout << mpPhanTu[i] << ' ';
    }
    cout << endl;
}

/* *
 * @brief Đếm số lần phần tử x xuất hiện trong mảng
 * @return void
 * */
void cArray::countPhanTuX() const {
    int x;
    cout << "Nhap x (tu " << mMin << " den " << mMax << "): ";
    cin >> x;

    int xCount{0};
    for (int i{0}; i < mN; i++) {
        xCount += (mpPhanTu[i] == x ? 1 : 0);
    }

    cout << "So lan x xuat hien trong mang: " << xCount << endl;
}

/* *
 * @brief Kiểm tra xem mảng có tăng dần không
 * @return bool true(Mảng tăng dần), false(Ngược lại)
 * */
bool cArray::isTangDan() const {
    for (int i{0}; i < mN - 1; i++) {
        if (mpPhanTu[i] > mpPhanTu[i + 1]) {
            return false;
        }
    }

    return true;
}

/* *
 * @brief Tìm phần tử lẻ nhỏ nhất trong mảng
 * @return int 0(Không có phần tử lẻ), khác 0(Phần tử lẻ nhỏ nhất)
 * */
int cArray::findPhanTuLeNhoNhat() const {
    int minLe{0};
    int i{0};
    for (; i < mN; i++) {
        if (mpPhanTu[i] % 2) {
            minLe = mpPhanTu[i];
            break;
        }
    }

    for (; i < mN; i++) {
        if (mpPhanTu[i] % 2 && mpPhanTu[i] < minLe)
            minLe = mpPhanTu[i];
    }

    return minLe;
}

/* *
 * @brief Tìm số nguyên tố lớn nhất trong mảng
 * @return int Số nguyên tố lớn nhất trong mảng
 * */
int cArray::findSoNguyenToLonNhat() const {
    int maxPrime{mpPhanTu[0]};

    for (int i{1}; i < mN; i++) {
        if (isPrime(mpPhanTu[i]) && mpPhanTu[i] > maxPrime)
            maxPrime = mpPhanTu[i];
    }

    return maxPrime;
}

/* *
 * @brief Sắp xếp các phần tử tăng dần bằng thuật toán "Bubble Sort"
 * @return void
 * */
void cArray::bubbleSort() {
    for (int i{0}; i < mN - 1; i++) {
        for (int j{0}; j < mN - i - 1; j++) {
            if (mpPhanTu[j] > mpPhanTu[j + 1]) {
                int t{mpPhanTu[j]};
                mpPhanTu[j] = mpPhanTu[j + 1];
                mpPhanTu[j + 1] = t;
            }
        }
    }
}

/* *
 * @brief Xác định 1 số có phải là số nguyên tố
 * @param n Số nguyên cần kiểm tra
 * @return bool true(Số nguyên tố), false(Ngược lại)
 * */
bool isPrime(const int &n) {
    if (n <= 1)
        return false;
    else if (n == 2)
        return true;
    else if (!(n % 2))
        return false;

    for (int i{3}; i * i <= n; i += 2) {
        if (!(n % i))
            return false;
    }

    return true;
}
