#include "Cube.h"
#include <string>
#include <iostream>

Cube::Cube(GLuint program, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, Model model, bool sun)
	: GameObject(program, position, rotation, scale, model)
{
	this->sun = sun;
	Start();
}

void Cube::Update(float dt) 
{
	//Movement Logic
	glm::vec3 positionN = normalize(position);
		
	float camX = distance * -sinf(rotation.x * (3.141516 / 180)) * cosf((rotation.y) * (3.141516 / 180));
	float camY = distance * -sinf((rotation.y) * (3.141516 / 180));
	float camZ = -distance * cosf((rotation.x) * (3.141516 / 180)) * cosf((rotation.y) * (3.141516 / 180));
		
	rotation.y += orbitVelocity * dt;

	position = glm::vec3(camZ, camY, camX);			

	// Detección del cuadrante y cálculo de alpha
	std::string cuadrante;
	float alpha = 0.0f;

	if (position.y >= 0) {
		if (position.x > 0) {
				alpha = positionN.x;
			cuadrante = "Arriba Derecha";
			colorA = colors[1];
			colorB = colors[2];
		}
		else {
				alpha = positionN.y;

			cuadrante = "Arriba Izquierda";
			colorA = colors[0];
			colorB = colors[1];
		}
		day = true;
	}
	else {
		cuadrante = "Abajo";
		if (position.x < 0) {
				alpha = -1 * positionN.x;

			colorA = colors[2];
			colorB = colors[0];
		}
		else  {
				alpha = -1 * positionN.y;

			colorA = colors[2];
			colorB = colors[2];
		}
		day = false;	
	}

	std::cout << "El objeto está en: " << cuadrante << "\n";
	std::cout << "Alpha: " << alpha << "\n";

	translateMatrix = MatrixTools::GenerateTranslationMatrix(position);
	rotateMatrix = MatrixTools::GenerateRotationMatrix(rotation, rotation.y);
	rotateMatrix *= MatrixTools::GenerateRotationMatrix(rotation, rotation.z);
	rotateMatrix *= MatrixTools::GenerateRotationMatrix(rotation, rotation.x);
	scaleMatrix = MatrixTools::GenerateScaleMatrix(scale);

	if (sun) {
		glUseProgram(program);
		glUniform3fv(glGetUniformLocation(program, "colorA"), 1, glm::value_ptr(colorA));
		glUniform3fv(glGetUniformLocation(program, "colorB"), 1, glm::value_ptr(colorB));
		glUniform1f(glGetUniformLocation(program, "colorInterpolation"), alpha);
		glUniform3fv(glGetUniformLocation(program, "sunPosition"), 1, glm::value_ptr(position));
		glUniform1f(glGetUniformLocation(program, "day"), day);
	}
}


void Cube::Start()
{
	distance = 8.0f;
	orbitVelocity = 15.0f;
	colors = { glm::vec3(0.0, 0.129, 0.306) , glm::vec3(1.0, 0.819, 0.384) , glm::vec3(0.0, 0.066, 0.266) };
}
