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
double frame;

// Rotations for the board
double thy=0;
double thx=0;
double thz=0;

// Animation lengths
const double tilt_frames = 1500;

// Texture names
unsigned int texture[2];

static void ball(double x,double y,double z,double r)
{
   //  Save transformation
   glPushMatrix();
   //  Offset, scale and rotate
   glTranslated(x,y,z);
   glScaled(r,r,r);
   //  White ball
   glColor3f(1,1,1);
   glutSolidSphere(1.0,16,16);
   //  Undo transofrmations
   glPopMatrix();
}

void display() {
  // Animation trigger
  int a_trigger = (animate_left || animate_right ||
  	               animate_up || animate_down);
  // Background color
  glClearColor(118.0/255.0,118.0/255.0,173.0/255.0,1);
  // Erase the window and the depth buffer
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  // Enable Z-Buffering
  glEnable(GL_DEPTH_TEST);
  // Undo transforms
  glLoadIdentity();
  // Point the camera.
  point_camera();
  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  /*************
   * LIGHTING  *
   *************/
  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  float Ambient[] = {.6,.6,.6,1.0};
  float Diffuse[] = {.5,.5,.5,1.0};
  float Specular[] = {2.0,2.0,2.0,1.0};
  glShadeModel(GL_SMOOTH);

  // Light 0
  float Position0[] = {.15,1,1,1};
  //ball(Position0[0],Position0[1],Position0[2],0.1);
  glEnable(GL_NORMALIZE);
  glEnable(GL_LIGHTING);
  glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
  glEnable(GL_COLOR_MATERIAL);
  glEnable(GL_LIGHT0);
  glLightfv(GL_LIGHT0,GL_AMBIENT,Ambient);
  glLightfv(GL_LIGHT0,GL_DIFFUSE,Diffuse);
  glLightfv(GL_LIGHT0,GL_SPECULAR,Specular);
  glLightfv(GL_LIGHT0,GL_POSITION,Position0);

  // Light 1
  float Position1[] = {-.15,1,-1,1};
  //ball(Position1[0],Position1[1],Position1[2],0.1);
  glEnable(GL_LIGHT1);
  glLightfv(GL_LIGHT1,GL_AMBIENT,Ambient);
  glLightfv(GL_LIGHT1,GL_DIFFUSE,Diffuse);
  glLightfv(GL_LIGHT1,GL_SPECULAR,Specular);
  glLightfv(GL_LIGHT1,GL_POSITION,Position1);

  // Light 2
  float Position2[] = {-1,1,-.15,1};
  //ball(Position2[0],Position2[1],Position2[2],0.1);
  glEnable(GL_LIGHT2);
  glLightfv(GL_LIGHT2,GL_AMBIENT,Ambient);
  glLightfv(GL_LIGHT2,GL_DIFFUSE,Diffuse);
  glLightfv(GL_LIGHT2,GL_SPECULAR,Specular);
  glLightfv(GL_LIGHT2,GL_POSITION,Position2);

  // Light 3
  float Position3[] = {1,1,.15,1};
  //ball(Position3[0],Position3[1],Position3[2],0.1);
  glEnable(GL_LIGHT3);
  glLightfv(GL_LIGHT3,GL_AMBIENT,Ambient);
  glLightfv(GL_LIGHT3,GL_DIFFUSE,Diffuse);
  glLightfv(GL_LIGHT3,GL_SPECULAR,Specular);
  glLightfv(GL_LIGHT3,GL_POSITION,Position3);
  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  /*************
   * ANIMATION *
   *************/
  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  // Transform the scene accordingly
  glRotated(thz,0,0,1);
  glRotated(thx,1,0,0);
  // Animate the scene if it needs to be animated
  frame = animate_scene(animate_left,
                        animate_right,
                        animate_up,
                        animate_down,
                        t_offset);
  if (frame >= tilt_frames) {
  // Tilt animation completed. Reset the 
  // animation triggers
    animate_right = 0;
    animate_up = 0;
    animate_down = 0;
    animate_left = 0;
  }
  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  /*************
   *  OBJECTS  *
   *************/
  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  board(texture[0],
  	    texture[1]);
  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  /*************
   * DEBUGGING *
   *************/
  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  if (debug) {
    // Axes
    axes(1);
    // Print info about the animation
    glColor3f(1,1,1);
    glWindowPos2i(5,5);
    Print("Animation trigger: %s",a_trigger ? "YES" : "NO");
    glWindowPos2i(5,20);
    Print("Animation frame: %f",a_trigger ? (glutGet(GLUT_ELAPSED_TIME)/1.06)-t_offset : 0);
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
  double fo2 = (tilt_frames/2);
  // Tilt left
  if (animate_left) {
    if ((thz < 45) && (frame < fo2)) {
      thz += 1.1;
    }
    else {
      thz -= 1.1;
    }
  }
  // Tilt right
  if (animate_right) {
    if ((thz > -45) && (frame < fo2)) {
      thz -= 1.1;
    }
    else {
      thz += 1.1;
    }
  }
  // Tilt up
  if (animate_up) {
    if ((thx > -45) && (frame < fo2)) {
      thx -= 1.1;
    }
    else {
      thx += 1.1;
    }
  }
  // Tilt down
  if (animate_down) {
    if ((thx < 45) && (frame < fo2)) {
      thx += 1.1;
    }
    else {
      thx -= 1.1;
    }
  }

  if (frame == 0) {
  	thz=0;
  	thx=0;
  	thy=0;
  }

  glutPostRedisplay();
  Project(fov,asp,dim);
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
  // Load textures
  texture[0] = LoadTexBMP("./src/textures/grid.bmp");
  texture[1] = LoadTexBMP("./src/textures/graph.bmp");
  // Pass control to GLUT so it can interact with the user
  ErrCheck("init");
  glutMainLoop();
  return 0;
}