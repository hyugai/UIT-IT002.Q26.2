#include "../include/cArray.h"
#include <iostream>

using namespace std;

int main() {
    cArray arr;
    arr.nhap();

    cout << "\n===== Liet ke =====\n";
    arr.xuat();

    cout << "===== Thong ke so lan phan tu x xuat hien =====\n";
    arr.countPhanTuX();

    cout << "===== Mang co tang dan hay khong =====\n";
    cout << (arr.isTangDan() ? "Co" : "Khong") << endl;

    cout << "===== Phan tu le nho nhat =====\n";
    int minLe{arr.findPhanTuLeNhoNhat()};
    if (minLe)
        cout << minLe << endl;
    else
        cout << "Khong co phan tu le\n";

    cout << "===== So nguyen to lon nhat =====\n";
    int maxSoNguyenTo{arr.findSoNguyenToLonNhat()};
    if (maxSoNguyenTo)
        cout << maxSoNguyenTo << endl;
    else
        cout << "Khong co so nguyen to\n";

    cout << "===== Mang sau khi sap xep theo thu tu tang dan =====\n";
    arr.bubbleSort();
    arr.xuat();

    return 0;
}
