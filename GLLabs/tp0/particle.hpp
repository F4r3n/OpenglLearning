#ifndef PARTICLE_H
#define PARTICLE_H

#include <GL/glew.h>  // must be included before gl.h
#include <GLFW/glfw3.h>
#include <fstream>
#include <iostream>
#include <vector>
#include "textures.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/constants.hpp>
class Particle {

	public:
		Particle(unsigned int maxParticles, glm::vec3 pos, glm::vec3 color);
		void makeObject();
		void draw();
	private:
		glm::vec3 pos;
		glm::vec3 color;

		float speed;
		float size;
		unsigned int maxParticles;
		GLuint vao;



};

#endif
