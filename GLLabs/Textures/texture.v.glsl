#version 150
// ins (inputs)
in vec3 vertexPosition;
in vec4 vertexColor;
in vec2 vertexUV;
// out (outputs)
out vec4 color; 
out vec2 uv;

// all those uniforms are only there for gouraud shading (otherwise they are only in th fragment shader) 
uniform mat4 modelViewMatrix;
uniform mat4 projectionMatrix;
uniform float time;

void main()
{

	mat3 rotation = mat3(
			  vec3( cos(time), sin(time), 0.0),
			  vec3(-sin(time), cos(time), 0.0),
			  vec3( 0.0, 0.0, 1.0)
			  );
	vec4 positionH=vec4(rotation*vertexPosition,1);
	gl_Position =  projectionMatrix * modelViewMatrix *  positionH;
	color=vertexColor;
	uv=vertexUV;
}
