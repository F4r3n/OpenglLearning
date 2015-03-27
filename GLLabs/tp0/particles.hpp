#ifndef PARTICLES_H
#define PARTICLES_H

#include <vector>
#include "particle.hpp"

class Particles {
	public:
		Particles();
		Particles(GLuint programm);
		void make();
		void draw();
		void addParticle(Particle *particle);

	private:
		std::vector<Particle*> particles;
		float x,y;
		GLuint programm;

};

#endif
