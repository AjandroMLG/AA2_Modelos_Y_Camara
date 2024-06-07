#pragma once
#include "GameObject.h"
#include <GLFW/glfw3.h>
#include <gtc/type_ptr.hpp>


class Cube : public GameObject
{
	GLuint vaoPuntos, vboPuntos;
	float distance = 6.0f;
	float orbitVelocity = 20.0f;
	glm::vec3 colorA;
	glm::vec3 colorB;
	bool day;
	std::vector<glm::vec3> colors{ glm::vec3(0.0, 0.129, 0.306) , glm::vec3(1.0, 0.819, 0.384) , glm::vec3(0.0, 0.066, 0.266) };
public:
	Cube(GLuint program, glm::vec3 position, glm::vec3 rotation, float rotationValue, glm::vec3 scale, glm::vec4 color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

	void Update(float dt);
	
};