#pragma once
#include "point.hpp"
#include <cstddef>
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
    cTamGiac(vector<Point>);
    cTamGiac(cTamGiac const &);
    ~cTamGiac();

    void input();
    void output() const;
    void identifyTriangleType();
    double calcPerimeter() const;
    double calcArea() const;
    cTamGiac translate() const;
    cTamGiac rotate() const;
    cTamGiac scaleUp() const;
    cTamGiac scaleDown() const;
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
    size_t n{v.size()};
    bool is_swapped{false};

    for (size_t i{0}; i < n - 1; i++) {
        for (size_t j{0}; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                double t{v[j]};
                v[j] = v[j + 1];
                v[j + 1] = t;

                is_swapped = true;
            }
        }

        if (!is_swapped)
            break;
    }
}
