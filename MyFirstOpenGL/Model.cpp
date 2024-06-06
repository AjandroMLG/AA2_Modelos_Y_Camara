#include "Model.h"
#include <iostream>

Model::Model(const std::vector<float>& vertexs, const std::vector<float>& uvs, const std::vector<float>& normals, GLuint program, glm::vec3 position, glm::vec3 rotation, float rotationValue, glm::vec3 scale, glm::vec4 color)
    : GameObject(program, position, rotation, rotationValue, scale, color)
{

    //Almaceno la cantidad de vertices que habra
    this->numVertexs = vertexs.size() / 3;

    //Generamos VAO/VBO
    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &this->VBO);
    glGenBuffers(1, &this->uvVBO);
    glGenBuffers(1, &this->normalsVBO);

    //Defino el VAO creado como activo
    glBindVertexArray(this->VAO);

    //Defino el VBO de las posiciones como activo, le paso los datos y lo configuro
    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, vertexs.size() * sizeof(float), vertexs.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    // Definimos el VBO de las coordenadas de textura como activo, le pasamos los datos y lo configuramos
    glBindBuffer(GL_ARRAY_BUFFER, this->uvVBO);
    glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(float), uvs.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);

    //Defino el VBO de las posiciones como activo, le paso los datos y lo configuro
    glBindBuffer(GL_ARRAY_BUFFER, this->normalsVBO);
    glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(float), normals.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    //Activamos ambos atributos para ser usados
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    //Desvinculamos VAO y VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Model::Render() const {

    glUseProgram(program);

    glm::mat4 translateMatrix = MatrixTools::GenerateTranslationMatrix(position);
    glm::mat4 rotateMatrix = MatrixTools::GenerateRotationMatrix(rotation, rotationValue);
    glm::mat4 scaleMatrix = MatrixTools::GenerateScaleMatrix(scale);

    glUniformMatrix4fv(glGetUniformLocation(program, "translationMatrix"), 1, GL_FALSE, glm::value_ptr(translateMatrix));
    glUniformMatrix4fv(glGetUniformLocation(program, "rotationMatrix"), 1, GL_FALSE, glm::value_ptr(rotateMatrix));
    glUniformMatrix4fv(glGetUniformLocation(program, "scaleMatrix"), 1, GL_FALSE, glm::value_ptr(scaleMatrix));


    //Vinculo su VAO para ser usado
    glBindVertexArray(this->VAO);

    // Dibujamos
    glDrawArrays(GL_TRIANGLES, 0, this->numVertexs);

    //Desvinculamos VAO
    glBindVertexArray(0);

}
