#ifndef GAME_H
#define GAME_H


#include <iostream>

#include <GL/glew.h>  // must be included before gl.h
#include <GLFW/glfw3.h>
#include <fstream>
#include <vector>
#include "gameTorus.hpp"
#include "gameSphere.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/constants.hpp>
#include "stage.hpp"

class Game {
	public:
		Game();
		~Game();
		void initGLFW();
		void initGLEW();
		void init();
		void make_resources();
		void renderFrame();
		GLuint createShaders(const std::string & vertex, const std::string & fragment);
		void run();
		void shutDown(int i);
		std::string file_contents(std::string file,GLint *length);

	private:
		GLuint programm;
		GLFWwindow *window;
		Stage stage;
		GLuint MatrixID;
		const int width = 1024, height = 800;
		GLuint type;
		GLuint diffuseID;

};
#endif 
