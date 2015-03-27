#ifndef STAGE_H
#define STAGE_H

#include "camera.hpp"
#include "gameObject.hpp"
#include "light.hpp"
#include "particles.hpp"

class Stage {
	public:
		Stage();
		Stage(GLuint programm);
		~Stage();
		void addObject(GameObject *object);
		void addParticle(Particle *particle);
		void draw();
		void makeObject();
		void setType(GLuint type);
		void init(std::vector<GLuint> programms);
		void update(float time,GLFWwindow *window);

	private:
		std::vector<GameObject*> objects;
		Particles particles;
		Camera camera;
		std::vector<GLuint> transID;
		std::vector<GLuint> viewID;
		std::vector<GLuint> projID;
		Light light;
		int numberTore;
		int numberSphere;
		std::vector<GLuint> timeID;
		std::vector<GLuint> programms;
		GLuint programm;
	

};

#endif
