#include "error.h"

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
using namespace std;

void _check_gl_error(const char *file, int line) {
	GLenum err (glGetError());

	while(err!=GL_NO_ERROR) {
		string error;

		switch(err) {
			case GL_INVALID_OPERATION:      error="INVALID_OPERATION";      break;
			case GL_INVALID_ENUM:           error="INVALID_ENUM";           break;
			case GL_INVALID_VALUE:          error="INVALID_VALUE";          break;
			case GL_OUT_OF_MEMORY:          error="OUT_OF_MEMORY";          break;
			case GL_INVALID_FRAMEBUFFER_OPERATION:  error="INVALID_FRAMEBUFFER_OPERATION";  break;
		}

		cerr << "GL_" << error.c_str() <<" - "<<file<<":"<<line<<endl;
		err=glGetError();
	}
}
