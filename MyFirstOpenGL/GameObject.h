#pragma once
#include "MatrixTools.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <gtc/type_ptr.hpp>
#include <vector>




class GameObject {
public:

	GLuint program;

	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
	
	glm::vec4 color;

	GameObject(GLuint program, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, glm::vec4 color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f)) 
		: program(program), position(position), rotation(rotation), scale(scale), color(color)
	{
		
	}

	virtual void Start()
	{
		glUseProgram(program);

		glUniform1i(glGetUniformLocation(program, "textureSampler"), 0);

		glUniformMatrix4fv(glGetUniformLocation(program, "translationMatrix"), 1, GL_FALSE, glm::value_ptr(MatrixTools::GenerateTranslationMatrix(position)));
		glUniformMatrix4fv(glGetUniformLocation(program, "rotationMatrix"), 1, GL_FALSE, glm::value_ptr(MatrixTools::GenerateRotationMatrix(rotation, 0)));
		glUniformMatrix4fv(glGetUniformLocation(program, "scaleMatrix"), 1, GL_FALSE, glm::value_ptr(MatrixTools::GenerateScaleMatrix(scale)));

		glUniform4fv(glGetUniformLocation(program, "ambientColor"), 1, glm::value_ptr(color));

	}
};