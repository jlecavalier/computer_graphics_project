#include "../main.h"

#define ANGLE .5
#define SCALE 0.9

// NOTE: This was adapted from here:
// http://www.csce.uark.edu/~jgauch/4813/src/tree.cpp
// I do not claim to have come up with the idea. I adapted it
// to suit my project.

// I didn't end up using this because I couldn't get it to
// work in time for the project submission.

void tree(float x1, float y1, float length1, float angle1, int depth, float rando) {
  if (depth > 0) {
    // Draw line segment
    float x2 = x1 + (length1 * Cos(angle1*(180/M_PI)));
    float y2 = y1 + (length1 * Sin(angle1*(180/M_PI)));
    //glVertex2f(x1, y1);
    //glVertex2f(x2, y2);
    cylinder(x1,y1,0,
             0,(angle1*(180/M_PI)),
             length1,((float)depth/500.0),
             3,0,
             0,
             1);

    glLoadIdentity();

    // Make two recursive calls
    float length2 = length1 * (SCALE + rando);
    float angle2 = angle1 + (ANGLE + rando);
    tree(x2, y2, length2, angle2, depth-1, rando);
    angle2 = angle1 - (ANGLE + rando);
    tree(x2, y2, length2, angle2, depth-1, rando);
  }
}
