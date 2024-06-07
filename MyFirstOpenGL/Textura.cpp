#include "Textura.h"

Textura::Textura(const char* texturePath, int index, GLuint textureMode)
{
	textInfo = stbi_load(texturePath, &width, &height, &nrChannels, 0);
	this->index = index;
	this->textureMode = textureMode;
	Initilize();
}

void Textura::Initilize()
{
	//Canal textura activo
	glActiveTexture(textureMode);

	//Genereamos y vinculamos textura
	GLuint textureID;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	//Config. textura
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//Cargar imagen a la textura
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, textInfo);

	//Genera MipMap
	glGenerateMipmap(GL_TEXTURE_2D);

	//Liberar memoria
	stbi_image_free(textInfo);
}
