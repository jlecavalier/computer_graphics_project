#include "../main.h"

void init_particles(PARTICLES particles[200]) {
  int i;
  for (i=0;i<200;i++) {
  	// Start in the middle of the lotus
  	// of the fountain.
  	particles[i].x = 0;
  	particles[i].y = 1.25;
  	particles[i].z = 0;
    
    // Make the particles move in a random
    // direction outward from the lotus
  	double d = ((double)rand()/360);
  	particles[i].x_m = .01 * Cos(d);
  	particles[i].z_m = .01 * Sin(d);
    
    // Particles are blue, like water.
    particles[i].r = 128.0/256.0;
    particles[i].g = 143.0/256.0;
    particles[i].b = 232.0/256.0;

    // Make the particles tiny
    particles[i].z_sc = .2;

    // Particles do not need to rotate
    particles[i].th = 0;

    // Accelerate and decelerate at different rates
    particles[i].accel = 0.025;
    particles[i].decel = 0.0025;
  }
}