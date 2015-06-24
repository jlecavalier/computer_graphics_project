#include "../main.h"

double animate_scene (int l,int r,int u,int d,
	                  double t_offset) {
  if (l || r || u || d) {
  	glutPostRedisplay();
  	return ((glutGet(GLUT_ELAPSED_TIME)/1.06)-t_offset);
  }
  else {
  	glutPostRedisplay();
  	return 0;
  }
}