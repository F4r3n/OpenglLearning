#version 330
in vec3 vColor;
in vec3 normals;
out vec4 out_color;

in vec2 uv;
uniform sampler2D colormap;
uniform vec3 ambient;
uniform vec3 spotcolor;
uniform vec3 spotpos;
uniform vec3 lightdir;


vec3 ComputeLightLambert(const in vec3 lightdirn, const in vec3 lightcolor, const in vec3 normal, const in vec3 mydiffuse)/*{{{*/
{
	vec3 lambert = max(0,dot(lightdirn,normal))*lightcolor*mydiffuse;
	return lambert;
}


void main()
{
	vec3 lambert = ComputeLightLambert(lightdir,vec3(0.5f,0.5f,0.9f),normals,vec3(1.0f,0.5f,0.5f));
	out_color=vec4(texture(colormap,uv).rgb*vec3(1.0f,0.9f,0.9f)+lambert,1.0)*vec4(vColor,1.0);
}
