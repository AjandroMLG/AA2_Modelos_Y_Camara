#include "GameObject.h"

GameObject::GameObject(GLuint program, glm::vec3 position, glm::vec3 rotation, float rotationValue, glm::vec3 scale, glm::vec4 color) : program(program), position(position), rotation(rotation), scale(scale), color(color), rotationValue(rotationValue)
{

}

void GameObject::Start()
{
	glUseProgram(program);


	glm::mat4 translateMatrix = MatrixTools::GenerateTranslationMatrix(position);
	glm::mat4 rotateMatrix = MatrixTools::GenerateRotationMatrix(rotation, rotationValue);
	glm::mat4 scaleMatrix = MatrixTools::GenerateScaleMatrix(scale);

	glUniformMatrix4fv(glGetUniformLocation(program, "translationMatrix"), 1, GL_FALSE, glm::value_ptr(translateMatrix));
	glUniformMatrix4fv(glGetUniformLocation(program, "rotationMatrix"), 1, GL_FALSE, glm::value_ptr(rotateMatrix));
	glUniformMatrix4fv(glGetUniformLocation(program, "scaleMatrix"), 1, GL_FALSE, glm::value_ptr(scaleMatrix));

	glUniform4fv(glGetUniformLocation(program, "ambientColor"), 1, glm::value_ptr(color));
}

