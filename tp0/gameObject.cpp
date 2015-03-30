#include "gameObject.hpp"

GameObject::GameObject(const std::string &name,GLuint &programm,std::vector<glm::vec3> &offset) {
	_name = name;
	this->programm = programm;
	color = new std::vector<glm::vec3>();
	pos = new std::vector<glm::vec3>();
	index = new std::vector<unsigned int>();
	uvs = new std::vector<glm::vec2>();
	normals = new std::vector<glm::vec3>();
	type = GL_TRIANGLES;
	this->offset = offset;

}

void GameObject::setUnit(int unit) {
	this->unit = unit;
}

GLuint GameObject::getProgramm() {
		return programm;
}

void GameObject::makeObject() {
	GLuint positionBuffer;
	GLuint indexBuffer;
	GLuint colorBuffer;
	GLuint textureBuffer;
	GLuint normalBuffer;

	if(index->size() == 0){
		for(unsigned int i=0;i<pos->size();i++) index->push_back(i);
	}
	std::cout << pos->size() <<std::endl;

	GLuint instanceVBO;
	glGenBuffers(1, &instanceVBO);
	glBindBuffer(GL_ARRAY_BUFFER, instanceVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * offset.size(), &offset[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);


	glGenBuffers(1, &positionBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, positionBuffer);
	glBufferData(GL_ARRAY_BUFFER, pos->size()* sizeof(glm::vec3), pos->data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &normalBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
	glBufferData(GL_ARRAY_BUFFER, normals->size()* sizeof(glm::vec3), normals->data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &colorBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
	glBufferData(GL_ARRAY_BUFFER, color->size()* sizeof(glm::vec3), color->data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);


	glGenBuffers(1, &indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, index->size()* sizeof(unsigned int), index->data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glGenBuffers(1, &textureBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, textureBuffer);
	glBufferData(GL_ARRAY_BUFFER, uvs->size()* sizeof(glm::vec2), uvs->data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	//--------- Encapsulation and setting of VBOs
	glBindBuffer(GL_ARRAY_BUFFER, positionBuffer);
	GLint positionIndex = glGetAttribLocation(programm, "position");//here is the index and the associated GLSL attribute "position" (more on that later)
	glEnableVertexAttribArray(positionIndex);
	glVertexAttribPointer(positionIndex, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
	GLint colorIndex = glGetAttribLocation(programm, "color");
	glEnableVertexAttribArray(colorIndex);
	glVertexAttribPointer(colorIndex, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
	GLint normalIndex = glGetAttribLocation(programm, "normal");
	glEnableVertexAttribArray(normalIndex);
	glVertexAttribPointer(normalIndex, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, textureBuffer);
	GLint textureIndex = glGetAttribLocation(programm, "vertexUv");
	glEnableVertexAttribArray(textureIndex);
	glVertexAttribPointer(textureIndex, 2, GL_FLOAT, GL_FALSE, 0, 0);
	//--------- Encapsulation of an IBO 
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	//--------- Desactivation (clean OpenGl state!!)
	//	glActiveTexture(GL_TEXTURE0);
	//	glBindTexture(GL_TEXTURE_2D, texture);

	// Set our "myTextureSampler" sampler to user Texture Unit 0



	glEnableVertexAttribArray(6);
	glBindBuffer(GL_ARRAY_BUFFER, instanceVBO);
	glVertexAttribPointer(6, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (GLvoid*)0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);	
	glVertexAttribDivisor(6, 1);  

	glBindVertexArray(0);
	check_gl_error();
}

std::string GameObject::getName() {
	return _name;
}

void GameObject::setType(GLuint type) {
	this->type = type;
}

glm::mat4 GameObject::moveObject() {
	glm::mat4 m = glm::mat4(1.0);
	m = glm::translate(m,translation);
	return m;
}


void GameObject::draw() {

	GLfloat fLargest;
	glActiveTexture(GL_TEXTURE0);

	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	// Set our "myTextureSampler" sampler to user Texture Unit 0
	glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &fLargest);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, fLargest);
	glUniform1i(textureID, 0);
	glBindVertexArray(vao);
	glDrawElementsInstanced(type, index->size(), GL_UNSIGNED_INT, 0,offset.size());
	glBindVertexArray(0);

}

bool GameObject::loadOBJ(const std::string &path) {

	std::cout << "Loading OBJ file " << path << std::endl;

	std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
	std::vector<glm::vec3> temp_vertices; 
	std::vector<glm::vec2> temp_uvs;
	std::vector<glm::vec3> temp_normals;


	FILE * file = fopen(path.c_str(), "r");
	if( file == NULL ){
		printf("Impossible to open the file ! Are you in the right path ? See Tutorial 1 for details\n");
		getchar();
		return false;
	}

	while( 1 ){
		char lineHeader[128];
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF)
			break; // EOF = End Of File. Quit the loop.


		if ( strcmp( lineHeader, "v" ) == 0 ){
			glm::vec3 vertex;
			fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z );
			temp_vertices.push_back(vertex);
		}else if ( strcmp( lineHeader, "vt" ) == 0 ){
			glm::vec2 uv;
			fscanf(file, "%f %f\n", &uv.x, &uv.y );
			uv.y = -uv.y; // Invert V coordinate since we will only use DDS texture, which are inverted. Remove if you want to use TGA or BMP loaders.
			temp_uvs.push_back(uv);
		}else if ( strcmp( lineHeader, "vn" ) == 0 ){
			glm::vec3 normal;
			fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z );
			temp_normals.push_back(normal);

		}else if ( strcmp( lineHeader, "f" ) == 0 ){

			std::string vertex1, vertex2, vertex3;
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
			int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2] );

			if (matches != 9){
				printf("File can't be read by our simple parser :-( Try exporting with other options\n");
				return false;

			}
			vertexIndices.push_back(vertexIndex[0]);
			vertexIndices.push_back(vertexIndex[1]);
			vertexIndices.push_back(vertexIndex[2]);
			uvIndices    .push_back(uvIndex[0]);
			uvIndices    .push_back(uvIndex[1]);
			uvIndices    .push_back(uvIndex[2]);

			normalIndices.push_back(normalIndex[0]);
			normalIndices.push_back(normalIndex[1]);
			normalIndices.push_back(normalIndex[2]);
		}else{


			char stupidBuffer[1000];
			fgets(stupidBuffer, 1000, file);
		}
	}

	for( unsigned int i=0; i<vertexIndices.size(); i++ ){


		unsigned int vertexIndex = vertexIndices[i];
		unsigned int uvIndex = uvIndices[i];
		unsigned int normalIndex = normalIndices[i];


		glm::vec3 vertex = temp_vertices[ vertexIndex-1 ];
		glm::vec2 uv = temp_uvs[ uvIndex-1 ];
		glm::vec3 normal = temp_normals[ normalIndex-1 ];


		pos->push_back(vertex);
		uvs->push_back(uv);
		normals->push_back(normal);
		color->push_back(glm::vec3(0.5,0.5,0.5));

	}
	return true;

}



GameObject::~GameObject() {
	delete color;
	delete pos;
	delete index;
}
