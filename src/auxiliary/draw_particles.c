#include "../main.h"

void draw_particles(PARTICLES particles[500],
	                unsigned int mask,
	                unsigned int tex) {
  int i;
  for (i=0;i<500;i++) {
    // Color the particle
  	glColor4f(particles[i].r,particles[i].g,particles[i].b,.6);

  	glPushMatrix();

  	// Transforms
  	glTranslated(particles[i].x,particles[i].y,particles[i].z);
  	glScaled(particles[i].z_sc,particles[i].z_sc,particles[i].z_sc);

    glEnable(GL_TEXTURE_2D);
    glDisable(GL_DEPTH_TEST);
  	glEnable(GL_BLEND);
  	glBlendFunc(GL_DST_COLOR,GL_ZERO);
  	glBindTexture(GL_TEXTURE_2D,mask);
    
    // Draw the particle mask
  	glBegin (GL_QUADS);
  	glTexCoord2f(0,1);
    glVertex3f (0, 1, 0);
    glTexCoord2f(1,1);
    glVertex3f (1, 1, 0);
    glTexCoord2f(1,0);
    glVertex3f (1, 0, 0);
    glTexCoord2f(0,0);
    glVertex3f (0, 0, 0);
    glEnd();

    glBlendFunc(GL_ONE, GL_ONE);
    glBindTexture(GL_TEXTURE_2D,tex);

    // Draw the particle
  	glBegin (GL_QUADS);
  	glTexCoord2f(0,1);
    glVertex3f (0, 1, 0);
    glTexCoord2f(1,1);
    glVertex3f (1, 1, 0);
    glTexCoord2f(1,0);
    glVertex3f (1, 0, 0);
    glTexCoord2f(0,0);
    glVertex3f (0, 0, 0);
    glEnd();

    glDisable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);

    glPopMatrix();

  }
}