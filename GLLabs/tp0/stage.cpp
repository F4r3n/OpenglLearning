#include "stage.hpp"

Stage::Stage() {

}

Stage::Stage(GLuint programmParticles) {
	particles = Particles(programmParticles);
	numberTore = 0;
	numberSphere = 0;

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

void Stage::addParticle(Particle *particle) {
	particles.addParticle(particle);

}

void Stage::update(float time,GLFWwindow *window) {

	camera.update(time,window);

	glm::mat4 proj = camera.getProjection();
	glm::mat4 view = camera.getView();
	glm::mat4 ModelMatrix = glm::mat4(1.0);
	for(auto programm : programms) {

		glUseProgram(programm.second);
		glUniformMatrix4fv(transID[programm.first], 1, GL_FALSE, glm::value_ptr(ModelMatrix));
		glUniformMatrix4fv(viewID[programm.first], 1, GL_FALSE, glm::value_ptr(view));
		glUniform1f(timeID[programm.first],time);
		glUniformMatrix4fv(projID[programm.first], 1, GL_FALSE, glm::value_ptr(proj));
	}
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
	particles.draw();

}

void Stage::makeObject() {
	int unit=0;
	for(auto o : objects) {
		o->makeObject();
		o->setUnit(unit);
		unit++;
	}
	particles.make();
}


void Stage::addObject(GameObject *object) {
	if(object->getName() =="tore") numberTore++;
	if(object->getName() =="sphere") numberSphere++;

	objects.push_back(object);
}
