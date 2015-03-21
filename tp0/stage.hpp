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

	private:
		std::vector<GameObject*> objects;

};

#endif
