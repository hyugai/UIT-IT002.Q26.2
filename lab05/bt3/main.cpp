#include "include/DanhSachSV.h"
#include <iostream>
#include <fstream>

using namespace std;

ifstream openInputFile(string &);
ofstream openOutputFile(string &);

int main() {
    string fName;
    ifstream iF{openInputFile(fName)};
    ofstream oF{openOutputFile(fName)};

    DanhSachSV dS;

    // nhap
    iF >> dS;

    // xuat
    oF << dS;

    // xuat danh sach sinh vien du dieu kien tot nghiep
    oF << "> Danh sach sinh vien du dieu kien tot nghiep:\n";
    dS.findSVTotNghiep(oF);

    // xuat danh sach sinh vien khong du dieu kien tot nghiep
    oF << "> Danh sach sinh vien khong du dieu kien tot nghiep:\n";
    dS.findSVKhongTotNghiep(oF);

    // sinh vien dai hoc co diem trung binh cao nhat
    oF << "> Sinh vien DH co diem TB cao nhat:\n" << dS.findMaxDTBDaiHoc();

    // sinh vien cao dang co diem trung binh cao nhat
    oF << "> Sinh vien CD co diem TB cao nhat:\n" << dS.findMaxDTBCaoDang();

    // voi moi loai cho biet co bao nhieu khong du dieu kien tot nghiep
    oF << "> So sinh vien CD khong du dieu kien tot nghiep: "
       << dS.countCDKhongTotNghiep() << endl
       << "> So sinh vien DH khong du dieu kien tot nghiep: "
       << dS.countDHKhongTotNghiep() << endl;

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
