#include "../main.h"

void init_particles(PARTICLES particles[500]) {
  int i;
  for (i=0;i<500;i++) {
  	// Start in the middle of the lotus
  	// of the fountain.
  	particles[i].x = 0;
  	particles[i].y = .2;
  	particles[i].z = 0;
    
    // Make the particles move in a random
    // direction outward from the lotus
  	double d = (drand48()*360);
  	particles[i].x_m = .005 * Cos(d);
  	particles[i].z_m = .005 * Sin(d);
    
    // Particles are blue, like water.
    particles[i].r = 128.0/256.0;
    particles[i].g = 143.0/256.0;
    particles[i].b = 232.0/256.0;

    // Make the particles tiny
    particles[i].z_sc = .0045;

    // Particles do not need to rotate
    particles[i].th = 0;

    // Accelerate and decelerate at different rates
    particles[i].accel = (drand48()*0.025);
    particles[i].decel = 0.0025;
  }
}