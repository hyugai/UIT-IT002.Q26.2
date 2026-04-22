#pragma once

class Point {
    double x, y;

  public:
    Point();
    Point(double, double);
    Point(Point const &);

    double getX() const;
    double getY() const;
    void setX(double const &);
    void setY(double const &);

    void input();
    static double calcDistanceTo(Point const &, Point const &);
    Point translate(double, double);
    Point rotate(double);
    Point scale(double);

    bool operator==(Point const &) const;
    friend Point operator-(Point const &, Point const &);
};
