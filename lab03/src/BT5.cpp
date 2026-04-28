#include "../include/cDaThuc.h"
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    cout << "===== Khoi tao da thuc bac 0 =====\n";
    cDaThuc daThucBac0;
    daThucBac0.xuat();

    cout << "===== Khoi tao da thuc bac n =====\n";
    int n;
    cout << "Nhap bac n (nguyen khong am) cho da thuc P: ";
    cin >> n;
    cDaThuc daThucBacN{n};
    daThucBacN.xuat();

    cout << "===== Tinh gia tri da thuc khi biet x =====\n";
    double x;
    cout << "Nhap x: ";
    cin >> x;
    cout << "Ket qua P(" << x << "): " << setprecision(3)
         << daThucBacN.calcDaThuc(x) << endl;

    cout << "===== Cong/Tru hai da thuc =====\n";
    cDaThuc daThuc1;
    cout << "Nhap da thuc Q:\n";
    daThuc1.nhap();
    cout << "Da thuc Q: ";
    daThuc1.xuat();
    cout << endl;

    cDaThuc daThuc2;
    cout << "Nhap da thuc R:\n";
    daThuc2.nhap();
    cout << "Da thuc R: ";
    daThuc2.xuat();
    cout << endl;

    cout << "Ket qua phep cong Q+R: ";
    cDaThuc kqPhepCong{daThuc1.addDaThuc(daThuc2)};
    kqPhepCong.xuat();

    cout << "Ket qua phep tru Q-R: ";
    cDaThuc kqPhepTru{daThuc1.subDaThuc(daThuc2)};
    kqPhepTru.xuat();

    return 0;
}
