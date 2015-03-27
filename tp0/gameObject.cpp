#include "gameObject.hpp"

GameObject::GameObject(const std::string &name,GLuint &programm,std::vector<float> &offset) {
	_name = name;
	this->programm = programm;
	color = new std::vector<float>();
	pos = new std::vector<float>();
	index = new std::vector<unsigned int>();
	uvs = new std::vector<float>();
	type = GL_TRIANGLES;
	this->offset = offset;

}

void GameObject::setUnit(int unit) {
	this->unit = unit;
}

void GameObject::makeObject() {
	GLuint positionBuffer;
	GLuint indexBuffer;
	GLuint colorBuffer;
	GLuint textureBuffer;

	GLuint instanceVBO;
	glGenBuffers(1, &instanceVBO);
	glBindBuffer(GL_ARRAY_BUFFER, instanceVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * offset.size(), offset.data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);


	glGenBuffers(1, &positionBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, positionBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertexCount* 3 * sizeof(float), pos->data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &colorBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertexCount*3* sizeof(float), color->data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);


	glGenBuffers(1, &indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, index->size()* sizeof(unsigned int), index->data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glGenBuffers(1, &textureBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, textureBuffer);
	glBufferData(GL_ARRAY_BUFFER, uvs->size()* sizeof(float), uvs->data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	//--------- Encapsulation and setting of VBOs
	glBindBuffer(GL_ARRAY_BUFFER, positionBuffer);
	GLint positionIndex = glGetAttribLocation(programm, "position");//here is the index and the associated GLSL attribute "position" (more on that later)
	glEnableVertexAttribArray(positionIndex);
	glVertexAttribPointer(positionIndex, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
	GLint normalIndex = glGetAttribLocation(programm, "color");
	glEnableVertexAttribArray(normalIndex);
	glVertexAttribPointer(normalIndex, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, textureBuffer);
	GLint textureIndex = glGetAttribLocation(programm, "vertexUv");
	glEnableVertexAttribArray(textureIndex);
	glVertexAttribPointer(textureIndex, 2, GL_FLOAT, GL_FALSE, 0, 0);
	//--------- Encapsulation of an IBO 
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	//--------- Desactivation (clean OpenGl state!!)
	//	glActiveTexture(GL_TEXTURE0);
	//	glBindTexture(GL_TEXTURE_2D, texture);

	// Set our "myTextureSampler" sampler to user Texture Unit 0



	glEnableVertexAttribArray(6);
	glBindBuffer(GL_ARRAY_BUFFER, instanceVBO);
	glVertexAttribPointer(6, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (GLvoid*)0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);	
	glVertexAttribDivisor(6, 1);  

	glBindVertexArray(0);
	check_gl_error();
}

std::string GameObject::getName() {
	return _name;
}

void GameObject::setType(GLuint type) {
	this->type = type;
}

glm::mat4 GameObject::moveObject() {
	glm::mat4 m = glm::mat4(1.0);
	m = glm::translate(m,translation);
	return m;
}


void GameObject::draw() {

	GLfloat fLargest;
	glActiveTexture(GL_TEXTURE0);

	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	// Set our "myTextureSampler" sampler to user Texture Unit 0
	glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &fLargest);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, fLargest);
	glUniform1i(textureID, 0);
	glBindVertexArray(vao);
	glDrawElementsInstanced(type, index->size(), GL_UNSIGNED_INT, 0,offset.size()/3);
	glBindVertexArray(0);

}

GameObject::~GameObject() {
	delete color;
	delete pos;
	delete index;
}
