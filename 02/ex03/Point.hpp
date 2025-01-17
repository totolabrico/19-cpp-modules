#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <cmath>
#include "Fixed.hpp"

class Point{

private:
    Fixed const x;
    Fixed const y;
public:
    Point();
    Point (Point const &src);
    Point (float const a, float const b);
    Point (Fixed const &fa, Fixed const &fb);
    Point(Point const &a, Point const &b);
    ~Point();
    Point const &operator=(Point const & rhs);
    float getX()const;
    float getY()const;
    float operator*(Point &other)const;
    Point getVector(Point const &dest)const;

};

std::ostream &operator<<(std::ostream &stream, Point const &point);
bool bsp( Point const a, Point const b, Point const c, Point const point);
#endif