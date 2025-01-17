#include "Point.hpp"


Point::Point(): x(0), y(0)
{
    //std::cout << "Default constructor called" << std::endl;
};

Point::Point(Point const &src):x(src.getX()), y(src.getY())
{
    //std::cout << "Copy constructor called" << std::endl;
};

Point::Point(float const fa, float const fb): x(Fixed(fa)), y(Fixed(fb))
{
    //std::cout << "Point Float constructor called" << std::endl;
};

Point::Point(Fixed const &fa, Fixed const &fb): x(fa), y(fb)
{
    //std::cout << "Fixeds constructor called" << std::endl;
};

Point::Point(Point const &a, Point const &b):
    x(Fixed(b.getX() - a.getX())),
    y(Fixed(b.getY() - a.getY()))
{};

Point::~Point()
{
    //std::cout << "Destructor called" << std::endl;
};

float Point::getX()const
{
    return(x.toFloat());
};

float Point::getY()const
{
    return(y.toFloat());
};

Point const &Point::operator=(Point const & src)
{
    //std::cout << "Can not copy, attribute are const" << std::endl;
    Point temp(src);
    return *this;
}

float Point::operator*(Point &other)const
{
    float x, y;
    
    x = getX() * other.getY();
    y = getY() * other.getX();
    return(x - y);
}

std::ostream &operator<<(std::ostream &stream, Point const &point)
{
    stream << point.getX() << "," << point.getY();
    return(stream);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{

Point ab(a, b);
Point bc(b, c);
Point ca(c, a);
Point pa(point, a);
Point pb(point, b);
Point pc(point, c);
Fixed const fa = Fixed(ab * pa);
Fixed const fb = Fixed(bc * pb);
Fixed const fc = Fixed(ca * pc);

if(fa == 0 || fb == 0 || fc == 0)
    return(false);
if(fa < 0 && (fb > 0 || fc > 0))
    return(false);
if(fa > 0 && (fb < 0 || fc < 0))
    return(false);
return(true);
}