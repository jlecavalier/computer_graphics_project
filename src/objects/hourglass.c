#include "../main.h"

void hourglass(double x,double y,double z,
	           double radius,double height,
	           double thx,double thz,
	           unsigned int tex) {
  glPushMatrix();

  glTranslated(x,y,z);
  glRotated(thx,1,0,0);
  glRotated(thz,0,0,1);
  glScaled(radius,height,radius);

  cone(0,0,0,
  	   1,.5,
  	   0,0,
  	   tex);
  cone(0,.5,0,
  	   1,.5,
  	   180,0,
  	   tex);

  glPopMatrix();
}