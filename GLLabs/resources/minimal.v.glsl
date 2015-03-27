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
uniform float time;
void main()
{
	mat3 t = mat3(vec3(cos(time*gl_InstanceID/100.0f),sin(time*gl_InstanceID/100.0f),0.0),
				  vec3(-sin(time*gl_InstanceID/100.0f),cos(time*gl_InstanceID/100.0f),0.0),
				  vec3(0.0,      0.0,      1.0));
	vec4 v=vec4(position+offset*t,1.0);
	gl_Position = proj*view*trans* v;
	vColor = color;
	uv = vertexUv;
}
