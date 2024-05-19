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
	float rotationValue;
	glm::vec3 scale;
	
	glm::vec4 color;

	GameObject(GLuint program, glm::vec3 position, glm::vec3 rotation, float rotationValue, glm::vec3 scale, glm::vec4 color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
		

	virtual void Start();

};