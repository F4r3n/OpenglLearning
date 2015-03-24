#include "game.hpp"

Game::Game() {

}

void Game::init() {

	initGLFW();
	initGLEW();
	type = GL_TRIANGLES;
	createShaders();

	make_resources();
}


void Game::initGLFW() {

	if (!glfwInit()) shutDown(1);
	// Create OpenGL 4.4 Core Profile and Forward Compatible Context                                                   
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// Create a window of given size
	window =glfwCreateWindow(width, height,
			  "Minimal OpenGL application with GLFW", NULL, NULL);
	if (!window) {
		std::cerr<<"Could not open a window"<<std::endl;
		//		shutDown(1);
	}
	// Make the context of the specified window current 
	glfwMakeContextCurrent(window);
}

void Game::initGLEW() {

	glewExperimental = GL_TRUE;
	GLenum GlewInitResult = glewInit();
	if (GlewInitResult != GLEW_OK) {
		std::cerr<<"ERROR: "<< glewGetErrorString(GlewInitResult)<<std::endl;
			shutDown(1);
	}
}


void Game::make_resources() {

	MatrixID = glGetUniformLocation(programm, "MVP");
}

void Game::renderFrame() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glUseProgram(programm);

	glm::mat4 ProjectionMatrix = camera.getProjection();
	glm::mat4 ViewMatrix = camera.getView();

	stage.draw(MatrixID,ViewMatrix,ProjectionMatrix);


	//--------- Clean state again
	glUseProgram(0);

	GLFWwindow *window = glfwGetCurrentContext();
	glfwSwapBuffers(window);
	glfwPollEvents();
}

void Game::run() {
	std::string name = "tore";
	GameTorus *torus = new GameTorus(name,programm,0.5,0.25,glm::vec3(1,0,0),glm::vec3(0,2,-5),"checkerboard.tga");
	GameTorus *torus2 = new GameTorus(name,programm,1,0.25,glm::vec3(0,1,0),glm::vec3(1,0,-5),"brick_colormap.tga");
	GameSphere *s = new GameSphere(name,programm,0.25,glm::vec3(1,1,0),glm::vec3(2,0,0),"checkerboard.tga");

	stage.addObject(torus);
	stage.addObject(torus2);
	stage.addObject(s);
	for(int i=0;i<10;++i) stage.addObject(new GameSphere(name,programm,0.25*i,glm::vec3(1,1,0),glm::vec3(-5+i,0,0),"brick_colormap.tga"));
	stage.makeObject();


	float dt = 1/60;
	float time = 0;
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	bool pressL=false;

	while(1)
	{

		if (glfwGetKey(window,GLFW_KEY_ESCAPE) == GLFW_PRESS) break;
		if(glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS && pressL == false){
			if(type == GL_TRIANGLES) type = GL_LINES;
			else type = GL_TRIANGLES;
			stage.setType(type);
			pressL = true;
		}
		if(glfwGetKey(window, GLFW_KEY_L) == GLFW_RELEASE) pressL = false;
		while(time<dt)
			time+=0.01;
		time=0;
		glClear( GL_COLOR_BUFFER_BIT );

		camera.update(time,window);
		glUseProgram(programm);

		glfwPollEvents();
		renderFrame();
	}
	shutDown(0);
}


void Game::shutDown(int i) {
	glfwTerminate();
}


std::string Game::file_contents(std::string file,GLint *length) {
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

void Game::createShaders() {

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
	programm = glCreateProgram();
	glAttachShader(programm, vShader);
	glAttachShader(programm, fShader);
	glLinkProgram(programm);

}



Game::~Game(){

}
