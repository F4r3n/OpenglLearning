#include "gameCube.hpp"

GameCube::GameCube(const std::string &name,GLuint programm,double size, glm::vec3 color,std::vector<glm::vec3> offset,const std::string &t):
	GameObject(name,programm,offset)
{
	this->textureName = t;
	this->colorValue = color;
}

void GameCube::makeObject() {
	std::cout << "make Cube" <<std::endl;
	const float vertices[] = {

		-1.0, -1.0,  1.0,
		1.0, -1.0,  1.0,
		1.0,  1.0,  1.0,
		-1.0,  1.0,  1.0,
		// back
		-1.0, -1.0, -1.0,
		1.0, -1.0, -1.0,
		1.0,  1.0, -1.0,
		-1.0,  1.0, -1.0

	};

	const unsigned int indexTab[] = {
		0, 1, 2,
		2, 3, 0,
		// top
		3, 2, 6,
		6, 7, 3,
		// back
		7, 6, 5,
		5, 4, 7,
		// bottom
		4, 5, 1,
		1, 0, 4,
		// left
		4, 0, 3,
		3, 7, 4,
		// right
		1, 5, 6,
		6, 2, 1
	};

	const float uvTab[] = {
		0,0,1,0,1,1,0,0,1,1,0,1
	};

	for(int i=0;i<36;i++)
		index->push_back(indexTab[i]);

	for(int i=0;i<24;i+=3) {
		pos->push_back(vertices[i]);
		pos->push_back(vertices[i+1]);
		pos->push_back(vertices[i+2]);

		color->push_back(colorValue[0]);
		color->push_back(colorValue[1]);
		color->push_back(colorValue[2]);

	}
	int j=0;
	for(int i=0;i<6*12;i++) {
		if((i%12)==0) j=0;
		uvs->push_back(uvTab[j]);
		j++;
	}

	for(int i=0;i<uvs->size();i+=2)
		std::cout << uvs->at(i) <<" "<< uvs->at(i+1) <<" "  <<std::endl; 

	textureID =glGetUniformLocation(programm, "colormap"); 

	texture = loadTGATexture(textureName);
	GameObject::makeObject();

}

void GameCube::draw() {
	GameObject::draw();
}
