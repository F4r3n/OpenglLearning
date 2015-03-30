#ifndef STAGE_H
#define STAGE_H

#include "camera.hpp"
#include "gameObject.hpp"
#include "light.hpp"
#include "particles.hpp"
#include <map>

class Stage {
	public:
		Stage();
		Stage(GLuint programm);
		~Stage();
		void addObject(GameObject *object);
		void addParticle(Particles *particles);
		void draw();
		void makeObject();
		void setType(GLuint type);
		void init(std::map<std::string,GLuint> programms);
		void update(float time,GLFWwindow *window, float dt);

	private:
		std::vector<GameObject*> objects;
		std::vector<Particles*> particlesTransmitter;
		Camera camera;
		std::map<std::string,GLuint> transID;
		std::map<std::string,GLuint> viewID;
		std::map<std::string,GLuint> projID;
		Light light;
		std::map<std::string,GLuint> timeID;
		std::map<std::string,GLuint> programms;
	

};

#endif
