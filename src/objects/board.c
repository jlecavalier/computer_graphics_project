#include "../main.h"

void board(unsigned int grid_tex,
	       unsigned int cyl_tex) {

  float white[] = {221.0/255.0,213.0/255.0,242.0/255.0,1};
  float shinyvec[1];
  shinyvec[0] = 32.0;
  glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,shinyvec);
  glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);

  glPushMatrix();

  // White, so texture shows up right.
  glColor3f(.6,.6,.6);
  // Texture for the face
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D,grid_tex);
  glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
  // Face of the board
  glBegin(GL_QUADS);
  // Upper left
  glNormal3f(0,+1,0);
  glTexCoord2f(.11,1);
  glVertex3f(-1,0,-1);
  // Upper right
  glTexCoord2f(1.11,1);
  glVertex3f(1,0,-1);
  // Lower right
  glTexCoord2f(1.11,0);
  glVertex3f(1,0,1);
  // Lower left
  glTexCoord2f(.11,0);
  glVertex3f(-1,0,1);
  glEnd();
  
  // Bordering cylinders
  // left side
  cylinder(-1,0,.98,
  	       270,0,
  	       1.965,.03,
  	       300,cyl_tex,
  	       cyl_tex);
  // right side
  cylinder(1,0,.98,
  	       270,0,
  	       1.965,.03,
  	       300,cyl_tex,
  	       cyl_tex);
  // back side
  cylinder(-.98,0,-1,
  	       0,270,
  	       1.965,.03,
  	       300,cyl_tex,
  	       cyl_tex);
  // front side
  cylinder(-.98,0,1,
  	       0,270,
  	       1.965,.03,
  	       300,cyl_tex,
  	       cyl_tex);

  // Corner Spheres
  // lower left
  sphere(-1,0,1,.045,
  	     90,0,0,
  	     cyl_tex);
  // lower right
  sphere(1,0,1,.045,
  	     90,0,0,
  	     cyl_tex);
  // upper right
  sphere(1,0,-1,.045,
  	     90,0,0,
  	     cyl_tex);
  // upper left
  sphere(-1,0,-1,.045,
  	     90,0,0,
  	     cyl_tex);

  glPopMatrix();
  glDisable(GL_TEXTURE_2D);
}