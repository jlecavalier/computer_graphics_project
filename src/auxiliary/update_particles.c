#include "../main.h"

void update_particles(PARTICLES particles[500]) {
  int i;
  for (i=0;i<500;i++) {
    // Move the particle accordingly
    particles[i].x += particles[i].x_m;
    particles[i].z += particles[i].z_m;
    particles[i].y += particles[i].accel - particles[i].decel;
    // Increase decel so that it falls faster
    particles[i].decel += .0025;
    // Restart the particle if it falls below the fountain
    if (particles[i].y <= .03) {
    particles[i].x = 0;
  	particles[i].y = .2;
  	particles[i].z = 0;
  	double d = (drand48()*360);
  	particles[i].x_m = .005 * Cos(d);
  	particles[i].z_m = .005 * Sin(d);
    particles[i].r = 128.0/256.0;
    particles[i].g = 143.0/256.0;
    particles[i].b = 232.0/256.0;
    particles[i].z_sc = .0045;
    particles[i].th = 0;
    particles[i].accel = (drand48()*0.025);
    particles[i].decel = 0.0025;
    }
  }
}