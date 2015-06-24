#include "../main.h"

void cylinder(double x,double y,double z,
	          double thx,double thz,
	          double h,double radius,
	          double num_quads,unsigned int cyl_tex) {

  float white[] = {1,1,1,1};
  float shinyvec[1];
  shinyvec[0] = 128.0;
  glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,shinyvec);
  glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);

  glPushMatrix();

  // Transformations
  glTranslated(x,y,z);
  glRotated(thx,1,0,0);
  glRotated(thz,0,0,1);
  glScaled(1,h,1);

  // White so the texture shows up right
  glColor3f(0.27,0.27,0.27);

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
  for (i=0.0;i<=pi2;i+=delta) {
  	  double x0 = radius * cos(i);
  	  double x1 = radius * cos(i+delta);
  	  double z0 = radius * sin(i);
  	  double z1 = radius * sin(i+delta);
  	  double n_x = z1 - z0;
  	  double n_z = x0 - x1;
  	  double t_x0 = i/pi2;
  	  double t_x1 = (i+delta)/pi2;
  	  glBegin(GL_QUADS);
	  // Upper left
	  glNormal3d(n_x,0,n_z);
	  glTexCoord2f(t_x0,h*12);
	  glVertex3f(x1,1,z1);
	  // Upper right
	  glNormal3d(n_x,0,n_z);
	  glTexCoord2f(t_x1,h*12);
	  glVertex3f(x0,1,z0);
	  // Lower right
	  glNormal3d(n_x,0,n_z);
	  glTexCoord2f(t_x1,0);
	  glVertex3f(x0,0,z0);
	  // Lower left
	  glNormal3d(n_x,0,n_z);
	  glTexCoord2f(t_x0,0);
	  glVertex3f(x1,0,z1);

	  glEnd();
  }
  glDisable(GL_TEXTURE_2D);

  // The top lid
  glColor3f(0,0,0);
  glBegin(GL_TRIANGLE_FAN);
  glVertex3f(0,1,0);
  for (i=0.0;i<=pi2;i+=delta) {
  	double x = radius * cos(i);
  	double z = radius * sin(i);
  	glNormal3d(0,1,0);
    glVertex3f(x,1,z);
  }
  glEnd();

  // The bottom lid
  glBegin(GL_TRIANGLE_FAN);
  glVertex3f(0,0,0);
  for (i=0.0;i<=pi2;i+=delta) {
  	double x = radius * cos(i);
  	double z = radius * sin(i);
  	glNormal3d(0,-1,0);
  	glVertex3f(x,0,z);
  }
  glEnd();

  glPopMatrix();
}