
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
#include <sstream>
#include "error.h"
class GameObject {

	public:
		GameObject(const std::string &name, GLuint &programm, std::vector<glm::vec3> &offset);
		~GameObject();
		virtual void draw();
		virtual void makeObject();
		glm::mat4 moveObject();
		glm::vec3 translation;
		void setType(GLuint type);
		void setUnit(int unit);
		GLuint getProgramm();
		std::string getName();
		bool loadOBJ(const std::string &path);


	protected:

		int unit=0;
		GLuint vao;
		GLuint programm;
		std::string _name;
		std::vector<glm::vec3> *color;
		std::vector<glm::vec3> *pos;
		std::vector<unsigned int> *index;
		std::vector<glm::vec2> *uvs;
		std::vector<glm::vec3> offset;
		std::vector<glm::vec3> *normals;
		GLuint type;
		GLuint texture;
		GLuint textureID;
		unsigned int vertexCount=0;


};

#endif
