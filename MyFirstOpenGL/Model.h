#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <GL/glew.h>
#include "GameObject.h"

class Model : public GameObject
{
public:
    Model(const std::vector<float>& vertexs, const std::vector<float>& uvs, const std::vector<float>& normals,
    GLuint program, glm::vec3 position, glm::vec3 rotation, float rotationValue, glm::vec3 scale, glm::vec4 color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
    void Render() const;

private:
    GLuint VAO, VBO, uvVBO, normalsVBO;
    unsigned int numVertexs;
};

#endif
