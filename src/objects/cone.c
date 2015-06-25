#include "../main.h"

void cone(double x,double y,double z,
	      double radius,double height,
	      double thx,double thz) {

  float white[] = {221.0/255.0,213.0/255.0,242.0/255.0,1};
  float shinyvec[1];
  shinyvec[0] = 64.0;
  glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,shinyvec);
  glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);

  glPushMatrix();

  // Transformations
  glTranslated(x,y,z);
  glRotated(thx,1,0,0);
  glRotated(thz,0,0,1);
  glScaled(1,height,1);

  glColor4f(0,1,1,0.8);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA,GL_SRC_ALPHA);

  const double pi2 = M_PI * 2;
  const double num_quads = 500;
  const double rh = radius/height;

  // The body
  double i;
  double delta = pi2 / num_quads;
  glBegin(GL_TRIANGLES);
  for (i=0.0;i<=pi2;i+=delta) {
  	double x0 = radius * cos(i);
  	double x1 = radius * cos(i+delta);
  	double z0 = radius * sin(i);
  	double z1 = radius * sin(i+delta);
  	double m0 = sqrt(pow(x0,2)+pow(z0,2));
  	double m1 = sqrt(pow(x1,2)+pow(z1,2));
  	double nx0 = (x0*height)/(radius*m0);
  	double nx1 = (x1*height)/(radius*m1);
  	double nz0 = (z0*height)/(radius*m0);
  	double nz1 = (z1*height)/(radius*m1);
  	// Lower left
  	glNormal3f(nx0,rh,nz0);
  	glVertex3f(x0,0,z0);
  	// Lower right
  	glNormal3f(nx1,rh,nz1);
  	glVertex3f(x1,0,z1);
  	// top
  	glNormal3f((x1-x0)/2,rh,(z1-z0)/2);
  	glVertex3f(0,height,0);
  }
  glEnd();

  glDisable(GL_BLEND);

  // The base
  glColor3f(0.2,0.2,0.2);
  glBegin(GL_TRIANGLE_FAN);
  glNormal3f(0,-1,0);
  glVertex3f(0,0,0);
  for (i=0.0;i<=pi2;i+=delta) {
    double x = radius * cos(i);
    double z = radius * sin(i);
    glVertex3f(x,0,z);
  }
  glEnd();

  glPopMatrix();
}