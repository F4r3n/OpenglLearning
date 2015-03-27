#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>

#include <GL/glew.h>  // must be included before gl.h
#include <GLFW/glfw3.h>
#include "glfwMinimal.h"/*}}}*/
#include <fstream>
#include <vector>
class Camera {

	public:
		Camera();
		void update(float deltaTime, GLFWwindow *window);
		glm::mat4 getProjection();
		glm::mat4 getView();

	private:
		glm::vec3 position = glm::vec3( 0, 0, 5 );
		float horizontalAngle = 3.14f;
		float verticalAngle = 0.0f;
		float initialFoV = 45.0f;
		double xpos, ypos; 
		float speed = 3.0f; // 3 units / second
		float mouseSpeed = 0.005f;
		glm::mat4 projection;
		glm::mat4 view;
};


#endif
