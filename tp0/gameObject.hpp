
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <GL/glew.h>  // must be included before gl.h
#include <GLFW/glfw3.h>
#include <fstream>
#include <iostream>
#include <vector>
#include "textures.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/constants.hpp>
class GameObject {

	public:
		GameObject(std::string &name, GLuint &programm, glm::vec3 translate);
		~GameObject();
		virtual void draw() = 0;
		virtual void makeObject()=0;
		glm::mat4 moveObject();
		glm::vec3 translation;
		void setType(GLuint type);
		void setUnit(int unit);

	protected:

		int unit=0;
		GLuint vao;
		GLuint programm;
		std::string _name;
		std::vector<float> *color;
		std::vector<float> *pos;
		std::vector<unsigned int> *index;
		std::vector<float> *uvs;
		GLuint type;
		GLuint texture;

		GLuint textureID;
		unsigned int vertexCount=0;


};

#endif
