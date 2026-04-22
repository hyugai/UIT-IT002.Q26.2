#include "../include/triangle.hpp"
#include <iostream>

using namespace std;

int main() {
    cTamGiac tri;
    tri.input();

    cout << "\n===== Tam giac ABC =====\n";
    tri.output();

    cout << "\n===== Tinh tien =====\n";
    cTamGiac translated_tri{tri.translate()};
    translated_tri.identifyTriangleType();
    translated_tri.output();

    cout << "\n===== Quay tam O =====\n";
    cTamGiac rotated_tri{tri.rotate()};
    rotated_tri.identifyTriangleType();
    rotated_tri.output();

    cout << "\n===== Phong to =====\n";
    cTamGiac scaled_up_tri{tri.scaleUp()};
    scaled_up_tri.identifyTriangleType();
    scaled_up_tri.output();

    cout << "\n===== Thu nho =====\n";
    cTamGiac scaled_down_tri{tri.scaleDown()};
    scaled_down_tri.identifyTriangleType();
    scaled_down_tri.output();

    return 0;
}
