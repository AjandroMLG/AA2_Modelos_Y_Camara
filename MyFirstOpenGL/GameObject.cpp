#include "GameObject.h"

GameObject::GameObject(GLuint program, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, Model model)
	: program(program), position(position), rotation(rotation), scale(scale), model(model)
{
	Start();
}

void GameObject::Start()
{

	translateMatrix = MatrixTools::GenerateTranslationMatrix(position);
	if (rotation == glm::vec3(0))
	{
		rotation = glm::vec3(1);
	}

	rotateMatrix = MatrixTools::GenerateRotationMatrix(rotation, rotation.y);
	rotateMatrix *= MatrixTools::GenerateRotationMatrix(rotation, rotation.x);
	rotateMatrix *= MatrixTools::GenerateRotationMatrix(rotation, rotation.z);
	scaleMatrix = MatrixTools::GenerateScaleMatrix(scale);
}

void GameObject::Render()
{
	//Indicar que programa debe usar la GPU
	glUseProgram(program);

	//Pasar Matrices
	glUniformMatrix4fv(glGetUniformLocation(program, "translationMatrix"), 1, GL_FALSE, glm::value_ptr(translateMatrix));
	glUniformMatrix4fv(glGetUniformLocation(program, "rotationMatrix"), 1, GL_FALSE, glm::value_ptr(rotateMatrix));
	glUniformMatrix4fv(glGetUniformLocation(program, "scaleMatrix"), 1, GL_FALSE, glm::value_ptr(scaleMatrix));

	if (model.GetTexture() != nullptr)
	{
		//Asignar valor de la textura
		glUniform1i(glGetUniformLocation(program, "textureSampler"), model.GetTextureIndex());
	}

	model.Render();
}

void GameObject::Update(float dt)
{

}

