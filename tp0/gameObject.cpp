#include "gameObject.hpp"

GameObject::GameObject(std::string &name,GLuint &programm,glm::vec3 translate) {
	_name = name;
	this->programm = programm;
	color = new std::vector<float>();
	pos = new std::vector<float>();
	index = new std::vector<unsigned int>();
	this->translation = translate;

}

void GameObject::makeObject() {

}

glm::mat4 GameObject::moveObject() {
	glm::mat4 m = glm::mat4(1.0);
	m = glm::translate(m,translation);
	return m;
}


void GameObject::draw() {

	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, index->size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

}

GameObject::~GameObject() {
	delete color;
	delete pos;
	delete index;
}
