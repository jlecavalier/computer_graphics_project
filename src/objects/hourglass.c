#include "../main.h"

void hourglass(double x,double y,double z,
	           double radius,double height,
	           double thx,double thz,
	           unsigned int tex,
             unsigned int wood_tex) {
  double i;
  const double pi2 = M_PI * 2;
  double delta = pi2 / 103;

  float white[] = {221.0/255.0,213.0/255.0,242.0/255.0,1};
  float shinyvec[1];
  shinyvec[0] = 16.0;
  glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,shinyvec);
  glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);

  glPushMatrix();

  glTranslated(x,y,z);
  glRotated(thx,1,0,0);
  glRotated(thz,0,0,1);
  glScaled(radius,height,radius);
  
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D,wood_tex);
  // The top lid
  glColor3f(.055,.055,.055);
  glBegin(GL_TRIANGLE_FAN);
  glNormal3f(0,1,0);
  glTexCoord2f(.5,.5);
  glVertex3f(0,1.01,0);
  for (i=0.0;i<=pi2;i+=delta) {
    double x = 1.5 * cos(i);
    double z = 1.5 * sin(i);
    glTexCoord2f(cos(i),sin(i));
    glVertex3f(x,1.01,z);
  }
  glEnd();

  // The bottom lid
  glColor3f(.055,.055,.055);
  glBegin(GL_TRIANGLE_FAN);
  glNormal3f(0,-1,0);
  glTexCoord2f(.5,.5);
  glVertex3f(0,-.01,0);
  for (i=0.0;i<=pi2;i+=delta) {
    double x = 1.5 * cos(i);
    double z = 1.5 * sin(i);
    glTexCoord2f(cos(i),sin(i));
    glVertex3f(x,-.01,z);
  }
  glEnd();

  // Cylinders coming down the sides
  cylinder(1.3,0,0,
           0,0,
           height*4,.15,
           51.5,wood_tex,
           wood_tex,
           0);

  cylinder(-1.3,0,0,
           0,0,
           height*4,.15,
           51.5,wood_tex,
           wood_tex,
           0);

  for (i=0.0;i<=360;i+=1) {
    hourglass_side(i,tex);
  }

  glPopMatrix();

  glDisable(GL_TEXTURE_2D);
}