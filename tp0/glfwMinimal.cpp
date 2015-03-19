/* Include headers*//*{{{*/
#include <iostream>

#include <GL/glew.h>  // must be included before gl.h
#include <GLFW/glfw3.h>
#include "glfwMinimal.h"/*}}}*/
#include <fstream>
#include <vector>

const int width = 1024, height = 800;
GLuint programId;
GLuint vao;
int indexCount;

void shutDown(int i) {

}

void init(void)
{ 
	initGLFW();
	initGLEW();
	programId = createShaders();

	make_resources();
}
int main(void)/*{{{*/
{
	std::cout << "yop"<<std::endl;
	init();
	// Sequential rendering of frames
	// a.k.a Main Loop
	while(1)
	{
		renderFrame();
	}
	shutDown(0);
}/*}}}*/


inline glm::vec3 torusPoint(double theta, double phi, double R, double r)/*{{{*/
{
	float x,y,z;
	x = (R+r*glm::cos(theta))*glm::cos(phi);
	y = (R+r*glm::cos(theta))*glm::sin(phi);
	z = r*glm::sin(theta);


	//!todo You may implement the correct formula for the torus point here
	return glm::vec3(x,y,z);
}/*}}}*/

void makeAColoredTorus(double R, double r, int nbBins)/*{{{*/
{

	GLuint positionBuffer;
	GLuint indexBuffer;
	GLuint normalBuffer;
	int indexT=0;
	int indexP=0;
	std::vector<float> *color = new std::vector<float>;
	std::vector<float> *pos = new std::vector<float>;
	std::vector<unsigned int> *index= new std::vector<unsigned int>;
	int vertexCount = 0;

	for(double theta = 0; theta < 2*glm::pi<float>(); theta+=2*glm::pi<float>() / nbBins) {
		indexP=0;

		for(double phi = 0; phi <2* glm::pi<float>() +glm::pi<float>() / nbBins; phi += 2*glm::pi<float>() / nbBins) {

			glm::vec3 p = torusPoint(theta,phi,R,r);
			color->push_back(1);
			color->push_back(0);
			color->push_back(0);

			pos->push_back(p[0]);
			pos->push_back(p[1]);
			pos->push_back(p[2]);
			vertexCount++;


			index->push_back(indexT*nbBins+indexP);
			index->push_back(((indexT+1)%nbBins)*nbBins+indexP);
			index->push_back(indexT*nbBins+(indexP+1)%nbBins);

			index->push_back(((indexT+1)%nbBins)*nbBins+indexP);
			index->push_back(indexT*nbBins+(indexP+1)%nbBins);
			index->push_back(((indexT+1)%nbBins)*nbBins+(indexP+1)%nbBins);

			indexP++;
		}

		indexT++;

	}

	std::cout << vertexCount <<std::endl;

	indexCount=index->size();

	glGenBuffers(1, &positionBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, positionBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertexCount* 3 * sizeof(float), pos->data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &normalBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, normalBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, vertexCount*3* sizeof(float), color->data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


	glGenBuffers(1, &indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount* sizeof(unsigned int), index->data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	//--------- Encapsulation and setting of VBOs
	glBindBuffer(GL_ARRAY_BUFFER, positionBuffer);
	GLint positionIndex = glGetAttribLocation(programId, "position");//here is the index and the associated GLSL attribute "position" (more on that later)
	glEnableVertexAttribArray(positionIndex);
	glVertexAttribPointer(positionIndex, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
	GLint normalIndex = glGetAttribLocation(programId, "color");
	glEnableVertexAttribArray(normalIndex);
	glVertexAttribPointer(normalIndex, 3, GL_FLOAT, GL_FALSE, 0, 0);

	//--------- Encapsulation of an IBO 
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	//--------- Deactivation (clean OpenGl state!!)
	glBindVertexArray(0);

	/*!todo exercise 2: build up a torus {{{
	 * You may find useful to implement the parametric formula in the torusPoint
	 * and torusNormal functions.
	 **/
	/*}}}*/
}/*}}}*/

std::string file_contents(std::string file,GLint *length) {
	std::cout << "in"<<std::endl;
	std::string s="";
	std::string line;
	std::ifstream myfile(file);
	if (myfile.is_open()){
		while ( getline (myfile,line) ){
			s+=line+"\n";

		}
		myfile.close();
	} else std::cout << "fichier pas ouvert";

	*length=s.size();
	std::cout << s<<std::endl;
	return s;
}

GLuint createShaders() {
	std::cout << "begin";
	GLint length1;
	GLint length2;

	std::string vs;
	std::string fs;
	vs = file_contents("../minimal.v.glsl", &length1);
	fs = file_contents("../minimal.f.glsl", &length2);

	GLchar *vSource = (GLchar*)vs.c_str();
	GLchar *fSource = (GLchar*)fs.c_str();

	//---- GPU side (Load and compile)
	GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vShader, 1, (const GLchar**)&vSource, &length1);
	glCompileShader(vShader);
	GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);   
	glShaderSource(fShader, 1, (const GLchar**)&fSource, &length2);
	glCompileShader(fShader);
	//---- GPU side (Link)
	GLuint programId = glCreateProgram();
	glAttachShader(programId, vShader);
	glAttachShader(programId, fShader);
	glLinkProgram(programId);

	return programId;

}

void make_resources() {


	/*	GLuint positionBuffer;
		GLuint indexBuffer;
		GLuint normalBuffer;

		int indexCount;
	//---------CPU side version
	int vertexCount = indexCount=3;
	float positions[]={0,0,0, 1,1,0, 1,0,0};
	unsigned int normals[] = {1,0,0, 0,1,0 ,0,0,1};

	unsigned int indices[]={0,1,2};
	//---------GPU side version
	glGenBuffers(1, &positionBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, positionBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertexCount* 3 * sizeof(float), positions, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &normalBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, normalBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, vertexCount*3* sizeof(unsigned int), normals, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


	glGenBuffers(1, &indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount* sizeof(unsigned int), indices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	//--------- Encapsulation and setting of VBOs
	glBindBuffer(GL_ARRAY_BUFFER, positionBuffer);
	GLint positionIndex = glGetAttribLocation(programId, "position");//here is the index and the associated GLSL attribute "position" (more on that later)
	glEnableVertexAttribArray(positionIndex);
	glVertexAttribPointer(positionIndex, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
	GLint normalIndex = glGetAttribLocation(programId, "color");
	glEnableVertexAttribArray(normalIndex);
	glVertexAttribPointer(normalIndex, 3, GL_UNSIGNED_INT, GL_FALSE, 0, 0);

	//--------- Encapsulation of an IBO 
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	//--------- Deactivation (clean OpenGl state!!)
	glBindVertexArray(0);*/

	makeAColoredTorus(0.25,0.5,50);


}




void initGLFW() {
	if (!glfwInit()) shutDown(1);
	// Create OpenGL 4.4 Core Profile and Forward Compatible Context                                                   
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// Create a window of given size
	const int window_width = 1024, window_height = 800;
	GLFWwindow* window =glfwCreateWindow(window_width, window_height,
			  "Minimal OpenGL application with GLFW", NULL, NULL);
	if (!window) {
		std::cerr<<"Could not open a window"<<std::endl;
		//		shutDown(1);
	}
	// Make the context of the specified window current 
	glfwMakeContextCurrent(window);
}

void initGLEW()
{
	/* GLEW Initialization */
	// Do not forget to use glewExperimental so that glewInit works with core
	// profile: http://www.opengl.org/wiki/OpenGL_Loading_Library#GLEW
	glewExperimental = GL_TRUE;
	GLenum GlewInitResult = glewInit();
	if (GlewInitResult != GLEW_OK) {
		std::cerr<<"ERROR: "<< glewGetErrorString(GlewInitResult)<<std::endl;
		//	shutDown(1);
	}
}

void renderFrame() {
	//--------- clear the color-buffer and the depth-buffer, set some states
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	//--------- bind shader program [and textures] (see later...)
	glUseProgram(programId);
	//--------- Activate the VAO and call the drawing routine
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
	//--------- Clean state again
	glBindVertexArray(0);
	glUseProgram(0);

	GLFWwindow* window = glfwGetCurrentContext();
	glfwSwapBuffers(window);
	glfwPollEvents();
}



// vim: ft=cpp foldmethod=marker:
