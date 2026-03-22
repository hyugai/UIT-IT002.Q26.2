#include "../include/student.hpp"
#include <iostream>
#include <istream>
#include <ostream>
#include <string>

using namespace std;

ostream &operator<<(ostream &out, const MyStudent &stu) {
    out << "Name: " << stu.name
        << "\nAvg: " << (stu.literature + stu.math) / 2.0 << endl;

    return out;
}

istream &operator>>(istream &in, MyStudent &stu) {
    string n;
    cout << "Enter name: ";
    getline(in, n);
    while (!(isNameValid(n))) {
        cout << "Enter name again: ";
        getline(in, n);
    }
    stu.name = n;

    cout << "Enter math & literature score: ";
    double m, l;
    in >> m >> l;
    while (!(isScoreValid(m) && isScoreValid(l))) {
        cout << "Enter score again:";
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
