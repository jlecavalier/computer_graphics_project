#include "../main.h"

void sphere(float x,float y,float z,double r,
	        double thx,double thy,double thz,
	        unsigned int tex) {
  const int d=5;
  int th,ph;
  
  float white[] = {1,1,1,1};
  glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);
  // Save transforms
  glPushMatrix();
  // Offset
  glTranslated(x,y,z);
  glRotated(thx,1,0,0);
  glRotated(thy,0,1,0);
  glRotated(thz,0,0,1);
  glScaled(r,r,r);
  // Texture for the sphere
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D,tex);
  glColor3f(.2,.2,.2);
  // Latitude bands
  for (ph=-90;ph<90;ph+=d) {
  	glBegin(GL_QUAD_STRIP);
  	for (th=0;th<=360;th+=d) {
  	  Vertex(th,ph,1);
  	  Vertex(th,ph+5,1);
  	}
  	glEnd();
  }

  // Undo transforms
  glPopMatrix();
  glDisable(GL_TEXTURE_2D);
}