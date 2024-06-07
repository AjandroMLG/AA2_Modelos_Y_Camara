#pragma once
#include "GameObject.h"
#include <GLFW/glfw3.h>
#include <gtc/type_ptr.hpp>


class Cube : public GameObject
{
	float distance;
	float orbitVelocity;
	glm::vec3 colorA;
	glm::vec3 colorB;
	std::vector<glm::vec3> colors;
	bool day, sun;
public:
	Cube(GLuint program, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, Model model, bool sun);

	virtual void Update(float dt) override;

	void Start();	
};