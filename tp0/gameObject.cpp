#include "gameObject.hpp"

GameObject::GameObject(std::string &name,GLuint &programm) {
	_name = name;
	this->programm = programm;
	color = new std::vector<float>();
	pos = new std::vector<float>();
	index = new std::vector<unsigned int>();

}

void GameObject::makeObject() {

}

void GameObject::translate(double x, double y, double z) {
	glPushMatrix();
	glTranslatef(x,y,z);
	//draw your object
	 
	glPopMatrix();
}

void GameObject::draw() {
	glPushMatrix();

        glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(100,0,0);

	glBindVertexArray(vao);

	glDrawElements(GL_TRIANGLES, index->size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	glPopMatrix();
}

GameObject::~GameObject() {
	delete color;
	delete pos;
	delete index;
}
