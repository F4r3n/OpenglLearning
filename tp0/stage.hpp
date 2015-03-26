#ifndef STAGE_H
#define STAGE_H

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
		void update(float time,GLuint MatrixID,glm::mat4 view,glm::mat4 proj);

	private:
		std::vector<GameObject*> objects;
		GLuint transID;
		GLuint viewID;
		GLuint projID;
		Light light;
		int numberTore;
		int numberSphere;
		GLuint timeID;
	

};

#endif
