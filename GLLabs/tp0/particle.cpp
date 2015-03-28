#include "particle.hpp"


Particle::Particle(GLuint programm,unsigned int maxParticles, glm::vec3 pos, glm::vec3 color) {
	this->maxParticles = maxParticles;
	this->pos = pos;
	this->color = color;
	this->programm = programm;
}

void Particle::makeObject() {
	const GLfloat g_vertex_buffer_data[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f,
		0.5f, 0.5f, 0.0f,
	};

	float positions [4*maxParticles];
	for(int i=0;i<4*maxParticles;i+=4) {
		positions[i] = pos[0];
		positions[i+1] = pos[1];
		positions[i+2] = pos[2];
		positions[i+3] = 0.1f;
	}

	float colors [4*maxParticles];
	int indexColor =1;
	for(int i=0;i<4*maxParticles;i+=4) {
		colors[i] = indexColor%2/2.0f;
		colors[i+1] = 0;
		colors[i+2] = indexColor%2;
		colors[i+3] = 1;
		indexColor++;
	}
	GLuint billboard_vertex_buffer;
	glGenBuffers(1, &billboard_vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, billboard_vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	// The VBO containing the positions and sizes of the particles
	GLuint particles_position_buffer;
	glGenBuffers(1, &particles_position_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, particles_position_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

	// The VBO containing the colors of the particles
	GLuint particles_color_buffer;
	glGenBuffers(1, &particles_color_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, particles_color_buffer);
	glBufferData(GL_ARRAY_BUFFER,sizeof(positions), colors, GL_STATIC_DRAW);


	unsigned int index[] = {0,1,2,3};
	GLuint indexBuffer;
	glGenBuffers(1, &indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index), index, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);


	glBindBuffer(GL_ARRAY_BUFFER, billboard_vertex_buffer);
	GLint positionIndex = glGetAttribLocation(programm, "position");//here is the index and the associated GLSL attribute "position" (more on that later)
	glEnableVertexAttribArray(positionIndex);
	glVertexAttribPointer(positionIndex, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);

	// 2nd attribute buffer : positions of particles' centers
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, particles_position_buffer);
	glVertexAttribPointer(1,4, GL_FLOAT, GL_FALSE, 4*sizeof(float), (void*)0 );

	// 3rd attribute buffer : particles' colors
	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, particles_color_buffer);
	glVertexAttribPointer(2,4,GL_FLOAT, GL_FALSE,4*sizeof(float), (void*)0 );

	glVertexAttribDivisor(1, 1);  
	glVertexAttribDivisor(2, 1);  

	glBindVertexArray(0);
}


void Particle::draw() {
	
	glBindVertexArray(vao);
	glDrawElementsInstanced(GL_TRIANGLES, 4, GL_UNSIGNED_INT, 0,maxParticles);
	glBindVertexArray(0);
}
