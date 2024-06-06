#include "Cube.h"
#include <string>
#include <iostream>

Cube::Cube(GLuint program, glm::vec3 position, glm::vec3 rotation, float rotationValue, glm::vec3 scale, glm::vec4 color)
	: GameObject(program, position, rotation, rotationValue, scale, color)
{
	//Definimos cantidad de vao a crear y donde almacenarlos 
	glGenVertexArrays(1, &vaoPuntos);

	//Indico que el VAO activo de la GPU es el que acabo de crear
	glBindVertexArray(vaoPuntos);

	//Definimos cantidad de vbo a crear y donde almacenarlos
	glGenBuffers(1, &vboPuntos);

	//Indico que el VBO activo es el que acabo de crear y que almacenará un array. Todos los VBO que genere se asignaran al último VAO que he hecho glBindVertexArray
	glBindBuffer(GL_ARRAY_BUFFER, vboPuntos);

	//Posición X e Y del punto
	GLfloat punto[] = {
		-0.5f, +0.5f, -0.5f, // 3
		+0.5f, +0.5f, -0.5f, // 2
		-0.5f, -0.5f, -0.5f, // 6
		+0.5f, -0.5f, -0.5f, // 7
		+0.5f, -0.5f, +0.5f, // 4
		+0.5f, +0.5f, -0.5f, // 2
		+0.5f, +0.5f, +0.5f, // 0
		-0.5f, +0.5f, -0.5f, // 3
		-0.5f, +0.5f, +0.5f, // 1
		-0.5f, -0.5f, -0.5f, // 6
		-0.5f, -0.5f, +0.5f, // 5
		+0.5f, -0.5f, +0.5f, // 4
		-0.5f, +0.5f, +0.5f, // 1
		+0.5f, +0.5f, +0.5f  // 0
	};

	//Definimos modo de dibujo para cada cara
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	//Ponemos los valores en el VBO creado
	glBufferData(GL_ARRAY_BUFFER, sizeof(punto), punto, GL_STATIC_DRAW);

	//Indicamos donde almacenar y como esta distribuida la información
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);

	//Indicamos que la tarjeta gráfica puede usar el atributo 0
	glEnableVertexAttribArray(0);

	//Desvinculamos VBO
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//Desvinculamos VAO
	glBindVertexArray(0);
}

void Cube::Update(float dt)
{
	{
		glUseProgram(program);
		glBindVertexArray(vaoPuntos);


		float camX = distance * -sinf(rotation.x * (3.141516 / 180)) * cosf((rotation.y) * (3.141516 / 180));
		float camY = distance * -sinf((rotation.y) * (3.141516 / 180));
		float camZ = -distance * cosf((rotation.x) * (3.141516 / 180)) * cosf((rotation.y) * (3.141516 / 180));

		rotation.y += orbitVelocity * dt;

		position = glm::vec3(camZ, camY, camX);
		// Calcular el ángulo polar
		float angle = atan2(camY, camX);

		// Ajustar el ángulo para que esté entre 0 y 2*PI
		if (angle < 0) {
			angle += 2 * 3.141516f;
		}

		// Detección del cuadrante y cálculo de alpha
		std::string cuadrante;
		float alpha = 0.0f;

		if (camY >= 0) {
			if (angle < 3.141516f / 2) {
				cuadrante = "Arriba Derecha";
				alpha =  0.5f + (angle / (3.141516f / 2)) * 0.5f;
				colorA = colors[0];
				colorB = colors[1];
			}
			else {
				cuadrante = "Arriba Izquierda";
				alpha =  1.0f - (angle / (3.141516f / 2) / (3.141516f / 2)) * 0.5f;
				colorA = colors[1];
				colorB = colors[2];
			}
		}
		else {
			cuadrante = "Abajo";
			if (angle >= 3.141516f && angle < 2 * 3.141516f) {
				alpha = (angle - 3.141516f) / (3.141516f);
				colorA = colors[2];
				colorB = colors[0];
			}
			else if (angle >= 0 && angle < 3.141516f / 2) {
				alpha = (3.141516f + angle) / (3.141516f);
				colorA = colors[0];
				colorB = colors[0];
			}
		}

		std::cout << "El objeto está en: " << cuadrante << "\n";
		std::cout << "Alpha: " << alpha << "\n";

		glm::mat4 translateMatrix = MatrixTools::GenerateTranslationMatrix(position);
		glm::mat4 rotateMatrix = MatrixTools::GenerateRotationMatrix(rotation, rotationValue);
		glm::mat4 scaleMatrix = MatrixTools::GenerateScaleMatrix(scale);

		glUniformMatrix4fv(glGetUniformLocation(program, "translationMatrix"), 1, GL_FALSE, glm::value_ptr(translateMatrix));
		glUniformMatrix4fv(glGetUniformLocation(program, "rotationMatrix"), 1, GL_FALSE, glm::value_ptr(rotateMatrix));
		glUniformMatrix4fv(glGetUniformLocation(program, "scaleMatrix"), 1, GL_FALSE, glm::value_ptr(scaleMatrix));
		glUniform3fv(glGetUniformLocation(program, "colorA"), 1, glm::value_ptr(colorA));
		glUniform3fv(glGetUniformLocation(program, "colorB"), 1, glm::value_ptr(colorA));
		glUniform1f(glGetUniformLocation(program, "colorInterpolation"), alpha);

		glBindVertexArray(vaoPuntos);

		// Definimos que queremos dibujar
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 14);

		// Dejamos de usar el VAO indicado anteriormente
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}
}