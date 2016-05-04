/* ----------------------------------------------------------------------------
 * Copyright &copy; 2015 Ben Blazak <bblazak@fullerton.edu>
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */

/**
 * Program to animate some basic shapes moving across the screen in the
 * terminal.
 */

#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

#include "point.h"
#include "shapes.h"

using std::cin;
using std::cout;
using std::endl;

using std::vector;

// ----------------------------------------------------------------------------

/**
 * A function to draw the `Shape*`s in the given vector in a terminal.
 *
 * Arguments:
 * - `v`: A vector containing pointers to each `Shape` to draw.
 *
 * Notes:
 * - A terminal window is typically 80 columns wide by 25 lines high.
 * - The width:height aspect ratio of a terminal character is approximately
 *   1:1.9.
 */
void draw(const vector<Shape*> & v) {
    const float xPixels = 80;
    const float yPixels = 25;

    const float xScale = 1;
    const float yScale = 1.9;

    for (float yp = 0; yp < yPixels; yp++) {
        float y = yp * yScale;

        for (float xp = 0; xp < xPixels; xp++) {
            float x = xp * xScale;

            if (yp == 0 || yp == yPixels-1) {
                cout << "-";
                continue;
            }

            if (xp == 0 || xp == xPixels-1) {
                cout << "|";
                continue;
            }

            bool includePoint = false;
            for (Shape * s : v)
                if (s->contains(Point(x,y)))
                    includePoint = true;

            if (includePoint)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}

// ----------------------------------------------------------------------------

int main() {
    const int frames = 40;
    const int frameSleep = 70;  // milliseconds

    // for each frame
    for (float f = 0; f < frames; f++) {
        // create some shapes
        Rectangle r( Point(5+f,5), 2, 8 );
        Square    s( Point(50-(f/2),5+(f/2)), 7 );
        Ellipse   e( Point(10-(f/3),35+(f/3)), Point(25-(f/3),35+(f/3)), 22+f );
        Circle    c( Point(50+(f/5),35), 15 );

        // put pointers to them in an array
        vector<Shape*> shapes = { &r, &s, &e, &c, };

        // draw the shapes in the terminal
        draw(shapes);

        // wait before drawing the next frame
        std::this_thread::sleep_for(std::chrono::milliseconds(frameSleep));
    }

    return 0;  // success
}

