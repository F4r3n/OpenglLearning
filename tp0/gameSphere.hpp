
#ifndef GAME_SPHERE_H
#define GAME_SPHERE_H
#include "gameObject.hpp"
class GameSphere : public GameObject {
	public:
		GameSphere(const std::string &name,GLuint &programm, double R,  glm::vec3 color, std::vector<float> &offset,const std::string t="");
		~GameSphere();
		void makeObject();
		void draw();
		glm::vec3 torusPoint(double theta, double phi, double R);

	private:
		glm::vec3 colorValue;
		std::string textureName;
		double R;

};

#endif
