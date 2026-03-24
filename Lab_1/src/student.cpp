#include "../include/student.hpp"
#include <iostream>
#include <istream>
#include <ostream>
#include <string>

using namespace std;

ostream &operator<<(ostream &out, const MyStudent &stu) {
    out << "Ten: " << stu.name << "\nDTB: " << (stu.literature + stu.math) / 2.0
        << endl;

    return out;
}

istream &operator>>(istream &in, MyStudent &stu) {
    string n;
    cout << "Nhap ten: ";
    getline(in, n);
    while (!(isNameValid(n))) {
        cout << "Nhap lai ten: ";
        getline(in, n);
    }
    stu.name = n;

    cout << "Nhap diem toan, van: ";
    double m, l;
    in >> m >> l;
    while (!(isScoreValid(m) && isScoreValid(l))) {
        cout << "Nhap lai diem toan, van: ";
        in >> m >> l;
    }
    stu.math = m;
    stu.literature = l;

    return in;
}

bool isScoreValid(double s) {
    bool res{true};

    if (s > 10.0 || s < 0.0) {
        res = false;
    }

    return res;
}

bool isNameValid(string name) {
    bool res{true};
    for (const char &c : name) {
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ')) {
            res = false;
        } else if (name.length() == 0) {
            res = false;
        }
    }

    return res;
}
