#include "../main.h"

void fountain_side(float thy,unsigned int stone_tex) {
  float white[] = {221.0/255.0,213.0/255.0,242.0/255.0,1};
  float shinyvec[1];
  shinyvec[0] = 64.0;
  glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,shinyvec);
  glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);

  glPushMatrix();

  // Transforms
  glRotated(thy,0,1,0);
  glScaled(10,1.25,10);

  glEnable(GL_TEXTURE_2D);
  glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
  glBindTexture(GL_TEXTURE_2D,stone_tex);

  glColor3f(0.23,0.23,0.23);

  const double pi2 = M_PI * 2;
  const double sinthy = Cos(thy);
  const double sinthyp = Cos(thy+2);
  const double costhy = Sin(thy);
  const double costhyp = Sin(thy+2);

  double i;
  double delta = pi2 / 51.5;
  glBegin(GL_QUADS);
  for (i=0.0;i<=pi2;i+=delta) {
  	double x0 = (i/75)*cos(i);
  	double x1 = ((i+delta)/75)*cos((i+delta));
  	double ny0 = (cos(i)-(i*(sin(i))))/75;
  	double ny1 = (cos((i+delta))-((i+delta)*(sin((i+delta)))))/75;
  	// Upper left
  	glNormal3f(sinthy,ny1,costhy);
  	glTexCoord2f(sinthy,(i+delta)/pi2);
  	glVertex3f(x1,(i+delta)/pi2,.002);
  	// Upper right
  	glNormal3f(sinthyp,ny1,costhyp);
  	glTexCoord2f(sinthyp,(i+delta)/pi2);
  	glVertex3f(x1,(i+delta)/pi2,-.002);
  	// Lower right
  	glNormal3f(sinthyp,ny0,costhyp);
  	glTexCoord2f(sinthyp,i/pi2);
  	glVertex3f(x0,i/pi2,-.002);
  	// Lower left
  	glNormal3f(sinthy,ny0,costhy);
  	glTexCoord2f(sinthy,i/pi2);
  	glVertex3f(x0,i/pi2,.002);
  }
  glEnd();

  glPopMatrix();

  glDisable(GL_TEXTURE_2D);
}