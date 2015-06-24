#include "../main.h"

void Vertex(int th,int ph,int out) {
  double x = -Sin(th)*Cos(ph);
  double y = Cos(th)*Cos(ph);
  double z = Sin(ph);
  if (out) {glNormal3d(x,y,z);}
  else {glNormal3d(-x,-y,-z);}
  glTexCoord2d(th/360.0,ph/180.0+0.5);
  glVertex3d(x,y,z);
}