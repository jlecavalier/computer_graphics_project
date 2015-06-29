#include "../main.h"

void cylinder(double x,double y,double z,
	          double thx,double thz,
	          double h,double radius,
	          double num_quads,unsigned int cyl_tex,
	          unsigned int cap_tex) {

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
  glScaled(1,h,1);

  // White so the texture shows up right
  glColor3f(0.2,0.2,0.2);

  // Texture
  glEnable(GL_TEXTURE_2D);
  glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
  glBindTexture(GL_TEXTURE_2D,cyl_tex);

  // constant so we don't have to
  // calculate 2pi over and over
  // again.
  const double pi2 = M_PI * 2;

  // The tube part
  double i;
  double delta = pi2 / num_quads;
  glBegin(GL_QUADS);
  for (i=0.0;i<=pi2;i+=delta) {
  	  double x0 = radius * cos(i);
  	  double x1 = radius * cos(i+delta);
  	  double z0 = radius * sin(i);
  	  double z1 = radius * sin(i+delta);
  	  double t_x0 = i/pi2;
  	  double t_x1 = (i+delta)/pi2;
	  // Upper left
	  glNormal3f(x1,0,z1);
	  glTexCoord2f(t_x0,h);
	  glVertex3f(x1,1,z1);
	  // Upper right
	  glNormal3f(x0,0,z0);
	  glTexCoord2f(t_x1,h);
	  glVertex3f(x0,1,z0);
	  // Lower right
	  glNormal3f(x0,0,z0);
	  glTexCoord2f(t_x1,0);
	  glVertex3f(x0,0,z0);
	  // Lower left
	  glNormal3f(x1,0,z1);
	  glTexCoord2f(t_x0,0);
	  glVertex3f(x1,0,z1);
  }
  glEnd();

  glBindTexture(GL_TEXTURE_2D,cap_tex);

  // The top lid
  glColor3f(0,0,0);
  glBegin(GL_TRIANGLE_FAN);
  glNormal3f(0,1,0);
  glTexCoord2f(.5,.5);
  glVertex3f(0,1,0);
  for (i=0.0;i<=pi2;i+=delta) {
  	double x = radius * cos(i);
  	double z = radius * sin(i);
  	glTexCoord2f(cos(i),sin(i));
    glVertex3f(x,1,z);
  }
  glEnd();

  // The bottom lid
  glBegin(GL_TRIANGLE_FAN);
  glNormal3f(0,-1,0);
  glTexCoord2f(.5,.5);
  glVertex3f(0,0,0);
  for (i=0.0;i<=pi2;i+=delta) {
  	double x = radius * cos(i);
  	double z = radius * sin(i);
  	glTexCoord2f(cos(i),sin(i));
  	glVertex3f(x,0,z);
  }
  glEnd();

  glPopMatrix();

  glDisable(GL_TEXTURE_2D);
}