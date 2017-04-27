//
// Created by karol on 4/27/17.
//

#include <cmath>
#include <iostream>
#include "Point.h"

using ::std::ostream;
using ::std::cout;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;

Point::Point() : x_(0), y_(0) {
    cout << "Konstruktor bezparametrowy Point" << endl;
}

Point::Point(double x, double y) {
    cout << "Konstruktor parametrowy Point" << endl;
    x_ = x;
    y_ = y;
}

Point::~Point(){
    cout << "Destruktor Point" << endl;
}

double Point::Distance(const Point &other) const {
    return sqrt(pow(GetX()-other.GetX(),2)+pow(GetY()-other.GetY(),2));
}

void Point::ToString(ostream *out) const {
    (*out) << "(" << GetX() << ";" << GetY() << ")";
}

double Point::GetX() const {
    return x_;
}

void Point::SetX(double x) {
    Point::x_ = x;
}

double Point::GetY() const {
    return y_;
}

void Point::SetY(double y){
    Point::y_ = y;
}

void CheckNextChar(char c, std::istream* is) {
    int next_char = is->peek();
    if (next_char != c) {
        throw std::runtime_error("invalid character");
    }
    is->ignore();
}

void IgnoreWhitespace(std::istream* is) {
    (*is) >> std::ws;
}

double ReadNumber(std::istream* is) {
    double d;
    (*is) >> d;
    return d;
}

std::istream& operator>>(std::istream & input, Point& p){
    CheckNextChar('(', &input);
    p.SetX(ReadNumber(&input));
    CheckNextChar(',', &input);
    IgnoreWhitespace(&input);
    p.SetY(ReadNumber(&input));
    CheckNextChar(')', &input);
    return input;      // Umożliwia cin >> a >> b >> c;
}

std::ostream &operator<<(std::ostream &os, const Point &point){
    os << "(" + std::to_string(point.GetX()) + "," + std::to_string(point.GetY()) + ")";
    return os;
}