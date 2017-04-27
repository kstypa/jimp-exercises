//
// Created by karol on 4/27/17.
//

#ifndef JIMP_EXERCISES_POINT_H
#define JIMP_EXERCISES_POINT_H

#include <iostream>

class Point {
public:
    Point();
    Point(double x, double y);
    virtual ~Point();

    void ToString(std::ostream *out) const;
    double Distance(const Point &other) const;

    double GetX() const;
    double GetY() const;

    void SetX(double x);
    void SetY(double y);

private:
    double x_, y_;
};

std::istream& operator>>(std::istream &is, Point& point);
std::ostream &operator<<(std::ostream &os, const Point &point);


#endif //JIMP_EXERCISES_POINT_H
