#version 330
in vec3 position;
layout(location = 1) in vec4 xyzs; // Position of the center of the particule and size of the square
layout(location = 2) in vec4 color; // Position of the center of the particule and size of the square


out vec4 vColor;
uniform mat4 trans;
uniform mat4 view;
uniform mat4 proj;
uniform float time;
void main()
{
	float particleSize = xyzs.w;
	float speed =30.0f;
	mat4 scale = mat4(vec4(particleSize,0,0,0),
						vec4(0,particleSize,0,0),
						vec4(0,0,particleSize,0),
						vec4(0,0,0,1));
	vec3 delta = vec3(sin(gl_InstanceID)*speed*time/gl_InstanceID,cos(gl_InstanceID)*speed*time/gl_InstanceID,1);

	vec4 v=scale*vec4(position + xyzs.xyz+delta,1.0);
	gl_Position = proj*view*trans* v;

	if(gl_InstanceID == 0) {
	vColor = vec4(1,0,0,1);
	}
	else {
	vColor = color;
	}
}
