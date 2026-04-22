#pragma once
#include "point.hpp"

class Line {
    double x_coef, y_coef, constant_term;

  public:
    Line();
    Line(Point const &, Point const &);

    double getXCoef() const;
    double getYCoef() const;
    double getConstantTerm() const;

    int isPointOnLine(Point const &) const;
    int isIntersecting(Line const &) const;
    double calcDist(Point const &) const;
    double calcAng(Line const &) const;
};
