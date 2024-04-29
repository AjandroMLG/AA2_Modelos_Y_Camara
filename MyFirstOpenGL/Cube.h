#pragma once
#include "GameObject.h"
#include <GLFW/glfw3.h>
#include <gtc/type_ptr.hpp>


class Cube : public GameObject
{
	glm::vec4 colorUp;
	glm::vec4 colorDown;
public:
	Cube() : GameObject()
	{
		vertex = {
		-0.125f, +0.125f, -0.125f,	// 3
		+0.125f, +0.125f, -0.125f,	// 2
		-0.125f, -0.125f, -0.125f,	// 6
		+0.125f, -0.125f, -0.125f,	// 7
		+0.125f, -0.125f, +0.125f,	// 4
		+0.125f, +0.125f, -0.125f,	// 2
		+0.125f, +0.125f, +0.125f,	// 0
		-0.125f, +0.125f, -0.125f,	// 3
		-0.125f, +0.125f, +0.125f,	// 1
		-0.125f, -0.125f, -0.125f,	// 6
		-0.125f, -0.125f, +0.125f,	// 5
		+0.125f, -0.125f, +0.125f,	// 4
		-0.125f, +0.125f, +0.125f,	// 1
		+0.125f, +0.125f, +0.125f	// 0
		};

		colorUp = glm::vec4(1.0, 1.0, 0.0, 1.0);
		colorDown = glm::vec4(1.0, 0.5, 0.0, 1.0);

		position = glm::vec3(0.f);
		rotation = glm::vec3(0.f);
		up = glm::vec3(0.f, 1.f, 0.f);
		rotationDirection = glm::vec3(0.f, 1.f, 0.f);
		modelMatrix = glm::mat4(1.f);
		fVelocity = 0.002f;
		fAngularVelocity = -1.f;

		glGenVertexArrays(1, &vao);

		//Indico que el VAO activo de la GPU es el que acabo de crear
		glBindVertexArray(vao);

		//Definimos cantidad de vbo a crear y donde almacenarlos
		glGenBuffers(1, &vbo);

		//Indico que el VBO activo es el que acabo de crear y que almacenará un array. Todos los VBO que genere se asignaran al último VAO que he hecho glBindVertexArray
		glBindBuffer(GL_ARRAY_BUFFER, vbo);

		//Definimos modo de dibujo para cada cara
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		//Ponemos los valores en el VBO creado
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * vertex.size(), vertex.data(), GL_STATIC_DRAW);

		//Indicamos donde almacenar y como esta distribuida la información
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);

		//Indicamos que la tarjeta gráfica puede usar el atributo 0
		glEnableVertexAttribArray(0);

		//Desvinculamos VBO
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		//Desvinculamos VAO
		glBindVertexArray(0);

		position = glm::vec3(-0.60, 0, 0);
	}

	void Update(GLuint compiled) override
	{
		glUseProgram(compiled);
		glBindVertexArray(vao);
		
		//Aplico velocidad hacia el forward
		position = position + up * fVelocity;
		rotation = rotation + glm::vec3(0.f, 1.f, 0.f) * fAngularVelocity;

		//Invierto direccion del cubo al llegar a los limites
		if (position.y >= topScreen || position.y <= downScreen) {
			up = up * -1.f;
		}

		//Genero matriz que 
		glm::mat4 cubeTranslationMatrix = MatrixTools::GenerateTranslationMatrix(position);
		glm::mat4 cubeRotationMatrix = MatrixTools::GenerateRotationMatrix(glm::vec3(0.f, 1.f, 0.f), rotation.y);

		//Aplico matriz de translacion
		modelMatrix = cubeTranslationMatrix * cubeRotationMatrix * glm::mat4(1);	
		glUniformMatrix4fv(glGetUniformLocation(compiled, "transform"), 1, GL_FALSE, glm::value_ptr(modelMatrix));		
		if(render)
			glDrawArrays(GL_TRIANGLE_STRIP, 0, 14);
		glBindVertexArray(0);
	}
};