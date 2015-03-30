#ifndef GAME_CUBE_H
#define GAME_CUBE_H

#include "gameObject.hpp"

class GameCube : public GameObject {
	public:
		GameCube(const std::string &name,GLuint programm,double size, glm::vec3 color,std::vector<float> offset, const std::string &t);
		~GameCube();
		void makeObject();
		void draw();

	private:
		std::string textureName;
		glm::vec3 colorValue;


};


#endif
