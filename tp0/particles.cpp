#include "particles.hpp"

Particles::Particles() {
	timer = 0;
}

Particles::Particles(GLuint programm,Particle *particle) {
	this->programm = programm;
	particles.push_back(particle);
	timer = 0;
	frequency = 2;
}

void Particles::update(float dt) {
		timer+=dt;
		if(timer>frequency) {
			std::cout << "redraw" << std::endl;
			redraw();
			timer = 0;
		}

	for(auto p: particles) {
		p->update(dt);
	}
}

void Particles::redraw() {

	for(auto p: particles) {
		p->time=0; 
	}
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
