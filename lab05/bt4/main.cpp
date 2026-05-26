#include "include/DanhSachNV.h"
#include <iostream>
#include <fstream>

using namespace std;

ifstream openInputFile(string &);
ofstream openOutputFile(string &);

int main() {
    string fName;
    ifstream iF{openInputFile(fName)};
    ofstream oF{openOutputFile(fName)};

    DanhSachNV dS;

    // nhap
    iF >> dS;

    // xuat
    oF << dS;

    // xuat danh sach nhan vien co muc luong thap hon muc luong trung binh
    dS.calcLuong();
    oF << "> Danh sach nhan vien co muc luong thap hon muc luong TB:\n";
    dS.findNVLuongThapHonTrungBinh(oF);

    // xuat nhan vien luong cao nhat
    oF << "> Thong tin nhan vien co luong cao nhat:\n";
    dS.findNVMaxLuong(oF);

    // xuat nhan vien luong thap nhat
    oF << "> Thong tin nhan vien co luong thap nhat:\n";
    dS.findNVMinLuong(oF);

    // xuat lap trinh vien luong cao nhat
    oF << "> Thong tin lap trinh vien co luong cao nhat:\n"
       << dS.findNVLapTrinhMaxLuong();

    // xuat kiem chung vien luong thap nhat
    oF << "> Thong tin kiem chung vien co luong thap nhat:\n"
       << dS.findNVKiemChungMinLuong();

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
