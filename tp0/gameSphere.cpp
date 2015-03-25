#include "gameSphere.hpp"


GameSphere::GameSphere(const std::string &name, GLuint &programm,double R,glm::vec3 color,glm::vec3 translation,const std::string t):
	GameObject(name,programm,translation) {
		this->R = R;
		this->colorValue = color;
		this->textureName = t;
	}

GameSphere::~GameSphere() {

}

void GameSphere::draw() {

	GLfloat fLargest;
	glActiveTexture(GL_TEXTURE0);

	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	// Set our "myTextureSampler" sampler to user Texture Unit 0
	glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &fLargest);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, fLargest);
	glUniform1i(textureID, 0);
	GameObject::draw();

}

glm::vec3 GameSphere::torusPoint(double theta, double phi, double R)/*{{{*/
{
	float x,y,z;
	x = R*glm::cos(theta)*glm::cos(phi);
	y = R*glm::cos(phi)*glm::sin(theta);
	z = R*glm::sin(phi);


	//!todo You may implement the correct formula for the torus point here
	return glm::vec3(x,y,z);
}/*}}}*/

void GameSphere::makeObject() {

	int nbBins = 50;

	for(int indexT = 0; indexT < nbBins; indexT++) {

		for(int indexP = 0;indexP < nbBins; indexP++) {
			double phi = -glm::pi<float>()/2 + indexP*glm::pi<float>()/(nbBins-1);
			double theta = 2*indexT*glm::pi<float>()/nbBins;



			glm::vec3 p = torusPoint(theta,phi,R);
			color->push_back(colorValue[0]*indexP/nbBins);
			color->push_back(colorValue[1]);
			color->push_back(colorValue[2]);

			pos->push_back(p[0]);
			pos->push_back(p[1]);
			pos->push_back(p[2]);
			vertexCount++;

			uvs->push_back(indexP%2);
			uvs->push_back(indexT%2);




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
