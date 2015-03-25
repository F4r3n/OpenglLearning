#version 330
in vec3 position;
in vec3 color;
in vec2 vertexUv;
layout (location = 6) in vec3 offset;

out vec3 vColor;
out vec2 uv;
uniform mat4 trans;
uniform mat4 view;
uniform mat4 proj;
void main()
{
	vec4 v=vec4(position+offset,1.0);
	gl_Position = proj*view*trans* v;
	vColor = color;
	uv = vertexUv;
}
