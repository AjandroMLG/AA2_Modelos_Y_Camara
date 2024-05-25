#include "Cube.h"

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
		glm::mat4 translateMatrix = MatrixTools::GenerateTranslationMatrix(position);
		glm::mat4 rotateMatrix = MatrixTools::GenerateRotationMatrix(rotation, rotationValue);
		glm::mat4 scaleMatrix = MatrixTools::GenerateScaleMatrix(scale);

		glUniformMatrix4fv(glGetUniformLocation(program, "translationMatrix"), 1, GL_FALSE, glm::value_ptr(translateMatrix));
		glUniformMatrix4fv(glGetUniformLocation(program, "rotationMatrix"), 1, GL_FALSE, glm::value_ptr(rotateMatrix));
		glUniformMatrix4fv(glGetUniformLocation(program, "scaleMatrix"), 1, GL_FALSE, glm::value_ptr(scaleMatrix));
		glUniform4fv(glGetUniformLocation(program, "ambientColor"), 1, glm::value_ptr(color));


		glBindVertexArray(vaoPuntos);

		//Definimos que queremos dibujar
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 14);

		//Dejamos de usar el VAO indicado anteriormente
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}
}
