#version 410
in vec3 vColor;
out vec4 out_color; 
void main()
{
	out_color=vec4(vColor,1.0);
}
