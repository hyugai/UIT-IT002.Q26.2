#include "../include/line.hpp"

// Defaulted constructor
Line::Line() {}

// Parameterized constructor: Khởi tạo đường thẳng với 2 điểm cho trước
Line::Line(Point const &p1, Point const &p2) {
    Point direction_vector{p2 - p1};
    x_coef = -direction_vector.getY();
    y_coef = direction_vector.getX();

    constant_term = x_coef * -p1.getX() + y_coef * -p1.getY();
}

// Trả về hệ số A trong (d): Ax + By + C = 0
double Line::getXCoef() const { return x_coef; }

// Trả về hệ số B trong (d): Ax + By + C = 0
double Line::getYCoef() const { return y_coef; }

// Trả về hằng số số C trong (d): Ax + By + C = 0
double Line::getConstantTerm() const { return constant_term; }

/* *
 * @brief Kiểm tra điểm có thuộc đường thẳng không
 * @param p Điểm cần kiểm tra
 * @return int -1(trái), 0(thuộc đường thẳng), 1(phải)
 * */
int Line::isPointOnLine(Point const &p) const {
    double val{x_coef * p.getX() + y_coef * p.getY() + constant_term};

    if (val >= 0 && val < 1e-8)
        return 0;

    return (val < 0 ? -1 : 1);
}

/* *
 * @brief Xác định vị trí của 2 đường thẳng
 * @param line Đường thẳng thứ 2
 * @return int -1(vuông góc), 0(song song), 1(cắt nhau)
 * */
int Line::isIntersecting(Line const &line) const {
    double dot_product{(x_coef * line.x_coef) + (y_coef * line.y_coef)};
    if (dot_product < 1e-8) {
        return -1;
    }

    double diff_ratio{(x_coef / line.x_coef) - (y_coef / line.y_coef)};
    if (diff_ratio < 1e-8) {
        return 0;
    }

    return 1;
}
