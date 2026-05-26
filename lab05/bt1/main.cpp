#include "include/DanhSachNV.h"
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <string>

ifstream openInputFile(string &);
ofstream openOutputFile(string &);

int main() {
    string fName;
    ifstream iF{openInputFile(fName)};
    ofstream oF{openOutputFile(fName)};

    DanhSachNV danhSach;

    // nhap
    iF >> danhSach;

    // tinh luong cho tung nhan vien
    danhSach.calcLuongNV();

    // xuat
    oF << danhSach;

    // tong luong cong ty phai tra
    oF << "> Tong luong cong ty phai tra: " << fixed << setprecision(2)
       << danhSach.calcTongLuongNV() << endl;

    // nvsx luong thap nhat
    oF << "> Nhan vien san xuat co luong thap nhat:\n"
       << danhSach.findMinLuongSX();

    // nvvp tuoi cao nhat
    oF << "> Nhan vien van phong co tuoi cao nhat:\n"
       << danhSach.findMaxTuoiVP();

    return 0;
}

/* *
 * @brief Đọc input file
 * @param fName
 * @return ifstream
 * */
ifstream openInputFile(string &fName) {
    cout << "Nhap ten file van ban cho danh sach: ";
    cin >> fName;

    ifstream iF{fName};
    if (!iF.is_open()) {
        cerr << "Failed to open: " << fName << endl;
        exit(1);
    }

    return iF;
}

/* *
 * @brief Xuất kết quả ra output file
 * @param fName
 * @return ofstream
 * */
ofstream openOutputFile(string &fName) {
    size_t pos{fName.find("INP")};
    if (pos != string::npos) {
        fName.replace(pos, 3, "OUT");
    }

    ofstream oF{fName};
    if (!oF.is_open()) {
        cerr << "Failed to open: " << fName << endl;
        exit(1);
    }

    return oF;
}
