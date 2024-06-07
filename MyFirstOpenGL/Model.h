#ifndef MODEL_H
#define MODEL_H

#include "Textura.h"
#include <vector>
#include <GL/glew.h>

class Model 
{
public:
    Model(const std::vector<float>& vertexs, const std::vector<float>& uvs, const std::vector<float>& normals, Textura* textura);
    
    Model(const std::vector<float>& vertexs, Textura* textura);

    void Render() const;
    inline int GetTextureIndex() const
    {
        return textura->index;
    }

    inline Textura* GetTexture() const
    {
        return textura;
    }
private:
    GLuint VAO, VBO, uvVBO, normalsVBO;
    Textura* textura;
    unsigned int numVertexs;    
};

#endif
