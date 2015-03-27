#include "particle.hpp"


Particle::Particle(unsigned int maxParticles, glm::vec3 pos, glm::vec3 color) {
	this->maxParticles = maxParticles;
	this->pos = pos;
	this->color = color;
}

void Particle::makeObject() {
	const GLfloat g_vertex_buffer_data[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f,
		0.5f, 0.5f, 0.0f,
	};
	GLuint billboard_vertex_buffer;
	glGenBuffers(1, &billboard_vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, billboard_vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	// The VBO containing the positions and sizes of the particles
	GLuint particles_position_buffer;
	glGenBuffers(1, &particles_position_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, particles_position_buffer);
	// Initialize with empty (NULL) buffer : it will be updated later, each frame.
	glBufferData(GL_ARRAY_BUFFER, maxParticles *  sizeof(glm::vec3), glm::value_ptr(pos), GL_STATIC_DRAW);

	// The VBO containing the colors of the particles
	GLuint particles_color_buffer;
	glGenBuffers(1, &particles_color_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, particles_color_buffer);
	// Initialize with empty (NULL) buffer : it will be updated later, each frame.
	glBufferData(GL_ARRAY_BUFFER, maxParticles * sizeof(glm::vec3), glm::value_ptr(color), GL_STATIC_DRAW);


	unsigned int index[] = {0,1,2,3};
	GLuint indexBuffer;
	glGenBuffers(1, &indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index), index, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, billboard_vertex_buffer);
	glVertexAttribPointer(
			  0, // attribute. No particular reason for 0, but must match the layout in the shader.
			  3, // size
			  GL_FLOAT, // type
			  GL_FALSE, // normalized?
			  0, // stride
			  (void*)0 // array buffer offset
			  );

	// 2nd attribute buffer : positions of particles' centers
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, particles_position_buffer);
	glVertexAttribPointer(
			  1, // attribute. No particular reason for 1, but must match the layout in the shader.
			  1, // size : x + y + z + size => 4
			  GL_FLOAT, // type
			  GL_TRUE, // normalized?
			  0, // stride
			  (void*)0 // array buffer offset
			  );

	// 3rd attribute buffer : particles' colors
	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, particles_color_buffer);
	glVertexAttribPointer(
			  2, // attribute. No particular reason for 1, but must match the layout in the shader.
			  1, // size : r + g + b + a => 4
			  GL_UNSIGNED_BYTE, // type
			  GL_TRUE, // normalized? *** YES, this means that the unsigned char[4] will be accessible with a vec4 (floats) in the shader ***
			  0, // stride
			  (void*)0 // array buffer offset
			  );

	glVertexAttribDivisor(2, 1);  
	glVertexAttribDivisor(1, 1);  

}


void Particle::draw() {
	
	glBindVertexArray(vao);
	glDrawElementsInstanced(GL_TRIANGLES, 4, GL_UNSIGNED_INT, 0,maxParticles);
	glBindVertexArray(0);
}
