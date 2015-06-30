#include "../main.h"

void draw_particles(PARTICLES particles[500]) {
  int i;
  for (i=0;i<500;i++) {
    // Color the particle
  	glColor4f(particles[i].r,particles[i].g,particles[i].b,.6);

  	glPushMatrix();

  	glEnable(GL_BLEND);
  	glBlendFunc(GL_SRC_ALPHA,GL_SRC_ALPHA);

  	// Transforms
  	glTranslated(particles[i].x,particles[i].y,particles[i].z);
  	glScaled(particles[i].z_sc,particles[i].z_sc,particles[i].z_sc);
    
    // Draw the particles
  	glBegin (GL_QUADS);
    glVertex3f (0, 1, 0);
    glVertex3f (1, 1, 0);
    glVertex3f (1, 0, 0);
    glVertex3f (0, 0, 0);
    glEnd();

    glDisable(GL_BLEND);

    glPopMatrix();
  }
}