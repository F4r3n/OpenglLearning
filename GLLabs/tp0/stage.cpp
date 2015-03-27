#include "stage.hpp"

Stage::Stage() {

}

Stage::Stage(GLuint programmParticles) {
	particles = Particles(programmParticles);
	numberTore = 0;
	numberSphere = 0;

}

void Stage::init(std::vector<GLuint> programms) {

	this->programms = programms;
	for( auto programm : programms) {
		transID.push_back(glGetUniformLocation(programm, "trans"));
		viewID.push_back(glGetUniformLocation(programm, "view"));
		projID.push_back(glGetUniformLocation(programm, "proj"));
		timeID.push_back(glGetUniformLocation(programm, "time"));
	}


	light = Light(programms[0]);
}

void Stage::addParticle(Particle *particle) {
	particles.addParticle(particle);

}

void Stage::update(float time,GLFWwindow *window) {

	camera.update(time,window);

	glm::mat4 proj = camera.getProjection();
	glm::mat4 view = camera.getView();
	glm::mat4 ModelMatrix = glm::mat4(1.0);
	for(int i=0;i<programms.size();i++) {
		glUniformMatrix4fv(transID[i], 1, GL_FALSE, glm::value_ptr(ModelMatrix));
		glUniformMatrix4fv(viewID[i], 1, GL_FALSE, glm::value_ptr(view));
		glUniform1f(timeID[i],time);
		glUniformMatrix4fv(projID[i], 1, GL_FALSE, glm::value_ptr(proj));
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

	glUseProgram(programm);
	light.draw();
	glUseProgram(0);
	for(auto o : objects) {
		glUseProgram(o->getProgramm());
		o->draw();
		glUseProgram(0);
	}
//	particles.draw();

}

void Stage::makeObject() {
	int unit=0;
	for(auto o : objects) {
		o->makeObject();
		o->setUnit(unit);
		unit++;
	}
//	particles.make();
}


void Stage::addObject(GameObject *object) {
	if(object->getName() =="tore") numberTore++;
	if(object->getName() =="sphere") numberSphere++;

	objects.push_back(object);
}
