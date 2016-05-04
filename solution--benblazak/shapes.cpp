/* ----------------------------------------------------------------------------
 * Copyright &copy; 2015 Ben Blazak <bblazak@fullerton.edu>
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */

#include <cmath>
using std::abs;

#include "shapes.h"

// ----------------------------------------------------------------------------

Rectangle::Rectangle(Point center, float dx, float dy) : center(center),
                                                         dx(dx),
                                                         dy(dy) {}

bool Rectangle::contains(const Point & p) const {
    return    abs( p.getX() - center.getX() ) <= dx
           && abs( p.getY() - center.getY() ) <= dy;
}

Square::Square(Point center, float side)
    : Rectangle(center, side/2, side/2) {}

// ----------------------------------------------------------------------------

Ellipse::Ellipse(Point f1, Point f2, float radius) : f1(f1),
                                                     f2(f2),
                                                     radius(radius) {}

bool Ellipse::contains(const Point & p) const {
    return p.distance(f1) + p.distance(f2) <= radius;
}

Circle::Circle(Point center, float radius)
    : Ellipse(center, center, radius) {}

