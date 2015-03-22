#include "stage.hpp"

Stage::Stage() {

}

Stage::~Stage() {

}

void Stage::draw() {
	for(auto o : objects) {
		o->draw();

	}
}

void Stage::draw(GLuint MatrixID,glm::mat4 view, glm::mat4 proj) {
	for(auto o : objects) {
		glm::mat4 ModelMatrix = glm::mat4(1.0);
		ModelMatrix = glm::translate(ModelMatrix,o->translation);
		glm::mat4 MVP = proj * view * ModelMatrix;
		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, glm::value_ptr(MVP));
		o->draw();
	}
}

void Stage::makeObject() {
	for(auto o : objects)
		o->makeObject();

}

void Stage::addObject(GameObject *object) {
	objects.push_back(object);
}
