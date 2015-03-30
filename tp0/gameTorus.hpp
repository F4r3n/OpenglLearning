#ifndef GAME_TORUS_H
#define GAME_TORUS_H
#include "gameObject.hpp"
class GameTorus : public GameObject {
	public:
		GameTorus(const std::string &name,GLuint &programm, double R, double r, glm::vec3 color, std::vector<glm::vec3> &offset,const std::string textureName="");
		~GameTorus();
		void makeObject();
		void draw();
		glm::vec3 torusPoint(double theta, double phi, double R, double r);

	private:
		glm::vec3 colorValue;
		double R;
		double r;
		std::string textureName;

};

#endif
