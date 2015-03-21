
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <GL/glew.h>  // must be included before gl.h
#include <GLFW/glfw3.h>
#include <fstream>
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/constants.hpp>
class GameObject {

		public:
			GameObject(std::string &name, GLuint &programm);
			~GameObject();
			virtual void draw() = 0;
			virtual void makeObject()=0;
			void translate(double x,double y, double z);

		protected:
		GLuint vao;
		GLuint programm;
		std::string _name;
		std::vector<float> *color;
		std::vector<float> *pos;
		std::vector<unsigned int> *index;


};

#endif
