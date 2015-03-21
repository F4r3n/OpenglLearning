#version 330
in vec3 position;
in vec3 color;
out vec3 vColor;
uniform mat4 MVP;
void main()
{
	vec4 v=vec4(position,1.0);
	gl_Position = MVP * v;
	vColor = color;
}
