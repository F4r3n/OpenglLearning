#include "particles.hpp"

Particles::Particles() {

}

Particles::Particles(GLuint programm) {
	this->programm = programm;
}


void Particles::addParticle(Particle *particle) {
	particles.push_back(particle);

}

void Particles::make() {

	glUseProgram(programm);
	for(auto p: particles) {
		p->makeObject();
	}

}

void Particles::draw() {
	glUseProgram(programm);
	for(auto p: particles) {
		p->draw();

	}


}
