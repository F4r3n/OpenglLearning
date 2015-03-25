#ifndef STAGE_H
#define STAGE_H

#include "gameObject.hpp"
class Stage {
	public:
		Stage();
		~Stage();
		void addObject(GameObject *object);
		void draw();
		void makeObject();
		void draw(GLuint MatrixID,glm::mat4 view,glm::mat4 proj);
		void setType(GLuint type);
		void init(GLuint programm);

	private:
		std::vector<GameObject*> objects;
		GLuint transID;
		GLuint viewID;
		GLuint projID;
		int numberTore;
		int numberSphere;
	

};

#endif
