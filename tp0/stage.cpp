#include "stage.hpp"

Stage::Stage() {

}

Stage::~Stage() {

}

void Stage::draw() {
	for(auto o : objects)
		o->draw();
}

void Stage::makeObject() {
	for(auto o : objects)
		o->makeObject();

}

void Stage::addObject(GameObject *object) {
	objects.push_back(object);
}
