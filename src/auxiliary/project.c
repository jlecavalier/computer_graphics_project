#include "../main.h"

/*
  Manipulates the projection matrix. If the user is in
  perspective mode, we will use gluPerspective() with
  view angle fov
  aspect ratio asp
  near clipping plane dim/4
  far clipping plane 4*dim
*/

void Project(int fov,double asp,double dim) {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  // Perspective transformation
  gluPerspective(fov,asp,dim/4,4*dim);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}