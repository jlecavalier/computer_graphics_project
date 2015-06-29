#include "../main.h"

void fountain_side(float thy,unsigned int stone_tex) {
  float white[] = {221.0/255.0,213.0/255.0,242.0/255.0,1};
  float shinyvec[1];
  shinyvec[0] = 64.0;
  glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,shinyvec);
  glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);

  glPushMatrix();

  // Transforms
  //glRotated(-25,0,0,1);
  glRotated(thy,0,1,0);
  glScaled(5,1,5);

  glEnable(GL_TEXTURE_2D);
  glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
  glBindTexture(GL_TEXTURE_2D,stone_tex);

  glColor3f(1,1,1);

  const double pi2 = M_PI * 2;

  double i;
  double delta = pi2 / 203;
  glBegin(GL_QUADS);
  for (i=0.0;i<=pi2;i+=delta) {
  	double x0 = (i/100)*cos(20*i);
  	double x1 = ((i+delta)/100)*cos(20*(i+delta));
  	double ny0 = (cos(20*i)-(i*20*(sin(20*i))))/20;
  	double ny1 = (cos(20*(i+delta))-((i+delta)*20*(sin(20*(i+delta)))))/20;
  	// Upper left
  	glNormal3f(1,ny1,0);
  	glTexCoord2f(0,(i+delta)/pi2);
  	glVertex3f(x1,(i+delta)/pi2,.002);
  	// Upper right
  	glNormal3f(1,ny1,0);
  	glTexCoord2f(1,(i+delta)/pi2);
  	glVertex3f(x1,(i+delta)/pi2,-.002);
  	// Lower right
  	glNormal3f(1,ny0,0);
  	glTexCoord2f(1,i/pi2);
  	glVertex3f(x0,i/pi2,-.002);
  	// Lower left
  	glNormal3f(1,ny0,0);
  	glTexCoord2f(0,i/pi2);
  	glVertex3f(x0,i/pi2,.002);
  }
  glEnd();

  glPopMatrix();

  glDisable(GL_TEXTURE_2D);
}