#version 330
in vec3 position;
in vec3 color;
in vec2 vertexUv;
in vec3 normal;
layout (location = 6) in vec3 offset;

out vec3 vColor;
out vec2 uv;
out vec3 normals;
uniform mat4 trans;
uniform mat4 view;
uniform mat4 proj;
uniform float time;
void main()
{
	vec4 v=vec4(position+offset,1.0);
	gl_Position = proj*view*trans* v;
	vColor = color;
	uv = vertexUv;
	normals = normal;
}
