#include "../main.h"

void board(unsigned int grid_tex) {
  glPushMatrix();
  // White, so texture shows up right.
  glColor3f(1,1,1);
  // Texture for the face
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D,grid_tex);
  // Face of the board
  glBegin(GL_QUADS);
  // Lower right
  glNormal3d(0,1,0);
  glVertex3f(1,0,1);
  glTexCoord2d(.11,1);
  // Upper right
  glNormal3d(0,1,0);
  glVertex3f(1,0,-1);
  glTexCoord2d(1.11,1);
  // Upper left
  glNormal3d(0,1,0);
  glVertex3f(-1,0,-1);
  glTexCoord2d(1.11,0);
  // Lower left
  glNormal3d(0,1,0);
  glVertex3f(-1,0,1);
  glTexCoord2d(.11,0);
  glEnd();
  glDisable(GL_TEXTURE_2D);

  // Bordering cylinders
  // left side
  cylinder(-1,0,.98,
  	       270,0,
  	       1.965,.03,
  	       26);
  // right side
  cylinder(1,0,.98,
  	       270,0,
  	       1.965,.03,
  	       26);
  // back side
  cylinder(-.98,0,-1,
  	       0,270,
  	       1.965,.03,
  	       26);
  // front side
  cylinder(-.98,0,1,
  	       0,270,
  	       1.965,.03,
  	       26);

  glPopMatrix();
}