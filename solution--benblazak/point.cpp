/* ----------------------------------------------------------------------------
 * Copyright &copy; 2015 Ben Blazak <bblazak@fullerton.edu>
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */

#include <cmath>
using std::pow;
using std::sqrt;

#include "point.h"

// ----------------------------------------------------------------------------

Point::Point(float x, float y) : x(x), y(y) {}

float Point::getX() const { return x; }
float Point::getY() const { return y; }

float Point::distance(const Point & a) const {
    return sqrt( pow( a.x - this->x, 2 ) + pow( a.y - this->y, 2 ) );
}

