#ifndef GLFWMINIMAL
#define GLFWMINIMAL

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/constants.hpp>

void initGLFW();
void initGLEW();
void make_resources();
void renderFrame();
GLuint createShaders();

void makeAColoredTorus(double R, double r, int nbBins=10);

#endif
