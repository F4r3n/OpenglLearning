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

	private:
		std::vector<GameObject*> objects;
	

};

#endif
