#include "gameTorus.hpp"

GameTorus::GameTorus(std::string &name, GLuint &programm,double R, double r,glm::vec3 color):GameObject(name,programm) {
	this->R = R;
	this->r = r;
	this->colorValue = color;
}

GameTorus::~GameTorus() {

}

void GameTorus::draw() {
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

	GLuint positionBuffer;
	GLuint indexBuffer;
	GLuint normalBuffer;
	int indexT=0;
	int indexP=0;
	int vertexCount = 0;
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

			indexP++;
		}

		indexT++;

	}



	glGenBuffers(1, &positionBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, positionBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertexCount* 3 * sizeof(float), pos->data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &normalBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, normalBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, vertexCount*3* sizeof(float), color->data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


	glGenBuffers(1, &indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, index->size()* sizeof(unsigned int), index->data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	//--------- Encapsulation and setting of VBOs
	glBindBuffer(GL_ARRAY_BUFFER, positionBuffer);
	GLint positionIndex = glGetAttribLocation(programm, "position");//here is the index and the associated GLSL attribute "position" (more on that later)
	glEnableVertexAttribArray(positionIndex);
	glVertexAttribPointer(positionIndex, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
	GLint normalIndex = glGetAttribLocation(programm, "color");
	glEnableVertexAttribArray(normalIndex);
	glVertexAttribPointer(normalIndex, 3, GL_FLOAT, GL_FALSE, 0, 0);

	//--------- Encapsulation of an IBO 
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	//--------- Deactivation (clean OpenGl state!!)
	glBindVertexArray(0);
}
