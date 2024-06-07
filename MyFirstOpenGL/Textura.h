#pragma once
#include "GL/glew.h"
#include "stb_image.h"

class Textura
{
	int width;
	int height;
	int nrChannels;
	unsigned char* textInfo;
	GLuint textureMode;

public:
	int index;

	Textura(const char* texturePath, int index, GLuint textureMode);	

private:
	void Initilize();
};