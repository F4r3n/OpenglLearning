#include "stage.hpp"


Stage::Stage() {
}

void Stage::init(std::map<std::string,GLuint> programms) {

	this->programms = programms;
	for( auto programm : programms) {
		glUseProgram(programm.second);
		transID[programm.first] = (glGetUniformLocation(programm.second, "trans"));
		viewID[programm.first] = (glGetUniformLocation(programm.second, "view"));
		projID[programm.first] = (glGetUniformLocation(programm.second, "proj"));
		timeID[programm.first] = (glGetUniformLocation(programm.second, "time"));
	}


	light = Light(programms["minimal"]);
}

void Stage::addParticle(Particles *particles) {
	particlesTransmitter.push_back(particles);

}

void Stage::update(float time,GLFWwindow *window, float dt) {

	camera.update(time,window);


	glm::mat4 proj = camera.getProjection();
	glm::mat4 view = camera.getView();
	glm::mat4 ModelMatrix = glm::mat4(1.0);
	for(auto programm : programms) {

		glUseProgram(programm.second);
		glUniformMatrix4fv(transID[programm.first], 1, GL_FALSE, glm::value_ptr(ModelMatrix));
		glUniformMatrix4fv(viewID[programm.first], 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(projID[programm.first], 1, GL_FALSE, glm::value_ptr(proj));
	}
	glUseProgram(programms["minimal"]);

	glUniform1f(timeID["minimal"],time);
	for(auto particles : particlesTransmitter)
		particles->update(dt);
}

Stage::~Stage() {

}


void Stage::setType(GLuint type) {
	for(auto o : objects) {
		o->setType(type);
	}
}

void Stage::draw() {

	glUseProgram(programms["minimal"]);
	light.draw();
	glUseProgram(0);
	for(auto o : objects) {
		glUseProgram(o->getProgramm());
		o->draw();
		glUseProgram(0);
	}
	for(auto particles : particlesTransmitter)
		particles->draw();

}

void Stage::makeObject() {
	int unit=0;
	for(auto o : objects) {
		o->makeObject();
		o->setUnit(unit);
		unit++;
	}

	for(auto particles : particlesTransmitter)
		particles->make();
}


void Stage::addObject(GameObject *object) {

	objects.push_back(object);
}
