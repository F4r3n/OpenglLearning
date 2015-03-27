#include "stage.hpp"

Stage::Stage() {
	numberTore = 0;
	numberSphere = 0;

}

void Stage::init(GLuint programm) {

	this->programm = programm;
	transID = glGetUniformLocation(programm, "trans");
	viewID = glGetUniformLocation(programm, "view");
	projID = glGetUniformLocation(programm, "proj");
	timeID = glGetUniformLocation(programm, "time");
	light = Light(programm);
}

void Stage::update(float time,GLFWwindow *window) {

		camera.update(time,window);

		glm::mat4 proj = camera.getProjection();
		glm::mat4 view = camera.getView();
		glm::mat4 ModelMatrix = glm::mat4(1.0);
		glUniformMatrix4fv(transID, 1, GL_FALSE, glm::value_ptr(ModelMatrix));
		glUniformMatrix4fv(viewID, 1, GL_FALSE, glm::value_ptr(view));
		glUniform1f(timeID,time);
		glUniformMatrix4fv(projID, 1, GL_FALSE, glm::value_ptr(proj));
}

Stage::~Stage() {

}


void Stage::setType(GLuint type) {
	for(auto o : objects) {
		o->setType(type);
	}
}

void Stage::draw() {

	glUseProgram(programm);
	light.draw();
	glUseProgram(0);
	for(auto o : objects) {
		glUseProgram(o->getProgramm());
		o->draw();
		glUseProgram(0);
	}

}

void Stage::makeObject() {
	int unit=0;
	for(auto o : objects) {
		o->makeObject();
		o->setUnit(unit);
		unit++;
	}
}


void Stage::addObject(GameObject *object) {
	if(object->getName() =="tore") numberTore++;
	if(object->getName() =="sphere") numberSphere++;

	objects.push_back(object);
}
