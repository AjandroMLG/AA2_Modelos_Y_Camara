#pragma once
#include "GameObject.h"
#include <GLFW/glfw3.h>
#include <gtc/type_ptr.hpp>


class Cube : public GameObject
{
	GLuint vaoPuntos, vboPuntos;
public:
	Cube(GLuint program, glm::vec3 position, glm::vec3 rotation, float rotationValue, glm::vec3 scale, glm::vec4 color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

	void Update();
	
};