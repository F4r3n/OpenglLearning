#version 330
in vec3 vColor;
out vec4 out_color;

in vec2 uv;
uniform sampler2D colormap;
void main()
{
	out_color=texture(colormap,uv)*vec4(1,1,1,1)*vec4(vColor,1.0);
}
