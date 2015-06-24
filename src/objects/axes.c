#include "../main.h"

void axes(double length) {
  glPushMatrix();

  // Axes are always white
  glColor3f(1,1,1);

  glBegin(GL_LINES);
  // X axis
  glVertex3f(0,0,0);
  glVertex3f(length,0,0);
  
  // Y axis
  glVertex3f(0,0,0);
  glVertex3f(0,length,0);

  // Z axis
  glVertex3f(0,0,0);
  glVertex3f(0,0,length);

  glEnd();

  // Axis labels
  glRasterPos3d(length,0,0);
  Print("X");
  glRasterPos3d(0,length,0);
  Print("Y");
  glRasterPos3d(0,0,length);
  Print("Z");

  glPopMatrix();
}