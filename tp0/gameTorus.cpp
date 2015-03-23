#include "gameTorus.hpp"

GameTorus::GameTorus(std::string &name, GLuint &programm,double R, double r,glm::vec3 color,glm::vec3 translation,const std::string t):
	GameObject(name,programm,translation) {
	this->R = R;
	this->r = r;
	this->colorValue = color;
	this->texture = t;
}

GameTorus::~GameTorus() {

}

void GameTorus::draw() {

    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	GameObject::draw();

}

glm::vec3 GameTorus::torusPoint(double theta, double phi, double R, double r)/*{{{*/
{
	float x,y,z;
	x = (R+r*glm::cos(theta))*glm::cos(phi);
	y = (R+r*glm::cos(theta))*glm::sin(phi);
	z = r*glm::sin(theta);


	//!todo You may implement the correct formula for the torus point here
	return glm::vec3(x,y,z);
}/*}}}*/

void GameTorus::makeObject() {

	int indexT=0;
	int indexP=0;
	int nbBins = 50;

	for(double theta = 0; theta < 2*glm::pi<float>(); theta+=2*glm::pi<float>() / nbBins) {
		indexP=0;

		for(double phi = 0; phi <2* glm::pi<float>() +glm::pi<float>() / nbBins; phi += 2*glm::pi<float>() / nbBins) {

			glm::vec3 p = torusPoint(theta,phi,R,r);
			color->push_back(colorValue[0]);
			color->push_back(colorValue[1]);
			color->push_back(colorValue[2]);

			pos->push_back(p[0]);
			pos->push_back(p[1]);
			pos->push_back(p[2]);
			vertexCount++;


			index->push_back(indexT*nbBins+indexP);
			index->push_back(((indexT+1)%nbBins)*nbBins+indexP);
			index->push_back(indexT*nbBins+(indexP+1)%nbBins);

			index->push_back(((indexT+1)%nbBins)*nbBins+indexP);
			index->push_back(indexT*nbBins+(indexP+1)%nbBins);
			index->push_back(((indexT+1)%nbBins)*nbBins+(indexP+1)%nbBins);
			uvs->push_back(indexP%2);
			uvs->push_back(indexT%2);

			indexP++;
		}
		indexT++;
	}
	textureID =glGetUniformLocation(programm, "colormap"); 

	texture = loadTGATexture(texture);
	GameObject::makeObject();

}
