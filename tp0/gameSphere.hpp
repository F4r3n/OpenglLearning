
#ifndef GAME_SPHERE_H
#define GAME_SPHERE_H
#include "gameObject.hpp"
class GameSphere : public GameObject {
	public:
		GameSphere(std::string &name,GLuint &programm, double R,  glm::vec3 color, glm::vec3 translate);
		~GameSphere();
		void makeObject();
		void draw();
		glm::vec3 torusPoint(double theta, double phi, double R);

	private:
		glm::vec3 colorValue;
		double R;

};

#endif
