#include "gameSphere.hpp"


GameSphere::GameSphere(const std::string &name, GLuint &programm,double R,glm::vec3 color,std::vector<glm::vec3> &offset,const std::string t):
	GameObject(name,programm,offset) {
		this->R = R;
		this->colorValue = color;
		this->textureName = t;
	}

GameSphere::~GameSphere() {

}

void GameSphere::draw() {
	GameObject::draw();
}

glm::vec3 GameSphere::torusPoint(double theta, double phi, double R)/*{{{*/
{
	float x,y,z;
	x = R*glm::cos(theta)*glm::cos(phi);
	y = R*glm::cos(phi)*glm::sin(theta);
	z = R*glm::sin(phi);


	return glm::vec3(x,y,z);
}/*}}}*/

void GameSphere::makeObject() {

	int nbBins = 50;

	for(int indexT = 0; indexT < nbBins; indexT++) {

		for(int indexP = 0;indexP < nbBins; indexP++) {
			double phi = -glm::pi<float>()/2 + indexP*glm::pi<float>()/(nbBins-1);
			double theta = 2*indexT*glm::pi<float>()/nbBins;



			glm::vec3 p = torusPoint(theta,phi,R);

		color->push_back(glm::vec3(colorValue[0],colorValue[1],colorValue[2]));
		pos->push_back(glm::vec3(p[0],p[1],p[2]));
			vertexCount++;

			uvs->push_back(glm::vec2(indexP%2,indexT%2));




		}
	}

	for(int indexT = 0; indexT < nbBins; indexT++) {
		for(int indexP =0;indexP < nbBins-1; indexP++) {
			index->push_back(indexT*nbBins+indexP);
			index->push_back(((indexT+1)%nbBins)*nbBins+indexP);
			index->push_back(indexT*nbBins+((indexP+1)));

			index->push_back(((indexT+1)%nbBins)*nbBins+indexP);
			index->push_back(indexT*nbBins+((indexP+1)));
			index->push_back(((indexT+1)%nbBins)*nbBins+(indexP+1));
		}
	}

	textureID =glGetUniformLocation(programm, "colormap"); 

	texture = loadTGATexture(textureName);
	GameObject::makeObject();

}
