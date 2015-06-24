#include "../main.h"

void board() {
  glPushMatrix();
  // White, for now.
  glColor3f(0,1,0);

  // Face of the board
  glBegin(GL_QUADS);
  // Lower right
  glVertex3f(1,0,1);
  // Lower left
  glVertex3f(-1,0,1);
  // Upper left
  glVertex3f(-1,0,-1);
  // Upper right
  glVertex3f(1,0,-1);
  glEnd();

  glPopMatrix();
}