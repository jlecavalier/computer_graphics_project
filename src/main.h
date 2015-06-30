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

// PARTICLE TYPE
typedef struct {
  // Location
  double x;
  double y;
  double z;
  // horizontal motion
  double x_m;
  double z_m;
  // Color
  double r;
  double g;
  double b;
  // Rotation angle
  double th;
  // vertical acceleration
  double accel;
  // vertical deceleration
  double decel;
  // Scaling
  double z_sc;
}PARTICLES;

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
void init_particles(/*PARTICLES particles[200]*/);

// OBJECTS
void axes(double length);
void board(unsigned int grid_tex,
	       unsigned int cyl_tex);
void cylinder(double x,double y,double z,
	          double thx,double thz,
	          double h,double radius,
	          double num_quads,unsigned int cyl_tex,
	          unsigned int cap_tex);
void sphere(float x,float y,float z,double r,
	        double thx,double thy,double thz,
	        unsigned int tex);
void cone(double x,double y,double z,
	      double radius,double height,
	      double thx,double thy,
	      unsigned int tex);
void hourglass(double x,double y,double z,
	           double radius,double height,
	           double thx,double thz,
	           unsigned int tex);
void fountain(unsigned int stone_tex,
	          unsigned int water_tex);
void fountain_side(float thy,unsigned int stone_tex);
void grass_block(double x,double y,double z,double dx_mat[5][5],double th_mat[5][5],
                 unsigned int tex,unsigned int tex_b);
void grass_blade(double x,double y,double z,
	             double dx,double dy,double dz,
	             double th,double thx,double thz,
                 unsigned int tex);

#ifdef __cplusplus
}
#endif

#endif