#include "include/DanhSachKH.h"
#include <iostream>
#include <fstream>

using namespace std;

ifstream openInputFile(string &);
ofstream openOutputFile(string &);

int main() {
    string fName;
    ifstream iF{openInputFile(fName)};
    ofstream oF{openOutputFile(fName)};

    DanhSachKH dS;

    // nhap
    iF >> dS;

    // tong tien tung khach hang va xuat ket qua
    dS.calcThanhTien();

    // xuat
    oF << dS;

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
