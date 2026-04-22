#pragma once
#include "point.hpp"
#include <iostream>
#include <vector>

#define MAX_SIDES 3
#define EPS 1e-8

using namespace std;

enum class TriangleType {
    Unknow,         // Không phải tam giác
    Regular,        // Thường
    Isosceles,      // Cân
    Right,          // Vuông
    IsoscelesRight, // Vuông Cân
    Equilateral     // Đều
};

class cTamGiac {
    vector<Point> points;
    vector<double> sides_length;
    TriangleType type{TriangleType::Unknow};

  public:
    cTamGiac();
    cTamGiac(Point const &, Point const &, Point const &);
    cTamGiac(cTamGiac const &);
    ~cTamGiac();

    void input();
    void output() const;
    void identifyTriangleType();
    double calcPerimeter() const;
    double calcArea() const;
    cTamGiac translate();
    cTamGiac rotate();
    cTamGiac scaleUp();
    cTamGiac scaleDown();
};

template <typename Func, typename VecIn, typename VecOut>
void calcCombination(Func fn, VecIn const &elements, VecOut &res, int const &n,
                     int i = 0) {
    if (i == n - 1) {
        return;
    }

    for (int k{i + 1}; k < n; k++) {
        res.push_back(fn(elements[i], elements[k]));
    }

    calcCombination(fn, elements, res, n, ++i);
}

template <typename Vec> void bubbleSort(Vec &v) {
    for (int i{0}; i < v.size() - 1; i++) {
        cout << v[i] << ' ' << v[i + 1] << endl;
        double t{v[i]};
        if (v[i] > v[i + 1]) {
            v[i] = v[i + 1];
            v[i + 1] = t;
        }
    }
}
