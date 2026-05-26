#include "include/DanhSachGD.h"
#include <iomanip>
#include <fstream>
#include <iostream>

using namespace std;

ifstream openInputFile(string &);
ofstream openOutputFile(string &);

int main() {
    string fName;
    ifstream iF{openInputFile(fName)};
    ofstream oF{openOutputFile(fName)};

    DanhSachGD danhSach;

    // nhap danh sach
    iF >> danhSach;

    danhSach.calcThanhTienGD();
    // cout << danhSach;

    // tinh tong giao dich tung loai
    oF << "> Tong giao dich Dat: " << danhSach.getDatCount() << endl
       << "> Tong giao dich nha pho: " << danhSach.getNhaPhoCount() << endl
       << "> Tong giao dich can ho chung cu: "
       << danhSach.getCanHoChungCuCount() << endl;

    // tinh trung binh thanh tien cua GDCanHoChungCu
    oF << "> Trung binh thanh tien cua giao dich Can ho chung cu: " << fixed
       << setprecision(3) << danhSach.calcAvgThanhTienCanHoChungCu() << endl;

    // GDNhaPho co gia tri cao nhat (thanh tien)
    oF << "> Giao dich Nha pho co gia tri cao nhat:\n"
       << danhSach.findMaxThanhTienNhaPho() << endl;

    // Xuat ra danh sach cac giao dich cua thang 12 nam 2024
    oF << "> Cac giao dich trong thang 12 nam 2024:\n";
    danhSach.findGD(12, 2024, oF);

    return 0;
}

/* *
 * @brief
 * @param
 * @return
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
 * @brief
 * @param
 * @return
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
