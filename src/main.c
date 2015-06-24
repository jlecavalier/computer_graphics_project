#include "main.h"

// Global Vars
// Window sizing
double win_width;
double win_height;
double asp=1;

// Projection
int fov=55;
double dim=4;

// Animation triggers
int animate_right=0;
int animate_left=0;
int animate_up=0;
int animate_down=0;

// Debug trigger
int debug=0;

// Animation timer
double t_offset;

void display() {
  // Erase the window and the depth buffer
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  // Enable Z-Buffering
  glEnable(GL_DEPTH_TEST);
  // Undo transforms
  glLoadIdentity();
  // Point the camera.
  point_camera();
  // Animate the scene if it needs to be animated
  if (animate_scene(animate_left,
                    animate_right,
                    animate_up,
                    animate_down,
                    t_offset) >= 3000) {
  // The animation completed. Reset the 
  // animation triggers
    animate_right = 0;
    animate_up = 0;
    animate_down = 0;
    animate_left = 0;
  }
  if (debug) {
    // Axes
    axes(1);
    // Print info about the animation
    glColor3f(1,1,1);
    glWindowPos2i(5,5);
    Print("Animation trigger: %s",
         (animate_left || 
          animate_right || 
          animate_down || 
          animate_up) ? "YES" : "NO");
    glWindowPos2i(win_width-130,win_height-20);
    Print("DEBUG MODE");
  }
  // End
  glFlush();
  glutSwapBuffers();
}

void key(unsigned char ch,int x,int y) {
  // Exit when the user presses ESC
  if (ch == 27) {
    exit(0);
  }
  // Debug mode
  else if (ch == 'd' || ch == 'D') {
    debug = 1 - debug;
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
  Project(fov,asp,dim);
}

void special(int key,int x,int y) {
  if (!(animate_up || animate_right || 
        animate_down || animate_left)) {
    if (key == GLUT_KEY_RIGHT) {
      animate_right = 1;
      t_offset = glutGet(GLUT_ELAPSED_TIME)/1.06;
    }
    if (key == GLUT_KEY_LEFT) {
      animate_left = 1;
      t_offset = glutGet(GLUT_ELAPSED_TIME)/1.06;
    }
    if (key == GLUT_KEY_UP) {
      animate_up = 1;
      t_offset = glutGet(GLUT_ELAPSED_TIME)/1.06;
    }
    if (key == GLUT_KEY_DOWN) {
      animate_down = 1;
      t_offset = glutGet(GLUT_ELAPSED_TIME)/1.06;
    }
  }
  glutPostRedisplay();
  Project(fov,asp,dim);
}

void idle() {
  Project(fov,asp,dim);
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
  glutSpecialFunc(special);
  glutIdleFunc(idle);
  // Pass control to GLUT so it can interact with the user
  ErrCheck("init");
  glutMainLoop();
  return 0;
}