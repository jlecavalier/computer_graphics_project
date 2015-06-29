#include "../main.h"

void fountain(unsigned int stone_tex,
	          unsigned int water_tex) {
  float white[] = {221.0/255.0,213.0/255.0,242.0/255.0,1};
  float shinyvec[1];
  shinyvec[0] = 64.0;
  glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,shinyvec);
  glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);

  glPushMatrix();

  // Transforms
  glScaled(.2,.2,.2);

  // Color of polys
  glColor3f(0.3,0.3,0.3);

  // Cylinder for base
  cylinder(0,0,0,
  	       0,0,
  	       .4,1,
  	       503,stone_tex,
  	       water_tex);

  glEnable(GL_TEXTURE_2D);
  glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
  glBindTexture(GL_TEXTURE_2D,stone_tex);

  glColor3f(1,1,1);

  // Weird shape for body
  double i;
  for(i=0.0;i<=360;i++) {
  	fountain_side(i,stone_tex);
  }

  glPopMatrix();

  glDisable(GL_TEXTURE_2D);

}