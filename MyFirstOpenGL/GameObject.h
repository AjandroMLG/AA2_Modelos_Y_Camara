#pragma once
#include "MatrixTools.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <gtc/type_ptr.hpp>
#include <vector>
#include "Model.h"

class GameObject {
public:

	GLuint program;
	Model model;

	//Transform
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
	
	//Matrix
	glm::mat4 translateMatrix;
	glm::mat4 rotateMatrix;
	glm::mat4 scaleMatrix;

public:
	GameObject(GLuint program, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, Model model);		

	virtual void Start();

	void Render();
	virtual void Update(float dt);
};