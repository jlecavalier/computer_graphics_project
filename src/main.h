#ifndef MAIN_DEFS_H
#define MAIN_DEFS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define Cos(th) cos(3.1415927/180*(th))
#define Sin(th) sin(3.1415927/180*(th))

#ifdef __cplusplus
extern "C" {
#endif

// AUXILIARY
void Print(const char* format , ...);
void Project(int fov,double asp,double dim);
unsigned int LoadTexBMP(const char* file);
void ErrCheck(const char* where);
void Fatal(const char* format , ...);
void Vertex(int th,int ph,int out);
void point_camera();
double animate_scene (int l,int r,int u,int d,
	                  double t_offset);

// OBJECTS
void axes(double length);

#ifdef __cplusplus
}
#endif

#endif