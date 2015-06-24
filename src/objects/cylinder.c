#include "../main.h"

void cylinder(double x,double y,double z,
	          double thx,double thz,
	          double h,double radius,
	          double num_quads) {
  glPushMatrix();

  // Transformations
  glTranslated(x,y,z);
  glRotated(thx,1,0,0);
  glRotated(thz,0,0,1);
  glScaled(1,h,1);

  // Red body, for now
  glColor3f(1,0,0);

  // constant so we don't have to
  // calculate 2pi over and over
  // again.
  const double pi2 = M_PI * 2;

  // The tube part
  double i;
  double delta = pi2 / num_quads;
  for (i=0.0;i<=pi2;i+=delta) {
  	  double x0 = radius * cos(i);
  	  double x1 = radius * cos(i+delta);
  	  double z0 = radius * sin(i);
  	  double z1 = radius * sin(i+delta);
  	  glBegin(GL_QUADS);
	  // Lower right
	  glVertex3f(x0,0,z0);
	  // Lower left
	  glVertex3f(x1,0,z1);
	  // Upper left
	  glVertex3f(x1,1,z1);
	  // Upper right
	  glVertex3f(x0,1,z0);
	  glEnd();
  }

  // The top lid
  glColor3f(0,0,1);
  glBegin(GL_TRIANGLE_FAN);
  glVertex3f(0,1,0);
  for (i=0.0;i<=pi2;i+=delta) {
  	double x = radius * cos(i);
  	double z = radius * sin(i);
    glVertex3f(x,1,z);
  }
  glEnd();

  // The bottom lid
  glColor3f(0,1,1);
  glBegin(GL_TRIANGLE_FAN);
  glVertex3f(0,0,0);
  for (i=0.0;i<=pi2;i+=delta) {
  	double x = radius * cos(i);
  	double z = radius * sin(i);
  	glVertex3f(x,0,z);
  }
  glEnd();

  glPopMatrix();
}