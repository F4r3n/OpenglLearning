#version 330
layout(location = 0) in vec3 squareVertices;
layout(location = 1) in vec3 xyz; // Position of the center of the particule and size of the square
layout(location = 2) in vec3 color; // Position of the center of the particule and size of the square


out vec3 vColor;
uniform mat4 trans;
uniform mat4 view;
uniform mat4 proj;
uniform float time;
void main()
{
	vec4 v=vec4(position+offset*t,1.0);
	gl_Position = proj*view*trans* v;
	vColor = color;
}
