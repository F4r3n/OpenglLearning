#ifndef STAGE_H
#define STAGE_H

#include "camera.hpp"
#include "gameObject.hpp"
#include "light.hpp"

class Stage {
	public:
		Stage();
		~Stage();
		void addObject(GameObject *object);
		void draw();
		void makeObject();
		void setType(GLuint type);
		void init(GLuint programm);
		void update(float time,GLFWwindow *window);

	private:
		std::vector<GameObject*> objects;
		Camera camera;
		GLuint transID;
		GLuint viewID;
		GLuint projID;
		Light light;
		int numberTore;
		int numberSphere;
		GLuint timeID;
		GLuint programm;
	

};

#endif
