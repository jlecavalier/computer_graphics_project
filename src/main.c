#include "main.h"

// Global Vars
double win_width;
double win_height;
double asp;

void display() {
  // Erase the window and the depth buffer
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  // Enable Z-Buffering
  glEnable(GL_DEPTH_TEST);
  // Undo transforms
  glLoadIdentity();
  // Print hello, world!
  glColor3f(1,1,1);
  glWindowPos2i(5,25);
  Print("Hello, world!");
  glFlush();
  glutSwapBuffers();
}

void key(unsigned char ch,int x,int y) {
  // Exit when the user presses ESC
  if (ch == 27) {
    exit(0);
  }
  glutPostRedisplay();
}

void reshape(int width,int height) {
  // Find the aspect ratio
  asp = (height>0) ? (double)width/height : 1;
  // Set global width and height
  win_width = (double)width;
  win_height = (double)height;
  // Set the viewport to the entire window
  glViewport(0,0,width,height);
  glutPostRedisplay();
}

/*
  Start up GLUT and tell it what to do
*/
int main(int argc, char* argv[]) {
  // Initialize GLUT
  glutInit(&argc,argv);
  // Request double buffer, true color, z buffering
  glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
  // Window is as large as the user's computer can handle
  int user_width = glutGet(GLUT_SCREEN_WIDTH);
  int user_height = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize(user_width,user_height);
  // Actually create the window
  glutCreateWindow("Jay LeCavalier --- final project");
  // Set callbacks
  glutDisplayFunc(display);
  glutKeyboardFunc(key);
  glutReshapeFunc(reshape);
  // Pass control to GLUT so it can interact with the user
  ErrCheck("init");
  glutMainLoop();
  return 0;
}